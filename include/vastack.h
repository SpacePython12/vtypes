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

#ifndef _VASTACK_H_
#define _VASTACK_H_ 1

#include "varray.h"

// Pushes VAL into INST.
extern inline void vastack_push(varray * inst, vague_t val);
// Pops from INST into VAL.
extern inline vague_t vastack_pop(varray * inst);
// Peeks into the top of INST, and places the result in VAL.
extern inline vague_t vastack_peek(varray * inst);

#endif