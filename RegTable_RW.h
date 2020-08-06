#ifndef _REGTABLE_H_
#define _REGTABLE_H_

#include "include.h"

void Set_RegTable(u8 index,u8 changeflag,u16 datavalue);
RegTableType * Get_RegTable(u8 index);

#endif
