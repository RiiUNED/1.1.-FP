#include "Options.h"
#include "ProgrammingDronRoutes.h"

AllManager allManager;

int returnMenu = 1;

typedef Text TextArray2[2];
typedef TextArray2 TextArray2Array9[9];

TextArray2Array9 allMenuTextOptions;

typedef enum menuOptions
{
  newProcess,             // 0
  newWarehouse,           // 1
  newPatientInWarehouse,  // 2
  patientLocation,        // 3
  newOrder,               // 4
  orderDay,               // 5
  dronRoutesProgramming,  // 6
  dronRoutesRepresent,    // 7
  quit,                   // 8
  none                    // 9
};

menuOptions optionSelected = menuOptions(9);

void MenuSettings(TextArray2Array9 allMenuTextOptions)
{
  const Text optionI = "Iniciar gestion";
  const Text optionM = "Alta almacen";
  const Text optionA = "Alta paciente almacen";
  const Text optionU = "Ubicar pacientes";
  const Text optionN = "Nuevo pedido";
  const Text optionL = "Lista diaria de pedidos";
  const Text optionP = "Programar rutas diarias del dron";
  const Text optionR = "Representar rutas diarias del dron";
  const Text optionS = "Salir";

  //Opcion I
  strcpy(allMenuTextOptions[0][0], optionI);
  strcpy(allMenuTextOptions[0][1], "I");
  //Opcion M
  strcpy(allMenuTextOptions[1][0], optionM);
  strcpy(allMenuTextOptions[1][1], "M");
  //Opcion A
  strcpy(allMenuTextOptions[2][0], optionA);
  strcpy(allMenuTextOptions[2][1], "A");
  //Opcion U
  strcpy(allMenuTextOptions[3][0], optionU);
  strcpy(allMenuTextOptions[3][1], "U");
  //Opcion N
  strcpy(allMenuTextOptions[4][0], optionN);
  strcpy(allMenuTextOptions[4][1], "N");
  //Opcion L
  strcpy(allMenuTextOptions[5][0], optionL);
  strcpy(allMenuTextOptions[5][1], "L");
  //Opcion P
  strcpy(allMenuTextOptions[6][0], optionP);
  strcpy(allMenuTextOptions[6][1], "P");
  //Opcion R
  strcpy(allMenuTextOptions[7][0], optionR);
  strcpy(allMenuTextOptions[7][1], "R");
  //Opcion S
  strcpy(allMenuTextOptions[8][0], optionS);
  strcpy(allMenuTextOptions[8][1], "S");
}

void PrintMenu()
{
  MenuSettings(allMenuTextOptions);

  printf("GESTION DE FarmaDrones: Distribucion de Farmacos");
  LineBreak();
  for(int i = 0; i<9; i++)
  {
    Tabulate(6);
    printf("%s", allMenuTextOptions[i][0]);
    Tabulate(37 - strlen(allMenuTextOptions[i][0]));
    printf("(Pulsar %s)", allMenuTextOptions[i][1]);
    LineBreak();
  }

  printf("Teclear una opcion valida (");
  for(int i = 0; i<8; i++) {printf("%s|", allMenuTextOptions[i][1]);}
  printf("%s)?", allMenuTextOptions[8][1]);
  LineBreak();
}

void GetOption(menuOptions &optionSelected)
{
  Text tipped;

  PrintMenu();

  scanf("%s", &tipped);

  for (int i=0; i<9; i++)
  {
    if(strcmp(tipped, allMenuTextOptions[i][1])==0) {optionSelected = menuOptions(i);}
  }
}

void RunOption(menuOptions optionSelected, PatientList List, OrderList allOrders)
{
  switch (optionSelected)
  {
    case (newProcess):
    LineBreak();
    NewProcess(allManager);
    LineBreak();
    break;
    case (newWarehouse):
    LineBreak();
    FillNewWarehouseData(allManager);
    LineBreak();
    break;
    case (newPatientInWarehouse):
    LineBreak();
    NewPatientInWarehouse(allManager);
    LineBreak();
    break;
    case (patientLocation):
    LineBreak();
    PlaceWarehousePatients(allManager);
    LineBreak();
    break;
    case (newOrder):
    LineBreak();
    NewOrderInWarehouse(allManager);
    LineBreak();
    break;
    case (orderDay):
    LineBreak();
    PrintDayOrderInWarehouse(allManager);
    LineBreak();
    break;
    case (dronRoutesProgramming):
    LineBreak();
    ProgrammingDronRoutes(allManager);
    LineBreak();
    break;
    case (dronRoutesRepresent):
    NewLine();
    printf("Opcion no desarrollada.");
    LineBreak();
    break;
    case (quit):
    LineBreak();
    break;
    default:
    LineBreak();
    printf("No elegio ninguna opcion del menu.");
    LineBreak();
  }
}

int main()
{
  CleanManagement(allManager);

  while(returnMenu==1)
  {
    GetOption(optionSelected);
    RunOption(optionSelected, allManager[0].patientList, allManager[0].orderList);
    optionSelected = menuOptions(9);
    returnMenu = Ask("Desea volver al menu GESTION DE FarmaDrones? (S/N)");
  }

  LineBreak();
  printf("La aplicacion FarmaDron se ha cerrado.");
  LineBreak();
}
