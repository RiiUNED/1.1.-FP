#include "PrintCalendar.h"

typedef Text Text7[7];
Text7 allDays = {"LU", "MA", "MI", "JU", "VI", "SA", "DO"};

typedef Text Text12[12];
Text12 allMonths = {
    "ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO",
    "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};

const char room1[] = "  ";
const char room2[] = " | ";
const char fill1[] = " ";
const char fill2[] = " .";

Date AskPrintCalendarDate()
{
  int auxMonth;
  Date calendarDate;

  auxMonth = 0;
  while ((auxMonth < 1) || (auxMonth > 12))
  {
    printf("Seleccion Mes? ");
    scanf("%d", &auxMonth);
    if (auxMonth < 1 || auxMonth > 12)
    {
      printf("Error. Introdujo: %d", auxMonth);
      LineBreak();
    }
  }
  calendarDate.month = Month(auxMonth - 1);
  LineBreak();
  printf("Seleccion Ano? ");
  scanf("%d", &calendarDate.year);

  return calendarDate;
}

void PrintHead(Text aMonth, int aYear)
{
  typedef char tooString[100];
  tooString Head;

  strcpy(Head, allDays[0]);
  for (int i = 1; i < 7; i++)
  {
    if (i != 5)
    {
      strcat(Head, room1);
    }
    else
    {
      strcat(Head, room2);
    }
    strcat(Head, allDays[i]);
  }
  printf("%s", aMonth);
  for (int i = 0; i < (strlen(Head) - strlen(aMonth) - 4); i++)
  {
    printf(" ");
  }
  printf("%d", aYear);
  printf("\n");
  for (int i = 0; i < strlen(Head); i++)
  {
    printf("=");
  }
  printf("\n");
  printf("%s", Head);
  printf("\n");
  for (int i = 0; i < strlen(Head); i++)
  {
    printf("=");
  }
  printf("\n");
}

int FirstDay(Date aDate)
{
  int dayAmount = 0;
  Date auxDate;
  for (int i = 1601; i < aDate.year; i++)
  {
    auxDate.year = i;
    if (auxDate.CheckLeapYear())
    {
      dayAmount = dayAmount + 366;
    }
    else
    {
      dayAmount = dayAmount + 365;
    }
  }
  for (int i = 1; i < aDate.month + 1; i++)
  {
    if (i == 1)
    {
      dayAmount = dayAmount + 31;
    }
    else if (i == 2 && aDate.CheckLeapYear())
    {
      dayAmount = dayAmount + 29;
    }
    else if (i == 2 && (!aDate.CheckLeapYear()))
    {
      dayAmount = dayAmount + 28;
    }
    else if (i == 3)
    {
      dayAmount = dayAmount + 31;
    }
    else if (i == 4)
    {
      dayAmount = dayAmount + 30;
    }
    else if (i == 5)
    {
      dayAmount = dayAmount + 31;
    }
    else if (i == 6)
    {
      dayAmount = dayAmount + 30;
    }
    else if (i == 7)
    {
      dayAmount = dayAmount + 31;
    }
    else if (i == 8)
    {
      dayAmount = dayAmount + 31;
    }
    else if (i == 9)
    {
      dayAmount = dayAmount + 30;
    }
    else if (i == 10)
    {
      dayAmount = dayAmount + 31;
    }
    else
    {
      dayAmount = dayAmount + 30;
    }
  }

  dayAmount = dayAmount % 7;

  return dayAmount;
}

void FillCalendar(int theOne, int stop, Date aDate, OrderList allOrders)
{
  int position = 0;
  bool anyInList;

  for (int i = 0; i < theOne; i++)
  {
    printf("%s", fill2);
    if (position == 4)
    {
      printf("%s", room2);
    }
    else
    {
      printf("%s", room1);
    }
    position = position + 1;
  }

  for (int i = 1; i <= stop; i++)
  {
    aDate.day = i;
    if (i < 10)
    {
      printf("%s", fill1);
      anyInList = false;
      for (int i = 0; i < 100; i++)
      {
        if (!anyInList)
        {
          anyInList = CheckOrderDate(aDate, allOrders[i]);
        }
      }
      if (anyInList)
      {
        printf("%d", i);
      }
      else
      {
        printf("-");
      }
      position = position + 1;
    }
    else
    {
      anyInList = false;
      for (int i = 0; i < 100; i++)
      {
        if (!anyInList)
        {
          anyInList = CheckOrderDate(aDate, allOrders[i]);
        }
      }
      if (anyInList)
      {
        printf("%d", i);
      }
      else
      {
        printf("--");
      }
      position = position + 1;
    }

    if (position == 5 || (position > 7 && position % 7 == 5))
    {
      printf("%s", room2);
    }
    else
    {
      printf("%s", room1);
    }
    if (position % 7 == 0)
    {
      printf("\n");
    }
  }

  while (position % 7 != 0)
  {
    printf("%s", fill2);
    if (position % 7 == 4)
    {
      printf("%s", room2);
    }
    else
    {
      printf("%s", room1);
    }
    position = position + 1;
  }
}

void PrintCalendar(OrderList allOrders)
{
  Date calendarDate;
  int days, fDay;

  LineBreak();
  printf("Calendario mensual de pedidos:");
  LineBreak();

  calendarDate = AskPrintCalendarDate();
  LineBreak();
  PrintHead(allMonths[int(calendarDate.month)], calendarDate.year);
  LineBreak();
  LineBreak();

  days = calendarDate.LastDay();

  fDay = FirstDay(calendarDate);

  FillCalendar(fDay, days, calendarDate, allOrders);
}
