static int setpoint = -1;
static bool overriding = false; 

int getArmSetpoint() {
	return setpoint;
}

void setOverriding(bool urMom) {
	overriding = urMom;
}

void setArmSetpoint(int target) {
	setpoint = target;
	if (setpoint > maxArmAngle) {
		setpoint = maxArmAngle;
		return;
	}
	if (setpoint < minArmAngle) {
		setpoint = minArmAngle;
		return;
	}
}

void setArmSpeedBasedOnSetpoint() {
	if (overriding) {
		return;
	}
	if (setpoint == -1) {
		return;
	}
	int measurement = SensorValue[potentiometer];
	int error = getArmSetpoint() - measurement;
	if (abs(error) < maxArmError) {
		motor[armMotor] = armHoldStrength * cosDegrees(SensorValue[potentiometer] / 4095 * 360 - 45);
		// make sure the math done here is correct
		return;
	}
	else {
		motor[armMotor] = error * armkP;
	}
}

void overrideMaxArmHeight() {
	setOverriding(true);
	motor[armMotor] = 127;
}
