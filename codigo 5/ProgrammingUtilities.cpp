#include "ProgrammingUtilities.h"

///--------------------------- Order List -----------------------------------

PointerOrder GenerateDayOrdersList(PointerOrder aPointer, Order aOrder)
{
  PointerOrder first, cursor, newNodeOrder;
  newNodeOrder = new NodeOrder;

  newNodeOrder->dayOrder = aOrder;
  newNodeOrder->next = NULL;

  first = aPointer;

  if (aPointer == NULL)
  {
    first = newNodeOrder;
    newNodeOrder->next = NULL;
  }
  else
  {
    cursor = first;
    if (cursor->next == NULL)
    {
      cursor->next = newNodeOrder;
    }
    else
    {
      while(cursor->next != NULL)
      {
        cursor = cursor->next;
      }
      cursor->next = newNodeOrder;
    }
  }

  return first;
}

PointerOrder GenerateOrderedDayOrdersList(PointerOrder aPointer, Order aOrder, PatientList patientList)
{
  int first_angle, new_angle, cursor_angle;
  PointerOrder previous, first, cursor, newNodeOrder;
  bool breaker;

  newNodeOrder = new NodeOrder;

  newNodeOrder->dayOrder = aOrder;
  new_angle = patientList[newNodeOrder->dayOrder.refPatient-1].position[1];
  newNodeOrder->next = NULL;

  first = aPointer;
  cursor = first;

  if (first == NULL)
  {
    first = newNodeOrder;
  }
  else
  {
    breaker = false;
    first_angle = patientList[first->dayOrder.refPatient-1].position[1];

    if (first_angle > new_angle)
    {
      first = newNodeOrder;
      newNodeOrder->next = cursor;

      breaker = true;
    }
    else
    {
      while(cursor->next != NULL && !breaker)
      {
        previous = cursor;
        cursor = cursor->next;
        cursor_angle = patientList[cursor->dayOrder.refPatient-1].position[1];

        if (cursor_angle > new_angle)
        {
          previous->next = newNodeOrder;
          newNodeOrder->next = cursor;

          breaker = true;
        }
        else if (cursor->next == NULL)
        {
          cursor->next = newNodeOrder;
          newNodeOrder->next = NULL;
        }
      }
      if (first == cursor)
      {
        if (cursor_angle > new_angle)
        {
          first = newNodeOrder;
          newNodeOrder->next = cursor;
        }
        else
        {
          cursor->next = newNodeOrder;
          newNodeOrder->next = NULL;
        }
      }
    }

  }
  return first;
}

Order GetOrderByListPosition(PointerOrder aPointer, int position)
{
  PointerOrder cursor;
  Order auxOrder;

  cursor = aPointer;

  if (position > 1)
  {
    for (int i=0; i<position-1; i++)
    {
      cursor = cursor->next;
    }
    if (cursor != NULL)
    {
      auxOrder = cursor->dayOrder;
    }
  }
  else
  {
    cursor = aPointer;
  }

  return cursor->dayOrder;
}

int GetListDimension(PointerOrder aPointer)
{
  PointerOrder cursor;
  int dimension = 1;

  cursor = aPointer;
  while(cursor->next != NULL)
  {
    cursor = cursor->next;
    dimension = dimension + 1;
  }

  return dimension;
}
PointerOrder RemoveOrderByListPosition(PointerOrder aPointer, int position)
{
  int counter;
  PointerOrder first, cursor, back;

  first = aPointer;
  cursor = first;
  counter = 1;

  if (position == 1)
  {
    first = first->next;
  }
  else
  {
    while (cursor->next != NULL && position!=1)
    {
      if (counter == position)
      {
        back->next = cursor->next;
      }
      else
      {
        back = cursor;
        cursor = cursor->next;
      }
      counter = counter + 1;
    }
  }

  if (position == counter && position != 1)
  {
    back->next = NULL;
  }

  return first;
}

///--------------------------- Integer List -----------------------------------
//Angle
PointerInt GenerateAngleList(PointerInt aPointer, int anAngle)
{
  PointerInt first, cursor, newNodeInt;
  newNodeInt = new NodeInt;

  newNodeInt->integer = anAngle;
  newNodeInt->next = NULL;

  first = aPointer;

  if (aPointer == NULL)
  {
    first = newNodeInt;
    newNodeInt->next = NULL;
  }
  else
  {
    cursor = first;
    if (cursor->next == NULL)
    {
      cursor->next = newNodeInt;
    }
    else
    {
      while(cursor->next != NULL)
      {
        cursor = cursor->next;
      }
      cursor->next = newNodeInt;
    }
  }

  return first;
}

//Arc
PointerInt GenerateArcList(PointerInt aPointer)
{
  PointerInt first, arcCursor, pArcNew, pAngle0, pAngle1;

  pAngle0 = aPointer;
  first = new NodeInt;
  first->next = NULL;

  if (pAngle0->next == NULL)
  {
    first->integer = 0;
    first->next = NULL;
  }
  else
  {
    while(pAngle0->next != NULL)
    {
      pAngle0 = pAngle0->next;
    }

    pAngle1 = aPointer;
    first->integer = (2000 - pAngle0->integer) + pAngle1->integer;
    arcCursor = first;

    while(pAngle1->next!=NULL)
    {
      pArcNew = new NodeInt;
      pArcNew->next = NULL;
      arcCursor->next = pArcNew;
      pAngle0 = pAngle1;
      pAngle1 = pAngle1->next;
      pArcNew->integer = pAngle1->integer - pAngle0->integer;
      arcCursor = pArcNew;
    }
  }

  return first;
}

int MaxArcPosition(PointerInt aPointer)
{
  int position;
  PointerInt cursor;
  Vector2 max;

  cursor = aPointer;
  max[1] = 1;
  position = 1;

  if (cursor->next != NULL)
  {
    max[0] = cursor->integer;

    while(cursor->next != NULL)
    {
      cursor = cursor->next;
      position = position + 1;

      if (cursor->integer > max[0])
      {
        max[0] = cursor->integer;
        max[1] = position;
      }
    }
  }

  return max[1];
}

///--------------------------- Coordinates -----------------------------------

void ToCartesian(Float2 &position)
{
  const float pi = 3.1416;
  float aux;

  position[1] = (position[1] * pi)/float(1000);
  aux = position[0];

  position[0] = position[0] * cos(position[1]);
  position[1] = aux * sin(position[1]);
}

void ToPolar(Float2 &position)
{
  float aux_0, aux_1;
  const float pi = 3.1416;

  if (position[0]!=0 || position[1]!=0)
  {
    aux_0 = position[0];
    aux_1 = position[1];
    position[0] = sqrt(position[0]*position[0] + position[1]*position[1]);
    position[1] = atan(position[1]/aux_0);

    position[1] = (position[1] * float(1000))/pi;
    if (position[1]<0) {position[1]= -1*position[1];}

    if (aux_0<=0 && aux_1>=0) {position[1] = 1000 - position[1];}
    else if (aux_0<=0 && aux_1<=0) {position[1] = 1000 + position[1];}
    else if (aux_0>=0 && aux_1<=0) {position[1] = 2000 - position[1];}

    if (position[1]==2000) {position[1]=0;}
  }

}

void NewDirection(Float2 &direction, Float2 destination)
{
  float delta_0, delta_1;

  delta_0 = direction[0] - destination[0];
  if (delta_0<0) {delta_0 = -1*delta_0;}
  delta_1 = direction[1] - destination[1];
  if (delta_1<0) {delta_1 = -1*delta_1;}

  if (delta_0>0.25 && delta_1>0.25)
  {
    for (int i=0; i<2; i++)
    {
      direction[i] = destination[i] - direction[i];
    }
  }
  else
  {
    for (int i=0; i<2; i++)
    {
      direction[i] = 0;
    }
  }

  ToPolar(direction);
}

///----------------------------- Info -----------------------------------

PointerVertex GenerateRoute(PointerVertex aRoute, VertexInfo info)
{
  PointerVertex first, cursor, newVertex;

  newVertex = new NodeVertexInfo;
  newVertex->vertex = info;
  newVertex->next = NULL;

  first = aRoute;

  if (first == NULL)
  {
    first = newVertex;
  }
  else
  {
    cursor = first;
    while (cursor->next != NULL)
    {
      cursor = cursor->next;
    }
    cursor->next = newVertex;
  }

  return first;
}

VertexInfo GetVertexByListPosition(PointerVertex aPointer, int position)
{
  PointerVertex cursor;
  VertexInfo auxVertex;

  cursor = aPointer;

  if (position > 1)
  {
    for (int i=0; i<position-1; i++)
    {
      cursor = cursor->next;
    }
    if (cursor != NULL)
    {
      auxVertex = cursor->vertex;
    }
  }

  return cursor->vertex;
}

int GetListDimensionRoute(PointerVertex aPointer)
{
  PointerVertex cursor;
  int dimension = 1;

  cursor = aPointer;

  while(cursor->next != NULL)
  {
    cursor = cursor->next;
    dimension = dimension + 1;
  }

  return dimension;
}

PointerVertex MergeVertex (PointerVertex printRoute)
{
  PointerVertex first, cursor, back;

  first = printRoute;
  cursor = first;

  while (cursor->next != NULL)
  {
    if (cursor->vertex.routeDirection[0] == 0 && cursor->vertex.routeDirection[1] == 0)
    {
      back->vertex.vertexWeight = back->vertex.vertexWeight + cursor->vertex.vertexWeight;
      back->vertex.routeWeight = cursor->vertex.routeWeight;
      back->next = cursor->next;
      cursor = cursor->next;
    }
    else
    {
      back = cursor;
      cursor = cursor->next;
    }
  }

  if (cursor->vertex.routeDirection[0] == 0 && cursor->vertex.routeDirection[1] == 0)
  {
    back->vertex.vertexWeight = back->vertex.vertexWeight + cursor->vertex.vertexWeight;
    back->vertex.routeWeight = cursor->vertex.routeWeight;
    back->next = NULL;
  }

  return first;
}
