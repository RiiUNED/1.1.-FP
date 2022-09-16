#include "Drug.h"

void Drug ::GetData()
{
  int loop;
  bool drugWeight = false;

  LineBreak();
  Tabulate(5);
  printf("Nombre del farmaco (Entre 1 y 20 caracteres)? ");
  scanf("%s", &name);
  while (!drugWeight)
  {
    weight = 3001;
    while (weight >= 3000)
    {
      LineBreak();
      Tabulate(5);
      printf("Peso farmaco (Menor de 3000 gramos)? ");
      scanf("%d", &weight);
      if (weight >= 3000 || weight <= 0)
      {
        LineBreak();
        Tabulate(5);
        printf("No se transporta peso igual o superior a 3000 gramos.");
        LineBreak();
        LineBreak();
        Tabulate(5);
      }
    }
    loop = 0;
    unities = -1;
    while (unities <= 0)
    {
      LineBreak();
      Tabulate(5);
      printf("Unidades de farmaco? ");
      scanf("%d", &unities);
      if (unities <= 0)
      {
        LineBreak();
        Tabulate(5);
        printf("Introdujo: %d", unities);
        printf(" unidades de farmaco");
        LineBreak();
      }
      else
      {
        if ((unities * weight) <= 3000)
        {
          drugWeight = true;
        }
        else
        {
          Tabulate(5);
          printf("Introdujo: %d", unities);
          printf(" unidades * %d", weight);
          printf(" peso por unidad, Resulta: %d", unities * weight);
          printf(" gramos.");
          LineBreak();
          Tabulate(5);
          printf("El sistema no transporta mas de 3000 gramos.");
          LineBreak();
        }
      }
      loop = loop + 1;
    }
  }
}
