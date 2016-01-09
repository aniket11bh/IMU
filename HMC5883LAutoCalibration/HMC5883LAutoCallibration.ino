#include <Wire.h>
#include "compass.h"
#define compass_address 0x1E 

void setup(){
  Serial.begin(9600);
  Serial.print("Setting up I2C ........\n");
  Wire.begin();
  compass_x_offset = -785.89;
  compass_y_offset = 1243.25;
  compass_z_offset = 751.30;
  compass_x_gainError = 8.39;
  compass_y_gainError = 8.67;
  compass_z_gainError = 8.17;

  compass_init(5);
//  compass_debug = 1;
  compass_offset_calibration(0);

}

void loop(){
  
  compass_scalled_reading();

#if 0
  Serial.print("x = ");Serial.print(compass_x_scalled); Serial.print('\t');
  Serial.print("y = ");Serial.print(compass_y_scalled); Serial.print('\t');
  Serial.print("z = ");Serial.print(compass_z_scalled); Serial.print('\t');
#endif
  

  compass_heading();
  Serial.print ("Heading angle = ");
  Serial.print (bearing);
  Serial.println(" Degree");
  delay(100);
  
  
}











