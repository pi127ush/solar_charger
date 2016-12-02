/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */


// the setup function runs once when you press reset or power the board
 string d1= "battery";
 string d2= "solar";
 string device = "";
 boolean device_complete=false;
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  device.reserve(10);
}

// the loop function runs over and over again forever
void loop() {
   digitalWrite(2, HIGH);// turn the LED on (HIGH is the voltage level)
  digitalWrite(3, LOW);
  delay(500);              // wait for a second
  digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(3,HIGH);
  delay(500);              // wait for a second

  ////
  int sensor_bat;
  sensor_bat=analogRead(A0);   //to read battery voltage
  int bat_v1=sensor_bat*(5/1023);
  int final_bat=bat_v1*3.1333;
  /////
  int sensor_sol;
  sensor_sol=analogRead(A1);    //to read solar volatge
  int solar_v1=sensor_sol*(5/1023);
  int final_sol=solar_v1*4.2;
  ////
 
  Serial.println("enter the device");
 
 // char device[10]={Serial.read()};
  if (device_complete)
  {
    Serial.println(device);
  
  if(device==d1)
  {
    Serial.println("battery voltage is=");
    Serial.println(final_bat);             ///to print battery volatge
    }
     if(device==d2)
    {
      Serial.println("solar voltage is=");
      Serial.println(final_sol);           ///to print solar voltage
      }
      else{
      Serial.println("wrong device");
      }
    device= "";
    device_complete=false;
  }
} 
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    string inChar;
    inChar= Serial.readString()};
    
    device += inChar;
    if(inChar== '\n'){
      device_complete=true;
    }
    
    
  }
 }
