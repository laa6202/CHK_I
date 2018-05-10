#ifndef __COMMU_H
#define __COMMU_H

int U1_Init(void);
int U1_IRQ(void);
int U1RecData(void);
int U1_IRQ_END(void);
int I2C_Init(void);
int I2C_EVIRQ(void);
int I2C_EVIRQ_End(void);


#endif
