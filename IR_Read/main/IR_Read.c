#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define IR_SENSOR_GPIO GPIO_NUM_4


void app_main(void)
{
    gpio_set_direction(IR_SENSOR_GPIO, GPIO_MODE_INPUT);
    

    while (1)
    {
        int value = gpio_get_level(IR_SENSOR_GPIO);
        printf("VAL:- %d \n",value);
        vTaskDelay(pdMS_TO_TICKS(100));
    
    };
}