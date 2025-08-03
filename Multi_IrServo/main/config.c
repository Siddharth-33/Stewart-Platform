#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "driver/ledc.h"
#include "esp_log.h"


#define IR_analog_1 ADC1_CHANNEL_4
#define IR_analog_2 ADC1_CHANNEL_5 
#define IR_analog_3 ADC1_CHANNEL_6 

#define SERVO_GPIO_1 GPIO_NUM_20
#define SERVO_GPIO_2 GPIO_NUM_21
#define SERVO_GPIO_3 GPIO_NUM_22

int angle_to_DutyCycle(int theta) {
    if (theta > 180) theta = 180;
    float pulse_ms = 0.5 + (theta / 180.0) * 2.0;     
    float duty = (pulse_ms / 20.0) * 1024.0;          
    return (int)duty;
}

void Config(void) {
    adc1_config_width(ADC_WIDTH_BIT_10);  
    adc1_config_channel_atten(IR_analog_1, ADC_ATTEN_DB_11);
    adc1_config_channel_atten(IR_analog_2, ADC_ATTEN_DB_11); 
    adc1_config_channel_atten(IR_analog_3, ADC_ATTEN_DB_11);  

    ledc_timer_config_t ledc_timer = {
        .speed_mode       = LEDC_LOW_SPEED_MODE,
        .timer_num        = LEDC_TIMER_0,
        .duty_resolution  = LEDC_TIMER_10_BIT,
        .freq_hz          = 50, 
        .clk_cfg          = LEDC_AUTO_CLK,
    };
    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t channels[3] = {
        {
            .channel    = LEDC_CHANNEL_0,
            .duty       = 0,
            .gpio_num   = SERVO_GPIO_1,
            .speed_mode = LEDC_LOW_SPEED_MODE,
            .hpoint     = 0,
            .timer_sel  = LEDC_TIMER_0,
        },
        {
            .channel    = LEDC_CHANNEL_1,
            .duty       = 0,
            .gpio_num   = SERVO_GPIO_2,
            .speed_mode = LEDC_LOW_SPEED_MODE,
            .hpoint     = 0,
            .timer_sel  = LEDC_TIMER_0,
        },
        {
            .channel    = LEDC_CHANNEL_2,
            .duty       = 0,
            .gpio_num   = SERVO_GPIO_3,
            .speed_mode = LEDC_LOW_SPEED_MODE,
            .hpoint     = 0,
            .timer_sel  = LEDC_TIMER_0,
        }
    };

    for (int i = 0; i < 3; i++) {
        ledc_channel_config(&channels[i]);
    }
}
