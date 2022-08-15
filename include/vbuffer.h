#ifndef _VBUFFER_H_
#define _VBUFFER_H_ 1

#ifndef _STDLIB_H_ 
#include <stdlib.h>
#endif

#ifndef _STDINT_H_
#include <stdint.h>
#endif

// A dynamic buffer that can be used to store data in a memory safe way. It is not recommended to access the buffer directly, but rather use the vbuffer_* functions.
typedef struct vbuffer_t {
    void *data; // The data in the buffer.
    size_t size; // The amount of data in the buffer.
    size_t capacity; // The capacity of the buffer.
} vbuffer_t;

// check for c++, if not use extern
#ifdef __cplusplus
extern "C" {
#endif
// INIT/DEINIT

// Allocates a new vbuffer. Returns NULL if allocation failed.
vbuffer_t *vbuffer_new(size_t size);
// Allocates a new vbuffer and copies SIZE bytes from DATA into it.
vbuffer_t *vbuffer_from(void * data, size_t size);
// Frees a vbuffer.
void vbuffer_free(vbuffer_t *vb);

// PROPERTY ACCESSORS

// Returns the size of the vbuffer.
size_t vbuffer_size(vbuffer_t *vb);
// Returns the capacity of the vbuffer.
size_t vbuffer_capacity(vbuffer_t *vb);
// Returns the a copy of the data of the vbuffer. The caller is responsible for freeing the memory.
void *vbuffer_data(vbuffer_t *vb);
// Returns SIZE bytes of the data of the vbuffer, offset by OFFSET. The caller is responsible for freeing the memory.
void *vbuffer_ndata(vbuffer_t *vb, size_t offset, size_t size);

// METHODS

// Resizes the vbuffer to SIZE bytes. Existing data is preserved. If SIZE is less than the current size, the vbuffer is truncated.
void vbuffer_resize(vbuffer_t *vb, size_t size);
// Clears the vbuffer. The size is set to 0.
void vbuffer_clear(vbuffer_t *vb);
// Duplicates the vbuffer. The caller is responsible for freeing the new vbuffer.
vbuffer_t *vbuffer_duplicate(vbuffer_t *vb);


// DATA ACCESSORS

// Gets SIZE bytes from the vbuffer into DATA, starting at POSITION. 
void vbuffer_get_array(vbuffer_t *vb, size_t position, void *data, size_t size);
// Puts SIZE bytes from DATA into the vbuffer, starting at POSITION.
void vbuffer_put_array(vbuffer_t *vb, size_t position, void *data, size_t size);
// Gets an int8 from the vbuffer at POSITION.
int8_t vbuffer_get_int8(vbuffer_t *vb, size_t position);
// Puts an int8 into the vbuffer at POSITION.
void vbuffer_put_int8(vbuffer_t *vb, size_t position, int8_t value);
// Gets a uint8 from the vbuffer at POSITION.
uint8_t vbuffer_get_uint8(vbuffer_t *vb, size_t position);
// Puts a uint8 into the vbuffer at POSITION.
void vbuffer_put_uint8(vbuffer_t *vb, size_t position, uint8_t value);
// Gets an int16 from the vbuffer at POSITION.
int16_t vbuffer_get_int16(vbuffer_t *vb, size_t position);
// Puts an int16 into the vbuffer at POSITION.
void vbuffer_put_int16(vbuffer_t *vb, size_t position, int16_t value);
// Gets a uint16 from the vbuffer at POSITION.
uint16_t vbuffer_get_uint16(vbuffer_t *vb, size_t position);
// Puts a uint16 into the vbuffer at POSITION.
void vbuffer_put_uint16(vbuffer_t *vb, size_t position, uint16_t value);
// Gets an int32 from the vbuffer at POSITION.
int32_t vbuffer_get_int32(vbuffer_t *vb, size_t position);
// Puts an int32 into the vbuffer at POSITION.
void vbuffer_put_int32(vbuffer_t *vb, size_t position, int32_t value);
// Gets a uint32 from the vbuffer at POSITION.
uint32_t vbuffer_get_uint32(vbuffer_t *vb, size_t position);
// Puts a uint32 into the vbuffer at POSITION.
void vbuffer_put_uint32(vbuffer_t *vb, size_t position, uint32_t value);
// Gets an int64 from the vbuffer at POSITION.
int64_t vbuffer_get_int64(vbuffer_t *vb, size_t position);
// Puts an int64 into the vbuffer at POSITION.
void vbuffer_put_int64(vbuffer_t *vb, size_t position, int64_t value);
// Gets a uint64 from the vbuffer at POSITION.
uint64_t vbuffer_get_uint64(vbuffer_t *vb, size_t position);
// Puts a uint64 into the vbuffer at POSITION.
void vbuffer_put_uint64(vbuffer_t *vb, size_t position, uint64_t value);
// Gets a float from the vbuffer at POSITION.
float vbuffer_get_float(vbuffer_t *vb, size_t position);
// Puts a float into the vbuffer at POSITION.
void vbuffer_put_float(vbuffer_t *vb, size_t position, float value);
// Gets a double from the vbuffer at POSITION.
double vbuffer_get_double(vbuffer_t *vb, size_t position);
// Puts a double into the vbuffer at POSITION.
void vbuffer_put_double(vbuffer_t *vb, size_t position, double value);
// Gets a long double from the vbuffer at POSITION.
long double vbuffer_get_long_double(vbuffer_t *vb, size_t position);
// Puts a long double into the vbuffer at POSITION.
void vbuffer_put_long_double(vbuffer_t *vb, size_t position, long double value);

// IO FUNCTIONS
#ifdef _STDIO_H
// Writes the vbuffer to a file.
void vbuffer_fwrite(vbuffer_t *vb, FILE *file);
// Reads into the vbuffer from a file.
void vbuffer_fread(vbuffer_t *vb, FILE *file);
#endif
#ifdef _UNISTD_H
// Writes the vbuffer to a file descriptor.
void vbuffer_write(vbuffer_t *vb, int fd);
// Reads into the vbuffer from a file descriptor.
void vbuffer_read(vbuffer_t *vb, int fd);

#ifdef __cplusplus
}
#endif

#endif
#endif