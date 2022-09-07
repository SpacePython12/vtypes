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

#ifndef _VARRAY_H_ 
#define _VARRAY_H_ 1

#include <stdlib.h>
#include "vdefs.h"

// A structure with a pointer of a specified type, with a given length.
typedef struct varray {
    void * data;
    size_t esize;
    size_t nmemb;
} varray;

// Macro containing the element size of the given array.
#define varray_esize(inst) ((inst)->esize)
// Macro containing the raw pointer to the data of the given array. Use this only if you know what you are doing.
#define varray_data(inst) ((inst)->data)
// Macro containing the value at the given index in the given array.
#define varray_at(inst, ind) ((inst)->data[ind*(inst)->esize])
// Macro containing the length of the given array. Don't write to this unless you know what you are doing.
#define varray_len(inst) ((inst)->nmemb)

// Initializes the given array with a valid data pointer and a given size.
extern inline varray * varray_init(size_t esize, size_t len);
// Initializes the given array with a valid data pointer and a given size, then copies data into it, without overflowing the allocated space.
extern inline varray * varray_initfrom(size_t esize, size_t len, void * data);
// Frees the given array.
extern inline void varray_free(varray * inst);
// Resizes the given array to the given size.
extern inline void varray_resize(varray * inst, size_t len);
// Sets all of the members of the given array to NULL or 0.
extern inline void varray_clear(varray * inst);
// Sets the size of the given array to zero.
extern inline void varray_reset(varray * inst);
#endif