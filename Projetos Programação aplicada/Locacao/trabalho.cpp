#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdio_ext.h> 

using namespace std;

class cliente{

	public:

		char nome[50];
		char cpf[11];
		char telefone[12];
		int numero_cliente=1;
		void cadastrar();


};

void cliente::cadastrar(){


				system("clear");
			
				cout<<"Nome do cliente:  ";
				fgets(nome, 50, stdin);
			
				__fpurge(stdin);
			
				cout<<"\n\nCpf:   ";
				fgets(cpf, 11, stdin);
			
				__fpurge(stdin);	
			
				cout<<"\n\nTelefone:   ";
				fgets(telefone, 12, stdin);

				system("clear");
				cout<<"\n\nCliente numero: "<<numero_cliente;
				cout<<"\n\nNome: "<<nome;
				cout<<"\n\nCpf: "<<cpf;
				cout<<"\n\ntelefone:  "<<telefone;
				
}
	
int main(){

	cliente   p;
	int 	opt;

		do{
			cout<<"++++++++++++++++++++++\n";
			cout<<"+        MENU        +\n";
			cout<<"++++++++++++++++++++++\n\n\n";

			cout<<"1-Cadastrar cliente\n0-Sair\n";
			cin>>opt;
	
			__fpurge(stdin);	
		
				switch(opt){
					case 1:{
						p.cadastrar();
					  break;
					}
				}
		}while(opt!=0);
	return 0;
