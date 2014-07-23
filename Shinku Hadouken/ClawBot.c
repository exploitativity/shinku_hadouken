/*Turning and moving content*/
int n=600;
int reflectValue=400; //highest color of white tape
int countTime=0;

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

void followLine()//making minor code for following the line
{
	printf("1. Checking for touch.\n");
	while (digital(10)==0)
	{
		printf("2. No touch. Checking reflect.\n");
		while (analog(4)<=reflectValue)
		{
			printf("3. Reflect successful. Moving.\n");
			motor(1,500);
			motor(3,500);
			msleep(500);
		}
		if (analog(4)>reflectValue)
		{
			printf("4. Reflect unsuccessful. Turning.\n");
			motor(1,100);//turn around, make SMALL TURNS, outer pivot
			countTime=0;									//countTime resets here.
			while (countTime<500 && analog(4)>=reflectValue)	//countTime variable checks constantly and acts as a delay.
			{													//if it either reaches 1000 or detects a line,
				countTime=countTime+1;							//it moves on and turns.
				msleep(2);
			}
			if (countTime>=500)
			{
				printf("5. Count time exceeded 1000. Turning.\n");
				while (analog(4)>=reflectValue)
				{	
					motor(3,100);
					msleep(1000);
					ao();
				}
			}
			
			else
			{
				printf("6. Reached end of if.\n");
				
			}
		}	//no "else", because that could give a false positive more easily
		printf("7.End of while loop. Deactivating motors...\n");
		ao();
	}
	ao();
}


int servo1port=2;
int lowerServoPos=1756;
int upperServoPos=1531;
int main()
{
	followLine();
	
	set_servo_position(servo1port,upperServoPos);
	
	rightTurnCP(500);
	rightTurnCP(500);
	followLine();
	
	return 0;
}
