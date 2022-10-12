/***********************************************************************
 * Project      :     tiny32_SDM120CT_AP_Power
 * Description  :     get Apparent power from EASTRON / model : SDM120CT 
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

float ap_power;
uint8_t id = 1; // Modbus Address of EASTRON / model : SDM120CT

void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** tiny32_SDM120CT_AP_Power ****\r\n");
  mcu.library_version();
  mcu.tiny32_SDM120CT_begin(RXD2, TXD2);
  mcu.buzzer_beep(2); // buzzer 2 beeps
}

void loop()
{

  ap_power = mcu.tiny32_SDM120CT_AP_Power(id);
  if (ap_power != -1)
  {
    Serial.printf("Apparent power = %.2f VA\r\n", ap_power);
  }
  else
  {
    Serial.println("Error: can't get value");
  }
  vTaskDelay(1000);
}