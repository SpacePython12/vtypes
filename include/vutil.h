/*  A small library to use variable size types safely.
    Copyright (C) 2022 SpacePython12

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.*/

#ifndef _VAUTIL_H_
#define _VAUTIL_H_ 1

#include "varray.h"

#define vague_to(T, vague) (*((T *)vague))
#define vague_from(T, val) (&(T){val})

// NOT SUITABLE FOR CRYPTOGRAPHY
unsigned long vutil_hash(void * data, size_t len)\
{\
    unsigned long ret = 19L;
    for (unsigned long i = 0; i < len; i++) {
        ret = (61 * (ret + (unsigned long)*((unsigned char *) data+i)));
    }
    return ret;
}

unsigned char vutil_equals(void * d1, size_t l1, void * d2, size_t l2)
{
    unsigned char ret = 1;
    if (l1 != l2) {
        ret = 0;
    } else {
        for (unsigned long i = 0; i < l1; i++) {
            if (*((unsigned char *) d1+i) != *((unsigned char *) d2+i)) {
                ret = 0;
                break;
            }
        }
    }
    return ret;
}


#endif