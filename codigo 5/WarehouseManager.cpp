#include "WarehouseManager.h"

void WarehouseManager :: NewWarehouse()
{
  warehouse.InsertData();
}

void WarehouseManager :: NewPatient()
{
  InsertPatient(patientList);
}

void WarehouseManager :: NewOrder()
{
  InsertOrderToPatient(orderList, patientList);
}

void WarehouseManager :: NewManager()
{
  warehouse.InsertData();
  InsertPatient(patientList);
  InsertOrderToPatient(orderList, patientList);
}
