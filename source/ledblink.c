/*
 * @file ledblink.c
 * @brief running FB_RUN and FB_DEBUG with timing cycle implementation
 * 		on KL25Z and blinking LED
 *
 *  @author Akshita Bhasin and Madhukar Arora
 *  @date 30/09/2019
 *  @version 1.0
 */

#include "ledblink.h"

uint16_t delay_time_table[] = {3000, 1000, 2000, 600, 1000, 400,\
		                   1000, 200, 500, 100, 500, 100, 500, 100,\
						   1000, 200, 1000, 400, 2000, 600}; // look-up table

void delay(uint16_t num); // to implement the delay from look-up table

// Function Name: blink
// Function arguments: void
// Function return type: void
/* Brief: Blinking LED with keeeping delay from look-up table
	and executing the timing cycle 10 times, printing the message
	via UART terminal and printing the difference in time
	between two events
	*/

void blink(void) {

	uint8_t count = 0, color, lookup=0;

	// for MODULE=FB_DEBUG; blink led, print message via serial terminal
	//	and printing timing cycle delay for the event
	#ifdef FB_DEBUG
	// move through the look-up table(timing cycle) 10 times
    while(lookup<10)
    {
   		for(color=0; color<3; color++) //to blink RED ON and OFF 3 times each
   		{
   			if(count==20)  //one entire run of the timing cycle
   			{
   				count=0;	// start from index 0 of timing cycle
				lookup++;
   			}
   			LED_RED_ON(); /*!< Turn on target LED_RED */
    		PRINTF("LED RED ON\t%d\n",delay_time_table[count]);
    		delay(delay_time_table[count]);
    		count++; // incrementing index in timing cycle

   			LED_RED_OFF(); /*!< Turn off target LED_GREEN */
    		PRINTF("LED RED OFF\t%d\n",delay_time_table[count]);
    		delay(delay_time_table[count]);
    		count++;
    	}
   		for(color=0; color<3; color++) //to blink BLUE ON and OFF 3 times each
   		{
   			if(count==20)
   			{
    			count=0;
    			lookup++;
    		}
    		LED_BLUE_ON(); /*!< Turn on target LED_BLUE */
    		PRINTF("LED BLUE ON\t%d\n",delay_time_table[count]);
    		delay(delay_time_table[count]);
    		count++;

    		LED_BLUE_OFF(); /*!< Turn off target LED_BLUE */
    		PRINTF("LED BLUE OFF\t%d\n",delay_time_table[count]);
    		delay(delay_time_table[count]);
    		count++;
    	}
   		for(color=0; color<3; color++) //to blink GREEN ON and OFF 3 times each
   		{
   			if(count==20)
   			{
    			count=0;
    			lookup++;
    		}
    		LED_GREEN_ON(); /*!< Turn on target LED_GREEN */
    		PRINTF("LED GREEN ON\t%d\n",delay_time_table[count]);
    		delay(delay_time_table[count]);
    		count++;

    		LED_GREEN_OFF(); /*!< Turn off target LED_GREEN */
    		PRINTF("LED GREEN OFF\t%d\n",delay_time_table[count]);
    		delay(delay_time_table[count]);
    		count++;
    	}
    }
	#endif

    /* for MODULE=FB_RUN; blink led with timing loop cycle,
    print message via serial terminal */
	#ifdef FB_RUN
    // move through the look-up table(timing cycle) 10 times
    while(lookup<10)
    {
    	for(color=0; color<3; color++) //to blink RED ON and OFF 3 times each
    	{
    		if(count==20)
    		{
   				count=0;
   				lookup++;
   			}
    		LED_RED_ON(); /*!< Turn on target LED_RED */
   			delay(delay_time_table[count]);
   			count++;

   			LED_RED_OFF(); /*!< Turn off target LED_RED */
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
    		LED_BLUE_ON(); /*!< Turn on target LED_BLUE */
    		delay(delay_time_table[count]);
    		count++;

    		LED_BLUE_OFF(); /*!< Turn off target LED_BLUE */
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
    		LED_GREEN_ON(); /*!< Turn on target LED_GREEN */
    		delay(delay_time_table[count]);
    		count++;

    		LED_GREEN_OFF(); /*!< Turn off target LED_GREEN */
    		delay(delay_time_table[count]);
    		count++;
    	}
    }
	#endif
}

//Function Name: delay
// Function Parameters: num - used for calculating delay from timing cycle
// Function Return type: void

/* Brief: a delay loop based on trial and error using oscilloscope
 	 which returns a 1000ms time gap for int 2,300,000 */

void delay(uint16_t num)
{
	uint64_t numb = num * 1000*2.3;
	while(numb != 0)
	{
		numb--;
	}
}
