#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"
#include "esp_err.h"
#include <math.h>

#define SERVO1_GPIO 18
#define SERVO2_GPIO 4
#define SERVO3_GPIO 19

<<<<<<< HEAD:platform_circle/Platform_circle/main/Kushaan.c
#define SERVO_MIN_PULSEWIDTH 500  // microseconds
#define SERVO_MAX_PULSEWIDTH 2500 // microseconds
#define SERVO_MAX_DEGREE 130

// Function to convert degree to duty cycle
=======
#define SERVO_MIN_PULSEWIDTH 500   //ms
#define SERVO_MAX_PULSEWIDTH 2500  /ms
#define SERVO_MAX_DEGREE 180

#define SERVO_SAFE_MIN 0
#define SERVO_SAFE_MAX 130   //limit


>>>>>>> 7d17a550fc9d50fb674688439a8c888e0049b5b0:platform_circle/Platform_circle/main/circle_movement.c
uint32_t servo_per_degree_init(uint32_t degree_of_rotation)
{
    uint32_t cal_pulsewidth = SERVO_MIN_PULSEWIDTH +
                              ((SERVO_MAX_PULSEWIDTH - SERVO_MIN_PULSEWIDTH) * degree_of_rotation) / SERVO_MAX_DEGREE;
    return cal_pulsewidth;
}

<<<<<<< HEAD:platform_circle/Platform_circle/main/Kushaan.c
=======

uint32_t clamp_angle(int angle)
{
    if (angle < SERVO_SAFE_MIN) return SERVO_SAFE_MIN;
    if (angle > SERVO_SAFE_MAX) return SERVO_SAFE_MAX;
    return angle;
}

>>>>>>> 7d17a550fc9d50fb674688439a8c888e0049b5b0:platform_circle/Platform_circle/main/circle_movement.c
void app_main(void)
{
    // Timer config
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = LEDC_HIGH_SPEED_MODE,
        .timer_num        = LEDC_TIMER_0,
        .duty_resolution  = LEDC_TIMER_16_BIT,
        .freq_hz          = 50,  // 50Hz for servos
        .clk_cfg          = LEDC_AUTO_CLK
    };
    ledc_timer_config(&ledc_timer);

    // Channel config for 3 servos
    ledc_channel_config_t ledc_channel[3] = {
        {
            .gpio_num   = SERVO1_GPIO,
            .speed_mode = LEDC_HIGH_SPEED_MODE,
            .channel    = LEDC_CHANNEL_0,
            .timer_sel  = LEDC_TIMER_0,
            .duty       = 0,
            .hpoint     = 0
        },
        {
            .gpio_num   = SERVO2_GPIO,
            .speed_mode = LEDC_HIGH_SPEED_MODE,
            .channel    = LEDC_CHANNEL_1,
            .timer_sel  = LEDC_TIMER_0,
            .duty       = 0,
            .hpoint     = 0
        },
        {
            .gpio_num   = SERVO3_GPIO,
            .speed_mode = LEDC_HIGH_SPEED_MODE,
            .channel    = LEDC_CHANNEL_2,
            .timer_sel  = LEDC_TIMER_0,
            .duty       = 0,
            .hpoint     = 0
        }
    };

    for (int ch = 0; ch < 3; ch++) {
        ledc_channel_config(&ledc_channel[ch]);
    }

    float t = 0.0;

    while (1) {
        // Generate sinusoidal angles for circular motion
        float angle1 = 150 + 40 * sin(t);                // Base angle 90°, amplitude 20°
        float angle2 = 150 + 40 * sin(t + 2 * M_PI / 3); // 120° shifted
        float angle3 = 150 + 40 * sin(t + 4 * M_PI / 3); // 240° shifted

        uint32_t duty1 = (servo_per_degree_init((uint32_t)angle1) * (1 << 16)) / 20000;
        uint32_t duty2 = (servo_per_degree_init((uint32_t)angle2) * (1 << 16)) / 20000;
        uint32_t duty3 = (servo_per_degree_init((uint32_t)angle3) * (1 << 16)) / 20000;

        ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, duty1);
        ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0);

        ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_1, duty2);
        ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_1);

        ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_2, duty3);
        ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_2);

        t += 0.1;  // speed of rotation
        if (t > 2 * M_PI) t = 0;

        vTaskDelay(pdMS_TO_TICKS(20)); // refresh every 20ms
    }
}