/*Turning and moving content*/

int TurnOP=1400;		//Outer Pivot, for turning with one wheel
int leftMotor=3;		//Left motor's position is 3.
int rightMotor=1;		//Right motor's position is 1.
int TurnCP=700;			//Center Pivot, for turning with both wheels
int pastLaptop=2050;	//Distance across the short side of the laptop, courtesy of Truman.
int crossLaptop=3000;	//Distance across the long side of the laptop, courtesy of Truman.

int goForwardPastLaptop(int moveSpeed)
{
	mrp(leftMotor,moveSpeed,pastLaptop);
	mrp(rightMotor,moveSpeed,pastLaptop);
	msleep(5000);
	return 0;
}
int rightTurnCP(int turnSpeed)
{
	//	move_to_position wouldn't work here.	
	mrp(leftMotor,turnSpeed,TurnCP);	//move_relative_position
	mrp(rightMotor,turnSpeed,-TurnCP);
	msleep(3000);
	return 0;
}

int rightTurnOP(int turnSpeed)
{
	mrp(leftMotor,turnSpeed,TurnOP);
	msleep(3000);
	return 0;
}

int leftTurnCP(int turnSpeed)
{
	mrp(leftMotor,turnSpeed,-TurnCP);
	mrp(rightMotor,turnSpeed,TurnCP);
	msleep(3000);
	return 0;
}

int leftTurnOP(int turnSpeed)
{
	mrp(rightMotor,turnSpeed,TurnOP);
	msleep(3000);
	return 0;
}

/*---------------------------*/

int servo1port=2;
int lowerServoPos=1756;
int upperServoPos=1531;
int main()
{
	followLine();
	mrp(1,500,-1400);
	mrp(3,500,-1400);
	msleep(3000);
	
	enable_servos();
	set_servo_position(servo1port,lowerServoPos);
	
	mrp(1,500,-1400);
	mrp(3,500,-1400);
	
	set_servo_position(servo1port,upperServoPos);
	
	rightTurnCP(500);
	rightTurnCP(500);
	goForwardPastLaptop(500);
	goForwardPastLaptop(500);
	
	return 0;
}
