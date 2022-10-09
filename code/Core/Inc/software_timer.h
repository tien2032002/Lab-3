/*
 * software_timer.h
 *
 *  Created on: 7 thg 10, 2022
 *      Author: Administrator
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;
void setTimer1(int duration);
void setTimer2(int duration);
void timeRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
