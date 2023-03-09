#include<stdio.h>

int main( void ){
    int numConta;
    char nome[30];
    double saldoConta;

    FILE *cfPtr;

    if((cfPtr = fopen("clients.dat", "w")) == NULL){
        printf("Arquivo não pode ser aberto");
    } else {
        printf("Digite o numero da conta, o nome e o saldo. \n");
        printf("Digite fim de arquivo para terminar a entrada. \n");
        printf("?");
        scanf("%d%s%f", &numConta, &nome, &saldoConta);
    
        //eof (end of file), é um estado que indica a finalização de um arquivo.
        while(!feof(stdin)){
            fprintf(cfPtr, "%d %s %.2f\n", numConta, nome, saldoConta);
            printf("?");
            scanf("%d%s%f", &numConta, &nome, &saldoConta);
            //Para você indicar o fim do arquivo/um eof você so precisa digitar Ctrl d ou Ctrl z
        }

        fclose(cfPtr)
    }

    return 0;   
}
