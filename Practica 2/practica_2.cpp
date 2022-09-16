/*************************************
* NOMBRE: #Ricardo#
* PRIMER APELLIDO: #Sanchez#
* EMAIL: #rsanchez628@alumno.uned.es#
*************************************/

#include <stdio.h>

int side, remainder;
int auxiliar, auxiliar_2, auxLine,leftAux;

const char basisTyp[] = "@.o.";
const char leftBasisTyp[] = ".o.@";
const char remainder1[] = "@";
const char remainder2[] = "@.";
const char leftRemainder2[] = ".@";
const char remainder3[] = "@.o";
const char leftRemainder3[] = "o.@";

int main()
{

    printf("Lado del Rombo?");
    scanf("%d", &side);

    if (side > 0 && side <= 20)
    {

      remainder = side % 4;
      printf("\n");

      // Upper Triangle
      for (int j = 0; j < side; j++)
      {

        auxiliar = (j+1)%4;
        auxLine = 0;

        for (int i = 0; i < side-(j+1); i++)
        {
          printf(" ");
          auxLine++;
        }

        if ( j < 4)
        {
          if (auxiliar  == 1)
          {
            printf("%s", remainder1);
            printf("\n");
          }
          else if (auxiliar == 2)
          {
            printf("%s", remainder2);
            printf("%s", remainder1);
            printf("\n");
          }
          else if (auxiliar == 3)
          {
            printf("%s", remainder3);
            printf("%s", leftRemainder2);
            printf("\n");
          }
          else
          {
            printf("%s", basisTyp);
            printf("%s", leftRemainder3);
            printf("\n");
          }
        }
        else
        {
          while (auxLine + 4 < side)
          {
            printf("%s", basisTyp);
            auxLine = auxLine + 4;
            leftAux++;
          }

          auxiliar_2 = (side - auxLine)%4;

          if (auxiliar_2 == 1)
          {
            printf("%s", remainder1);
            for (int k = 0; k < leftAux; k++)
            {
                printf("%s", leftBasisTyp);
            }
            printf("\n");
            leftAux = 0;
          }
          else if (auxiliar_2 == 2)
          {
            printf("%s", remainder2);
            printf("%s", remainder1);
            for (int k = 0; k < leftAux; k++)
            {
                printf("%s", leftBasisTyp);
            }
            printf("\n");
            leftAux = 0;
          }
          else if (auxiliar_2 ==3)
          {
            printf("%s", remainder3);
            printf("%s", leftRemainder2);
            for (int k = 0; k < leftAux; k++)
            {
                printf("%s", leftBasisTyp);
            }
            printf("\n");
            leftAux = 0;
          }
          else
          {
            printf("%s", basisTyp);
            printf("%s", leftRemainder3);
            for (int k = 0; k < leftAux; k++)
            {
                printf("%s", leftBasisTyp);
            }
            printf("\n");
            leftAux = 0;
          }
        }
      }

      // Down Triangle
      for (int j = 1; j<side; j++)
      {
        auxLine = side-j;
        auxiliar = (auxLine)%4;
        for (int i=0; i<j; i++)
        {
          printf(" ");
        }

        if (auxLine <= 4)
        {
          if (auxiliar  == 1)
          {
            printf("%s", remainder1);
            printf("\n");
          }
          else if (auxiliar == 2)
          {
            printf("%s", remainder2);
            printf("%s", remainder1);
            printf("\n");
          }
          else if (auxiliar == 3)
          {
            printf("%s", remainder3);
            printf("%s", leftRemainder2);
            printf("\n");
          }
          else
          {
            printf("%s", basisTyp);
            printf("%s", leftRemainder3);
            printf("\n");
          }
        }
        else
        {
          while(auxLine>4)
          {
            printf("%s", basisTyp);
            auxLine = auxLine -4;
          }
          if(auxLine == 1)
          {
            printf("%s", remainder1);
            auxLine = side - j - 1;
            while (auxLine >=4)
            {
              printf("%s", leftBasisTyp);
              auxLine = auxLine -4;
            }

          }
          else if(auxLine == 2)
          {
            printf("%s", remainder2);
            auxLine = side - j - 1;
            printf("%s", remainder1);
            auxLine = auxLine - 1;
            while (auxLine >=4)
            {
              printf("%s", leftBasisTyp);
              auxLine = auxLine -4;
            }

          }
          else if(auxLine == 3)
          {
            printf("%s", remainder3);
            auxLine = side - j - 1;
            printf("%s", leftRemainder2);
            auxLine = auxLine - 2;
            while (auxLine >=4)
            {
              printf("%s", leftBasisTyp);
              auxLine = auxLine -4;
            }

          }
          else
          {
            printf("%s", basisTyp);
            auxLine = side - j - 1;
            printf("%s", leftRemainder3);
            auxLine = auxLine - 3;
            while (auxLine >=4)
            {
              printf("%s", leftBasisTyp);
              auxLine = auxLine -4;
            }
          }
          printf("\n");
        }
      }
    }
}
