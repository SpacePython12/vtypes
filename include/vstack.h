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

#ifndef _VSTACK_H_
#define _VSTACK_H_ 1

#ifndef _VARRAY_H_
#error "vstack.h needs varray.h included before it."
#endif

#define vstack_push(inst, val)\
{\
    varray_resize(inst, varray_len(inst)+1);\
    varray_at(inst, varray_len(inst)-1) = val;\
}

#define vstack_pop(inst, val)\
{\
    varray_resize(inst, varray_len(inst)1);\
    val = varray_at(inst, varray_len(inst));\ // Yes, it's a hack. Do I care? No. Can you stop me? Nope. Is it dangerous? Hell yes.
}

#define vstack_peek(inst, val)\
{\
    val varray_at(inst, varray_len(inst)-1);\
}

#endif