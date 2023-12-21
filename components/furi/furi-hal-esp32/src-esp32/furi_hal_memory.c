#include "furi_hal.h"
#include "furi_hal_memory.h"
#include "furi_hal_rtc.h"

#define TAG "FuriHalMemory"

// Tamaño del pool de memoria en bytes
#define FURI_HAL_MEMORY_POOL_SIZE 512

// Pool de memoria
static uint8_t furi_hal_memory_pool[FURI_HAL_MEMORY_POOL_SIZE];

// Puntero actual en el pool de memoria
static uint8_t* furi_hal_memory_ptr = furi_hal_memory_pool;

void furi_hal_memory_init() {
}

void* furi_hal_memory_alloc(size_t size) {
    void* p = NULL;

    if (furi_hal_memory_ptr + size <= furi_hal_memory_pool + FURI_HAL_MEMORY_POOL_SIZE) {
        p = furi_hal_memory_ptr;
        furi_hal_memory_ptr += size;
    }

    return p;
}

size_t furi_hal_memory_get_free() {
    return FURI_HAL_MEMORY_POOL_SIZE - (furi_hal_memory_ptr - furi_hal_memory_pool);
}

size_t furi_hal_memory_max_pool_block() {
    size_t max_block = 0;
    size_t curr_block = 0;
    uint8_t* curr_ptr = furi_hal_memory_ptr;

    while (curr_ptr < furi_hal_memory_pool + FURI_HAL_MEMORY_POOL_SIZE) {
        if (*curr_ptr == 0) {
            curr_block++;
        } else {
            if (curr_block > max_block) {
                max_block = curr_block;
            }
            curr_block = 0;
        }

        curr_ptr++;
    }

    if (curr_block > max_block) {
        max_block = curr_block;
    }

    return max_block;
}