#include "Servo_Config.c"

void app_main(void)
{ Servo();
while(1){
    for(int thetha= 50; thetha<=180;thetha +=10){
        printf("Servo ka angle:- %d \n", thetha);
        ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, angle_to_DutyCycle(thetha));
        ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    for(int thetha= 170; thetha >=50;thetha -=10){
        printf("Servo ka angle:- %d \n", thetha);
        ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, angle_to_DutyCycle(thetha));
        ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
}
