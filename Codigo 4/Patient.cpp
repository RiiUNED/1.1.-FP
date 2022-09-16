#include "Patient.h"

void Patient ::NewPatient()
{
  LineBreak();
  Tabulate(5);
  printf("Identificador (entre 1 y 20 carateres): ");
  scanf("%s%s", &id[0], &id[1]);
  LineBreak();
  position[0] = -1;
  while ((position[0] < 0) || (position[0] > 15000))
  {
    Tabulate(5);
    printf("Distancia (hasta 10000 metros a plena carga): ");
    scanf("%d", &position[0]);
    if ((position[0] < 0) || (position[0] > 15000))
    {
      Tabulate(5);
      printf("Introdujo: %d", position[0]);
      LineBreak();
      if (position[0] > 15000)
      {
        Tabulate(5);
        printf("El FarmaDron no hace portes a mas de 15000 metros.");
        LineBreak();
      }
    }
  }
  LineBreak();
  position[1] = -1;
  while ((position[1] < 0) || (position[1] > 2000))
  {
    Tabulate(5);
    printf("Angulo (entre 0 y 2000 pi / 1000 radianes): ");
    scanf("%d", &position[1]);
    if ((position[1] < 0) || (position[1] > 2000))
    {
      Tabulate(5);
      printf("Introdujo: %d", position[1]);
      LineBreak();
    }
  }
}

void Patient ::ShowPatient(int referencia)
{
  int stringLength;

  Tabulate(5);
  if ((referencia) < 10)
  {
    printf("%d", referencia);
    Tabulate(4);
  }
  else
  {
    printf("%d", referencia);
    Tabulate(3);
  }
  printf("%s %s", id[0], id[1]);
  stringLength = strlen(id[0]) + strlen(id[1]) + 1;
  Tabulate(24 - stringLength);
  printf("%9d", position[0]);
  Tabulate(5);
  printf("%6d", position[1]);
}
