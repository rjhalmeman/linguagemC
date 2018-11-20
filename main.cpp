
#include <stdio.h>
#include <stdlib.h>
#define N 2

struct {
    char nome[50];
    char categ;
    float valor;
} listaero[N];

int arquivo(void) {
    // criando a variável ponteiro para o arquivo
    FILE *pont_arq;

    //abrindo o arquivo
    pont_arq = fopen("arquivo.txt", "a");
    // note que o arquivo.txt será criado na pasta do programa

    // fechando arquivo
    fclose(pont_arq);

    //mensagem para o usuário
    printf("O arquivo foi criado com sucesso!");

    system("pause");
    return (0);
}

int adicionarDados(void) {
    FILE *pont_arq; // cria variável ponteiro para o arquivo
    char palavra[20]; // variável do tipo string

    //abrindo o arquivo com tipo de abertura w
    pont_arq = fopen("arquivo_palavra.txt", "w");

    //testando se o arquivo foi realmente criado
    if (pont_arq == NULL) {
        printf("Erro na abertura do arquivo!");
        return 1;
    }

    printf("Escreva uma palavra para testar gravacao de arquivo: ");
    scanf("%s", palavra);

    //usando fprintf para armazenar a string no arquivo
    fprintf(pont_arq, "%s", palavra);

    //usando fclose para fechar o arquivo
    fclose(pont_arq);

    printf("Dados gravados com sucesso!");


    return (0);
}

//Leitura de arquivo
#include <stdio.h>
#include <stdlib.h>

int lerDadosSalvos(void) {
    FILE *pont_arq;
    char texto_str[20];

    //abrindo o arquivo_frase em modo "somente leitura"
    pont_arq = fopen("arquivo_palavra.txt", "r");

    //enquanto não for fim de arquivo o looping será executado
    //e será impresso o texto
    while (fgets(texto_str, 20, pont_arq) != NULL)
        printf("%s", texto_str);

    //fechando o arquivo
    fclose(pont_arq);

    return (0);
}

int main() {

    // arquivo();
  //  adicionarDados();
    lerDadosSalvos();


    //    int i;
    //    printf(" cadastro de aeros");
    //    for (i = 0; i < N; i++) {
    //        printf(" nome do aero ");
    //        scanf(" %s", &listaero[i].nome);
    //        printf(" categoria eletrico (E) ou gasolina (G)");
    //        scanf(" %c", &listaero[i].categ);
    //        printf(" valor do aeromodelo ");
    //        scanf(" %f", &listaero[i].valor);
    //    }
    //
    //    for (i = 0; i < N; i++) {
    //        printf(" nome do aero: %s \n ", listaero[i].nome);
    //        printf(" categoria: %c \n", listaero[i].categ);
    //        printf(" valor do aeromodelo: %f ", listaero[i].valor);
    //    }
}

