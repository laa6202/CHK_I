#ifndef __TOP_H
#define __TOP_H

int AppInit(void);
int AppMain(void);

int U1_IRQ(void);
int U1_IRQ_END(void);

int U2_IRQ(void);

int ADC_Init(void);
int ADC_IRQ(void);
int ADC_IRQ_End(void);

#endif
