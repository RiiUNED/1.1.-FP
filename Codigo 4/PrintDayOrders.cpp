#include "PrintDayOrders.h"

void PrintDayOrders(OrderList allOrders, PatientList allPatients)
{
  Date checkDate;
  int distance, angle, ud, wg, totalWeight;
  int orderInDay = 1;
  bool noOrder = true;

  LineBreak();
  printf("Lista diaria de pedidos:");
  LineBreak();
  LineBreak();

  checkDate.NewDate("Dia? ", "Mes? ", "Ano? ");

  for (int i = 0; i < 100; i++)
  {
    if (CheckOrderDate(checkDate, allOrders[i]))
    {
      noOrder = false;
      LineBreak();
      LineBreak();
      Tabulate(5);
      printf("Pedido: %d", orderInDay);
      LineBreak();
      distance = allPatients[allOrders[i].refPatient - 1].position[0];
      printf("Ubicacion destino: Distancia: %d", distance);
      angle = allPatients[allOrders[i].refPatient - 1].position[1];
      printf(" y Angulo: %d", angle);
      LineBreak();
      totalWeight = 0;
      for (int j = 0; j < 5; j++)
      {
        if ((allOrders[i].orderDrugs[j].weight * allOrders[i].orderDrugs[j].unities) <= 3000)
        {
          ud = allOrders[i].orderDrugs[j].unities;
          printf("%2d", ud);
          printf(" Unidades");
          Tabulate(8);
          printf(allOrders[i].orderDrugs[j].name);
          Tabulate(18 - strlen(allOrders[i].orderDrugs[j].name));
          printf("Peso:");
          wg = allOrders[i].orderDrugs[j].weight;
          printf("%5d", wg);
          printf(" gramos");
          LineBreak();
          totalWeight = totalWeight + (ud * wg);
        }
        if (j == 4)
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
