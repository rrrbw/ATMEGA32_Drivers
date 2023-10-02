#ifndef EINT_H
#define EINT_H

#include "BIT_MATH.h"
#include "Types_Interrupts.h"
#include "ATEMGA32_REG.h"

void Ext_INT_Enable(Ext_INT_Types INTId);
void Ext_INT_Disable(Ext_INT_Types INTId);
void Ext_INT_Sncontrol(Ext_INT_Types INTId,Ext_ISC_Types mode);

#endif 