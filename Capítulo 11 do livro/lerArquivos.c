#include<stdio.h>

int main(void){
    int numConta;
    char nome[30];
    double saldoConta;

    FILE *cfPtr;

    if((cfPtr = fopen("clients.dat", "r")) == NULL){
        printf("O arquivo não pode ser aberto");
    } else {
        printf("%-10s%-13s%s\n", "numConta", "nome", "saldoConta");
        fscanf(cfPtr, "%d%s%f", &numConta, &nome, &saldoConta);
        
        //Nesse caso o eof fecha quando o arquivo termina, como ele recebe como argumento o ponteiro para o arquivo, quando esse arquivo termina o eof fecha.
        while(!feof(cfPtr)){
            printf("%-10s%-13s%s\n", "numConta", "nome", "saldoConta");
            fscanf(cfPtr, "%d%s%f", &numConta, &nome, &saldoConta);
        }

        fclose(cfPtr);
    }

    return 0;
}
