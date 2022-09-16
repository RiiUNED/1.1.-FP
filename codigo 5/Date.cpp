#include "Date.h"

void SendDayMonthError(int day, Month month)
{
  LineBreak();
  Tabulate(5);
  printf("Error. Introdujo dia: %d", day);
  printf(" y mes: %d", int(month)+1);
  printf(". ");
  LineBreak();
  Tabulate(5);
  printf("No se corresponde el numero de dias con el mes introducido");
  LineBreak();
}

bool Date :: CheckLeapYear()
{
  bool check;

  if (year % 4 == 0)
  {
    if (year % 100 == 0)
    {
      if (year % 400 == 0) {check = true;}
      else {check = false;}
    }
    else { check = true; }
  }
  else
  {
    check = false;
  }

  return check;
}

bool Date :: Validate()
{
  bool leapYear, validate;
  leapYear = CheckLeapYear();

  switch (month)
  {
    case(january):
    if (day>0 && day<=31){validate = true;}
    else{SendDayMonthError(day, month);validate = false;}
    break;

    case(february):
    if (leapYear && day>0 && day<=29){validate = true;}
    else if (!leapYear && day>0 && day<=28){validate = true;}
    else{SendDayMonthError(day, month);validate = false;}
    break;
    case(march):

    if (day>0 && day<=31){validate = true;}
    else{SendDayMonthError(day, month);validate = false;}
    break;
    case(april):
    if (day>0 && day<=30){validate = true;}
    else{SendDayMonthError(day, month);validate = false;}
    break;
    case(may):
    if (day>0 && day<=31){validate = true;}
    else{SendDayMonthError(day, month);validate = false;}
    break;
    case(june):
    if (day>0 && day<=30){validate = true;}
    else{SendDayMonthError(day, month);validate = false;}
    break;
    case(july):
    if (day>0 && day<=31){validate = true;}
    else{SendDayMonthError(day, month);validate = false;}
    break;
    case(august):
    if (day>0 && day<=31){validate = true;}
    else{SendDayMonthError(day, month);validate = false;}
    break;
    case(september):
    if (day>0 && day<=30){validate = true;}
    else{SendDayMonthError(day, month);validate = false;}
    break;
    case(october):
    if (day>0 && day<=31){validate = true;}
    else{SendDayMonthError(day, month);validate = false;}
    break;
    case(november):
    if (day>0 && day<=30){validate = true;}
    else{SendDayMonthError(day, month);validate = false;}
    break;
    case(december):
    if (day>0 && day<=31){validate = true;}
    else{SendDayMonthError(day, month);validate = false;}
    break;
    default:
    LineBreak();
    Tabulate(5);
    printf("Error. Introdujo el mes: %d", int(month)+1);
    LineBreak();
    validate = false;
  }
  return validate;
}

void Date :: NewDate(Text askDay, Text askMonth, Text askYear)
{
  bool trueDate;
  int auxMonth;

  trueDate = false;
  while(!trueDate)
  {
    LineBreak();
    Tabulate(5);
    printf(askDay);
    scanf("%d", &day);
    LineBreak();
    Tabulate(5);
    printf(askMonth);
    scanf("%d", &auxMonth);
    month = Month(auxMonth-1);
    LineBreak();
    Tabulate(5);
    printf(askYear);
    scanf("%d", &year);
    trueDate = Validate();
  }

}

Date Date :: AddDays(int numberOfDays)
{
  Date futureDate;
  int deadLine;

  futureDate.day = day;
  futureDate.month = month;
  futureDate.year = year;

  deadLine = futureDate.LastDay();
  futureDate.day = futureDate.day + numberOfDays;

  while (futureDate.day > deadLine)
  {
    if (futureDate.month == Month(11))
    {
      futureDate.year = futureDate.year + 1;
      futureDate.month = Month(0);
      numberOfDays = futureDate.day - deadLine;
      futureDate.day = numberOfDays;
    }
    else
    {
    futureDate.month = Month(int(futureDate.month) + 1);
    numberOfDays = futureDate.day - deadLine;
    futureDate.day = numberOfDays;
    }
  }

  return futureDate;
}

bool Date :: EqualDates(Date dateToCompare)
{
  bool equal = false;
  bool compareDay, compareMonth, compareYear;

  compareDay = day == dateToCompare.day;
  compareMonth = int(month) == int(dateToCompare.month);
  compareYear = year == dateToCompare.year;

  if (compareDay && compareMonth && compareYear) {equal = true;}

  return equal;
}

int Date :: LastDay()
{
  int deadLine;

  bool leapYear;
  leapYear = CheckLeapYear();

  switch (month)
  {
    case(january):
    deadLine = 31;
    break;

    case(february):
    if (leapYear){deadLine = 29;}
    else{deadLine = 28;}
    break;

    case(march):
    deadLine = 31;
    break;
    case(april):
    deadLine = 30;
    break;
    case(may):
    deadLine = 31;
    break;
    case(june):
    deadLine = 30;
    break;
    case(july):
    deadLine = 31;
    break;
    case(august):
    deadLine = 31;
    break;
    case(september):
    deadLine = 30;
    break;
    case(october):
    deadLine = 31;
    break;
    case(november):
    deadLine = 30;
    break;
    case(december):
    deadLine = 31;
    break;
    default:
    printf("Error");
  }
  return deadLine;
}

void Date :: ShowDate()
{
  printf("%2d/%d/%d", day, int(month)+1, year);
}
