#include "Servo_config.c"

void app_main(void) {
    Servo_Control();

    while (1) {
        // Sweep from 0° → 130°
        for (int theta = 0; theta <= 130; theta += 10) {
            int inverted_theta = 180 - theta;   // invert angle mapping
            printf("Servo angle: %d (mapped to %d)\n", theta, inverted_theta);

            int duty = angle_to_DutyCycle(inverted_theta);

            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, duty);
            ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);

            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1, duty);
            ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1);

            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2, duty);
            ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2);

            vTaskDelay(pdMS_TO_TICKS(500));
        }

        //Sweep back
        for (int theta = 130; theta >= 0; theta -= 10) {
            int inverted_theta = 180 - theta;   // invert angle mapping
            printf("Servo angle: %d (mapped to %d)\n", theta, inverted_theta);

            int duty = angle_to_DutyCycle(inverted_theta);

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
