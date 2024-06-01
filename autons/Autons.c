task scoreDriveBack() {
	startTask(armFollowSetpoint);
	setArmSetpoint(maxArmAngle);
	driveForwardDistance(5);
	wait1Msec(1000);
	setArmSetpoint(200);
	wait1Msec(1750);
    driveBackwardsDistance(1.5);
    while(true) {
        abortTimeslice();
    }
}

// turns right
task scoreThenGoToNextPieceRed() {
	startTask(armFollowSetpoint);
	setArmSetpoint(maxArmAngle);
	driveForwardDistance(6);
	wait1Msec(1000);
	setArmSetpoint(200);
	wait1Msec(1500);
    driveBackwardsDistance(1);
	turnDegreesRight(90);
	driveForwardDistance(3);
    while(true) {
        abortTimeslice();
    }
}