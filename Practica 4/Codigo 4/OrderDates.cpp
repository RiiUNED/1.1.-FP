#include "OrderDates.h"

void OrderDates ::GetOrderDates()
{
  bool trueDate;
  int auxMonth;

  LineBreak();
  Tabulate(5);

  sendNumbers = -1;
  while (sendNumbers <= 0)
  {
    printf("Numero de envios? ");
    scanf("%d", &sendNumbers);
    if (sendNumbers <= 0)
    {
      LineBreak();
      Tabulate(5);
      printf("El sistema no puede procesar: %d", sendNumbers);
      printf(" envios.");
      LineBreak();
      Tabulate(5);
    }
  }

  if (sendNumbers == 1)
  {
    daysToAdd = 0;
    firstSendingDay.NewDate("Dia del envio? ", "Mes del envio? ", "Ano del envio? ");
  }
  else
  {
    LineBreak();
    Tabulate(5);
    daysToAdd = 16;
    while ((daysToAdd < 1) || (daysToAdd > 15))
    {
      printf("Numero de dias entre cada envio (Entre 1 y 15 dias)? ");
      scanf("%d", &daysToAdd);
      if ((daysToAdd < 1) || (daysToAdd > 16))
      {
        LineBreak();
        Tabulate(5);
        printf("El sistema no procesa %d", daysToAdd);
        printf(" dias entre envios");
        LineBreak();
        Tabulate(5);
      }
    }
    firstSendingDay.NewDate("Dia del primer envio? ", "Mes del primer envio? ", "Ano del primer envio? ");
  }
}
