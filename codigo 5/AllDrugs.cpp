#include "AllDrugs.h"

void InsertDrug(DrugList drugList)
{
  bool newDrug;
  int loop, totalWeight, loopWeight;

  newDrug = 1;
  loop = 0;

  for (int i = 0; i < 5; i++)
  {
    drugList[i].unities = -1;
  }

  while (newDrug == 1)
  {
    if (loop < 5)
    {
      totalWeight = 3001;
      while(totalWeight>3000)
      {
          drugList[loop].GetData();
          totalWeight = 0;
          for(int i = 0; i<=loop; i++)
          {
            totalWeight = totalWeight + (drugList[i].weight*drugList[i].unities);
          }

          if (totalWeight>3000)
          {
            LineBreak();
            Tabulate(5);
            printf("El peso del pedido excede 3000 gramos.");
            LineBreak();
            Tabulate(5);
            printf("El pedido actual puede incluir farmacos");
            loopWeight = drugList[loop].weight*drugList[loop].unities;
            printf(" de peso menor o igual a: %d", 3000-(totalWeight-loopWeight));
            LineBreak();
          }
      }

      loop = loop + 1;
      Tabulate(5);
      if (totalWeight<3000){newDrug = Ask("Otro farmaco (S/N)? ");}
      else
      {
        if (loop<5)
        {
          LineBreak();
          Tabulate(5);
          printf("El peso del pedido es igual a 3000 gramos");
          LineBreak();
          Tabulate(5);
          printf("No se admiten mas farmacos en el pedido");
          LineBreak();
          newDrug=0;
        }
      }
    }
    else
    {
      newDrug = 0;
      printf("El sistema no admite mas de 5 farmacos por pedido.");
    }
  }
}
