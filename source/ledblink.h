/*
 * @file ledblink.h
 * @brief header file for FB_RUN and FB_DEBUG including function prototyping
 *
 *  @author Akshita Bhasin and Madhukar Arora
 *  @date 30/09/2019
 *  @version 1.0
 */

#ifndef LEDBLINK_H_
#define LEDBLINK_H_

// includes to run the program on Freedom board
#include <stdint.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "clock_config.h"

void blink(void); //to blink the LED

void delay(uint16_t num); // to implement the delay from look-up table

#endif /* LEDBLINK_H_ */
