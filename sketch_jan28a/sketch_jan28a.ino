#include <U8x8lib.h>

#include <DHT.h>
#include <Grove_Temperature_And_Humidity_Sensor.h>

U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

DHT dht(3, DHT11);

void setup() {
  // put your setup code here, to run once:
u8x8.begin();
u8x8.setFlipMode(1);
u8x8.clear();

dht.begin();

}

void loop() {
double var1 = dht.readTemperature();
double var2 = dht.readHumidity();
//Coversions
double var1F = var1 * 9/5 +32;
double var2F = var2 * 9/5 +32;
  // put your main code here, to run repeatedly:
u8x8.setFont(u8x8_font_chroma48medium8_r);
u8x8.setCursor(0, 0);
//u8x8.print("Hello World!");
u8x8.println("Temp:");
u8x8.println(var1F);
u8x8.println("Humidity:");
u8x8.println(var2F);
}
