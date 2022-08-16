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
typedef struct vstring {
    char *data;
    size_t length;
} vstring;

// check for c++, if not use extern
#ifdef __cplusplus
extern "C" {
#endif

// INIT/DEINIT

// Allocates a new vstring. Returns NULL if allocation failed.
vstring *vstring_new();
// Allocates a new vstring and copies LEN bytes from DATA into it.
vstring *vstring_from(char *data, size_t len);
// Sets the data of the vstring to DATA, and sets the length to LEN.
void vstring_set(vstring *vstr, char *data, size_t len);
// Frees a vstring.
void vstring_free(vstring *vs);

// PROPERTY ACCESSORS

// Returns the length of the vstring.
size_t vstring_length(vstring *vs);
// Returns a copy of the data of the vstring. The caller is responsible for freeing the memory.
char *vstring_data(vstring *vs);
// Returns SIZE bytes of a copy of the data of the vstring, offset by OFFSET. The caller is responsible for freeing the memory.
char *vstring_ndata(vstring *vs, size_t offset, size_t size);

// METHODS

// Gets a character from the vstring at POSITION.
char get_char(vstring *vs, size_t position);
// Sets a character in the vstring at POSITION.
void set_char(vstring *vs, size_t position, char c);
// Appends a vstring to another vstring.
void vstring_append(vstring *vsa, vstring *vsb);
// Appends a C-string to a vstring, with a length of LEN.
void vstring_append_nstring(vstring *vsa, char *cstring, size_t len);
// Appends a character to a vstring.
void vstring_append_char(vstring *vsa, char c);
// Compares two vstrings. Returns 1 if they are equal, 0 otherwise.
int vstring_compare(vstring *vsa, vstring *vsb);
// Compares two vstrings, ignoring case. Returns 1 if they are equal, 0 otherwise.
int vstring_icompare(vstring *vsa, vstring *vsb);
// Compares a vstring with a C-string. Returns 1 if they are equal, 0 otherwise.
int vstring_compare_string(vstring *vsa, char *cstring, size_t len);
// Compares a vstring with a C-string, ignoring case. Returns 1 if they are equal, 0 otherwise.
int vstring_icompare_string(vstring *vsa, char *cstring, size_t len);
// Detects instances of a vstring in another vstring. Returns the number of instances found.
size_t vstring_count(vstring *vsa, vstring *vsb);
// Detects instances of a vstring in another vstring, ignoring case. Returns the number of instances found.
size_t vstring_count_string(vstring *vsa, char *cstring, size_t len);
// Detects instances of a C-string in a vstring, ignoring case. Returns the number of instances found.
size_t vstring_count_char(vstring *vsa, char c);
// Detects instances of a character in a vstring, ignoring case. Returns the number of instances found.
size_t vstring_find(vstring *vsa, vstring *vsb, size_t **positions);
// Finds all instances of a vstring in another vstring, ignoring case. Returns the number of instances found, and stores the positions in the array pointed to by POSITIONS.
size_t vstring_find_string(vstring *vsa, char *cstring, size_t len, size_t **positions);
// Finds all instances of a C-string in a vstring, ignoring case. Returns the number of instances found, and stores the positions in the array pointed to by POSITIONS.
size_t vstring_find_char(vstring *vsa, char c, size_t **positions);
// Finds all instances of a character in a vstring, ignoring case. Returns the number of instances found, and stores the positions in the array pointed to by POSITIONS.
void vstring_replace(vstring *vsa, vstring *vsb, vstring *vsc);
// Replaces instances of a C-string in another vstring with a C-string.
void vstring_replace_string(vstring *vsa, char *cstringa, size_t lena, char *cstringb, size_t lenb);
// Replaces instances of a character in another vstring with a character.
void vstring_replace_char(vstring *vsa, char ca, char cb);
// Removes all instances of a vstring from another vstring.
void vstring_remove(vstring *vsa, vstring *vsb);
// Removes all instances of a C-string from a vstring.
void vstring_remove_string(vstring *vsa, char *cstring, size_t len);
// Removes all instances of a character from a vstring.
void vstring_remove_char(vstring *vsa, char c);
// Returns a vstring with the lowercase version of the vstring.
vstring *vstring_lower(vstring *vs);
// Returns a vstring with the uppercase version of the vstring.
vstring *vstring_upper(vstring *vs);




#ifdef __cplusplus
}
#endif
#endif