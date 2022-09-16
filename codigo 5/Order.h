#pragma once
#include "OrderDates.h"
#include "AllDrugs.h"

typedef struct Order
{
  int refPatient;
  OrderDates orderDate;
  DrugList orderDrugs;

  void GetOrder(int reference);
  void ShowOrder();
};
