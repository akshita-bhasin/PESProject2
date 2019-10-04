/*
 * @file pc_print.c
 * @brief running PC_RUN and PC_DEBUG with timing cycle implementations
 *
 *  @author Akshita Bhasin and Madhukar Arora
 *  @date 30/09/2019
 *  @version 1.0
 */

#include "pc_print.h"

uint16_t delay_time_table[] = {3000, 1000, 2000, 600, 1000, 400,\
		                   1000, 200, 500, 100, 500, 100, 500, 100,\
						   1000, 200, 1000, 400, 2000, 600}; // look-up table

void calcTime(uint16_t num); // calculating timestamp and difference in time

void delay(uint16_t num); // to implement the delay from look-up table

// Function Name: blink
// Function arguments: void
// Function return type: void
/* Brief: Not blinking LED but just printing LED outputs D with keeping
 * delay from look-up table and executing the timing cycle 10 times,
 * printing the message with normal printf, current timestamp
 * and printing the difference in time between two events
	*/
void blink(void) {
	uint8_t count = 0, color, lookup=0;

	// for MODULE=PC_DEBUG; to print message for LED color toggle
#ifdef PC_RUN
	// move through the look-up table(timing cycle) 10 times
    while(lookup<10)
    {
    	for(color=0; color<3; color++)//to blink RED ON and OFF 3 times each
    	{
    		if(count==20) //one entire run of the timing cycle
    		{
    			count=0;	// start from index 0 of timing cycle
				lookup++;
   			}
   			printf("LED RED ON\t\n");
    		delay(delay_time_table[count]);
    		count++;

    		printf("LED RED OFF\t\n");
    		delay(delay_time_table[count]);
    		count++; // incrementing index in timing cycle
    	}
    	for(color=0; color<3; color++)
    	{
    		if(count==20)
    		{
    		    count=0;
    		    lookup++;
    		}
    		printf("LED BLUE ON\n");
			delay(delay_time_table[count]);
    		count++;

    		printf("LED BLUE OFF\n");
    		delay(delay_time_table[count]);
    		count++;
    	}
    	for(color=0; color<3; color++)
    	{
    		if(count==20)
    		{
    			count=0;
    			lookup++;
    		}
    		printf("LED GREEN ON\n");
    		delay(delay_time_table[count]);
    		count++;

    		printf("LED GREEN OFF\n");
    		delay(delay_time_table[count]);
    		count++;
    	}
    }
	#endif

    // for MODULE=PC_DEBUG; to print message for LED color toggle,
    // timestamp and delay from timing cycle
#ifdef PC_DEBUG
    // move through the look-up table(timing cycle) 10 times
    while(lookup<10)
    {
    	for(color=0; color<3; color++)
    	{
   			if(count==20)
   			{
   			    count=0;
   			    lookup++;
   			}
   			printf("LED RED ON\t");
    		delay(delay_time_table[count]);
    		calcTime(delay_time_table[count]);
    		count++;

    		printf("LED RED OFF\t");
    		delay(delay_time_table[count]);
    		calcTime(delay_time_table[count]);
    		count++;
    	}
    	for(color=0; color<3; color++)
    	{
    		if(count==20)
    		{
    		    count=0;
    		    lookup++;
    		}
    		printf("LED BLUE ON\t");
    		delay(delay_time_table[count]);
    		calcTime(delay_time_table[count]);
    		count++;

    		printf("LED BLUE OFF\t");
    		delay(delay_time_table[count]);
    		calcTime(delay_time_table[count]);
    		count++;
    	}
    	for(color=0; color<3; color++)
    	{
    		if(count==20)
    		{
    		    count=0;
    		    lookup++;
    		}
    		printf("LED GREEN ON\t");
    		delay(delay_time_table[count]);
    		calcTime(delay_time_table[count]);
   			count++;

    		printf("LED GREEN OFF\t");
    		delay(delay_time_table[count]);
    		calcTime(delay_time_table[count]);
    		count++;
    	}
    }
	#endif
}

//Function Name: delay
// Function Parameters: num - used for calculating delay from timing cycle
// Function Return type: void

/* Brief: a delay loop based on trial and error using oscilloscope
 	 which returns a 1000ms time gap for int 100000000 */

void delay(uint16_t num)
{
	uint64_t numb = num * 100000;
	while(numb != 0)

	{
		numb--;
	}
}

//Function Name: calcTime
// Function Parameters: num - used for passing timing cycle value
// Function Return type: void

/* Brief: used currentTime and prevTime to calculate time difference
 * 		in events, adding the new cycle value everytime
 * 		Calculating time stamp using struct tm, and strdtime function
 * 		and then storing current time to previous time */

void calcTime(uint16_t num)
{
	static int64_t currentTime = 0;
	static int64_t prevTime = 0;
	currentTime += num;

	//https://www.tutorialspoint.com/c_standard_library/c_function_strftime.htm
	//https://stackoverflow.com/questions/5248915/execution-time-of-c-program
	struct tm * timeLocal;
	time_t timeA;
	char buffer [80];
	time (&timeA);
	timeLocal = localtime (&timeA);
	strftime (buffer,80,"%x - %I:%M%p",timeLocal);
	printf(" %s %ld\n", buffer, currentTime - prevTime);
	prevTime = currentTime; // done for calculating time difference
}
