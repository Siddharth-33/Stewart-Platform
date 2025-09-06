#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "esp_log.h"

#define IR_analog_1 ADC1_CHANNEL_4
#define IR_analog_2 ADC1_CHANNEL_5 
#define IR_analog_3 ADC1_CHANNEL_6 
#define IR_analog_4 ADC1_CHANNEL_7 
#define LED_GPIO GPIO_NUM_2

void app_main(void)
{
    adc1_config_width(ADC_WIDTH_BIT_10);  
    adc1_config_channel_atten(IR_analog_1, ADC_ATTEN_DB_11);
    adc1_config_channel_atten(IR_analog_2, ADC_ATTEN_DB_11); 
    adc1_config_channel_atten(IR_analog_3, ADC_ATTEN_DB_11);  
    adc1_config_channel_atten(IR_analog_4, ADC_ATTEN_DB_11); 
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    while (1)
    {
        int Read_1= adc1_get_raw(IR_analog_1);
        printf("Shreya 1st : %d" " ", Read_1);
        if (Read_1 > 696)  
        {
            gpio_set_level(LED_GPIO, 1); 
        }
        else
        {
            gpio_set_level(LED_GPIO, 0); 
        }

        int Read_2= adc1_get_raw(IR_analog_2);
        printf("Shreya 2nd : %d" " ", Read_2);
        if (Read_2 > 696)  
        {
            gpio_set_level(LED_GPIO, 1); 
        }
        else
        {
            gpio_set_level(LED_GPIO, 0); 
        }

        int Read_3= adc1_get_raw(IR_analog_3);
        printf("Shreya 3rd : %d" " ", Read_3);
        if (Read_3 > 696)  
        {
            gpio_set_level(LED_GPIO, 1); 
        }
        else
        {
            gpio_set_level(LED_GPIO, 0); 
        }

        int Read_4= adc1_get_raw(IR_analog_4);
        printf("Shreya 4th : %d\n" " ", Read_4);
        if (Read_4 > 696)  
        {
            gpio_set_level(LED_GPIO, 1); 
        }
        else
        {
            gpio_set_level(LED_GPIO, 0); 
        }
        vTaskDelay(pdMS_TO_TICKS(500)); 
    }
}