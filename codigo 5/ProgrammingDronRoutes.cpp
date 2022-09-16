#include "ProgrammingDronRoutes.h"

typedef Order Order2[2];

void VectorAssigment(Float2 vector1, Float2 vector2)
{
  for (int i=0; i<2; i++)
  {
    vector1[i] = vector2[i];
  }
}

int GetOrderWeight(Order anOrder)
{
  int orderWeight = 0;

  for(int i=0; i<5; i++)
  {
    if (anOrder.orderDrugs[i].unities!=-1)
    {
      orderWeight = orderWeight
        + (anOrder.orderDrugs[i].weight*anOrder.orderDrugs[i].unities);
    }
  }

  return orderWeight;
}

void PrintList(int &printCounter, int listDimension,
  PointerVertex route, PointerVertex printRoute,
  Float2 warehouseLocation)
{
  int aux, weight;
  Float2 auxF2;
  VertexInfo vertexInfo;

  LineBreak();
  LineBreak();
  Tabulate(5);
  printf("Ruta %d", printCounter);
  printCounter = printCounter + 1;
  if (listDimension == 1)
  {
    vertexInfo = GetVertexByListPosition(route, listDimension);
    weight = vertexInfo.routeWeight;
    vertexInfo = GetVertexByListPosition(route, 1);
    printf("\nOrigen a Cliente%d    -- ", vertexInfo.refPatientDestination);
    printf("Distancia recorrida: %5d Angulo: %5d  ",
      int(vertexInfo.routeDirection[0]), int(vertexInfo.routeDirection[1]));
    printf("Peso: %5d\n", weight);
    weight = weight - vertexInfo.vertexWeight;

    ToCartesian(auxF2);
    NewDirection(auxF2, warehouseLocation);
    printf("\nCliente%d a Origen    -- ", vertexInfo.refPatientDestination);
    printf("Distancia recorrida: %5d Angulo: %5d  ",
      int(vertexInfo.warehouseBack[0]), int(vertexInfo.warehouseBack[1]));
    printf("Peso: %5d\n", weight);
    printf("Distancia total de la ruta: %d",
      int(vertexInfo.routeDistance+vertexInfo.warehouseBack[0]));
    LineBreak();
  }
  else
  {
    aux = GetListDimensionRoute(printRoute);
    vertexInfo = GetVertexByListPosition(printRoute, aux);
    weight = vertexInfo.routeWeight;
    for(int i=1; i<=aux; i++)
    {
      vertexInfo = GetVertexByListPosition(printRoute, i);
      if (vertexInfo.refPatientOrigin == -1)
      {
        printf("\nOrigen a Cliente%d    -- ", vertexInfo.refPatientDestination);
        printf("Distancia recorrida: %5d Angulo: %5d  ",
          int(vertexInfo.routeDirection[0]), int(vertexInfo.routeDirection[1]));
        printf("Peso: %5d\n", weight);
        weight = weight - vertexInfo.vertexWeight;
        if (aux==1)
        {
          VectorAssigment(auxF2,vertexInfo.routeDirection);
          ToCartesian(auxF2);
          NewDirection(auxF2, warehouseLocation);
          printf("\nCliente%d a Origen    -- ", vertexInfo.refPatientDestination);
          printf("Distancia recorrida: %5d Angulo: %5d  ",
            int(vertexInfo.warehouseBack[0]), int(vertexInfo.warehouseBack[1]));
          printf("Peso: %5d\n", weight);
          printf("Distancia total de la ruta: %d",
            int(vertexInfo.routeDistance+vertexInfo.warehouseBack[0]));
          LineBreak();
        }
      }
      else
      {
        printf("\nCliente %d a Cliente%d -- ",
          vertexInfo.refPatientOrigin,
          vertexInfo.refPatientDestination);
        printf("Distancia recorrida: %5d Angulo: %5d  ",
          int(vertexInfo.routeDirection[0]), int(vertexInfo.routeDirection[1]));
        printf("Peso: %5d\n", weight);
        weight = weight - vertexInfo.vertexWeight;
        if (i==aux)
        {
          VectorAssigment(auxF2,vertexInfo.routeDirection);
          ToCartesian(auxF2);
          NewDirection(auxF2, warehouseLocation);
          printf("\nCliente%d a Origen    -- ", vertexInfo.refPatientDestination);
          printf("Distancia recorrida: %5d Angulo: %5d  ",
            int(vertexInfo.warehouseBack[0]), int(vertexInfo.warehouseBack[1]));
          printf("Peso: %5d\n", weight);
          printf("Distancia total de la ruta: %d",
            int(vertexInfo.routeDistance+vertexInfo.warehouseBack[0]));
          LineBreak();
        }
      }
    }
  }
}

void ProgrammingDronRoutes(AllManager allManager)
{
  Date checkDate;
  WarehouseManager aManager;
  int managerPosition, listDimension, startingPosition, counter;
  int orderWeight, weightTotal, position, printCounter;
  float distanceTotal, flightRange;
  PointerOrder dayOrderList, routeOrderList;
  PointerInt angleList, arcList;
  Order2 auxOrder;
  Order orderNull;
  bool voidList = true;
  Float2 patientOrigin, patientDestination, warehouseLocation, originToWarehouse;
  VertexInfo vertexInfo;
  PointerVertex route, printRoute;

/// 1.- Settings
  orderNull.refPatient = -1;

  warehouseLocation[0] = 0;
  warehouseLocation[1] = 0;

  Title("Programar rutas diarias del dron:");

  GetManagerPosition(allManager, managerPosition);

  aManager = allManager[managerPosition];

  checkDate.NewDate("Dia? ","Mes? ","Ano? ");

/// 2.- Getting day orders ordered by patient's angle
  dayOrderList = NULL;
  for (int i = 0; i<100; i++)
  {
    if(CheckOrderDate(checkDate, aManager.orderList[i]))
    {
      voidList = false;
      dayOrderList = GenerateOrderedDayOrdersList(dayOrderList,
        aManager.orderList[i],
        aManager.patientList);
    }
  }

  if (!voidList)
  {
    listDimension = GetListDimension(dayOrderList);

/// 3.- Dimissing bigger arch
    angleList = NULL;
    for (int i=0; i<listDimension; i++)
    {
      auxOrder[1] = GetOrderByListPosition(dayOrderList, i+1);
      angleList = GenerateAngleList(angleList,
        aManager.patientList[auxOrder[1].refPatient-1].position[1]);
    }

    arcList = GenerateArcList(angleList);

    startingPosition = MaxArcPosition(arcList);

/// 4.- New Order's order
    routeOrderList = NULL;
    counter = listDimension;
    for (int i=startingPosition; i<=listDimension; i++)
    {
      auxOrder[0] = GetOrderByListPosition(dayOrderList, i);
      routeOrderList = GenerateDayOrdersList(routeOrderList, auxOrder[0]);
      counter = counter - 1;
    }
    for (int i=0; i<counter; i++)
    {
      auxOrder[0] = GetOrderByListPosition(dayOrderList, i+1);
      routeOrderList = GenerateDayOrdersList(routeOrderList, auxOrder[0]);
    }

/// 5.- Route's Info
    printCounter = 1;
    while(listDimension>0)
    {
      distanceTotal = 0;
      weightTotal = 0;
      route = NULL;

/// 5.1.- Generating Vertex Info
      for (int i = 1; i<=listDimension; i++)
      {
        orderWeight = 0;
        /// 5.1.1.- Getting order from list
        auxOrder[1] = GetOrderByListPosition(routeOrderList, i);

        /// 5.1.2.- Getting data from order
        /// 5.1.2.1.- Location
        patientDestination[0] = float(aManager.patientList[auxOrder[1].refPatient-1].position[0]);
        patientDestination[1] = float(aManager.patientList[auxOrder[1].refPatient-1].position[1]);
        /// 5.1.2.2.- Weight
        orderWeight = GetOrderWeight(auxOrder[1]);
        weightTotal = weightTotal + orderWeight;
        /// 5.1.2.3.- Distance.
        if (i==1)
        {
          VectorAssigment(patientOrigin, warehouseLocation);
          auxOrder[0] = orderNull;
        }
        ToCartesian(patientOrigin);
        ToCartesian(patientDestination);
        VectorAssigment(originToWarehouse, patientDestination);
        NewDirection(patientOrigin, patientDestination);
        NewDirection(originToWarehouse, warehouseLocation);
        distanceTotal = distanceTotal + patientOrigin[0];
        ToPolar(patientDestination);

        /// 5.2.- Setting Node's Info data
        vertexInfo.refPatientOrigin = auxOrder[0].refPatient;
        vertexInfo.refPatientDestination = auxOrder[1].refPatient;
        VectorAssigment(vertexInfo.routeDirection, patientOrigin);
        vertexInfo.routeDistance = distanceTotal;
        VectorAssigment(vertexInfo.warehouseBack, originToWarehouse);
        vertexInfo.vertexWeight = orderWeight;
        vertexInfo.routeWeight = weightTotal;

        /// 5.3.- Setting Route's Info
        route = GenerateRoute(route, vertexInfo);

        /// 5.4.- Setting new loop
        VectorAssigment(patientOrigin, patientDestination);
        auxOrder[0] = auxOrder[1];
      }

      /// 6.- Generating Print List
      printRoute = NULL;
      for (int i=1; i<=listDimension; i++)
      {
        vertexInfo = GetVertexByListPosition(route, i);
        flightRange = (25000 - (5000*(float(vertexInfo.routeWeight)/3000)));
        if (vertexInfo.routeDistance+vertexInfo.warehouseBack[0]<int(flightRange)
          && vertexInfo.routeWeight<=3000)
        {
          printRoute = GenerateRoute(printRoute, vertexInfo);
          position = i;
        }
      }

      /// 7.- Merge Vertex
      if (listDimension>1){printRoute = MergeVertex(printRoute);}


      /// 8.- Printing List
      PrintList(printCounter, listDimension, route, printRoute, warehouseLocation);

      /// 9.- Removing printed orders
      if (position<listDimension)
      {
        for (int i=0; i<position; i++)
        {
          routeOrderList = RemoveOrderByListPosition(routeOrderList, 1);
        }
        listDimension = GetListDimension(routeOrderList);
      }
      else
      {
        listDimension = 0;
      }
    }
  }
  else
  {
    NewLine();
    LineBreak();
    printf("el almacen selecionado no tiene envios programados en la fecha consultada.");
  }
}



