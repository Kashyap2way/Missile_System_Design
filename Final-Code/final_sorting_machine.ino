// C++ code
//
#include <Servo.h>
#include <Stepper.h>
const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 7, 8, 9, 10);
int count = 0;

Servo servo_11;

void setup()
{
  servo_11.attach(11, 500, 2500);
  pinMode(13, INPUT);
  pinMode(12, INPUT);
}

void loop()
{
  servo_11.write(0);
  delay(100); // Wait for 100 millisecond(s)

  count = 0;
  delay(10); // Wait for 10 millisecond(s)
  if (digitalRead(13) <= 8) {
    count + 1;
  } else {
    count += 0;
  }

  if (digitalRead(12) >= 4) {
    servo_11.write(75);
    delay(200); // Wait for 200 millisecond(s)
  }
  
    // read the sensor value:
  int sensorReading = analogRead(A0);
  // map it to a range from 0 to 100:
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  // set the motor speed:
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution / 100);
  }
}
