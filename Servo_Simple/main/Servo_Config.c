#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"
#include "esp_log.h"

#define servo_gpio GPIO_NUM_4

int angle_to_DutyCycle(int thetha){
    if (thetha>180) thetha= 180;
    float pulse = 0.5 +(thetha/180.0)*2.0;
    float duty = (pulse/20.0)*1024;
    return duty;
}

void Servo(void)
{
ledc_timer_config_t ledc_timer = {
    .speed_mode = LEDC_LOW_SPEED_MODE,
    .timer_num= LEDC_TIMER_0,
    .duty_resolution = LEDC_TIMER_10_BIT,
    .freq_hz = 50,
    .clk_cfg = LEDC_AUTO_CLK,
};
ledc_timer_config(&ledc_timer);

ledc_channel_config_t ledc_channel= {
    .channel = LEDC_CHANNEL_0,
    .duty=0,
    .gpio_num = servo_gpio,
    .speed_mode = LEDC_LOW_SPEED_MODE,
    .hpoint = 0,
    .timer_sel = LEDC_TIMER_0,
};
ledc_channel_config(&ledc_channel);
}
