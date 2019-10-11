#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdio_ext.h> 

using namespace std;

class aluguel{
public:
	char nome[50];
	char modelo[20];
	int  n_diarias;
};

class cliente{

public:

		char nome[50];
		char cpf[11];
		char telefone[12];
		int numero_cliente;
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
}





class veiculo{

private:
	

public:
	int 	fator_disponibilidade;
	char 			   modelo[20];
	char 				 placa[7];
	int 				   diaria;
	
	void       cadastro_veiculo();
	veiculo();


};
veiculo::veiculo(){
	bzero(&modelo, 20);
	bzero(&placa, 7);
	fator_disponibilidade=0;
}

void veiculo::cadastro_veiculo(){
	
	cout << "Cadastro de novo veiculo:"<< endl << endl <<"Entre com o modelo do carro a cadastrar :" ;
	cin  >>  modelo;
	cout << "\nEntre com a placa do carro a cadastrar :" ;
	cin  >>  placa;
	cout << "\nEntre com o valor da diaria para este modelo :";
	cin  >>  diaria;
}

int compara(veiculo* veiculo_array, int pos){
	 for (int i = 0; i < 100; ++i)
	 {
	 	if (i!=pos){	
	 				
	 		 		if(strcmp(veiculo_array[i].modelo,veiculo_array[pos].modelo)==0){
	 		 			return 1;
	 		 		}
	 		 		if(strcmp(veiculo_array[i].placa,veiculo_array[pos].placa)==0){
	 		 			return 1;
	 		 		}
	 	}
	 }
	 return 0;
}

void listar_veiculos(veiculo *veiculo_array, int pos){

	for (int i = 0; i < pos; ++i)
	{
		cout <<"modelo : " << veiculo_array[i].modelo <<"\n placa : "<< veiculo_array[i].placa <<"\n"<< "diaria : "<< veiculo_array[i].diaria<<"\n\n\n\n";
	}
}
void listar_cliente(cliente *cliente_array, int pos){

	for (int i = 0; i < pos; ++i)
	{
		cout <<"Nome : " << cliente_array[i].nome <<"\n cpf : "<< cliente_array[i].cpf <<"\n"<< "telefone : "<< cliente_array[i].telefone<<"\n\n\n\n";
	}
}
void atualiza_aluguel(char *nome, char *modelo, aluguel *aluguel_array){

	
}
int busca_cliente(char *nome, cliente *cliente_array){

	for (int i = 0; i < 100; ++i)
	{
		if(strcmp(nome, cliente_array[i].nome)==0)
			return i;
	}
	return -1;

}
int busca_veiculo(char *nome, veiculo *veiculo_array){

	for (int i = 0; i < 100; ++i)
	{
		//cout << "MODELO PROCURADO : "<< nome << " VETOR ["<< i<< "] : "<< veiculo_array[i].modelo<< endl;
		if(strcmp(nome, veiculo_array[i].modelo)==0){

				return 1;
		}
	}
	return 0;

}
int main(){
	int 	  opt;
	char nome[50];
	char modelo[20];
	cliente *cliente_array;
	veiculo *veiculo_array;
	aluguel *aluguel_array;
	cliente_array = new cliente[100]();
	veiculo_array = new veiculo[100]();
	aluguel_array = new aluguel[100]();
	int indice_veiculo=0, indice_cliente=0, indice_aluguel=0;

	do{
			cout<<"++++++++++++++++++++++\n";
			cout<<"+        MENU        +\n";
			cout<<"++++++++++++++++++++++\n\n\n";

			cout<<"1-Cadastrar cliente\n2-Cadastrar veiculo\n3-Listar clientes\n4-Listar veiculos\n5-Cadastrar aluguel\n0-Sair\n";
			cin>>opt;
	
			__fpurge(stdin);	
		
				switch(opt){
					case 1:{
					 	cliente_array[indice_cliente].cadastrar();
					  	indice_cliente++;
					  break;
					}
					case 2:{
					  veiculo_array[indice_veiculo].cadastro_veiculo();
					  if (compara(veiculo_array, indice_veiculo)==1){
						cout << "Veiculo com informações ja cadastradas!\npara manter cadastro - 1\npara refazer cadastro - 2\n";
						cin >> opt;
						if(opt==2){
								veiculo_array[indice_veiculo].cadastro_veiculo();
						}
					  }
					  indice_veiculo++;
					  break;
					}
					case 3:{
					 	listar_cliente(cliente_array, indice_cliente);
					 	cout << "Tecle algo para voltar ao menu.";
					 	getchar();
					  break;
					}
					case 4:{
					 	listar_veiculos(veiculo_array, indice_veiculo);
					 	cout << "Tecle algo para voltar ao menu.";
					 	getchar();
					  break;
					}
					case 5:{
					 	cout<<"Nome do cliente:  ";
						fgets(nome, 50, stdin);
						__fpurge(stdin);

						if (busca_cliente(nome, cliente_array)!=-1){
							cout << "Cliente encontrado\n";
							strcpy(aluguel_array[indice_aluguel].nome, nome);
							indice_aluguel++;
						}
						else{
							cout << "Cliente nao cadastrado\n";
							cliente_array[indice_cliente].cadastrar();
							indice_cliente++;
						}
						while(busca_veiculo(modelo, veiculo_array)!=1){
								cout<<"Nome do veiculo:  ";
								__fpurge(stdin);
								cin >> modelo;
								 
								if (busca_veiculo(modelo, veiculo_array)==1){
										cout << "\nveiculo disponivel\n";
										strcpy(aluguel_array[indice_aluguel].modelo, nome);
										veiculo_array[busca_veiculo(nome, veiculo_array)].fator_disponibilidade=1;
										indice_aluguel++;
										cout << "tecle algo para finalizar cadastro";
										getchar();
										getchar();
										break;

								}
								else{
									cout << "\nveiculo nao disponivel\n";
								}
						}
					  break;
					}
				}
				system("clear");
		}while(opt!=0);
	return 0;
}