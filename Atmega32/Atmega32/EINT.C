#include "EINT.h"

void Ext_INT_Enable(Ext_INT_Types INTId) {
    switch (INTId) {
        case Ext_INT0:
            SET_BIT(GICR, GICR_INT0_Bit);
            break;
        case Ext_INT1:
            SET_BIT(GICR, GICR_INT1_Bit);
            break;
        case Ext_INT2:
            SET_BIT(GICR, GICR_INT2_Bit);
            break;
    }
}

void Ext_INT_Disable(Ext_INT_Types INTId) {
    switch (INTId) {
        case Ext_INT0:
            CLEAR_BIT(GICR, GICR_INT0_Bit);
            break;
        case Ext_INT1:
            CLEAR_BIT(GICR, GICR_INT1_Bit);
            break;
        case Ext_INT2:
            CLEAR_BIT(GICR, GICR_INT2_Bit);
            break;
    }
}

void Ext_INT_Sncontrol(Ext_INT_Types INTId, Ext_ISC_Types mode) {
    switch (INTId) {
        case Ext_INT0:
            MCUCR |= (mode << 0);
            break;
        case Ext_INT1:
            MCUCR |= (mode << 2);
            break;
        case Ext_INT2:
            if (mode == Falling_Edge) {
                CLEAR_BIT(MCUCSR, MCUCSR_BIT);
            } else if (mode == Rising_Edge) {
               SET_BIT(MCUCSR, MCUCSR_BIT);
            } else {
            }
            break;
    }
}
