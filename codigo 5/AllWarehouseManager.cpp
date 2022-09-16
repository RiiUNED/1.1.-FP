#include "AllWarehouseManager.h"

void CleanManagement(AllManager allManager)
{
  for (int i = 0; i<10; i++)
  {
    ResetOrderList(allManager[i].orderList);
    allManager[i].warehouse.EraseWarehouseData();
  }
}

void GetManagerPosition(AllManager allManager, int &managerPosition)
{
  int warehouseCode;
  bool stop;

  stop = false;
  warehouseCode = GetWarehouseCode(allManager);

  for (int i = 0; i<10; i++)
  {
      if (allManager[i].warehouse.code == warehouseCode && !stop)
      {
        managerPosition = i;
        stop = true;
      }
  }
}

int GetWarehouseCode(AllManager allManager)
{
  bool correctCode = false;
  int auxCode;

  while(!correctCode)
  {
    printf("Codigo almacen? (entre 1-10) ");
    scanf("%d", &auxCode);

    for (int i = 0; i<10; i++){if (allManager[i].warehouse.code==auxCode){correctCode=true;}}

    if (!correctCode)
    {
      for (int i=0; i<10; i++) {allManager[i].warehouse.ShowWarehouse();}
      NewLine();
      printf("El codigo %d no se corresponde con nigun almacen registrado", auxCode);
      NewLine();
    }
  }

  return auxCode;
}

void ShowDataAllManager(AllManager allManager)
{
  bool emptyClient;

  Title("ListadoGestion FarmaDron");

  for(int i=0; i<10; i++)
  {
    if (allManager[i].warehouse.CheckWarehouse())
    {
      emptyClient = true;
      for(int j=0; j<20; j++)
      {
        if (strlen(allManager[i].patientList[j].id[0])!=0) {emptyClient = false;}
      }

      allManager[i].warehouse.ShowWarehouse();

      NewLine();

      if (!emptyClient)
      {
        NewLine();
        ShowPatientList(allManager[i].patientList);
        NewLine();
      }


      if (CheckOrderList(allManager[i].orderList))
      {
        NewLine();
        printf("Pedidos:");
        NewLine();
        NewLine();
        ShowOrderList(allManager[i].orderList);
        NewLine();;
      }
    }
  }
}

bool CheckOrderDate(Date aDate, Order anOrder)
{
  bool inside = false;
  int days = 0;
  Date auxDate;

  if (anOrder.orderDate.sendNumbers == 1)
  {
    if (anOrder.orderDate.firstSendingDay.EqualDates(aDate)) {inside = true;}
  }
  else
  {
    for (int i = 0; i < anOrder.orderDate.sendNumbers; i++)
    {
      if (i == 0)
      {
        if (anOrder.orderDate.firstSendingDay.EqualDates(aDate)) {inside = true;}
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
