/*************************************
* NOMBRE: #Ricardo#
* PRIMER APELLIDO: #Sanchez#
* EMAIL: #rsanchez628@alumno.uned.es#
*************************************/

#include <stdio.h>
#include <string.h>

typedef char TipoCadena[15];
typedef TipoCadena vectorString[12];
vectorString allMonths = {
    "ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO",
    "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};
vectorString allDays = {"LU", "MA", "MI", "JU", "VI", "SA", "DO"};

int year, month;
bool check;

const char room1[] = "  ";
const char room2[] = " | ";
const char fill1[] = " ";
const char fill2[] = " .";

bool CheckBisiesto(int aYear)
{
  bool check;

  if (aYear % 4 == 0)
  {
    if (aYear % 100 == 0)
    {
      if (aYear % 400 == 0)
      {
        check = true;
      }
      else
      {
        check = false;
      }
    }
    else
    {
      check = true;
    }
  }
  else
  {
    check = false;
  }

  return check;
}

void AskData()
{
  printf("Mes (1..12)?");
  scanf("%d", &month);
  printf("Ano (1601..3000)?");
  scanf("%d", &year);
  printf("\n");
}

void PrintHead(TipoCadena aMonth, int aYear)
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

int DaysPerMonth(int aMonth, int aYear)
{
  int dayAmount = 0;

  if (aMonth == 1)
  {
    dayAmount = dayAmount + 31;
  }
  else if (aMonth == 2 && CheckBisiesto(aYear))
  {
    dayAmount = dayAmount + 29;
  }
  else if (aMonth == 2 && !CheckBisiesto(aYear))
  {
    dayAmount = dayAmount + 28;
  }
  else if (aMonth == 3)
  {
    dayAmount = dayAmount + 31;
  }
  else if (aMonth == 4)
  {
    dayAmount = dayAmount + 30;
  }
  else if (aMonth == 5)
  {
    dayAmount = dayAmount + 31;
  }
  else if (aMonth == 6)
  {
    dayAmount = dayAmount + 30;
  }
  else if (aMonth == 7)
  {
    dayAmount = dayAmount + 31;
  }
  else if (aMonth == 8)
  {
    dayAmount = dayAmount + 31;
  }
  else if (aMonth == 9)
  {
    dayAmount = dayAmount + 30;
  }
  else if (aMonth == 10)
  {
    dayAmount = dayAmount + 31;
  }
  else if (aMonth == 11)
  {
    dayAmount = dayAmount + 30;
  }
  else
  {
    dayAmount = dayAmount + 31;
  }

  return dayAmount;
}

int FirstDay(int aMonth, int aYear)
{
  int dayAmount = 0;
  for (int i = 1601; i < aYear; i++)
  {
    if (CheckBisiesto(i))
    {
      dayAmount = dayAmount + 366;
    }
    else
    {
      dayAmount = dayAmount + 365;
    }
  }
  for (int i = 1; i < aMonth; i++)
  {
    if (i == 1)
    {
      dayAmount = dayAmount + 31;
    }
    else if (i == 2 && CheckBisiesto(aYear))
    {
      dayAmount = dayAmount + 29;
    }
    else if (i == 2 && !CheckBisiesto(aYear))
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

void FillCalendar(int theOne, int stop)
{
  int position = 0;

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
    if (i < 10)
    {
      printf("%s", fill1);
      printf("%d", i);
      position = position + 1;
    }
    else
    {
      printf("%d", i);
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
int main()
{
  AskData();
  if (month >= 1 && month <= 12 && year >= 1601 && year <= 3000)
  {
    PrintHead(allMonths[month - 1], year);
    FillCalendar(FirstDay(month, year), DaysPerMonth(month, year));
  }
}
