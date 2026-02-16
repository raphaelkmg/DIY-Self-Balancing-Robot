/*
  DIY Self‑Balancing Robot Firmware

  This sketch provides a simple framework for balancing a two‑wheel robot using
  an MPU‑6050 IMU and two DC motors driven by an L298N module.  It reads the
  pitch angle from the IMU, computes a PID correction and drives the motors
  accordingly.  Tune the Kp, Ki and Kd values for best performance.
*/

#include <Wire.h>
#include <MPU6050.h>

// Instantiate the IMU
MPU6050 imu;

// Motor control pins
const int motorLeftForward  = 5;
const int motorLeftBackward = 6;
const int motorRightForward = 9;
const int motorRightBackward = 10;

// PID parameters (tune for your hardware)
float Kp = 15.0;
float Ki = 0.0;
float Kd = 0.5;

float targetAngle = 0.0;
float lastError   = 0.0;
float integral    = 0.0;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  imu.initialize();

  // Configure motor pins
  pinMode(motorLeftForward,  OUTPUT);
  pinMode(motorLeftBackward, OUTPUT);
  pinMode(motorRightForward,  OUTPUT);
  pinMode(motorRightBackward, OUTPUT);
}

// Read the pitch angle from the IMU (simplified)
float readAngle() {
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  imu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  // Simple angle estimate from accelerometer (radians)
  float angle = atan2(ay, az) * 57.2958; // convert to degrees
  return angle;
}

// Drive motors with PWM value (positive = forward, negative = backward)
void driveMotors(float pwm) {
  int power = constrain((int)pwm, -255, 255);
  if (power > 0) {
    analogWrite(motorLeftForward,  power);
    analogWrite(motorLeftBackward, 0);
    analogWrite(motorRightForward, power);
    analogWrite(motorRightBackward,0);
  } else {
    power = -power;
    analogWrite(motorLeftForward,  0);
    analogWrite(motorLeftBackward, power);
    analogWrite(motorRightForward, 0);
    analogWrite(motorRightBackward,power);
  }
}

void loop() {
  float angle = readAngle();
  float error = targetAngle - angle;
  integral += error;
  float derivative = error - lastError;
  float output = Kp * error + Ki * integral + Kd * derivative;
  driveMotors(output);
  lastError = error;
  delay(10);
}
