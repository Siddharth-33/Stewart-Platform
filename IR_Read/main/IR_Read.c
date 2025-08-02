#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define IR_SENSOR_GPIO GPIO_NUM_4
#define LED_GPIO GPIO_NUM_2

void app_main(void)
{
    gpio_set_direction(IR_SENSOR_GPIO, GPIO_MODE_INPUT);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    while (1)
    {
        int value = gpio_get_level(IR_SENSOR_GPIO);

        if (value == 0)
        {
            gpio_set_level(LED_GPIO, 1); 
        }
        else
        {
            gpio_set_level(LED_GPIO, 0);
        }

        vTaskDelay(pdMS_TO_TICKS(100)); 
    }
}