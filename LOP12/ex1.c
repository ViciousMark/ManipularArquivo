#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo1, *arquivo2, *arquivoSaida;
    char linha1[100], linha2[100];

    // Abrindo os arquivos de entrada
    arquivo1 = fopen("teste1.txt", "r");
    if (arquivo1 == NULL) {
        printf("Erro ao abrir o arquivo arquivo1.txt.\n");
        return 1;
    }

    arquivo2 = fopen("teste2.txt", "r");
    if (arquivo2 == NULL) {
        printf("Erro ao abrir o arquivo arquivo2.txt.\n");
        fclose(arquivo1);
        return 1;
    }

    // Abrindo o arquivo de saída
    arquivoSaida = fopen("saida.txt", "w");
    if (arquivoSaida == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        fclose(arquivo1);
        fclose(arquivo2);
        return 1;
    }

    // Mesclando os arquivos linha a linha
    while (1) {
        // Lendo uma linha de cada arquivo
        if (fgets(linha1, sizeof(linha1), arquivo1)!= NULL) {
            fputs(linha1, arquivoSaida);
        } else {
            break; // Se arquivo1 chegou ao fim, saímos do loop
        }

        if (fgets(linha2, sizeof(linha2), arquivo2)!= NULL) {
            fputs(linha2, arquivoSaida);
        } else {
            break; // Se arquivo2 chegou ao fim, saímos do loop
        }
    }

    // Fechando todos os arquivos
    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivoSaida);

    printf("Arquivos mesclados com sucesso em saida.txt\n");

    return 0;
}
