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
	clearTimer(T1);
	int encoderDistanceToTravel = feet * feetToEncoderUnits;
	while (SensorValue[leftEncoder] < encoderDistanceToTravel && SensorValue[rightEncoder] < encoderDistanceToTravel) {
		if (SensorValue[leftEncoder] - SensorValue[rightEncoder] > 100) {
			drive(63, 80);
		}
		else if (SensorValue[rightEncoder] - SensorValue[leftEncoder] > 100) {
			drive(80, 63);
		}
		else {
			drive(63, 63);
		}

		// saftey for if wheel gets stuck or something
		if (time1[T1] > 9000) {
			break;
		}
	}
	drive(0,0);
}

void driveBackwardsDistance(int feet) {
	zeroDriveEncoders();
	clearTimer(T1);
	int encoderDistanceToTravel = feet * feetToEncoderUnits;
	while (SensorValue[leftEncoder] > -encoderDistanceToTravel && SensorValue[rightEncoder] > -encoderDistanceToTravel) {
		if (SensorValue[leftEncoder] - SensorValue[rightEncoder] < -100) {
			drive(-63, -80);
		}
		else if (SensorValue[rightEncoder] - SensorValue[leftEncoder] < -100) {
			drive(-80, -63);
		}
		else {
			drive(-63, -63);
		}
		

		// saftey for if wheel gets stuck or something
		if (time1[T1] > 9000) {
			break;
		}
	}
	drive(0,0);
}

void turnDegreesRight(int degrees) {
	zeroDriveEncoders();
	clearTimer(T1);
	float circumference = drivetrainWidth * 3.1415;
	int encoderDistanceToTravel = inchesToEncoderUnits * circumference * degrees / 360;
	while (SensorValue[leftEncoder] < encoderDistanceToTravel && SensorValue[rightEncoder] > -encoderDistanceToTravel) {
		drive(80, -80);

		// saftey for if wheel gets stuck or something
		if (time1[T1] > (float)degrees / 360 * 4000) {
			break;
		}
	}
	drive(0,0);
}

void turnDegreesLeft(int degrees) {
	zeroDriveEncoders();
	clearTimer(T1);
	float circumference = drivetrainWidth * 3.1415;
	int encoderDistanceToTravel = inchesToEncoderUnits * circumference * degrees / 360;
	while (SensorValue[leftEncoder] > -encoderDistanceToTravel && SensorValue[rightEncoder] < encoderDistanceToTravel) {
		drive(-80, 80);

		// saftey for if wheel gets stuck or something
		if (time1[T1] > (float)degrees / 360 * 4000) {
			break;
		}
	}
	drive(0,0);
}
