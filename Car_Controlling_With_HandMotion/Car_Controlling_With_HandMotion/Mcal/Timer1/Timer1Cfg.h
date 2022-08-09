/*
 * Timer1Cfg.h
 *
 * Created: 7/16/2022 3:02:09 AM
 *  Author: DELL G3
 */ 


#ifndef TIMER1CFG_H_
#define TIMER1CFG_H_

/******************************************_SELECT_TIMER0_MODE_********************************************/
// option 1 -> [ NORMAL_MODE ]
// option 2 -> [ CTC_MODE    ]
#define TIMER1_MODE                    CTC_MODE
/******************************************_SELECT_FAST_PWM_MODE_********************************************/
// option 1 -> [ NON_INVERTING ]
// option 2 -> [ INVERTING     ]
#define FAST_PWM_MODE                  NON_INVERTED
/**************************************_SELECT_PHASE_CORRECT_PWM_MODE_********************************************/
// option 1 -> [ NON_INVERTING ]
// option 2 -> [ INVERTING     ]
#define PHASE_CORRECT_PWM_MODE         NON_INVERTED
/******************************************_SELECT_PWM_MODE_********************************************/
// option 1 -> [ FAST_PWM ]
// option 2 -> [ PHASE_CORRECT_PWM ]
#define PWM_MODE                        FAST_PWM
/*********************************************_SELECT_F_OSC_********************************************/
#define F_OSC                   8
/***************************************_SELECT_TIMER0_PRESCALER_********************************************/
// option 1 -> [ 1024 ]
// option 2 -> [ 256  ]
#define TIMER1_PRESCALER       256



#endif /* TIMER1CFG_H_ */