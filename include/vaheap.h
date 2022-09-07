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

#ifndef _VAHEAP_H_
#define _VAHEAP_H_ 1

#include "varray.h"

#define vaheap_get(T, inst, pos, val) {if (!(pos + sizeof(T) > varray_len(inst)/sizeof(T))) {val = *(T *)(varray_data(inst) + pos);}}
#define vaheap_put(T, inst, pos, val) {if (!(pos + sizeof(T) > varray_len(inst)/sizeof(T))) {*(T *)(varray_data(inst) + pos) = val;}}

#define vaheap_get_bulk(inst, pos, ptr, len, copied) {size_t to_copy = len - (pos + len > varray_len(inst)/sizeof(T) ? varray_len(inst)*sizeof(T) - pos : len);memmove(ptr, varray_data(inst) + pos, to_copy);copied=to_copy;}
#define vaheap_put_bulk(inst, pos, ptr, len, copied) {size_t to_copy = len - (pos + len > varray_len(inst)/sizeof(T) ? varray_len(inst)*sizeof(T) - pos : len);memmove(varray_data(inst) + pos, ptr, to_copy);copied=to_copy;}

#endif