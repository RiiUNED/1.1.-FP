#include "Order.h"

void Order :: GetOrder(int reference)
{
  refPatient = reference;
  orderDate.GetOrderDates();
  InsertDrug(orderDrugs);
}

void Order :: ShowOrder()
{
  const int lineLenght = 51;

  for (int i=0; i<5; i++)
  {
    if (orderDrugs[i].unities != -1)
    {
      printf("%d", refPatient);
      if(refPatient<10){Tabulate(10);}
      else{Tabulate(9);}
      orderDate.firstSendingDay.ShowDate();
      Tabulate(3);
      printf(orderDrugs[i].name);
      Tabulate(19-strlen(orderDrugs[i].name));
      printf("%d", orderDrugs[i].weight);
      if(orderDrugs[i].weight<10){Tabulate(11);}
      else if(orderDrugs[i].weight<100){Tabulate(10);}
      else if(orderDrugs[i].weight<1000){Tabulate(9);}
      else {Tabulate(8);}
      printf("%d", orderDrugs[i].unities);
      NewLine();
    }
  }
}
