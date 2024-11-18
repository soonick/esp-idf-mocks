#include "FreeRTOS.h"

BaseType_t xTaskCreate(TaskFunction_t pxTaskCode,
                       const char* const pcName,
                       const configSTACK_DEPTH_TYPE uxStackDepth,
                       void* const pvParameters,
                       UBaseType_t uxPriority,
                       TaskHandle_t* const pxCreatedTask) {
  (void)pxTaskCode;
  (void)pcName;
  (void)uxStackDepth;
  (void)pvParameters;
  (void)uxPriority;
  (void)pxCreatedTask;

  return 1;
}

BaseType_t xQueueGenericSend(QueueHandle_t xQueue,
                             const void* const pvItemToQueue,
                             TickType_t xTicksToWait,
                             const BaseType_t xCopyPosition) {
  (void)xQueue;
  (void)pvItemToQueue;
  (void)xTicksToWait;
  (void)xCopyPosition;
  return 0;
}

QueueHandle_t xQueueGenericCreate(const UBaseType_t uxQueueLength,
                                  const UBaseType_t uxItemSize,
                                  const uint8_t ucQueueType) {
  (void)uxQueueLength;
  (void)uxItemSize;
  (void)ucQueueType;
  return {};
}

BaseType_t xQueueSemaphoreTake(QueueHandle_t xQueue, TickType_t xTicksToWait) {
  (void)xQueue;
  (void)xTicksToWait;
  return 0;
}
