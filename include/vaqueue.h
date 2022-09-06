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

#ifndef _VAQUEUE_H_
#define _VAQUEUE_H_ 1

#include "varray.h"

#define vaqueue_add(inst, val)\
{\
    varray_resize(inst, varray_len(inst)+1);\
    varray_at(inst, varray_len(inst)-1) = val;\
}

#define vaqueue_rem(inst, val)\
{\
    val = varray_at(inst, 0);\
    memmove(varray_data(inst), varray_data(inst)+varray_tsize(inst), varray_len(inst)-varray_tsize(inst));\
    varray_resize(inst, varray_len(inst)-1);\
}

#define vaqueue_peek(inst, val)\
{\
    val = varray_at(inst, 0);\
}

#endif