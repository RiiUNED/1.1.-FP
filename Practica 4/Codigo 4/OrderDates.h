#pragma once
#include "Date.h"

typedef struct OrderDates
{
  int sendNumbers;
  int daysToAdd;
  Date firstSendingDay;

  void GetOrderDates();
};
