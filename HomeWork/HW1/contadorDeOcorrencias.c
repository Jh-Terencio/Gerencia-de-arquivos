#include<stdio.h>
#define MAX 256

int main(int argc, char** argv)
{
    FILE *entrada;
    int cont = 0;
    int array[MAX] = {0};

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

    while(!feof(entrada)){
        fread()
    }

    fclose(entrada);

    return 0;
}
