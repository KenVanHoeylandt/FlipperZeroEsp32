#include <furi_hal_random.h>
#include <furi.h>

#define TAG "FuriHalRandom"

static uint32_t furi_hal_random_read_rng() {
    return rand();
}

void furi_hal_random_init() {
}

uint32_t furi_hal_random_get() {
    return rand();
}

void furi_hal_random_fill_buf(uint8_t* buf, uint32_t len) {
    for(uint32_t i = 0; i < len; i += 4) {
        const uint32_t random_val = furi_hal_random_read_rng();
        uint8_t len_cur = ((i + 4) < len) ? (4) : (len - i);
        memcpy(&buf[i], &random_val, len_cur);
    }
}

void srand(unsigned seed) {
    UNUSED(seed);
}

int rand() {
    return (furi_hal_random_get() & RAND_MAX);
}

long random() {
    return (furi_hal_random_get() & RAND_MAX);
}
