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

int y1=300; //lowest color of white tape

void followLine()//making minor code for following the line
{
	while (digital(10)==0)
	{
		while (analog(4)<y1)
		{
			mrp(1,500,2000);
			mrp(3,500,2000);
		}
		if (analog(4)>y1)//y1>y2
		{
			mrp(1,300,n);//turn around, make SMALL TURNS, outer pivot
			int countTime=0;
			while (countTime<1000 && analog(4)>y1)
			{
				countTime=countTime+1;
			}
			
			if (countTime>=1000)
			{
			}
			
			else
			{
				while (analog(4)>y1)
				{	
					mrp(1,300,-n);
					mrp(3,300,n);
				}
			}
		}	//no "else", because that could give a false positive more easily
		ao();
	}
}


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
