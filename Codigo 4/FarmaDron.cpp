#include "DataManager.h"
#include "PrintDayOrders.h"
#include "PrintCalendar.h"

int returnMenu = 1;

PatientList allPatients;
OrderList allOrders;

typedef enum menuOptions
{
  newPatient,
  patientLocation,
  newOrder,
  orderDay,
  orderMonth,
  quit,
  none
};

menuOptions optionSelected = menuOptions(6);

void PrintMenu()
{
  // Presentaci�n
  printf("\nFarmaDron: Distribucion de Farmacos con Dron\n");
  //Opci�n A
  Tabulate(5);
  printf("Alta nuevo paciente");
  Tabulate(16);
  printf("(Pulsar A)\n");
  //Opci�n U
  Tabulate(5);
  printf("Ubicar pacientes");
  Tabulate(19);
  printf("(Pulsar U)\n");
  //Opci�n N
  Tabulate(5);
  printf("Nuevo pedido");
  Tabulate(23);
  printf("(Pulsar N)\n");
  //Opci�n L
  Tabulate(5);
  printf("Lista diario de pedidos");
  Tabulate(12);
  printf("(Pulsar L)\n");
  //Opci�n C
  Tabulate(5);
  printf("Calendario mensual de pedidos");
  Tabulate(6);
  printf("(Pulsar C)\n");
  //Opci�n S
  Tabulate(5);
  printf("Salir");
  Tabulate(30);
  printf("(Pulsar S)\n");
  //Solicitud
  printf("Teclear una opcion valida (A|U|N|L|C|S)? ");
}

menuOptions GetOption()
{
  Text tipped;
  const char a[] = "A";
  const char u[] = "U";
  const char n[] = "N";
  const char l[] = "L";
  const char c[] = "C";
  const char s[] = "S";

  menuOptions optionSelected = menuOptions(6);

  PrintMenu();
  scanf("%s", &tipped);

  if (strcmp(tipped, a) == 0)
  {
    optionSelected = menuOptions(0);
  }
  else if (strcmp(tipped, u) == 0)
  {
    optionSelected = menuOptions(1);
  }
  else if (strcmp(tipped, n) == 0)
  {
    optionSelected = menuOptions(2);
  }
  else if (strcmp(tipped, l) == 0)
  {
    optionSelected = menuOptions(3);
  }
  else if (strcmp(tipped, c) == 0)
  {
    optionSelected = menuOptions(4);
  }
  else if (strcmp(tipped, s) == 0)
  {
    optionSelected = menuOptions(5);
  }
  else
  {
    optionSelected = menuOptions(6);
  }

  return optionSelected;
}

void RunOption(menuOptions optionSelected, PatientList List, OrderList allOrders)
{
  switch (optionSelected)
  {
  case (newPatient):
    InsertPatient(allPatients);
    break;
  case (patientLocation):
    ShowPatientList(allPatients);
    break;
  case (newOrder):
    InsertOrderToPatient(allOrders, allPatients);
    break;
  case (orderDay):
    PrintDayOrders(allOrders, allPatients);
    break;
  case (orderMonth):
    PrintCalendar(allOrders);
    break;
  case (quit):
    break;
  default:
    printf("No elegio ninguna opcion del menu.");
  }
}

int main()
{
  ResetOrderList(allOrders);
  while (returnMenu == 1)
  {
    optionSelected = GetOption();
    RunOption(optionSelected, allPatients, allOrders);
    returnMenu = Ask("Desea volver al menu FarmaDron? (S/N) ");
  }

  LineBreak();
  printf("La aplicacion FarmaDron se ha cerrado.");
  LineBreak();
}
