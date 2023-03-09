#include<stdio.h>

int main(int argc, char** argv){

    FILE *entrada, *saida;
    int c;
    int cont = 0;
    char n = '\n';

    if(argc != 2){
        fprintf(stderr,"Erro na chamada do comando.\n");
		return 1;
    }

    entrada = fopen(argv[1],"rb");
	if(!entrada)
	{
		fprintf(stderr,"Arquivo %s não pode ser aberto para leitura\n", argv[1]);
		return 1;
	}

    c = fgetc(entrada);
	while(c != EOF)
	{
        if(c == n){
           cont++; 
        }
		c = fgetc(entrada);
	}

	fclose(entrada);
    printf("\nNumero de linhas: %d\n", cont);
	return 0;
}