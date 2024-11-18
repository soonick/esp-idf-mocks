#pragma once

#include <stdint.h>

#define portMAX_DELAY (TickType_t)  0xffff
#define semSEMAPHORE_QUEUE_ITEM_LENGTH      ( ( uint8_t ) 0U )
#define queueQUEUE_TYPE_BINARY_SEMAPHORE      ( ( uint8_t ) 3U )
#define configSTACK_DEPTH_TYPE uint32_t
#define semGIVE_BLOCK_TIME                  ( ( TickType_t ) 0U )
#define queueSEND_TO_BACK                     ( ( BaseType_t ) 0 )
#define xSemaphoreGive( xSemaphore )    xQueueGenericSend( ( QueueHandle_t ) ( xSemaphore ), NULL, semGIVE_BLOCK_TIME, queueSEND_TO_BACK )
#define xSemaphoreCreateBinary()    xQueueGenericCreate( ( UBaseType_t ) 1, semSEMAPHORE_QUEUE_ITEM_LENGTH, queueQUEUE_TYPE_BINARY_SEMAPHORE )
#define xSemaphoreTake( xSemaphore, xBlockTime )    xQueueSemaphoreTake( ( xSemaphore ), ( xBlockTime ) )

typedef uint16_t TickType_t;
struct QueueDefinition;
typedef struct QueueDefinition   * QueueHandle_t;
typedef QueueHandle_t SemaphoreHandle_t;
typedef void* TaskHandle_t;
typedef long BaseType_t;
typedef unsigned int UBaseType_t;
typedef void (*TaskFunction_t)(void*);

BaseType_t xTaskCreate(TaskFunction_t pxTaskCode,
                       const char* const pcName,
                       const configSTACK_DEPTH_TYPE uxStackDepth,
                       void* const pvParameters,
                       UBaseType_t uxPriority,
                       TaskHandle_t* const pxCreatedTask);

BaseType_t xQueueGenericSend(QueueHandle_t xQueue,
                              const void * const pvItemToQueue,
                              TickType_t xTicksToWait,
                              const BaseType_t xCopyPosition);

QueueHandle_t xQueueGenericCreate( const UBaseType_t uxQueueLength,
                                   const UBaseType_t uxItemSize,
                                   const uint8_t ucQueueType );

BaseType_t xQueueSemaphoreTake( QueueHandle_t xQueue,
                                TickType_t xTicksToWait );
