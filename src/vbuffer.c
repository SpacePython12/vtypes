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

#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "vbuffer.h"

#define VBUFFER_IOCHUNK_SIZE 1024

vbuffer_t *vbuffer_new(size_t size) {
    vbuffer_t *vb = malloc(sizeof(vbuffer_t));
    if (vb == NULL) {
        return NULL;
    }
    vb->data = malloc(size);
    memset(vb->data, 0, size);
    if (vb->data == NULL) {
        free(vb);
        return NULL;
    }
    vb->capacity = size;
    return vb;
}

vbuffer_t *vbuffer_from(void *data, size_t size) {
    vbuffer_t *vb = vbuffer_new(size);
    if (vb == NULL) {
        return NULL;
    }
    memcpy(vb->data, data, size);
    return vb;
}

void vbuffer_free(vbuffer_t *vb) {
    free(vb->data);
    free(vb);
}

size_t vbuffer_capacity(vbuffer_t *vb) {
    return vb->capacity;
}

void *vbuffer_data(vbuffer_t *vb) {
    void * ret = malloc(vbuffer_capacity(vb));
    memcpy(ret, vb->data, vbuffer_capacity(vb));
    return ret;
}

void *vbuffer_ndata(vbuffer_t *vb, size_t offset, size_t size) {
    void * ret = malloc(size);
    memcpy(ret, vb->data + offset, size);
    return ret;
}

void vbuffer_resize(vbuffer_t *vb, size_t size) {
    vb->data = realloc(vb->data, size);
    vb->capacity = size;
}

void vbuffer_clear(vbuffer_t *vb) {
    memset(vb->data, 0, vb->capacity);
}

vbuffer_t * vbuffer_duplicate(vbuffer_t *vb) {
    return vbuffer_from(vbuffer_data(vb), vbuffer_capacity(vb));
}

size_t vbuffer_get_array(vbuffer_t *vb, size_t position, void *data, size_t size) {
    size_t to_copy = size - (position + size > vbuffer_capacity(vb) ? vbuffer_capacity(vb) - position : size); // bounds check
    memcpy(data, vb->data + position, to_copy);
    return to_copy;
}

size_t vbuffer_put_array(vbuffer_t *vb, size_t position, void *data, size_t size) {
    size_t to_copy = size - (position + size > vbuffer_capacity(vb) ? vbuffer_capacity(vb) - position : size); // bounds check
    memcpy(vb->data + position, data, to_copy);
    return to_copy;
}

int8_t vbuffer_get_int8(vbuffer_t *vb, size_t position) {
    if (position + sizeof(int8_t)> vbuffer_capacity(vb)) {return 0;}
    return *(int8_t *)(vb->data + position);
}

void vbuffer_put_int8(vbuffer_t *vb, size_t position, int8_t value) {
    if (position + sizeof(int8_t)> vbuffer_capacity(vb)) {return;}
    *(int8_t *)(vb->data + position) = value;
}

uint8_t vbuffer_get_uint8(vbuffer_t *vb, size_t position) {
    if (position + sizeof(uint8_t)> vbuffer_capacity(vb)) {return 0;}
    return *(uint8_t *)(vb->data + position);
}

void vbuffer_put_uint8(vbuffer_t *vb, size_t position, uint8_t value) {
    if (position + sizeof(uint8_t)> vbuffer_capacity(vb)) {return;}
    *(uint8_t *)(vb->data + position) = value;
}

int16_t vbuffer_get_int16(vbuffer_t *vb, size_t position) {
    if (position + sizeof(int16_t)> vbuffer_capacity(vb)) {return 0;}
    return *(int16_t *)(vb->data + position);
}

void vbuffer_put_int16(vbuffer_t *vb, size_t position, int16_t value) {
    if (position + sizeof(int16_t)> vbuffer_capacity(vb)) {return;}
    *(int16_t *)(vb->data + position) = value;
}

uint16_t vbuffer_get_uint16(vbuffer_t *vb, size_t position) {
    if (position + sizeof(uint16_t)> vbuffer_capacity(vb)) {return 0;}
    return *(uint16_t *)(vb->data + position);
}

void vbuffer_put_uint16(vbuffer_t *vb, size_t position, uint16_t value) {
    if (position + sizeof(uint16_t)> vbuffer_capacity(vb)) {return;}
    *(uint16_t *)(vb->data + position) = value;
}

int32_t vbuffer_get_int32(vbuffer_t *vb, size_t position) {
    if (position + sizeof(int32_t)> vbuffer_capacity(vb)) {return 0;}
    return *(int32_t *)(vb->data + position);
}

void vbuffer_put_int32(vbuffer_t *vb, size_t position, int32_t value) {
    if (position + sizeof(int32_t)> vbuffer_capacity(vb)) {return;}
    *(int32_t *)(vb->data + position) = value;
}

uint32_t vbuffer_get_uint32(vbuffer_t *vb, size_t position) {
    if (position + sizeof(uint32_t)> vbuffer_capacity(vb)) {return 0;}
    return *(uint32_t *)(vb->data + position);
}

void vbuffer_put_uint32(vbuffer_t *vb, size_t position, uint32_t value) {
    if (position + sizeof(uint32_t)> vbuffer_capacity(vb)) {return;}
    *(uint32_t *)(vb->data + position) = value;
}

int64_t vbuffer_get_int64(vbuffer_t *vb, size_t position) {
    if (position + sizeof(int64_t)> vbuffer_capacity(vb)) {return 0;}
    return *(int64_t *)(vb->data + position);
}

void vbuffer_put_int64(vbuffer_t *vb, size_t position, int64_t value) {
    if (position + sizeof(int64_t)> vbuffer_capacity(vb)) {return;}
    *(int64_t *)(vb->data + position) = value;
}

uint64_t vbuffer_get_uint64(vbuffer_t *vb, size_t position) {
    if (position + sizeof(uint64_t)> vbuffer_capacity(vb)) {return 0;}
    return *(uint64_t *)(vb->data + position);
}

void vbuffer_put_uint64(vbuffer_t *vb, size_t position, uint64_t value) {
    if (position + sizeof(uint64_t)> vbuffer_capacity(vb)) {return;}
    *(uint64_t *)(vb->data + position) = value;
}

float vbuffer_get_float(vbuffer_t *vb, size_t position) {
    if (position + sizeof(float)> vbuffer_capacity(vb)) {return 0;}
    return *(float *)(vb->data + position);
}

void vbuffer_put_float(vbuffer_t *vb, size_t position, float value) {
    if (position + sizeof(float)> vbuffer_capacity(vb)) {return;}
    *(float *)(vb->data + position) = value;
}

double vbuffer_get_double(vbuffer_t *vb, size_t position) {
    if (position + sizeof(double)> vbuffer_capacity(vb)) {return 0;}
    return *(double *)(vb->data + position);
}

void vbuffer_put_double(vbuffer_t *vb, size_t position, double value) {
    if (position + sizeof(double)> vbuffer_capacity(vb)) {return;}
    *(double *)(vb->data + position) = value;
}

long double vbuffer_get_ldouble(vbuffer_t *vb, size_t position) {
    if (position + sizeof(long double)> vbuffer_capacity(vb)) {return 0;}
    return *(long double *)(vb->data + position);
}

void vbuffer_put_ldouble(vbuffer_t *vb, size_t position, long double value) {
    if (position + sizeof(long double)> vbuffer_capacity(vb)) {return;}
    *(long double *)(vb->data + position) = value;
}

char * vbuffer_get_string(vbuffer_t *vb, size_t position) {
    size_t length = strnlen(vb->data+position, vbuffer_capacity(vb)-position);
    if (length == 0 || length == (vbuffer_capacity(vb) - position)) {return NULL;}
    char *str = malloc(length+1);
    if (str == NULL) {return NULL;}
    memcpy(str, vb->data+position, length);
    str[length] = '\0';
    return str;
}

void vbuffer_put_string(vbuffer_t *vb, size_t position, char *value) {
    size_t length = strnlen(value, vbuffer_capacity(vb)-position);
    if (length == 0 || length == (vbuffer_capacity(vb) - position)) {return;}
    memcpy(vb->data+position, value, length);
}

// TODO: This implementation probably leaks memory, and is kind of a mess. Don't use it for now.
ssize_t vbuffer_fnread(vbuffer_t *vb, size_t position, size_t offset, size_t size, FILE *stream) {
    if (stream == NULL) {return -1;}
    ssize_t read = 0;
    // Offset the amount of bytes to skip before reading.
    fseek(stream, offset, SEEK_CUR);
    if (size == VBUFFER_RW_ALL) { // Read all remaining bytes.
        ssize_t temp;
        while (1) {
            vbuffer_resize(vb, position + read + VBUFFER_IOCHUNK_SIZE);
            temp = fread(vb->data + position + read, 1, VBUFFER_IOCHUNK_SIZE, stream);
            if (temp == 0) {
                break;
            } else if (temp < 0) {
                return -1;
            }
            read += temp;
        }
        vbuffer_resize(vb, position + read);
    } else { // Read only SIZE bytes.
        vbuffer_resize(vb, position + size);
        read = fread(vb->data + position, 1, size, stream);
        if (read < 0) {
            return -1;
        }
    }
    return read;
}
// TODO: This implementation probably leaks memory, and is kind of a mess. Don't use it for now.
ssize_t vbuffer_fnwrite(vbuffer_t *vb, size_t position, size_t offset, size_t size, FILE *stream) {
    ssize_t written = 0;
    // Offset the amount of bytes to skip before writing.
    fseek(stream, offset, SEEK_CUR);
    if (size == VBUFFER_RW_ALL) { // Write all remaining bytes.
        written = fwrite(vb->data + position, 1, vbuffer_capacity(vb) - position, stream);
        if (written < 0) {
            return -1;
        }
    } else { // Write only SIZE bytes.
        written = fwrite(vb->data + position, 1, size, stream);
        if (written < 0) {
            return -1;
        }
    }
    return written;
}

ssize_t vbuffer_fread(vbuffer_t *vb, FILE *stream) {
    return vbuffer_fnread(vb, 0, 0, VBUFFER_RW_ALL, stream);
}

ssize_t vbuffer_fwrite(vbuffer_t *vb, FILE *stream) {
    return vbuffer_fnwrite(vb, 0, 0, VBUFFER_RW_ALL, stream);
}

// TODO: This implementation probably leaks memory, and is kind of a mess. Don't use it for now.
ssize_t vbuffer_nread(vbuffer_t *vb, size_t position, size_t offset, size_t size, int fd) {
    ssize_t _read = 0; // Names, right?
    // Offset the amount of bytes to skip before reading.
    lseek(fd, offset, SEEK_CUR);
    if (size == VBUFFER_RW_ALL) { // Read all remaining bytes.
        ssize_t temp;
        while (1) {
            vbuffer_resize(vb, position + _read + VBUFFER_IOCHUNK_SIZE);
            temp = read(fd, vb->data + position + _read, VBUFFER_IOCHUNK_SIZE);
            if (temp == 0) {
                break;
            } else if (temp < 0) {
                return -1;
            }
            _read += temp;
        }
        vbuffer_resize(vb, position + _read);
    } else { // Read only SIZE bytes.
        _read = read(fd, vb->data + position, size);
        if (_read < 0) {
            return -1;
        }
    }
    return _read;
}

// TODO: This implementation probably leaks memory, and is kind of a mess. Don't use it for now.
ssize_t vbuffer_nwrite(vbuffer_t *vb, size_t position, size_t offset, size_t size, int fd) {
    ssize_t written = 0;
    // Offset the amount of bytes to skip before writing.
    lseek(fd, offset, SEEK_CUR);
    if (size == VBUFFER_RW_ALL) { // Write all remaining bytes.
        written = write(fd, vb->data + position, vbuffer_capacity(vb) - position);
        if (written < 0) {
            return -1;
        }
    } else { // Write only SIZE bytes.
        written = write(fd, vb->data + position, size);
        if (written < 0) {
            return -1;
        }
    }
    return written;
}

ssize_t vbuffer_read(vbuffer_t *vb, int fd) {
    return vbuffer_nread(vb, 0, 0, VBUFFER_RW_ALL, fd);
}

ssize_t vbuffer_write(vbuffer_t *vb, int fd) {
    return vbuffer_nwrite(vb, 0, 0, VBUFFER_RW_ALL, fd);
}