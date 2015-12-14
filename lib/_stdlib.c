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
 *   _stdlib.c
 * DESCRIPTION:
 *   Extended stdlib.
 * HISTORY:
 *   2015.8.4        PANDA         Create
 *
 *****************************************************************************/

#include "typedef.h"


#if 1

#define NUMBER_OF_DIGITS 16

void _uitoa(unsigned int value, char *string, unsigned char radix)
{
    unsigned char index, i;

    index = NUMBER_OF_DIGITS;
    i = 0;

    do {
        string[--index] = '0' + (value % radix);
        if (string[index] > '9')
            string[index] += 'A' - '9' - 1;
        value /= radix;
    } while (value != 0);

    do {
        string[i++] = string[index++];
    } while (index < NUMBER_OF_DIGITS);

    /* string terminator */
    string[i] = '\0';
}

void _itoa(int value, char *string, unsigned char radix)
{
    if ((value < 0) && (radix == 10))
    {
        *string++ = '-';
        _uitoa(-value, string, radix);
    }
    else
    {
        _uitoa(value, string, radix);
    }
}

void _ftoa(double value, char *string, int digits, char e_notation)
{
    signed int integer;
    signed int decimal;
    signed int multiple;
    signed int exponent = 0;

    if (e_notation)
    {
        double v_tmp = value;

        if (value < 0)
        {
            v_tmp = -v_tmp;
        }

        if (v_tmp >= 10)
        {
            while (v_tmp >= 10)
            {
                v_tmp /= 10;
                exponent++;
            }
        }
        else if (fabs(v_tmp) < 1E-100)
        {
            /* almost equal to 0, do nothing */
        }
        else if (v_tmp < 1)
        {
            while (v_tmp < 1)
            {
                v_tmp *= 10;
                exponent--;
            }
        }

        value = ((value<0)?(-v_tmp):v_tmp);
    }

    /* integer part */
    integer = (signed int)value;
    if ((integer == 0) && (value < 0))
    {
        strcpy(string, "-");
    }
    else
    {
        strcpy(string, "");
    }
    _itoa(integer, string+strlen(string), 10);

    /* float point */
    strcat(string, ".");

    /* decimal part */
    multiple = 1;
    while (digits--)
    {
        multiple *= 10;
    }
    value  -= integer;
    if (value < 0)
    {
        value = -value;
    }
    decimal = (value * multiple *10 +5) /10;
    if (decimal == 0)
    {
        while (multiple != 1)
        {
            strcat(string, "0");
            multiple /= 10;
        }
    }
    else
    {
        for (integer = decimal*10; integer < multiple; integer *= 10)
        {
            strcat(string, "0");
        }
        _uitoa((unsigned int)decimal, string+strlen(string), 10);
    }

    if (e_notation)
    {
        strcat(string, "E");
        if (exponent >= 0)
        {
            strcat(string, "+");
        }
        _itoa(exponent, string+strlen(string), 10);
    }
}

#endif


/* memory allocation related */
#if 1

__used caddr_t _sbrk(int incr)
{
    static char *heap_end      = (char *)__heap_start;
           char *prev_heap_end = heap_end;

    if (heap_end+incr > (char *)__heap_end)
    {
        /* heap overflow */
        errno = ENOMEM;
        return (void *)-1;
    }
    heap_end += incr;

    return (caddr_t)prev_heap_end;
}

#endif

