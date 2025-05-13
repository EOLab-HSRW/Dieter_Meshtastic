#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME680.h>
#include <Arduino.h> // required Serial

#define SEALEVELPRESSURE_HPA (1010.0)

Adafruit_BME680 bme;



bool bme680_init() {
  Wire.begin();
  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME680 sensor, check wiring!");
    return false;
  }
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150);

  return true;
}


// Buffer
String message = "";

void setup() {
  // UART Connection to RAK 4631
  Serial.begin(115200);
  Serial1.begin(9600);
}

void loop() {

    // if available then read values from the 1906 sensor , if not then send test values
    /*
    if (!bme.performReading()) {
    Serial.println("Failed to perform reading :(");
    return; 
    }
    else{
      message = String(bme.temperature)+","+String(bme.pressure)+","+String(bme.humidity)+","+String(bme.gas_resistance)+","; 
      Serial.println(message);
      message= "";
      delay(5000);

    }
    */
    Serial1.println("28.66°C, 3556.66, 30.01%, 15200.44");
    delay(5000);
    

}
