#include "Warehouse.h"

void Warehouse :: InsertData()
{
  int answer;

  answer = 0;
  while (answer == 0)
  {
    printf("Alta nuevo almacen:");
    LineBreak();
    NewLine();
    printf("Identificador almacen (cod. de alamacen 1 a 10)? ");
    scanf("%d", &code);
    NewLine();
    GetString("Direccion almacen? (entre 1 y 48 caracteres) ", address);
    NewLine();
    GetString("Municipio almacen? (entre 1 y 48 caracteres) ", city);
    NewLine();
    printf("Provincia almacen? (entre 1 y 16 caracteres) ");
    scanf("%s", &state);
    NewLine();
    GetString("Descripcion almacen? (entre 1 y 48 caracteres) ", description);

    answer = Ask("Datos correctos (S/N)? ");
  }
}

void Warehouse :: EraseWarehouseData()
{
  code = -1;
}

bool Warehouse :: CheckWarehouse()
{
  bool full = false;

  if (code != -1) {full = true;}

  return full;
}

void Warehouse :: ShowWarehouse()
{
  if (code!=-1)
  {
    NewLine();
    printf("Almacen %d - %s - %s - %s", code, address, city, state);
    NewLine();
    printf("Descripcion: %s", description);
    LineBreak();
  }
}

