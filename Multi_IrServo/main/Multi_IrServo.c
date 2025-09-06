#include "config.c"

void app_main(void)
{ Config();
    
    while (1) {
  
     int Read_1= adc1_get_raw(IR_analog_1);
     printf("Shreya 1st : %d" " ", Read_1);

     int Read_2= adc1_get_raw(IR_analog_2);
     printf("Shreya 2nd : %d" " ", Read_2);

      int Read_3= adc1_get_raw(IR_analog_3);
      printf("Shreya 3rd : %d/n " " ", Read_3);

      float thetha_1= (180.0/1023.0)*Read_1;
      printf("ANGLE 1:- %f \n",thetha_1);
      ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, angle_to_DutyCycle(thetha_1));
      ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
     
      float thetha_2= 180.0-((180.0/1023.0)*Read_2);
      printf("ANGLE 2:- %f \n",thetha_2);
      ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1, angle_to_DutyCycle(thetha_2));
      ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1);
     
      float thetha_3= (180.0/1023.0)*Read_3;
     // printf("ANGLE:- %f \n",thetha_3);
      ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2, angle_to_DutyCycle(thetha_3));
      ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2);
      vTaskDelay(pdMS_TO_TICKS(1000));
    }


}
