#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "esp_log.h"

#define IR_analog_1 ADC1_CHANNEL_0
#define IR_analog_2 ADC1_CHANNEL_1 
#define IR_analog_3 ADC1_CHANNEL_2 
#define IR_analog_4 ADC1_CHANNEL_3 
#define IR_analog_5 ADC1_CHANNEL_4
#define IR_analog_6 ADC1_CHANNEL_5 
#define IR_analog_7 ADC1_CHANNEL_6 
#define IR_analog_8 ADC1_CHANNEL_7 
#define IR_analog_9 ADC2_CHANNEL_0 

int IR_analog[]={
    IR_analog_1,IR_analog_2,IR_analog_3,IR_analog_4,IR_analog_5,IR_analog_6,IR_analog_7,
    IR_analog_8,IR_analog_9
};
int IR_Read[9] ;

void Config(void){
   adc1_config_width(ADC_WIDTH_BIT_10);  
    adc1_config_channel_atten(IR_analog_1, ADC_ATTEN_DB_11);
    adc1_config_channel_atten(IR_analog_2, ADC_ATTEN_DB_11); 
    adc1_config_channel_atten(IR_analog_3, ADC_ATTEN_DB_11);  
    adc1_config_channel_atten(IR_analog_4, ADC_ATTEN_DB_11); 
    adc1_config_channel_atten(IR_analog_5, ADC_ATTEN_DB_11);
    adc1_config_channel_atten(IR_analog_6, ADC_ATTEN_DB_11); 
    adc1_config_channel_atten(IR_analog_7, ADC_ATTEN_DB_11);  
    adc1_config_channel_atten(IR_analog_8, ADC_ATTEN_DB_11); 
    adc2_config_channel_atten(IR_analog_9, ADC_ATTEN_DB_11); 

    for (int i=0;i<8;i++){
        IR_Read[i]= adc1_get_raw(IR_analog[i]);
    };
      int val ;
      adc2_get_raw(IR_analog_9, ADC_WIDTH_BIT_10, &val);
      IR_Read[8] = val;

}