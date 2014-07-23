int servo1port=2;
int lowerServoPos=1756
int upperServoPos=1531
int main()
{
	followLine();
	enable_servos();
	set_servo_position(servo1port,lowerServoPos);
	
	return 0;
}
