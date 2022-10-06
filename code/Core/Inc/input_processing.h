/*
 * input_processing.h
 *
 *  Created on: Oct 6, 2022
 *      Author: Administrator
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

#include "main.h"
//we aim to work with more than one buttons
#define NO_OF_BUTTON 1
// timer interrupt duration is 10ms , so to pass 1 second ,
// we need to jump to the interrupt service routine 100 time

#define DURATION_FOR_AUTO_INCREASING 100
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET
// the buffer that the final result is stored after
// debouncing

static GPIO_PinState buttonBuffer [ N0_OF_BUTTONS ];
// we define two buffers for debouncing
static GPIO_PinState debounceButtonBuffer1 [ N0_OF_BUTTONS ];
static GPIO_PinState debounceButtonBuffer2 [ N0_OF_BUTTONS ];
// we define a flag for a button pressed more than 1 second .
static uint8_t flagForButtonPress1s [ N0_OF_BUTTONS ];
// we define counter for automatically increasing the value
// after the button is pressed more than 1 second .
static uint16_t counterForButtonPress1s [ N0_OF_BUTTONS ];
void button_reading ( void ){
	for ( char i = 0; i < N0_OF_BUTTONS ; i ++){
		debounceButtonBuffer2 [i] = debounceButtonBuffer1 [i];
		debounceButtonBuffer1 [i] = HAL_GPIO_ReadPin (BUTTON_1_GPIO_Port , BUTTON_1_Pin );
		if( debounceButtonBuffer1 [i] == debounceButtonBuffer2 [i])
			buttonBuffer [i] = debounceButtonBuffer1 [i];
	}
}
#endif /* INC_INPUT_PROCESSING_H_ */
