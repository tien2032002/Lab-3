/*
 * fsm_manual.c
 *
 *  Created on: Oct 7, 2022
 *      Author: Administrator
 */
#include "fsm_manual.h"

void fsm_manual_run() {
	switch (status) {
		case MAN_RED:
			HAL_GPIO_WritePin(GPIOA, A0_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, B0_Pin, RESET);
			if (timer1_flag == 1) {
				status =AUTO_RED;
				setTimer1(500);
			}
			if (button1_flag==1) {
				button1_flag=0;
				setTimer1(0);
				status=MAN_GREEN;
				setTimer1(500);
			}
			break;
		case MAN_GREEN:
			HAL_GPIO_WritePin(GPIOA, A0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, B0_Pin, SET);
			if (timer1_flag == 1) {
				status =AUTO_GREEN;
				setTimer1(GREEN_TIME);
			}
			if (button1_flag==1) {
				button1_flag=0;
				setTimer1(0);
				status=MAN_YELLOW;
				setTimer1(500);
			}
			break;
		case MAN_YELLOW:
			HAL_GPIO_WritePin(GPIOA, A0_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, B0_Pin, SET);
			if (timer1_flag == 1) {
				status =AUTO_YELLOW;
				setTimer1(YELLOW_TIME);
			}
			if (button1_flag==1) {
				button1_flag=0;
				setTimer1(0);
				status=MAN_RED;
				setTimer1(500);
			}
			break;
		default:
			break;
	}
}
