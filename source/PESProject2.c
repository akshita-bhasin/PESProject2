/**
 * @file    PESProject2.c
 * @brief   Application entry point.
 */

#include<stdio.h>
#include <stdint.h>

// MODULE=FB_RUN; include all the h files needed to run on KL25Z
#ifdef FB_RUN
#include "ledblink.h"
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "clock_config.h"
#endif

#ifdef FB_DEBUG
#include "ledblink.h" // led blink for FB_RUN and FB_DEBUG
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "clock_config.h"
#endif

#ifdef PC_RUN
#include "pc_print.h" // PC print messages for PC_RUN and PC_DEBUG
#endif

#ifdef PC_DEBUG
#include "pc_print.h"
#endif
/*
 * @brief   Application entry point.
 */

// Function Name: main
// Function arguments: void
// Function return type: int (returns 0)
/* Brief: Call the required blink() function based on which MODULE is
 * 		chosen, initializing board options and RED/BLUE/GREEN LED's
 * 		for FB_RUN and FB_DEBUG
	*/

int main(void)
{
	//initialize board pins for FB_RUN and call blink
#ifdef FB_RUN
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();
	/* Init FSL debug console. */
	BOARD_InitDebugConsole();

	LED_RED_INIT(1); // initialize RED LED to 1
	LED_BLUE_INIT(1);
	LED_GREEN_INIT(1);
	blink();
#endif

	//initialize board pins for FB_RUN and call blink
#ifdef FB_DEBUG
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();
	/* Init FSL debug console. */
	BOARD_InitDebugConsole();

	LED_RED_INIT(1);
	LED_BLUE_INIT(1);
	LED_GREEN_INIT(1);
	blink();
#endif

#ifdef PC_RUN
	blink();
#endif

#ifdef PC_DEBUG
	blink();
#endif
}
