#include "RegTable_RW.h"

static RegTableType regTableList[REGTABLE_MAXSIZE];

void Set_RegTable(u8 index,u8 changeflag,u16 datavalue)
{
    if (index <= REGTABLE_MAXSIZE)
    {
        RegTableType * regTableData;

        regTableData = &regTableList[index];
        regTableData->changeFlag = changeflag;
        regTableData->dataValue = datavalue;
    }
    return;
}
RegTableType * Get_RegTable(u8 index)
{
    if (index <= REGTABLE_MAXSIZE)
    {
        RegTableType * regTableData;

        regTableData = &regTableList[index];
        return regTableData;
    }
    return;
}

