/*
 * AdcCfg.h
 *
 * Created: 7/16/2022 3:27:11 AM
 *  Author: DELL G3
 */ 


#ifndef ADCCFG_H_
#define ADCCFG_H_

/*******************************************_SELECT_ADC_OPERATION_MODE_********************************************/
// option 1 -> [ ADC_INT ]
// option 1 -> [ ADC_POL ]
#define ADC_OPERATION_MODE        ADC_POL
/*************************************************_SELECT_VREF_********************************************/
// option 1 -> [ AVCC     ]
// option 2 -> [ AREF_PIN ]
// option 3 -> [ _2V56    ]
#define VREF                      AVCC



#endif /* ADCCFG_H_ */