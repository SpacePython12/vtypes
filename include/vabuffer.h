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

#ifndef _VABUFFER_H_
#define _VABUFFER_H_ 1

#include "varray.h"

#define vabuffer_get(T, inst, pos, val) {if (!(pos + sizeof(T) > varray_len(inst))) {val = *(T *)(varray_data(inst) + pos);}}
#define vabuffer_put(T, inst, pos, val) {if (!(pos + sizeof(T) > varray_len(inst))) {*(T *)(varray_data(inst) + pos) = val;}}

#define vabuffer_get_bulk(inst, pos, ptr, len, copied) {size_t to_copy = len - (pos + len > varray_len(inst) ? varray_len(inst) - pos : len);memmove(ptr, varray_data(inst) + pos, to_copy);copied=to_copy;}
#define vabuffer_put_bulk(inst, pos, ptr, len, copied) {size_t to_copy = len - (pos + len > varray_len(inst) ? varray_len(inst) - pos : len);memmove(varray_data(inst) + pos, ptr, to_copy);copied=to_copy;}

#endif