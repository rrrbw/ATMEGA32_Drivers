#define GICR_INT0_Bit 6
#define GICR_INT1_Bit 7
#define GICR_INT2_Bit 5

#define MCUCSR_BIT 6

typedef enum {
    Ext_INT0 = 0,
    Ext_INT1,
    Ext_INT2
} Ext_INT_Types;

typedef enum {
    Low_Level = 0,
    Both_Edge,
    Falling_Edge,
    Rising_Edge
} Ext_ISC_Types;