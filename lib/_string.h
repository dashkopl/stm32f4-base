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
 *   _string.h
 * DESCRIPTION:
 *   Extended string.
 * HISTORY:
 *   2015.8.4        PANDA         Create
 *
 *****************************************************************************/

#ifndef ___STRING_H
#define ___STRING_H


/* check string is empty */
#define IsStrEmpty(a)           (strlen(a) == 0)

/* check string is equal */
#define IsStrEqual(a, b)        (strcmp((a), (b)) == 0)

/* check can find string/char b in string a? */
#define ContainStr(a, b)        (strstr((a), (b)) == '\0')
#define ContainChar(a, b)       (strchr((a), (b)) == '\0')

/* return the string end address, i.e. the '\0' character address */
#define StrEnd(s)               ((s) + strlen(s))


/******************************************************************************
 * FUNCTION NAME:
 *      _trimHead
 * DESCRIPTION:
 *      Trim the leading spaces of the input string.
 * PARAMETERS:
 *      pStr : Input string to trim, and output string after trimmed.
 * RETURN:
 *      The trimmed string.
 * NOTES:
 *      This API will modify the input string, please backup it first.
 * HISTORY:
 *      2012.7.19        Panda.Xiong         Create/Update
 *****************************************************************************/
char *_trimHead(IN OUT char *pStr);

/******************************************************************************
 * FUNCTION NAME:
 *      _trimTail
 * DESCRIPTION:
 *      Trim the tailing spaces of the input string.
 * PARAMETERS:
 *      pStr : Input string to trim, and output string after trimmed.
 * RETURN:
 *      The trimmed string.
 * NOTES:
 *      This API will modify the input string, please backup it first.
 * HISTORY:
 *      2012.7.19        Panda.Xiong         Create/Update
 *****************************************************************************/
char *_trimTail(IN OUT char *pStr);

/******************************************************************************
 * FUNCTION NAME:
 *      _trim
 * DESCRIPTION:
 *      Trim the leading & tailing spaces of the input string.
 * PARAMETERS:
 *      pStr : Input string to trim, and output string after trimmed.
 * RETURN:
 *      The trimmed string.
 * NOTES:
 *      This API will modify the input string, please backup it first.
 * HISTORY:
 *      2012.7.19        Panda.Xiong         Create/Update
 *****************************************************************************/
char *_trim(IN OUT char *pStr);

/******************************************************************************
 * FUNCTION NAME:
 *      _trimAll
 * DESCRIPTION:
 *      Trim the leading & tailing & inside spaces of the input string,
 *       the inside spaces will be trimmed to only one space.
 * PARAMETERS:
 *      pStr : Input string to trim, and output string after trimmed.
 * RETURN:
 *      The trimmed string.
 * NOTES:
 *      This API will modify the input string, please backup it first.
 * HISTORY:
 *      2012.7.19        Panda.Xiong         Create/Update
 *****************************************************************************/
char *_trimAll(IN OUT char *pStr);


#endif /* ___STRING_H */

