#ifndef __MAPLE_LIB_H
#define __MAPLE_LIB_H

/* ST Libs (stripped) */
#include "stm32f10x_type.h" /* defines simple types (u32, vu16, etc) */
#include "cortexm3_macro.h" /* provides asm instruction macros */
#include "usb_lib.h"

/* Local Includes */
#include "maple_usb.h"
#include "maple_dfu.h"
#include "maple_regs.h"


/* any global setting macros */
#define F_SUSPEND_ENABLED 1

/* exposed library structs */
typedef struct {
  vu32 ISER[2];
  u32  RESERVED0[30];
  vu32 ICER[2];
  u32  RSERVED1[30];
  vu32 ISPR[2];
  u32  RESERVED2[30];
  vu32 ICPR[2];
  u32  RESERVED3[30];
  vu32 IABR[2];
  u32  RESERVED4[62];
  vu32 IPR[15];
} NVIC_TypeDef;

typedef struct {
  u8 NVIC_IRQChannel;
  u8 NVIC_IRQChannelPreemptionPriority;
  u8 NVIC_IRQChannelSubPriority;
  bool NVIC_IRQChannelCmd; /* TRUE for enable */
} NVIC_InitTypeDef;

typedef struct {
  vuc32 CPUID;
  vu32 ICSR;
  vu32 VTOR;
  vu32 AIRCR;
  vu32 SCR;
  vu32 CCR;
  vu32 SHPR[3];
  vu32 SHCSR;
  vu32 CFSR;
  vu32 HFSR;
  vu32 DFSR;
  vu32 MMFAR;
  vu32 BFAR;
  vu32 AFSR;
} SCB_TypeDef;

void setPin    (u32 bank, u8 pin);
void resetPin  (u32 bank, u8 pin);
void strobePin (u32 bank, u8 pin, u8 count, u32 rate);

void systemReset   (void);
void setupCLK      (void);
void setupUSB      (void);
void setupLED      (void);
void setupTimer    (void);
bool checkUserCode (u32 usrAddr);
void jumpToUser    (u32 usrAddr);

void flashErasePage (u16 pageNum);
s8   flashWritePage (u8 pageNum, u8 *srcBuf);
void flashEraseAll  (void);
void flashUnlock    (void);
void flashBlock     (void);  /* waits until flash is ready */
s8   flashGetStatus (void);

void nvicInit(NVIC_InitTypeDef*);







#endif
