#include <stdio.h>
#include "Servo_Ir_config.c"

void app_main(void)
{
 Servo_IR();
while(1)
{
      int ReadVal= adc1_get_raw(IR_analog);
      printf("IR value : %d\n", ReadVal);

      float thetha= (180.0/1023.0)*ReadVal;
      printf("ANGLE:- %f \n",thetha);
      ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, angle_to_DutyCycle(thetha));
      ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
      vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

