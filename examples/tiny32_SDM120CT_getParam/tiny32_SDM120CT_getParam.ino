/***********************************************************************
 * Project      :     SDM120CT_getParam
 * Description  :     Get each parameter from SDM120CT Modbus RTU power meter module
 * Hardware     :     tiny32         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     01/08/2023
 * Revision     :     1.0
 * Rev1.0       :     Original
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-308-3299
 ***********************************************************************/
#include <Arduino.h>
#include <tiny32_v3.h> //for tiny32 v3


tiny32_v3 mcu; //define object

uint8_t id = 1; //Address if SDM120CT, You can change here if it differance

float volt, amp, power, freq, pf, ap_power, reac_power, energy;


void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** SDM120CT_getParam ****\r\n");
  mcu.SDM120CT_begin(RXD2,TXD2);
  mcu.Relay(1);
  vTaskDelay(3000);
  mcu.buzzer_beep(2); //buzzer 2 beeps
  mcu.library_version();
}

void loop()
{

    /* Read voltage parameter */
    volt = mcu.SDM120CT_Volt(id);
    if(volt != -1)
    {
      Serial.printf("Info: volt = %.2fV\r\n",volt);
    }
    else
    {
      Serial.printf("Error: can't read volt!!\r\n");
    }

    /* Read current parameter */
    amp = mcu.SDM120CT_Current(id);
     if(amp != -1)
     {
       Serial.printf("Info: current = %.2fA\r\n",amp);
     }
    else
    {
      Serial.printf("Error: can't read current!!\r\n");
    }


    /* Read power parameter */
    power = mcu.SDM120CT_Power(id);
    if(power != -1)
    {
      Serial.printf("Info: Power = %.1fW\r\n",power);
    }
    else
    {
      Serial.printf("Error: can't read power!!\r\n");
    }

    /* Read energy parameter */
    energy = mcu.SDM120CT_Total_Energy(id);
    if(energy != -1)
    {
      Serial.printf("Info: energy = %.1fkWh\r\n",energy);
    }
    else
    {
      Serial.printf("Error: can't read engergy!!\r\n");
    }

    /* Read frequency parameter */
    freq = mcu.SDM120CT_Freq(id);
    if(freq != -1)
    {
      Serial.printf("Info: frequency = %0.1fHz\r\n",freq);
    }
    else
    {
      Serial.printf("Error: can't read frequency!!\r\n");
    }

    /* Read power factor parameter */
    pf = mcu.SDM120CT_POWER_FACTOR(id);
    if(pf != -1)
    {
      Serial.printf("Info: pf = %.2f\r\n",pf);
    }
    else
    {
      Serial.printf("Error: can't read power factor!!\r\n");
    }

    Serial.println("********************************\r\n");
  
    vTaskDelay(5000);

}
