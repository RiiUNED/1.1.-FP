#include "Options.h"

//------------------------------------------New Process----------------------------------

void NewProcess(AllManager allManager)
{
  InsertBasisData(allManager);

  ShowDataAllManager(allManager);
}

//----------------------------Fill New Warehouse Data----------------------------------

int FindManager(AllManager allManager)
{
  bool full = true;
  int index;

  for (int i=0; i<10; i++)
  {
    if (full)
    {
      index = i + 1;
      full = allManager[i].warehouse.CheckWarehouse();
    }
  }

  if (full) {index = 25;}

  return index;
}

void FillNewWarehouseData(AllManager allManager)
{
  int auxCode;
  bool correctCode = false;

  if (FindManager(allManager)!=25){allManager[FindManager(allManager)-1].NewWarehouse();}
  else
  {
    NewLine();
    printf("El sistema esta completo");

    while(!correctCode)
    {
      for (int i = 0; i<10; i++){allManager[i].warehouse.ShowWarehouse();}
      LineBreak();

      printf("Introduzca el codigo del almacen que eliminar del sistema: ");
      scanf("%d", &auxCode);

      for (int i = 0; i<10; i++)
      {
        if (allManager[i].warehouse.code==auxCode)
        {
          correctCode=true;
          allManager[i].warehouse.EraseWarehouseData();
          NewLine();
          printf("El almacen con codigo: %d se borro del sistema", auxCode);
          LineBreak();
        }
      }
    }
    allManager[FindManager(allManager)-1].NewWarehouse();
  }
}

void NewPatientInWarehouse(AllManager allManager)
{
  int managerPosition, newPatient;

  Title("Alta nuevo paciente:");

  newPatient = 1;
  while(newPatient==1)
  {
    GetManagerPosition(allManager, managerPosition);

    allManager[managerPosition].NewPatient();

    newPatient = Ask("Otro Paciente (S/N)?");
  }
}

//---------------------------- Place Warehouse Patients --------------------------------------

void PlaceWarehousePatients(AllManager allManager)
{
  int managerPosition;

  Title("Lista de pacientes y su ubicacion:");

  GetManagerPosition(allManager, managerPosition);

  ShowPatientList(allManager[managerPosition].patientList);
}

//---------------------------- New Order in Warehouse --------------------------------------

void NewOrderInWarehouse(AllManager allManager)
{
  int managerPosition;

  Title("Nuevo Pedido");

  GetManagerPosition(allManager, managerPosition);

  allManager[managerPosition].NewOrder();
}

//---------------------------- Print Day Order in Warehouse ------------------------------------

void PrintDayOrder(OrderList allOrders, PatientList allPatients, Text description)
{
  Date checkDate;
  int distance, angle, ud, wg, totalWeight;
  int orderInDay = 1;
  bool noOrder = true;

  description = strupr(description);

  LineBreak();
  printf("Pedido ALMACEN - %s", description);
  LineBreak();
  LineBreak();

  checkDate.NewDate("Dia? ", "Mes? ", "Ano? ");

  for (int i = 0; i < 100; i++)
  {
    if(CheckOrderDate(checkDate, allOrders[i]))
    {
      noOrder = false;
      LineBreak();
      LineBreak();
      Tabulate(5);
      printf("Pedido: %d", orderInDay);
      LineBreak();
      distance = allPatients[allOrders[i].refPatient-1].position[0];
      printf("Ubicacion destino: Distancia: %d", distance);
      angle = allPatients[allOrders[i].refPatient-1].position[1];
      printf(" y Angulo: %d", angle);
      LineBreak();
      totalWeight = 0;
      for (int j = 0; j < 5; j++)
      {
        if (allOrders[i].orderDrugs[j].unities!=-1)
        {
          ud = allOrders[i].orderDrugs[j].unities;
          printf("%2d", ud);
          printf(" Unidades");
          Tabulate(8);
          printf(allOrders[i].orderDrugs[j].name);
          Tabulate(18-strlen(allOrders[i].orderDrugs[j].name));
          printf("Peso:");
          wg = allOrders[i].orderDrugs[j].weight;
          printf("%5d", wg);
          printf(" gramos");
          LineBreak();
          totalWeight = totalWeight + (ud * wg);
        }
        if (j==4)
        {
          Tabulate(19);
          printf("Peso Total del envio: %6d", totalWeight);
          printf(" gramos");
          LineBreak();
          LineBreak();
        }
      }
      orderInDay = orderInDay + 1;
    }
  }
  if (noOrder)
    {
      LineBreak();
      Tabulate(5);
      printf("No hay ningun pedido registrado para la fecha consultada.");
      LineBreak();
    }
}

void PrintDayOrderInWarehouse(AllManager allManager)
{
  int managerPosition;

  Title("Lista diaria de pedidos:");

  GetManagerPosition(allManager, managerPosition);

  PrintDayOrder(allManager[managerPosition].orderList,
                allManager[managerPosition].patientList,
                allManager[managerPosition].warehouse.description);
}
