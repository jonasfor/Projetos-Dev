#include<stdio.h>
#include<string.h> //strtok
#include<stdlib.h>  //realloc
#include<sys/socket.h>
#include<netinet/in.h> //sockaddr_in
#include<arpa/inet.h>  // getsockname
#include<netdb.h>  //hostent
#include<unistd.h> //close

void pegar_whois(char *ip, char **dados);

int main(int argc, char** argv)
{
	char ip[100], *dados = NULL;
	printf("Entre com o endereco IP para o whois: ");
	scanf("%s", ip);

	pegar_whois(ip, &dados);
	printf("\n\n");
	puts(dados);
	
	free(dados);
	return 0;
}

/*Pegar o conteúdo do whois a partir do ip fornecido selecionando o servidor correto.
 Como eu não sei qual o servidor armazena as informações daquele IP então devo pegar esta 
informação no iana e a partir desta informação partir para o servidor correto. */

void pegar_whois(char *ip, char **dados)
{
	char *checa_whois = NULL, *pch, *resposta = NULL;
	if(whois_query("whois.iana.org", ip, &resposta))
	{
		printf("Pesquisa whois_query falhou!");
	}

	pch = strtok(resposta, "\n"); // a função strtok faz um parse de uma string para um token
				      // cada chamada da função strtok retorna um ponteiro para a última string
                                      // não nula contendo o próximo token.

	while(pch != NULL)
	{
		//faz a checagem da linha recebida do whois
		checa_whois = strstr(pch, "whois.");
		if(checa_whois != NULL)
		{
			break;
		}

		//analisa a próxima linha
		pch = strtok(NULL, "\n");
	}
	
	if(checa_whois != NULL)
	{
		printf("\nServidor Whois e: %s", checa_whois);
		whois_query(checa_whois, ip, dados);
	}
	else
	{
		*dados = malloc(100);
		strcpy(*dados, "Nao existem dados sobre o whois!");
	}

	return; //Não retorna nada porque a função é void.
}
		
//Executa a pesquisa whois (whois_query) em um servidor e guarda a resposta.

int whois_query(char *servidor, char *busca, char **resposta)
{
	char ip[32], mensagem[100], buffer[1500];
	int meu_socket, ler_tamanho, tamanho_total = 0;
	struct sockaddr_in destino;

	meu_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//Preparando a estrutura de conexão
	memset(&destino, 0, sizeof(destino));
	destino.sin_family = AF_INET;

	printf("\nBuscando (resolving) %s...", servidor);
	if(hostname_to_ip(servidor, ip))
	{
		printf("Falha na busca!");
		return 1;
	}

	printf("%s", ip);
	destino.sin_addr.s_addr = inet_addr( ip );
	destino.sin_port = htons( 43 );

	//Conectar ao servidor remoto. Pois já tenho o seu ip
	if(connect( meu_socket, (const struct sockaddr*)&destino, sizeof(destino)) < 0)
	{
		//checagem de erro
		perror("Falha ao conectar!");
	}

	//Enviando dados para o servidor
	printf("\nBuscando por ... %s ...", busca);
	sprintf(mensagem, "%s\r\n", busca);
	if(send(meu_socket, mensagem, strlen(mensagem), 0) < 0)
	{
		perror("Falha na funcao Send!");
	}

	//Recebendo a resposta do servidor
	while((ler_tamanho = recv(meu_socket, buffer, sizeof(buffer), 0)))
	{
		*resposta = realloc(*resposta, ler_tamanho + tamanho_total); //realocando memoria para receber a resposta
		if(*resposta == NULL)
		{
			printf("Erro na realocacao de memoria!");
		}
		
		memcpy(*resposta + tamanho_total, buffer, ler_tamanho);
		tamanho_total += ler_tamanho;
	}

	printf("Feito!!");
	fflush(stdout);

	*resposta = realloc(*resposta, tamanho_total + 1);
	*(*resposta + tamanho_total) = '\0';  //muito cuidado nesta linha para não preencher com lixo.
	
	close(meu_socket);
	return 0;
}

int hostname_to_ip(char *hostname, char* ip) 
{
	struct hostent *alvo;
	struct in_addr **addr_list;
	int i;
		
	if((alvo = gethostbyname(hostname)) == 	NULL)
	{
		//Não consegue a informação do host
		herror("Erro na funcao gethostbyname!");
		return 1;
	}
	
	addr_list = (struct in_addr **) alvo->h_addr_list;
	
	for(i = 0; addr_list[i] != NULL; i++)
	{
		//Retorna o primeiro
		strcpy(ip, inet_ntoa(*addr_list[i]));
		return 0;
	}

	return 0;
}

