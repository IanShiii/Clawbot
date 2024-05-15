int deadband(int value) {
	if (abs(value) < driveDeadband) {
		return 0;
	}
	return value;
}

int squareInput(int input) {
	int x = ((float)input / 127);
	if (x == 0) {
		return 0;
	}
	return abs(pow(x, 3)) / x * 127;
}
