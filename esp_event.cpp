#include "esp_event.h"

esp_err_t esp_event_loop_create_default() {
  return ESP_OK;
}

esp_err_t esp_event_handler_register(esp_event_base_t event_base,
                                     int32_t event_id,
                                     esp_event_handler_t event_handler,
                                     void* event_handler_arg) {
  (void)event_base;
  (void)event_id;
  (void)event_handler;
  (void)event_handler_arg;

  return ESP_OK;
}
