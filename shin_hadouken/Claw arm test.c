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
