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
extern inline void valist_insert(varray * inst, size_t ind, vague_t val);
// Removes the value at the given index in the arraylist. It is recommended to free the result.
extern inline vague_t valist_remove(varray * inst, size_t ind);
// Pushes a value on the end of the arraylist.
extern inline void valist_push(varray * inst, vague_t val);
// Pops a value from the end of the arraylist.
extern inline vague_t valist_pop(varray * inst);

#endif