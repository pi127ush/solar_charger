void setup() {
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);// put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

 digitalWrite(2, HIGH);// turn the LED on (HIGH is the voltage level)
  digitalWrite(3, LOW);
  delay(500);              // wait for a second
  digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(3,HIGH);
  delay(500);              // wait for a second
    ////
  int sensor_bat;
  sensor_bat=analogRead(A0);   //to read battery voltage
  float bat_v1=sensor_bat*(5.0/1023.0);
  float final_bat=bat_v1*3.1333;
  /////
  int sensor_sol;
  sensor_sol=analogRead(A1);    //to read solar volatge
  float solar_v1=sensor_sol*(5.0/1023.0);
  float final_sol=solar_v1*4.2;
  ////
  Serial.println("battery voltage is=");
  Serial.println(final_bat);
  delay(500); 
  Serial.println("solar voltage is=");
  Serial.println(final_sol);
  delay(500); 
}
