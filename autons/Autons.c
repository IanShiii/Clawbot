task ScoreDriveBack() {
	startTask(armFollowSetpoint);
	setArmSetpoint(maxArmAngle);
	driveForwardDistance(4.95);
	wait1Msec(1000);
	setArmSetpoint(200);
	wait1Msec(1000);
    driveBackwardsDistance(3);
    while(true) {
        abortTimeslice();
    }
}