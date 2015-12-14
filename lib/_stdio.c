/******************************************************************************
 *
 * (C) Copyright 2005-2050
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License as
 *   published by the Free Software Foundation; either version 2 of
 *   the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 *   MA 02111-1307 USA
 *
 * FILE NAME:
 *   _stdio.c
 * DESCRIPTION:
 *   Extended stdio.
 * HISTORY:
 *   2015.8.4        PANDA         Create
 *
 *****************************************************************************/

#include "cfg.h"
#include "drv.h"


#if STDIO_SUPPORT

/* stdio porting part */
#if 1
 #define __delayms(n)       DRV_CPU_DelayMs(n)
 #define __putchar(c)       DRV_UART_WriteByte(c)
 #define __getchar()        DRV_UART_ReadByte()
 #define __is_tx_empty()    DRV_UART_IsTxEmpty()
 #define __is_rx_empty()    DRV_UART_IsRxEmpty()
 #define __watchdog_kick()  DRV_WATCHDOG_Kick()
#endif


/* stdio low-level part */
#if 1

int _getchar(int timeout)
{
    if (timeout != NO_PENDING)
    {
        while (__is_rx_empty())
        {
            if ((timeout >= 0) && (timeout-- == 0))
            {
                break;
            }

            __delayms(1);
        }
    }

    return (__is_rx_empty()? -1 : __getchar());
}

void _putchar(char ch)
{
    /* wait until buffer is empty */
    while (!__is_tx_empty())
    {
        __watchdog_kick();
    }

    __putchar(ch);
}

void _puts(const char *str)
{
    while (*str != '\0')
    {
        _putchar(*str++);
    }
}

#endif


/* stdio middle-level part */
#if 1

typedef void (*VPUTCHAR_FUNC)(char ch);
typedef void (*VPUTS_FUNC)(const char *str, int len);
static VPUTCHAR_FUNC    vPUTCHAR;
static VPUTS_FUNC       vPUTS;

static char *__sprintf_buffer;
static void __sprintf_putchar(char ch)
{
    int _len = strlen(__sprintf_buffer);
    __sprintf_buffer[_len+0] = ch;
    __sprintf_buffer[_len+1] = '\0';
}
static void __sprintf_puts(const char *str, int len)
{
    int _len = strlen(__sprintf_buffer);
    strncpy(__sprintf_buffer+_len, str, len);
    __sprintf_buffer[_len+len] = '\0';
}
static void __printf_putchar(char ch)
{
    _putchar(ch);
}
static void __printf_puts(const char *str, int len)
{
    while (len--)
    {
        _putchar(*str++);
    }
}

static int __format_string
(
    char        left_fmt,
    char        zero_head,
    int         fmt_len,
    const char *str
)
{
    int len = strlen(str);

    if (fmt_len <= len)
    {
        vPUTS(str, len);
        return len;
    }
    else
    {
        if (left_fmt)
        {
            vPUTS(str, len);

            /* append spaces after the string */
            len = fmt_len - len;
            while (len-- > 0)
            {
                vPUTCHAR(' ');
            }
        }
        else
        {
            len = fmt_len - len;
            while (len-- > 0)
            {
                vPUTCHAR(zero_head?'0':' ');
            }

            vPUTS(str, strlen(str));
        }

        return fmt_len;
    }
}

static int __vprintf(const char *format, va_list arg)
{
    char    fch;
    int     fmt_len;
    char    left_fmt;
    char    zero_head;
    int     length = 0;

    for (;;)
    {
        while ((fch = *format++) != '%')
        {
            vPUTCHAR(fch);

            if (fch == '\0')
            {
                return length;
            }

            length++;
        }

        fmt_len   = 0;
        zero_head = 0;
        left_fmt  = 0;

      _format:
        switch (fch = *format++)
        {
            case '-':
                left_fmt = 1;
                /* fall-through */

            case '+':
                goto _format;

            case '.':
                zero_head = 1;
                goto _format;

            case '#':
                vPUTS("0x", 2);
                goto _format;

            case '*':
                fmt_len = va_arg(arg, int);
                goto _format;

            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                fmt_len *= 10;
                fmt_len += fch - '0';
                goto _format;

            case 'd':
            case 'i':
            {
                char    buf[12];
                int     value = va_arg(arg, int);
                _itoa(value, buf, 10);
                length += __format_string(left_fmt, zero_head, fmt_len, buf);
                break;
            }

            case 'u':
            case 'x':
            case 'X':
            {
                char         buf[11];
                unsigned int value = va_arg(arg, unsigned int);
                _uitoa(value, buf, ((fch == 'u')?10:16));
                length += __format_string(left_fmt, zero_head, fmt_len, buf);
                break;
            }

            case 'e':
            case 'E':
            case 'f':
            {
                char    buf[32];
                float   fvalue = va_arg(arg, double);
                _ftoa(fvalue, buf, ((fmt_len==0)? 6: fmt_len), (fch!='f'));
                length += __format_string(left_fmt, zero_head, fmt_len, buf);
                break;
            }

            case 'c':
            {
                char    buf[2];
                buf[0] = (char)va_arg(arg, int);
                buf[1] = '\0';
                length += __format_string(left_fmt, zero_head, fmt_len, buf);
                break;
            }

            case 's':
            {
                char   *str = va_arg(arg, char *);
                length += __format_string(left_fmt, zero_head, fmt_len, str);
                break;
            }

            default:
                /* unsupported format */
                vPUTCHAR(fch);
                length++;
                break;
        }
    }
}

#endif

/* stdio high-level part */
#if 1

int _sprintf(char *buffer, const char *fmt, ...)
{
    va_list ptr;
    int     length;

    *buffer = '\0';
    vPUTCHAR = __sprintf_putchar;
    vPUTS    = __sprintf_puts;
    __sprintf_buffer = buffer;

    va_start(ptr, fmt);
    length = __vprintf(fmt, ptr);
    va_end(ptr);

    return length;
}

int _printf(const char *fmt, ...)
{
    va_list     ptr;
    int         length;

    vPUTCHAR = __printf_putchar;
    vPUTS    = __printf_puts;

    va_start(ptr, fmt);
    length = __vprintf(fmt, ptr);
    va_end(ptr);

    return length;
}

#endif

#endif

