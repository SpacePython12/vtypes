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
#include <string.h>

// A structure with a pointer of a specified type, with a given length.
#define varray(T) struct varray_##T {T * data; size_t len;}

// Macro containing the type size (as by sizeof()) of the given array.
#define varray_tsize(inst) (sizeof(*(inst)->data))
// Macro containing the raw pointer to the data of the given array. Use this only if you know what you are doing.
#define varray_data(inst) ((inst)->data)
// Macro containing the value at the given index in the given array.
#define varray_at(inst, ind) ((inst)->data[ind])
// Macro containing the length of the given array. Don't write to this unless you know what you are doing.
#define varray_len(inst) ((inst)->len)

// Initializes the given array with a valid data pointer and a given size.
#define varray_init(inst, len)\
{\
    inst = malloc(sizeof(void *) + sizeof(size_t));\
    varray_data(inst) = malloc(varray_tsize(inst) * len);\
    varray_len(inst) = len;\
}
// Initializes the given array with a valid data pointer and a given size, then copies data into it, without overflowing the allocated space.
#define varray_initfrom(inst, data, len)\
{\
    varray_init(inst, len);\
    memmove(varray_data(inst), data, varray_len(inst)*varray_tsize(inst));\
}
// Frees the given array.
#define varray_free(inst)\
{\
    free(varray_data(inst));\
    free(inst);\
}
// Resizes the given array to the given size.
#define varray_resize(inst, len)\
{\
    varray_data(inst) = realloc(varray_data(inst), len*varray_tsize(inst));\
    varray_len(inst) = len;\
}
// Sets all of the members of the given array to NULL or 0.
#define varray_clear(arr)\
{\
    memset(varray_data(arr), 0, varray_len(arr)*varray_tsize(arr));\
}
// Sets the size of the given array to zero.
#define varray_reset(arr)\
{\
    varray_resize(arr, 0);\
}
#endif