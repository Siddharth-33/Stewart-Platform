#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "esp_log.h"

#define IR_analog ADC1_CHANNEL_6  
#define LED_GPIO GPIO_NUM_2

void app_main(void)
{
    adc1_config_width(ADC_WIDTH_BIT_10);  
    adc1_config_channel_atten(IR_analog, ADC_ATTEN_DB_11); 
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    while (1)
    {
        int ReadVal= adc1_get_raw(IR_analog);
        printf("Shreya: %d\n", ReadVal);
        if (ReadVal > 696)  
        {
            gpio_set_level(LED_GPIO, 1); 
        }
        else
        {
            gpio_set_level(LED_GPIO, 0); 
        }
        vTaskDelay(pdMS_TO_TICKS(200)); 
    }
}