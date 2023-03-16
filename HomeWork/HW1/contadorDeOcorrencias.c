#include<stdio.h>
#define MAX 256

int main(int argc, char** argv)
{
    FILE *entrada;
    int c;
    int byte;
    int array[MAX];

    for(int i = 0; i < MAX; i++){
        array[i] = 0;
    }

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

    while((byte = c) != EOF){
        array[byte]++;
        c = fgetc(entrada);
    }

    fclose(entrada);

    for (int i = 0; i < MAX; i++) {
      if (array[i] != 0) {
         printf("O byte %d apareceu %d vezes no arquivo.\n", i, array[i]);
      }
   }

    return 0;
}
