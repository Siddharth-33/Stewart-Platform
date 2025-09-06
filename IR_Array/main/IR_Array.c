#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "esp_log.h"

#define IR_analog_1 GPIO_NUM_36
#define IR_analog_2 GPIO_NUM_39
#define IR_analog_3 GPIO_NUM_34
#define IR_analog_4 GPIO_NUM_35
#define IR_analog_5 GPIO_NUM_32
#define IR_analog_6 GPIO_NUM_33
#define IR_analog_7 GPIO_NUM_26
#define IR_analog_8 GPIO_NUM_21
#define IR_analog_9 GPIO_NUM_4

int IR_analog[]={
    IR_analog_1,IR_analog_2,IR_analog_3,IR_analog_4,IR_analog_5,IR_analog_6,IR_analog_7,
    IR_analog_8,IR_analog_9
};
int IR_Read[9] ;
void app_main(void)
{
    gpio_set_direction(IR_analog_1, GPIO_MODE_INPUT);
    gpio_set_direction(IR_analog_2, GPIO_MODE_INPUT);
    gpio_set_direction(IR_analog_3, GPIO_MODE_INPUT);
    gpio_set_direction(IR_analog_4, GPIO_MODE_INPUT);
    gpio_set_direction(IR_analog_5, GPIO_MODE_INPUT);
    gpio_set_direction(IR_analog_6, GPIO_MODE_INPUT);
    gpio_set_direction(IR_analog_7, GPIO_MODE_INPUT);
    gpio_set_direction(IR_analog_8, GPIO_MODE_INPUT);
    gpio_set_direction(IR_analog_9, GPIO_MODE_INPUT);

float sensor_co[9][2] = {
  {-1, 1}, {0, 1}, {1, 1},
  {-1, 0}, {0, 0}, {1, 0},
  {-1, -1}, {0, -1}, {1, -1}
};



 while (1){
   for (int i=0;i<9;i++){
        IR_Read[i]=  1 -gpio_get_level(IR_analog[i]);
    };
   float Xval = 0;
   float Yval= 0;
   float SUM_VAL = 0;
    
    for (int i = 0; i < 9; i++) {
        float Value = IR_Read[i]; 
        Xval += sensor_co[i][0] * Value;
        Yval += sensor_co[i][1] * Value;
        SUM_VAL += Value;
    };
        Xval /= SUM_VAL;
        Yval /= SUM_VAL;

        printf(" X Co-ordinate : %f Y Co-ordinate: %f \n",Xval,Yval);
        vTaskDelay(pdMS_TO_TICKS(500));

 };
}
