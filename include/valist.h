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

#ifndef _VALIST_H_
#define _VALIST_H_ 1

#include "varray.h"

// Inserts a given value at the given index in the arraylist.
#define valist_insert(inst, ind, val)\
{\
    varray_resize(inst, varray_len(inst)+1);\
    memmove(varray_data(inst)+(ind*varray_tsize(inst))+varray_tsize(inst), varray_data(inst)+(ind*varray_tsize(inst)), varray_len(inst)-ind);\
    varray_at(inst, ind) = val;\
}
// Removes the value at the given index in the arraylist.
#define valist_remove(inst, ind)\
{\
    memmove(varray_data(inst)+(ind*varray_tsize(inst))-varray_tsize(inst), varray_data(inst)+(ind*varray_tsize(inst)), varray_len(inst)-ind);\
    varray_resize(inst, varray_len(inst)-1);\
}
// Insert a value at the end of the arraylist.
#define valist_add(inst, val)\
{\
    valist_insert(inst, varray_len(inst), val);\
}

#endif