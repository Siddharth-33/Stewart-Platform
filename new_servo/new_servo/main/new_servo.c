#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"
#include "esp_log.h"

#define SERVO_GPIO GPIO_NUM_18

// Convert angle (0-180°) to duty cycle (inverted mapping)
int angle_to_DutyCycle(int theta) {
    if (theta < 0) theta = 0;
    if (theta > 180) theta = 180;

    // Invert angle: 0 -> 180, 180 -> 0
    int inverted_theta = 180 - theta;

    float pulse_ms = 0.5 + (inverted_theta / 180.0) * 2.0;   // 0.5ms - 2.5ms
    float duty = (pulse_ms / 20.0) * 1024;                   // 20ms period @ 50Hz
    return (int)duty;
}

void servo_init(void) {
    // Configure LEDC timer
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = LEDC_LOW_SPEED_MODE,
        .timer_num        = LEDC_TIMER_0,
        .duty_resolution  = LEDC_TIMER_10_BIT,
        .freq_hz          = 50, // 50Hz for servo
        .clk_cfg          = LEDC_AUTO_CLK
    };
    ledc_timer_config(&ledc_timer);

    // Configure LEDC channel
    ledc_channel_config_t ledc_channel = {
        .channel    = LEDC_CHANNEL_0,
        .duty       = 0,
        .gpio_num   = SERVO_GPIO,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .hpoint     = 0,
        .timer_sel  = LEDC_TIMER_0
    };
    ledc_channel_config(&ledc_channel);
}

void servo_set_angle(int angle) {
    int duty = angle_to_DutyCycle(angle);
    ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, duty);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
}

// Example FreeRTOS task to sweep servo
void servo_task(void *pvParameter) {
    while (1) {
        for (int angle = 0; angle <= 150; angle += 10) {
            servo_set_angle(angle);
            vTaskDelay(pdMS_TO_TICKS(500));
        }
        for (int angle = 150; angle >= 0; angle -= 10) {
            servo_set_angle(angle);
            vTaskDelay(pdMS_TO_TICKS(500));
        }
    }
}

void app_main(void) {
    servo_init();
    xTaskCreate(servo_task, "servo_task", 2048, NULL, 5, NULL);
}

