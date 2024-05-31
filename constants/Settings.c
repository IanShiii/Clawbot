// drivetrain
bool squareInputs = true;
int drivetrainWidth = 20; // find the real value for this, in inches
int driveDeadband = 5;
int feetToEncoderUnits = 344;
int inchesToEncoderUnits = 28.7;

// arm
int maxArmAngle = 850;
int minArmAngle = 10;
int armHoldStrength = 18;
int maxArmError = 40;
float armkP = .45;