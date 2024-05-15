task moveClawWithController() {
	while (true) {
		if(vexRT[Btn6U] == 1) {
			motor[clawMotor] = -127;
		}
		else if (vexRT[Btn6D] == 1) {
			motor[clawMotor] = 127;
		}
		else {
			motor[clawMotor] = 0;
		}
		abortTimeslice();
	}
}