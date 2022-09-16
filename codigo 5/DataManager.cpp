#include "DataManager.h"

//------------------------------Data Manager---------------------------------------------
int CheckReference(PatientList allPatients, int i)
{
  bool voidPatient;
  int reference;

  reference = -1;
  voidPatient = true;
  while(reference < 1 || reference > 20 || voidPatient)
  {
    printf("Pedido %d", i+1);
    LineBreak();
    LineBreak();
    Tabulate(5);
    printf("Ref. Paciente (entre 1 y 20) ");
    scanf("%d", &reference);
    if (reference < 1 || reference > 20)
    {
      Tabulate(5);
      printf("Introdujo como referencia paciente: %d", reference);
      LineBreak();
      Tabulate(5);
      printf("FarmaDron 20 pacientes con referencia entre 1 y 20");
      LineBreak();
      LineBreak();
    }
    else
    {
      if (strlen(allPatients[reference -1 ].id[0]) != 0) {voidPatient = false;}
      else
      {
        Tabulate(5);
        printf("Introdujo como referencia paciente: %d", reference);
        LineBreak();
        Tabulate(5);
        printf("No existe ningun paciente registrado con esa referencia.");
        LineBreak();
        LineBreak();
      }
    }
  }
  return reference;
}

bool CheckFlightRange(OrderList allOrders, int i, PatientList allPatients, int reference)
{
  bool check = true;
  int unities, weight, distance, totalWeight;
  float flightRange;
  distance = allPatients[reference-1].position[0];

  if (distance > 10000)
  {
    check = false;
    totalWeight = 0;
    unities = 0;
    weight = 0;
    for (int j = 0; j < 5; j++)
    {
      if (allOrders[i].orderDrugs[j].unities != 6666)
      {
        unities = allOrders[i].orderDrugs[j].unities;
        weight = allOrders[i].orderDrugs[j].weight;
        totalWeight = totalWeight + (unities * weight);
      }
    }
    flightRange = (25000 - (5000*(float(totalWeight)/3000)))/2;

    if (float(distance)<flightRange) {check = true;}
    else
    {
      LineBreak();
      Tabulate(5);
      printf("*** LA APLICACION NO HA REGISTRADO EL PEDIDO ***");
      LineBreak();
      Tabulate(5);
      printf("================================================");
      LineBreak();
      Tabulate(5);
      printf("El peso del pedido es de %d", totalWeight);
      printf(" gramos.");
      LineBreak();
      Tabulate(5);
      printf("A ese peso le corresponde una autonomia de vuelo de: %5.1f", flightRange);
      printf(" metros.");
      LineBreak();
      Tabulate(5);
      printf("El paciente se encuentra a una distancia: %5.1f", float(distance));
      printf(" metros");
      LineBreak();
      Tabulate(5);
      printf("El paciente esta fuera de la autonomia de vuelo del dron");
      LineBreak();
      LineBreak();
      Tabulate(5);
      printf("** SE REPITE LA TOMA DE DATOS DESDE EL PRINCIPIO **");
      LineBreak();
      Tabulate(5);
      printf("Por favor, incluya menos peso en el pedido");
      LineBreak();
    }
  }

  return check;
}

void InsertOrderToPatient(OrderList allOrders, PatientList allPatients)
{
  bool flightRange;
  bool cut = false;
  int oneMoreOrder;
  int reference;

  for (int i = 0; i < 100; i++)
  {
    if (allOrders[i].refPatient == 21 && !cut)
    {
      flightRange = false;
      while (!flightRange)
      {
        reference = CheckReference(allPatients, i);
        allOrders[i].GetOrder(reference);

        flightRange = CheckFlightRange(allOrders, i, allPatients, reference);

      }
      Tabulate(5);
      oneMoreOrder = Ask("Otro pedido (S/N)? ");
      if (oneMoreOrder == 0) {cut = true;}
    }
  }
}

//---------------------------------------------All Patient------------------------------------------------
void InsertPatient(PatientList List)
{
  int answerCheck, answerNewPatient;

  answerNewPatient = 1;
  for (int i=0; i<20; i++)
  {
    if (answerNewPatient == 1)
    {
      if (strlen(List[i].id[0]) == 0)
      {
        answerCheck = 2;
        while (answerCheck != 1)
        {
          if (answerCheck == 0) {LineBreak(); printf("Vuelva a introducir los datos"); LineBreak();}
          if (i!=0) {LineBreak();}
          printf("Alta nuevo paciente. Referencia paciente: %d", i+1);
          LineBreak();
          List[i].NewPatient();

          answerCheck = Ask("Los datos son correctos? (S/N)? "); //Y->1; N->0
          if ((answerCheck == 1) && (i != 19))
          {
            answerNewPatient = Ask("Otro paciente mismo almacen? (S/N)? "); //Y->1; N->0
          }
        }
      }
    }
    if (strlen(List[19].id[0]) != 0)
    {
      printf("El sistema no almacena mas de 20 pacientes.");
      LineBreak();
    }
  }
}

bool CheckPatientList(PatientList List) //1->empty, 0->full
{
  bool empty = true;

  for (int i=0; i<20; i++)
  {
    if (empty && (strlen(List[i].id[0]) != 0))
    {
      empty = false;
    }
  }

  return empty;
}

void ShowPatientList(PatientList List)
{
  if (CheckPatientList(List))
  {
    NewLine();
    printf("El almacen selecionado no tiene pacientes registrados");
    NewLine();
  }
  else
  {
    PrintHeadShowPatientList();

    for (int i=0; i<20; i++)
    {
      if (strlen(List[i].id[0]) != 0)
      {
        List[i].ShowPatient(i+1);
        LineBreak();
      }
    }
  }
}

void PrintHeadShowPatientList()
{
  printf("Lista de pacientes y su ubicacion:");
  LineBreak();
  LineBreak();
  Tabulate(5);
  printf("Ref.  Identificador");
  Tabulate(10);
  printf("Distancia");
  Tabulate(5);
  printf("Angulo\n\n");
}

//--------------------------------------------All Orders---------------------------------------------
void ResetOrderList(OrderList allOrders)
{
  for (int i = 0; i < 100; i++)
  {
    allOrders[i].refPatient = 21;
    for (int j=0; j<5; j++)
    {
      allOrders[i].orderDrugs[j].unities = -1;
    }
  }
}

bool CheckOrderList(OrderList allOrders)  //True: full; False: empty
{
  bool full = false;

  for (int i = 0; i < 100; i++)
  {
    if (allOrders[i].refPatient != 21) {full = true;}
  }

  return full;
}

void ShowOrderList(OrderList allOrders)
{
  printf("Cliente");
  Tabulate(4);
  printf("Fecha");
  Tabulate(7);
  printf("Farmaco");
  Tabulate(12);
  printf("Peso");
  Tabulate(4);
  printf("Unidades");
  LineBreak();
  NewLine();

  for (int i = 0; i < 100; i++)
  {
    if (allOrders[i].refPatient != 21) {allOrders[i].ShowOrder();}
  }
}
