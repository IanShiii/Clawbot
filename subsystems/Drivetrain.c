void zeroDriveEncoders() {
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
}

void drive(int left, int right) {
	motor[leftMotor] = left;
	motor[rightMotor] = right;
}

void driveForwardDistance(int feet) {
	zeroDriveEncoders();
	int encoderDistanceToTravel = feet * feetToEncoderUnits;
	while (SensorValue[leftEncoder] < encoderDistanceToTravel && SensorValue[rightEncoder] < encoderDistanceToTravel) {
		drive(63, 63);
	}
	drive(0,0);
}

void driveBackwardsDistance(int feet) {
	zeroDriveEncoders();
	int encoderDistanceToTravel = feet * feetToEncoderUnits;
	while (SensorValue[leftEncoder] > -encoderDistanceToTravel && SensorValue[rightEncoder] > -encoderDistanceToTravel) {
		drive(-63, -63);
	}
	drive(0,0);
}

void turnDegreesRight(int degrees) {
	zeroDriveEncoders();
	float circumference = drivetrainWidth * 3.1415;
	int encoderDistanceToTravel = inchesToEncoderUnits * circumference * degrees / 360;
	while (SensorValue[leftEncoder] < encoderDistanceToTravel && SensorValue[rightEncoder] > -encoderDistanceToTravel) {
		drive(80, -80);
	}
	drive(0,0);
}

void turnDegreesLeft(int degrees) {
	zeroDriveEncoders();
	float circumference = drivetrainWidth * 3.1415;
	int encoderDistanceToTravel = inchesToEncoderUnits * circumference * degrees / 360;
	while (SensorValue[leftEncoder] > -encoderDistanceToTravel && SensorValue[rightEncoder] < encoderDistanceToTravel) {
		drive(-80, 80);
	}
	drive(0,0);
}
