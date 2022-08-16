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

#ifndef _VSTRING_H_
#define _VSTRING_H_ 1

#ifndef _STDLIB_H_ 
#include <stdlib.h>
#endif
// A string buffer that can be used to store data in a memory safe way. It is not recommended to access the struct directly, but rather use the vstring_* functions.
typedef struct vstring_t {
    char *data;
    size_t length;
} vstring_t;

// check for c++, if not use extern
#ifdef __cplusplus
extern "C" {
#endif

// INIT/DEINIT

// Allocates a new vstring. Returns NULL if allocation failed.
vstring_t *vstring_new();
// Allocates a new vstring and copies LEN bytes from DATA into it.
vstring_t *vstring_from(char *data, size_t len);
// Sets the data of the vstring to DATA, and sets the length to LEN.
void vstring_set(vstring_t *vstr, char *data, size_t len);
// Frees a vstring.
void vstring_free(vstring_t *vs);

// PROPERTY ACCESSORS

// Returns the length of the vstring.
size_t vstring_length(vstring_t *vs);
// Returns a copy of the data of the vstring. The caller is responsible for freeing the memory.
char *vstring_data(vstring_t *vs);
// Returns SIZE bytes of a copy of the data of the vstring, offset by OFFSET. The caller is responsible for freeing the memory.
char *vstring_ndata(vstring_t *vs, size_t offset, size_t size);

// METHODS

// Gets a character from the vstring at POSITION.
char get_char(vstring_t *vs, size_t position);
// Sets a character in the vstring at POSITION.
void set_char(vstring_t *vs, size_t position, char c);
// Appends a vstring to another vstring.
void vstring_append(vstring_t *vsa, vstring_t *vsb);
// Appends a C-string to a vstring, with a length of LEN.
void vstring_append_nstring(vstring_t *vsa, char *cstring, size_t len);
// Appends a character to a vstring.
void vstring_append_char(vstring_t *vsa, char c);
// Compares two vstrings. Returns 1 if they are equal, 0 otherwise.
int vstring_compare(vstring_t *vsa, vstring_t *vsb);
// Compares two vstrings, ignoring case. Returns 1 if they are equal, 0 otherwise.
int vstring_icompare(vstring_t *vsa, vstring_t *vsb);
// Compares a vstring with a C-string. Returns 1 if they are equal, 0 otherwise.
int vstring_compare_string(vstring_t *vsa, char *cstring, size_t len);
// Compares a vstring with a C-string, ignoring case. Returns 1 if they are equal, 0 otherwise.
int vstring_icompare_string(vstring_t *vsa, char *cstring, size_t len);
// Detects instances of a vstring in another vstring. Returns the number of instances found.
size_t vstring_count(vstring_t *vsa, vstring_t *vsb);
// Detects instances of a C-string in a vstring, ignoring case. Returns the number of instances found.
size_t vstring_count_string(vstring_t *vsa, char *cstring, size_t len);
// Detects instances of a character in a vstring, ignoring case. Returns the number of instances found.
size_t vstring_count_char(vstring_t *vsa, char c);
// Finds all instances of a vstring in another vstring, ignoring case. Returns the number of instances found, and stores the positions in the array pointed to by POSITIONS. The caller is responsible for freeing the memory.
size_t vstring_find(vstring_t *vsa, vstring_t *vsb, size_t **positions);
// Finds all instances of a C-string in a vstring, ignoring case. Returns the number of instances found, and stores the positions in the array pointed to by POSITIONS. The caller is responsible for freeing the memory.
size_t vstring_find_string(vstring_t *vsa, char *cstring, size_t len, size_t **positions);
// Finds all instances of a character in a vstring, ignoring case. Returns the number of instances found, and stores the positions in the array pointed to by POSITIONS. The caller is responsible for freeing the memory.
size_t vstring_find_char(vstring_t *vsa, char c, size_t **positions);
// Replaces all instances of a vstring in another vstring with another vstring. Returns the number of instances replaced.
size_t vstring_replace(vstring_t *vsa, vstring_t *vsb, vstring_t *vsc);
// Replaces instances of a C-string in another vstring with a C-string. Returns the number of instances replaced.
size_t vstring_replace_string(vstring_t *vsa, char *cstringa, size_t lena, char *cstringb, size_t lenb);
// Replaces instances of a character in another vstring with a character. Returns the number of instances replaced.
size_t vstring_replace_char(vstring_t *vsa, char ca, char cb);
// Removes all instances of a vstring from another vstring.
size_t vstring_remove(vstring_t *vsa, vstring_t *vsb);
// Removes all instances of a C-string from a vstring.
size_t vstring_remove_string(vstring_t *vsa, char *cstring, size_t len);
// Removes all instances of a character from a vstring.
size_t vstring_remove_char(vstring_t *vsa, char c);
// Returns a vstring with the lowercase version of the vstring.
vstring_t *vstring_lower(vstring_t *vs);
// Returns a vstring with the uppercase version of the vstring.
vstring_t *vstring_upper(vstring_t *vs);




#ifdef __cplusplus
}
#endif
#endif