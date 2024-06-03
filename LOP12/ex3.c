#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *entrada, *saida;
    char caractere;

    entrada = fopen("teste22.txt", "r"); // Abre o arquivo de entrada
    saida = fopen("teste22saida.txt", "w"); // Abre o arquivo de sa�da

    if (entrada == NULL || saida == NULL) { // Verifica se houve erro na abertura dos arquivos
        printf("Erro ao abrir os arquivos.");
        return 1;
    }

    while ((caractere = fgetc(entrada)) != EOF) { // L� caractere por caractere at� o fim do arquivo
        if (caractere == ' ' || caractere == '\n') { // Verifica se � espa�o, quebra de linha ou tabula��o
            continue; // Ignora e vai para o pr�ximo caractere
        } else {
            fputc(caractere, saida); // Se n�o for espa�o ou quebra de linha, escreve no arquivo de sa�da
        }
    }

    fclose(entrada); // Fecha o arquivo de entrada
    fclose(saida); // Fecha o arquivo de sa�da

    printf("Espa�os e quebras de linha removidos com sucesso.\n");

    return 0;
}
