#pragma once

#include "Warehouse.h"
#include "DataManager.h"

typedef struct WarehouseManager
{
  Warehouse warehouse;
  PatientList patientList;
  OrderList orderList;

  void NewManager();
  void NewWarehouse();
  void NewPatient();
  void NewOrder();
};
