void followLeader()
{
	
}

int main()
{
	while(analog(5)==1)
	{
		
		while(digital(10)==1)
		{
			enable_servo(2);
			enable_servo(0);
			set_servo_position(2,1777);
			set_servo_position(0,____);
		}
		followLeader();
	}
}