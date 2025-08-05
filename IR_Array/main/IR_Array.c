#include <stdio.h>
#include "ir_config.c"

void app_main(void)
{
 Config();

float sensor_co[9][2] = {
  {-1, 1}, {0, 1}, {1, 1},
  {-1, 0}, {0, 0}, {1, 0},
  {-1, -1}, {0, -1}, {1, -1}
};

 while (1){
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

        printf(" X Co-ordinate :-%f Y Co-ordinate:- %f \n",Xval,Yval);
        vTaskDelay(pdMS_TO_TICKS(500));
 };


}
