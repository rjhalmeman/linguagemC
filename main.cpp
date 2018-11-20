

/*
 https://www.embarcados.com.br/struct-registros-em-linguagem-c/
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 2

typedef struct {
    char nome[30];
    char categ;
    double valor;
} Aeromodelo; //você define um tipo chamado Aeromodelo, não simplifique demais, depois isso fica complicado.... 

Aeromodelo listaDeAeromodelo[N]; //cria uma lista do tipo Aeromodelo, definido anteriormente

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

int lerDadosSalvos(void) {
    FILE *pont_arq;
    char texto_str[20];

    //abrindo o arquivo_frase em modo "somente leitura"
    pont_arq = fopen("arquivo_palavra.txt", "r");

    //enquanto não for fim de arquivo o looping será executado
    //e será impresso o texto
    while (fgets(texto_str, 50, pont_arq) != NULL) {
        printf("%s", texto_str);
    }

    //fechando o arquivo
    fclose(pont_arq);

    return (0);
}

int exemplo_fRead(void) {
    // Declaramos um ponteiro(link para o endereço da memória) para o arquivo de nome: 'pf'
    FILE *pf;
    char conteudo[100];

    pf = fopen("arquivo_palavra.txt", "rb"); /* Abre o arquivo novamente para leitura */

    fread(&conteudo, sizeof (Aeromodelo), 3, pf); /* Le em conteudo o valor da variável armazenada anteriormente pf */
    //fread (void *buffer, int numero_de_bytes, int count, FILE *fp);
    printf("\nO conteúdo do arquivo é':\n %s \n", conteudo);

    fclose(pf);

    return (0);
}

int salvarRegistro(Aeromodelo *aero) {
    FILE *pf;

    printf("chegou o valor: %i\n",aero->valor);
    
    if ((pf = fopen("arquivo.bin", "wb")) == NULL) /* Abre arquivo binário para escrita */ {
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    Aeromodelo xx =  *aero;

    /* Escreve a variável aero 
     *  o operador sizeof, que retorna o tamanho em bytes 
     * da variável ou do tipo de dados. */
    if (fwrite(&xx, sizeof (Aeromodelo), 1, pf) != 1)
        printf("Erro na escrita do arquivo");

    fclose(pf);
    return (0);
}

int lerRegistro(void) {
    FILE *pf;
    if ((pf = fopen("arquivo.bin", "rb")) == NULL) /* Abre arquivo binário para leitura */ {
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    Aeromodelo aeromodelo;
    fread(&aeromodelo, sizeof (Aeromodelo), 1, pf);

    printf("No arquivo foram lidos %lu bytes do registro:  \n", sizeof (Aeromodelo));
    printf("Nome: %s\n", aeromodelo.nome);
    printf("Categoria: %c\n", aeromodelo.categ);
    printf("Valor: %f\n", aeromodelo.valor);

    fclose(pf);
    return (0);
}

int main() {

    //  printf("%i", sizeof (Aeromodelo)); //retorna quantos bytes tem a struct Aeromodelo



    // arquivo();
    //  adicionarDados();
    //   lerDadosSalvos();
    //  exemplo_fRead();

    int i;
    //    printf(" cadastro de aeros");
    //    for (i = 0; i < N; i++) {
    //        printf(" nome do aero ");
    //        scanf(" %s", &listaDeAeromodelo[i].nome);
    //        printf(" categoria eletrico (E) ou gasolina (G)");
    //        scanf(" %c", &listaDeAeromodelo[i].categ);
    //        printf(" valor do aeromodelo ");
    //        scanf(" %f", &listaDeAeromodelo[i].valor);
    //    }
    //
    //    for (i = 0; i < N; i++) {
    //        salvar_registro(&listaDeAeromodelo[i]);
    //    }

        Aeromodelo aa;
        strcpy(aa.nome, "UM");
        aa.categ = 'G';
        aa.valor = 11;

    // printf("%s\n\n", aa.nome);

    salvarRegistro(&aa);


    lerRegistro();


    //    for (i = 0; i < N; i++) {
    //        printf(" nome do aero: %s \n ", listaDeAeromodelo[i].nome);
    //        printf(" categoria: %c \n", listaDeAeromodelo[i].categ);
    //        printf(" valor do aeromodelo: %f ", listaDeAeromodelo[i].valor);
    //    }
}

