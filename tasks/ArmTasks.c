task armFollowSetpoint() {
	while (true) {
        setArmSpeedBasedOnSetpoint();
        abortTimeslice();
	}
}

// task moveArmWithController() {
//     startTask(armFollowSetpoint);
// 	while(true) {
// 		if (vexRT[Btn8U] == 1) {
// 			overrideMaxArmHeight();
// 		}
// 		else {
// 			setOverriding(false);
// 			int currentSetpoint = getArmSetpoint();
// 			if(vexRT[Btn5U] == 1) {
// 				setArmSetpoint(currentSetpoint + armControllerSensitivity);
// 			}
// 			else if(vexRT[Btn5D] == 1) {
// 				setArmSetpoint(currentSetpoint - armControllerSensitivity);
// 			}
// 		}
// 		abortTimeslice();
// 	}
// }

task moveArmWithController() {
	while (true) {
		if (vexRT[Btn8U] == 1) {
			motor[armMotor] = 127;
		}
		else if(vexRT[Btn5U] == 1) {
			if (SensorValue[potentiometer] < maxArmAngle) {
				motor[armMotor] = 127;
			}
			else {
				motor[armMotor] = 0;
			}
		}
		else if(vexRT[Btn5D] == 1) {
			motor[armMotor] = -127;
		}
		else {
			if (SensorValue[potentiometer] < maxArmAngle + 20) {
				motor[armMotor] = armHoldStrength * cosDegrees(SensorValue[potentiometer] / 4095 * 360 - 45);
			}
			else {
				motor[armMotor] = 0;
			}
		}
	}
}