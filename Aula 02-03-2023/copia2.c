#include <stdio.h>

#define TAMANHO 4096

int main(int argc, char** argv)
{
	FILE *entrada, *saida;
	char buffer[TAMANHO];
	int qtd;

	if(argc != 3)
	{
		fprintf(stderr,"Erro na chamada do comando.\n");
		fprintf(stderr,"Uso: %s [ARQUIVO ORIGEM] [ARQUIVO DESTINO].\n", argv[0]);
		return 1;
	}

	entrada = fopen(argv[1],"rb");
	if(!entrada)
	{
		fprintf(stderr,"Arquivo %s não pode ser aberto para leitura\n", argv[1]);
		return 1;
	}

	saida = fopen(argv[2],"wb");
	if(!saida)
	{
		fclose(entrada);
		fprintf(stderr,"Arquivo %s não pode ser aberto para escrita\n", argv[2]);
		return 1;
	}
	//Parametros do fread (Aonde vai ser colocado os dados vindos, Qual a unidade de leitura/tamanho do elemento (nesse exemplo 1 byte), Tamanho que quero ler e daonde eu vou ler)
	//O fwrite é a mesma coisa que o fread
	qtd = fread(buffer,sizeof(char),TAMANHO,entrada);
	while(qtd > 0)
	{
		fwrite(buffer,1,qtd,saida);
		qtd = fread(buffer,1,TAMANHO,entrada);
	}

	fclose(entrada);
	fclose(saida);
	return 0;
}

