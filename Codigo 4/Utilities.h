#pragma once
#include <stdio.h>
#include <string.h>

typedef char Text[100];

typedef Text Id[2];

typedef int Vector2[2];

void Tabulate(int space);

void LineBreak();

int Ask(Text question);//Y->1; N->0
