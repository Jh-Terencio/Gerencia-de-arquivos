#include<stdio.h>

typedef struct _Registro Registro;

struct _Registro{ //15+20+11+1+40+1 = 88
    char cpf[15];
    char curso[20];
    char dataNascimento[11];
    char sexo;
    char email[40];
    char opcaoQuadro;
};

int main(int argc, char** argv){

    //Criamos o ponteiros para os respectivos arquivos
    FILE *candidatos2021, *candidatos2022, *candidatosGeral;

    //criamos duas variaveis do tipo endereço
    Registro r2021, r2022;

    //Lê o primeiro registro de cada arquivo
    fread(&r2021, sizeof(Registro), 1, candidatos2021);
    fread(&r2022, sizeof(Registro), 1, candidatos2022);


    //lendo e criando os arquivos
    candidatos2021 = fopen("candidatos2021.dat", "rb");
    candidatos2022 = fopen("candidatos2022.dat", "rb");
    candidatosGeral = fopen("candidatosGeral.dat", "wb");

    //Verificando se o arquivo não está vazio
    if(candidatos2021 == NULL && candidatos2022 == NULL){
        printf("Erro na leitura dos arquivos");
        return 1;
    }

     while(!feof(candidatos2021) && !feof(candidatos2022)){
        if(strncmp(r2021.cpf, r2022.cpf, 15) == 0){
            fwrite(&r2021, sizeof(Registro), 1, candidatosGeral);
            fread(&r2021, sizeof(Registro), 1, candidatos2021);
            fread(&r2022, sizeof(Registro), 1, candidatos2022);
        }
        else if(strncmp(r2021.cpf, r2022.cpf, 15) < 0){
            fread(&r2022, sizeof(Registro), 1, candidatos2022);
        } else {
            fread(&r2021, sizeof(Registro), 1, candidatos2021);
        }
    }

    
    fclose(candidatos2021);
    fclose(candidatos2022);
    fclose(candidatosGeral);
    return 0;
}
