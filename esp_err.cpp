#include "esp_err.h"

const char* esp_err_to_name(esp_err_t code) {
  switch (code) {
    case -1:
      return "ESP_FAIL";
    case 0:
      return "ESP_OK";
    case 1:
      return "ESP_ERR";
    default:
      throw("Unknown error code");
  }
}
