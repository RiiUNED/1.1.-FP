#pragma once
#include "Utilities.h"

typedef enum Month
{
  january,
  february,
  march,
  april,
  may,
  june,
  july,
  august,
  september,
  october,
  november,
  december
};

typedef struct Date
{
  int day;
  Month month;
  int year;

  void NewDate(Text askDay, Text askMonth, Text askYear);
  bool Validate();
  int LastDay();
  Date AddDays(int numberOfDays);
  bool EqualDates(Date dateToCompare);
  bool CheckLeapYear();
};
