#pragma once
#include "Utilities.h"

typedef struct Patient
{
  Id id;
  Vector2 position;

  void NewPatient();
  void ShowPatient(int referencia);
};
