/***********************************************************************
 * Project      :     tiny32_SDM120CT_Freq
 * Description  :     get Frequency from EASTRON / model : SDM120CT 
 * Hardware     :     tiny32
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     11/10/2022
 * Revision     :     1.0
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 62-308-3299
 ***********************************************************************/
#include <Arduino.h>
#include <tiny32_v3.h>

tiny32_v3 mcu; // define object

float freq;
uint8_t id = 1; // Modbus Address of EASTRON / model : SDM120CT

void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** tiny32_SDM120CT_Freq ****\r\n");
  mcu.library_version();
  mcu.tiny32_SDM120CT_begin(RXD2, TXD2);
  mcu.buzzer_beep(2); // buzzer 2 beeps
}

void loop()
{

  freq = mcu.tiny32_SDM120CT_Freq(id);
  if (freq != -1)
  {
    Serial.printf("Frequency = %.4f Hz\r\n", freq);
  }
  else
  {
    Serial.println("Error: can't get value");
  }
  vTaskDelay(1000);
}