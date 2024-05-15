// drivetrain
bool squareInputs = true;
int drivetrainWidth = 20; // find the real value for this, in inches
int driveDeadband = 5;
int feetToEncoderUnits = 344;
int inchesToEncoderUnits = 28.7
int lineFollowerThreshhold = 300; // line follower detects values under this (brighter light means lower value)

// arm
float armControllerSensitivity = 0.5; // higher values means setpoint will change faster
int maxArmAngle = 1200;
int minArmAngle = 10;
int armHoldStrength = 15;
int maxArmError = 40;
float armkP = .45;

// claw