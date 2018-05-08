/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
float heartRate;


void setup() {
  myservo.attach(11);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
pinMode(7,1);
digitalWrite(7,1);
}

void showHeartRate(float heartRate){
  Serial.println(heartRate);
  heartRate *= 0.57;
  int printtaus = heartRate;
    myservo.write(printtaus); 
}

int measureHeartRate(){
  long firstBeat = 0;
  double timeDifference = 0;
firstBeat = peakDetector();
delay(200);
timeDifference = peakDetector() - firstBeat;
heartRate = 60/(timeDifference/1000);
delay(200);
//Serial.println(heartRate);
return heartRate;
}

void loop() {

heartRate = measureHeartRate();
showHeartRate(heartRate);
//Serial.println(analogRead(A0));
//showHeartRate(heartRate);

}

long peakDetector(){
  long amplitude1 = analogRead(A0);
  delay(5);
  long amplitude2 = analogRead(A0);
    while(amplitude1 < 80){
      amplitude1 = analogRead(A0);
      delay(5);
      amplitude2 = analogRead(A0);
     
    }
    while( amplitude1 <= amplitude2 && amplitude1 > 80){
      amplitude1 = analogRead(A0);
      delay(2);
      amplitude2 = analogRead(A0);
    }
    return millis();
}

