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

// Pushes VAL to INST.
extern inline void vaqueue_push(varray * inst, vague_t val);
// Returns and removes the head of INST, advancing the rest of the queue.
extern inline vague_t vaqueue_pop(varray * inst);
// Peeks at the head of INST, and puts it into VAL.
extern inline vague_t vaqueue_peek(varray * inst);

#endif