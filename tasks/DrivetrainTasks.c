task driveWithController() {
	while (true) {
		if (squareInputs) {
			int leftStick = deadband(squareInput(vexRT[Ch3]));
			int rightStick = deadband(squareInput(vexRT[Ch1]));
			drive((leftStick + rightStick), (leftStick - rightStick));
		}
		else {
			int leftStick = deadband(vexRT[Ch3]);
			int rightStick = deadband(vexRT[Ch1]);
			drive((leftStick + rightStick), (leftStick - rightStick));
		}
		abortTimeslice();
	}
}