#pragma once
#include <math.h>
#include "AllWarehouseManager.h"

typedef float Float2[2];

//-------------------------------------Order List---------------------------------------------------

typedef struct NodeOrder
{
  Order dayOrder;
  NodeOrder* next;
};

typedef NodeOrder* PointerOrder;

PointerOrder GenerateDayOrdersList(PointerOrder aPointer, Order aOrder);
PointerOrder GenerateOrderedDayOrdersList(PointerOrder aPointer, Order aOrder, PatientList patientList);
Order GetOrderByListPosition(PointerOrder aPointer, int position);
int GetListDimension(PointerOrder aPointer);
PointerOrder RemoveOrderByListPosition(PointerOrder aPointer, int position);

//-------------------------------------Integer List---------------------------------------------------

typedef struct NodeInt
{
  int integer;
  NodeInt* next;
};

typedef NodeInt* PointerInt;

// Angle
PointerInt GenerateAngleList(PointerInt aPointer, int anAngle);

// Arc
PointerInt GenerateArcList(PointerInt aPointer);
int MaxArcPosition(PointerInt aPointer);

//------------------------------------Coordinate---------------------------------------------

void ToCartesian(Float2 &position);
void ToPolar(Float2 &position);
void NewDirection(Float2 &direction, Float2 destination);

//------------------------------------Info List------------------------------------------

typedef struct VertexInfo
{
    int refPatientOrigin;
    int refPatientDestination;
    Float2 routeDirection;
    float routeDistance;
    Float2 warehouseBack;
    int vertexWeight;
    int routeWeight;
};

typedef struct NodeVertexInfo
{
  VertexInfo vertex;
  NodeVertexInfo* next;
};

typedef NodeVertexInfo* PointerVertex;

PointerVertex GenerateRoute(PointerVertex aRoute, VertexInfo info);
VertexInfo GetVertexByListPosition(PointerVertex aPointer, int position);
int GetListDimensionRoute(PointerVertex aPointer);
PointerVertex MergeVertex (PointerVertex printRoute);
