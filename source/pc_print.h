/*
 * @file pc_print.h
 * @brief header file for PC_RUN and PC_DEBUG including function prototyping
 *
 *  @author Akshita Bhasin and Madhukar Arora
 *  @date 30/09/2019
 *  @version 1.0
 */

#ifndef PC_PRINT_H_
#define PC_PRINT_H_

#include <stdint.h>
#include <stdio.h>
#include <time.h>

void calcTime(uint16_t num); //used to calculate timestamp and diff in time

void blink(void); //to print the LED toggle messages

void delay(uint16_t num); // to implement the delay from look-up table

#endif /* PC_PRINT_H_ */
