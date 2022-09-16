#pragma once
#include "WarehouseManager.h"

typedef WarehouseManager AllManager[10];

///-------------------- All Manager -----------------------
void CleanManagement(AllManager allManager);
void GetManagerPosition(AllManager allManager,
  int &managerPosition);
int GetWarehouseCode(AllManager allManager);
void ShowDataAllManager(AllManager allManager);

///--------------- All Options Utilities ------------------
bool CheckOrderDate(Date aDate, Order anOrder);
