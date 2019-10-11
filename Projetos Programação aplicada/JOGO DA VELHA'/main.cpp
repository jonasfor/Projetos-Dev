#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class velha {

    private :
        char matriz[3][3];
    public :
        int cond;
        velha();
        void desenha();
        void jogador1();
        void jogador2();
        int verifica();
};
velha::velha()
{
    int i,j;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            matriz[i][j]='\0';
        }
    }
}
void velha :: desenha()
{
    int i, j;
    cout << "   0 1 2\n  ------\n";
    for (i=0;i<3;i++)
    {
        cout<<i<<"| ";
        for (j=0;j<3;j++)
        {
           cout<<matriz[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void velha :: jogador1()
{
    int i, j;
    cout << "\nJOGADOR 1 :\n\n";
    cout << "Entre com a coordenada na dire허o horizontal :";
    cin>> j;
    cout << "Entre com a coordenada na dire허o vertical :";
    cin>> i;
    if (matriz[i][j]!='\0'){
        cout << "\n\nERROU A POSI플O tecle algo para continuar\n\n";
        getchar();
    }
    else{
        matriz[i][j]='O';
    }
}

void velha :: jogador2()
{
    int i, j;
    cout << "\nJOGADOR 2 :\n\n";
    cout << "Entre com a coordenada na dire허o horizontal :";
    cin>> j;
    cout << "Entre com a coordenada na dire허o vertical :";
    cin>> i;
    if (matriz[i][j]!='\0'){
        cout << "\n\nERROU A POSI플O tecle algo para continuar\n\n";
        getchar();
    }
    else
        matriz[i][j]='X';
}
int velha::verifica()
{
    int i,j;
    char str_aux[3];
    if (((matriz[0][0]=='X')&& (matriz[0][1]=='X')&&(matriz[0][2]=='X'))||((matriz[0][0]=='O')&& (matriz[0][1]=='O')&&(matriz[0][2]=='O')))
        return 1;

    if (((matriz[1][0]=='X')&&(matriz[1][1]=='X')&& (matriz[1][2]=='X'))||((matriz[1][0]=='O')&&(matriz[1][1]=='O')&& (matriz[1][2]=='O')))
        return 1;

    if (((matriz[2][0]=='X')&&(matriz[2][1]=='X')&& (matriz[2][2]=='X'))||((matriz[2][0]=='O')&&(matriz[2][1]=='O')&& (matriz[2][2]=='O')))
        return 1;

    if (((matriz[0][0]=='X')&&(matriz[1][1]=='X')&& (matriz[2][2]=='X'))||((matriz[0][0]=='O')&&(matriz[1][1]=='O')&& (matriz[2][2]=='O')))
        return 1;

    if (((matriz[0][0]=='X')&&(matriz[1][0]=='X')&& (matriz[2][0]=='X'))||((matriz[0][0]=='O')&&(matriz[1][0]=='O')&& (matriz[2][0]=='O')))
        return 1;

    if (((matriz[0][1]=='X')&&(matriz[1][1]=='X')&& (matriz[2][1]=='X'))||((matriz[0][1]=='O')&&(matriz[1][1]=='O')&& (matriz[2][1]=='O')))
        return 1;

    if (((matriz[0][2]=='X')&&(matriz[1][2]=='X')&& (matriz[2][2]=='X'))||((matriz[0][2]=='O')&&(matriz[1][2]=='O')&& (matriz[2][2]=='O')))
        return 1;
}
int main()
{
    velha obj;
    int cond=0;
    while(cond!=1)
    {
        cond=obj.verifica();
        if (cond==1)
        {
            break;
        }
        obj.desenha();
        obj.jogador1();
        system("cls");
        cond=obj.verifica();
        if (cond==1)
        {
            break;
        }
        obj.desenha();
        obj.jogador2();
        system("cls");
        cond=obj.verifica();

    }
    obj.desenha();
    cout<<"\nACABOU\n";
    return 0;
}
