#include "CheckOrderDate.h"

bool CheckOrderDate(Date aDate, Order anOrder)
{
  bool inside = false;
  int days = 0;
  Date auxDate;

  if (anOrder.orderDate.sendNumbers == 1)
  {
    if (anOrder.orderDate.firstSendingDay.EqualDates(aDate))
    {
      inside = true;
    }
  }
  else
  {
    for (int i = 0; i < anOrder.orderDate.sendNumbers; i++)
    {
      if (i == 0)
      {
        if (anOrder.orderDate.firstSendingDay.EqualDates(aDate))
        {
          inside = true;
        }
      }
      else
      {
        if (!inside)
        {
          days = days + anOrder.orderDate.daysToAdd;
          auxDate = anOrder.orderDate.firstSendingDay.AddDays(days);
          inside = auxDate.EqualDates(aDate);
        }
      }
    }
  }

  return inside;
}
