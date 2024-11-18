#pragma once

// Standard library
#include <cstdint>

// esp-idf
#include "esp_err.h"

typedef enum {
    HTTP_EVENT_ERROR = 0,
    HTTP_EVENT_ON_CONNECTED,
    HTTP_EVENT_HEADERS_SENT,
    HTTP_EVENT_HEADER_SENT = HTTP_EVENT_HEADERS_SENT,
    HTTP_EVENT_ON_HEADER,
    HTTP_EVENT_ON_DATA,
    HTTP_EVENT_ON_FINISH,
    HTTP_EVENT_DISCONNECTED,
    HTTP_EVENT_REDIRECT,
} esp_http_client_event_id_t;

typedef enum {
    HTTP_METHOD_GET = 0,
    HTTP_METHOD_POST,
    HTTP_METHOD_PUT,
    HTTP_METHOD_PATCH,
    HTTP_METHOD_DELETE,
} esp_http_client_method_t;

typedef struct {
} esp_http_client_handle_t;

typedef struct {
  esp_http_client_event_id_t event_id;
  char *header_key;
  char *header_value;
  esp_http_client_handle_t client;
  void *data;
  int data_len;
} esp_http_client_event_t;

typedef esp_err_t (*http_event_handle_cb)(esp_http_client_event_t *evt);

typedef struct {
    const char *url;
    esp_http_client_method_t method;
    http_event_handle_cb event_handler;
    esp_err_t (*crt_bundle_attach)(void *conf);
} esp_http_client_config_t;

esp_err_t esp_http_client_cleanup(esp_http_client_handle_t client);
esp_err_t esp_http_client_perform(esp_http_client_handle_t client);
esp_err_t esp_http_client_set_header(esp_http_client_handle_t client, const char *key, const char *value);
esp_err_t esp_http_client_set_post_field(esp_http_client_handle_t client, const char *data, int len);
esp_http_client_handle_t esp_http_client_init(const esp_http_client_config_t *config);
int esp_http_client_get_status_code(esp_http_client_handle_t client);
int64_t esp_http_client_get_content_length(esp_http_client_handle_t client);
