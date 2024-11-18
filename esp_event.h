#pragma once

// Standard library
#include <stdint.h>

// esp-idf
#include "esp_err.h"

typedef const char* esp_event_base_t;
typedef void (*esp_event_handler_t)(void* event_handler_arg,
                                    esp_event_base_t event_base,
                                    int32_t event_id,
                                    void* event_data);

esp_err_t esp_event_loop_create_default();
esp_err_t esp_event_handler_register(esp_event_base_t event_base,
                                     int32_t event_id,
                                     esp_event_handler_t event_handler,
                                     void* event_handler_arg);
