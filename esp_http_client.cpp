#include "esp_http_client.h"

esp_err_t esp_http_client_cleanup(esp_http_client_handle_t client) {
  (void)client;
  return ESP_OK;
}

esp_err_t esp_http_client_perform(esp_http_client_handle_t client) {
  (void)client;
  return ESP_OK;
}

esp_err_t esp_http_client_set_header(esp_http_client_handle_t client,
                                     const char* key,
                                     const char* value) {
  (void)client;
  (void)key;
  (void)value;
  return ESP_OK;
}

esp_err_t esp_http_client_set_post_field(esp_http_client_handle_t client,
                                         const char* data,
                                         int len) {
  (void)client;
  (void)data;
  (void)len;
  return ESP_OK;
}

esp_http_client_handle_t esp_http_client_init(
    const esp_http_client_config_t* config) {
  (void)config;
  return {};
}

int esp_http_client_get_status_code(esp_http_client_handle_t client) {
  (void)client;
  return 200;
}

int64_t esp_http_client_get_content_length(esp_http_client_handle_t client) {
  (void)client;
  return 0;
}
