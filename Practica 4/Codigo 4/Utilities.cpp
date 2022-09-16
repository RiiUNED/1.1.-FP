#include "Utilities.h"

void Tabulate(int space)
{
  for (int j = 0; j < space; j++)
  {
    printf(" ");
  }
}

void LineBreak()
{
  printf("\n");
}

int Ask(Text question) //Y->1; N->0
{
  bool acceptableAnswer;

  Text yesNo;
  const char yes[] = "S";
  const char no[] = "N";

  int compareYes, compareNo, round;

  acceptableAnswer = false;
  round = 1;
  while (!acceptableAnswer)
  {
    if (round != 1)
    {
      printf("Introdujo: %s", yesNo);
    }
    LineBreak();
    printf(question);
    scanf("%s", &yesNo);
    compareYes = 0;
    compareNo = 0;
    compareYes = strcmp(yesNo, yes); //S->0; N->-1
    compareNo = strcmp(yesNo, no);   //S->1; N->0
    if ((compareYes == 0 && compareNo == 1) || (compareYes == -1 && compareNo == 0))
    {
      acceptableAnswer = true;
    }
    round++;
  }

  return compareNo;
}
