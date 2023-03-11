#include "storage.h"

#define TAG "STOR"

static FILE *f;

void storage_init(char *_fn) {
  ESP_LOGI(TAG, "Init storage");
  char fn[32] = SD_MOUNT "/" STOR_PREFIX "0000.txt";
  f = NULL;
  if (_fn == NULL) {
    uint16_t i = 0;
    struct stat st;
    while (stat(fn, &st) == 0)
      sprintf(fn, SD_MOUNT "/" STOR_PREFIX "%04d.txt", ++i);
    f = fopen(fn, "a+");
    printf("Open %s %d\n", fn, f == NULL);
  } else {
    f = fopen(fn, "a+");
    printf("Open %s %d\n", _fn, f == NULL);
  }
}

void storage_read(char *ptr, size_t len) {
  if (f == NULL) return;
}

void storage_write(uint8_t *ptr, size_t len) {
  if (f == NULL) return;
  fwrite(ptr, len, 1, f);
}

void storage_deinit() {
  if (f == NULL) return;
  fclose(f);
}
