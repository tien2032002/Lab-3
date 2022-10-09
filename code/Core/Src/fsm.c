/*
 * fsm.c
 *
 *  Created on: 7 thg 10, 2022
 *      Author: Administrator
 */

#include "main.h"
#include "global.h"
#include "fsm.h"
#include "software_timer.h"
void fsmRun() {
	switch (status) {
	case INIT:
		status=AUTO_RED;
		setTimer1(RED_TIME);
		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(GPIOA, A0_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, B0_Pin, RESET);
		if (timer1_flag==1) {
			status=AUTO_GREEN;
			setTimer1(GREEN_TIME);
		}
		if (button1_flag==1) {
			status=MAN_RED;
			setTimer1(1000);
		}
		break;
	case AUTO_GREEN:
			HAL_GPIO_WritePin(GPIOA, A0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, B0_Pin, SET);
			if (timer1_flag==1) {
				status=AUTO_YELLOW;
				setTimer1(YELLOW_TIME);
			}
			break;
	case AUTO_YELLOW:
			HAL_GPIO_WritePin(GPIOA, A0_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, B0_Pin, SET);
			if (timer1_flag==1) {
				status=AUTO_RED;
				setTimer1(RED_TIME);
			}
			break;
	default:
		break;
	}
}
void fsmRun1() {
	switch (status1) {
	case INIT:
		status1=AUTO_GREEN;
		setTimer2(GREEN_TIME);
		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(GPIOA, A1_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, B1_Pin, RESET);
		if (timer2_flag==1) {
			status1=AUTO_GREEN;
			setTimer2(GREEN_TIME);
		}
		break;
	case AUTO_GREEN:
			HAL_GPIO_WritePin(GPIOA, A1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, B1_Pin, SET);
			if (timer2_flag==1) {
				status1=AUTO_YELLOW;
				setTimer2(YELLOW_TIME);
			}
			break;
	case AUTO_YELLOW:
			HAL_GPIO_WritePin(GPIOA, A1_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, B1_Pin, SET);
			if (timer2_flag==1) {
				status1=AUTO_RED;
				setTimer2(RED_TIME);
			}
			break;
	default:
		break;
	}
}
