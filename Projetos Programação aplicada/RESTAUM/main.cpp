#include <iostream>
#include <stdlib.h>

using namespace std;
class tabuleiro {
private :
    char **campo;
public :
    void Desenha_campo();
    void Aloca_campo();
    void Inicializa_campo();
};
void tabuleiro::Aloca_campo()
{
    campo=(char**)calloc(7, sizeof(char*));
    for (int i=0;i<7;i++)
        campo[i]=(char*)calloc(7, sizeof(char));
}
void tabuleiro::Inicializa_campo()
{

    for (int i=0;i<7;i++)
        for (int j=0;j<7;j++){
            if (((i>=0)&&(i<=1))&&((j>=2)&&(j<=4)))
                campo[i][j]='X';
            if (((i>1)&&(i<5))&&((j>=0)&&(j<=7)))
                campo[i][j]='X';
            if (((i>=5)&&(i<=7))&&((j>=2)&&(j<=4)))
                campo[i][j]='X';
        }
        campo[3][3]='\0';
}
void tabuleiro::Desenha_campo()
{

    for (int i=0;i<7;i++){
        for (int j=0;j<7;j++){
                cout<< campo[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    tabuleiro T;
    T.Aloca_campo();
    T.Inicializa_campo();
    cout << "RESTA UM!\n" << endl;
    T.Desenha_campo();
    return 0;
}
