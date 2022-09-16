#pragma once

#include "Utilities.h"

typedef struct Warehouse
{
  int code;
  Text address;
  Text city;
  Text state;
  Text description;

  void InsertData();
  void EraseWarehouseData();
  bool CheckWarehouse(); //True: full; False: empty
  void ShowWarehouse();
};
