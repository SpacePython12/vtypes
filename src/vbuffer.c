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
    memcpy(ret, vb->data, vbuffer_size(vb));
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
    return vbuffer_from(vbuffer_data(vb), vbuffer_size(vb));
}

size_t vbuffer_get_array(vbuffer_t *vb, size_t position, void *data, size_t size) {
    size_t to_copy = size - (position + size > vbuffer_size(vb) ? vbuffer_size(vb) - position : size); // bounds check
    memcpy(data, vb->data + position, to_copy);
    return to_copy;
}

size_t vbuffer_set_array(vbuffer_t *vb, size_t position, void *data, size_t size) {
    size_t to_copy = size - (position + size > vbuffer_size(vb) ? vbuffer_size(vb) - position : size); // bounds check
    memcpy(vb->data + position, data, to_copy);
    return to_copy;
}

int8_t vbuffer_get_int8(vbuffer_t *vb, size_t position) {
    int8_t ret;
    vbuffer_get_array(vb, position, (void *)&ret, sizeof(int8_t));
    return ret;
}

void vbuffer_set_int8(vbuffer_t *vb, size_t position, int8_t value) {
    vbuffer_set_array(vb, position, (void *)&value, sizeof(int8_t));
}

uint8_t vbuffer_get_uint8(vbuffer_t *vb, size_t position) {
    uint8_t ret;
    vbuffer_get_array(vb, position, (void *)&ret, sizeof(uint8_t));
    return ret;
}

void vbuffer_set_uint8(vbuffer_t *vb, size_t position, uint8_t value) {
    vbuffer_set_array(vb, position, (void *)&value, sizeof(uint8_t));
}

int16_t vbuffer_get_int16(vbuffer_t *vb, size_t position) {
    int16_t ret;
    vbuffer_get_array(vb, position, (void *)&ret, sizeof(int16_t));
    return ret;
}

void vbuffer_set_int16(vbuffer_t *vb, size_t position, int16_t value) {
    vbuffer_set_array(vb, position, (void *)&value, sizeof(int16_t));
}

uint16_t vbuffer_get_uint16(vbuffer_t *vb, size_t position) {
    uint16_t ret;
    vbuffer_get_array(vb, position, (void *)&ret, sizeof(uint16_t));
    return ret;
}

void vbuffer_set_uint16(vbuffer_t *vb, size_t position, uint16_t value) {
    vbuffer_set_array(vb, position, (void *)&value, sizeof(uint16_t));
}

int32_t vbuffer_get_int32(vbuffer_t *vb, size_t position) {
    int32_t ret;
    vbuffer_get_array(vb, position, (void *)&ret, sizeof(int32_t));
    return ret;
}

void vbuffer_set_int32(vbuffer_t *vb, size_t position, int32_t value) {
    vbuffer_set_array(vb, position, (void *)&value, sizeof(int32_t));
}

uint32_t vbuffer_get_uint32(vbuffer_t *vb, size_t position) {
    uint32_t ret;
    vbuffer_get_array(vb, position, (void *)&ret, sizeof(uint32_t));
    return ret;
}

void vbuffer_set_uint32(vbuffer_t *vb, size_t position, uint32_t value) {
    vbuffer_set_array(vb, position, (void *)&value, sizeof(uint32_t));
}

int64_t vbuffer_get_int64(vbuffer_t *vb, size_t position) {
    int64_t ret;
    vbuffer_get_array(vb, position, (void *)&ret, sizeof(int64_t));
    return ret;
}

void vbuffer_set_int64(vbuffer_t *vb, size_t position, int64_t value) {
    vbuffer_set_array(vb, position, (void *)&value, sizeof(int64_t));
}

uint64_t vbuffer_get_uint64(vbuffer_t *vb, size_t position) {
    uint64_t ret;
    vbuffer_get_array(vb, position, (void *)&ret, sizeof(uint64_t));
    return ret;
}

void vbuffer_set_uint64(vbuffer_t *vb, size_t position, uint64_t value) {
    vbuffer_set_array(vb, position, (void *)&value, sizeof(uint64_t));
}

float vbuffer_get_float(vbuffer_t *vb, size_t position) {
    float ret;
    vbuffer_get_array(vb, position, (void *)&ret, sizeof(float));
    return ret;
}

void vbuffer_set_float(vbuffer_t *vb, size_t position, float value) {
    vbuffer_set_array(vb, position, (void *)&value, sizeof(float));
}

double vbuffer_get_double(vbuffer_t *vb, size_t position) {
    double ret;
    vbuffer_get_array(vb, position, (void *)&ret, sizeof(double));
    return ret;
}

void vbuffer_set_double(vbuffer_t *vb, size_t position, double value) {
    vbuffer_set_array(vb, position, (void *)&value, sizeof(double));
}

long double vbuffer_get_ldouble(vbuffer_t *vb, size_t position) {
    long double ret;
    vbuffer_get_array(vb, position, (void *)&ret, sizeof(long double));
    return ret;
}

void vbuffer_set_ldouble(vbuffer_t *vb, size_t position, long double value) {
    vbuffer_set_array(vb, position, (void *)&value, sizeof(long double));
}
// TODO: This implementation probably leaks memory, and is kind of a mess. Don't use it for now.
ssize_t vbuffer_fnread(vbuffer_t *vb, size_t position, size_t offset, size_t size, FILE *stream) {
    ssize_t read = 0;
    // Offset the amount of bytes to skip before reading.
    fseek(stream, offset, SEEK_CUR);
    if (size == VBUFFER_RW_ALL) { // Read all remaining bytes.
        ssize_t temp;
        while (1) {
            temp = fread(vb->data + position + read, VBUFFER_IOCHUNK_SIZE, 1, stream);
            if (temp == 0) {
                break;
            } else if (temp < 0) {
                return -1;
            }
            read += temp;
        }
    } else { // Read only SIZE bytes.
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
        ssize_t temp;
        while (1) {
            temp = fwrite(vb->data + position + written, VBUFFER_IOCHUNK_SIZE, 1, stream);
            if (temp == 0) {
                break;
            } else if (temp < 0) {
                return -1;
            }
            written += temp;
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
            temp = read(fd, vb->data + position + _read, VBUFFER_IOCHUNK_SIZE);
            if (temp == 0) {
                break;
            } else if (temp < 0) {
                return -1;
            }
            _read += temp;
        }
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
        ssize_t temp;
        while (1) {
            temp = write(fd, vb->data + position + written, VBUFFER_IOCHUNK_SIZE);
            if (temp == 0) {
                break;
            } else if (temp < 0) {
                return -1;
            }
            written += temp;
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