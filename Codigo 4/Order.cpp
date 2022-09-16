#include "Order.h"

void Order ::GetOrder(int reference)
{
  refPatient = reference;
  orderDate.GetOrderDates();
  InsertDrug(orderDrugs);
}
