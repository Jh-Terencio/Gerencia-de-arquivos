/*Nos arquivos texto no sistemas operacionais tipo UNIX, a quebra de linha  é representada pelo caractere\n.  Já nos sistemas origina dos a partir do DOS, a quebra de linha  é representada pelos caracteres\r e \n(nessa ordem e um seguido do outro).  Faça um programa em C que dado um arquivo texto com quebra de linhas no formato UNIX converta-o para o formato DOS.*/

#include<stdio.h>

int main(int argc, char** argv){
  //Crio os ponteiros para os respectivos ponteiros
  FILE *arquivoUnix, *arquivoDos;

  //Crio a variavel que vai armazenar o byte do arquivoUnix
  int c;

  //Abro o arquivo txt para leitura e vejo se ele não está vazio
  arquivoUnix = fopen("arquivoUnix.txt", "rb");
  if(arquivoUnix == NULL){
    printf("Erro ao abrir o arquivo");
    return 1;
  }

  //Crio o arquivo txt para escrita e vejo se ele não está vazio
  arquivoDos = fopen("arquivoDos.txt", "wb");
  if (arquivoDos == NULL){
    printf("Erro ao abrir o arquivo");
    return 1;
  }

  //Salvo na variavel c o byte atual
  c = fgetc(arquivoUnix);

  //Inicio do loop que verifica se c é um EOF, caso não seja era irá entrar em um if que verifica se o byte é ou não é
  //Uma quebra de linha, caso seja converte para \r ou \n, caso contrário escreve o caracter atual no arquivo
  while (c != EOF){
    if(c == '\n'){
      fputc('\n', arquivoDos);
      fputc('\r', arquivoDos);
      c = fgetc(arquivoUnix);
    } else {
      fputc(c, arquivoDos);
      c = fgetc(arquivoUnix);
    }
  }
  
  // Fecha os arquivos
    fclose(arquivoUnix);
    fclose(arquivoDos);

    printf("Arquivo convertido com sucesso.\n");
  

  return 0;
}
