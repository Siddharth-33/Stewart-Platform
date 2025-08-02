#include "Servo_config.c"

void app_main(void) {
    Servo_Control();

    while (1) {
        for (int theta = 0; theta <= 180; theta += 10) {
            printf("Servo angle: %d\n", theta);
            int duty = angle_to_DutyCycle(theta);

            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, duty);
            ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);

            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1, duty);
            ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1);

            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2, duty);
            ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2);

            vTaskDelay(pdMS_TO_TICKS(500));
        }

        for (int theta = 180; theta >= 0; theta -= 10) {
            printf("Servo angle: %d\n", theta);
            int duty = angle_to_DutyCycle(theta);

            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, duty);
            ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);

            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1, duty);
            ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1);

            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2, duty);
            ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2);

            vTaskDelay(pdMS_TO_TICKS(500));
        }
    }
}