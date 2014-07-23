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
	
	return 0;
}
