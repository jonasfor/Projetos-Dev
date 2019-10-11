#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
uint16_t matrizA[2][2];
uint16_t matrizB[2][2];
uint16_t matrizM[2][2];

int main()
{
    int i, j;
    uint16_t A, B;
    void multiplica();
    for (i=0;i<2;i++)
    {
            for (j=0;j<2;j++)
            {
               scanf("%d", &);
               matrizA[i][j]=A;
               A=0;
            }

    }
    for (i=0;i<2;i++)
    {
            for (j=0;j<2;j++)
            {
               fflush(stdin);
               scanf("%d", &B);
               matrizB[i][j]=B;
            }

    }
    multiplica();
    system("cls");
    for (i=0;i<2;i++)
    {
            for (j=0;j<2;j++)
            {
               printf("%d", matrizM[i][j]);
            }
            printf("\n");

    }


}
void multiplica()
{
    int i, j, k=0, parcial=0;

    for (i=0;i<2;i++)
    {
            for (j=0;j<2;j++)
            {
                parcial=parcial+(matrizA[i][j]*matrizB[j][i]);
            }
            matrizM[i][k]=parcial;
            k++;
            parcial=0;
    }
}
