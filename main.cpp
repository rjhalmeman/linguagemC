/* 
 * File:   main.cpp
 * Author: Radames J Halmeman  - rjhalmeman@gmail.com
 *
 * Created on 21 de Novembro de 2018, 15:16
 */

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Cliente {
    char nome[20];
    char rua[20];
    int idade;
};

int inserirDadosParaTeste(char nomeArquivo[100]) {

    FILE *f = fopen(nomeArquivo, "wb");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    struct Cliente cadastroDeClientes[4] = {
        "Ricardo", "rua ricardo", 1,
        "Carlos", "rua carlos", 2,
        "Ana", "rua da Ana", 3,
        "Bianca", "rua bianca", 4
    };

    fwrite(cadastroDeClientes, sizeof (struct Cliente), 4, f);
    fclose(f);

    return 0;
}

int inserirUmRegistro(Cliente cli, char nomeArquivo[100]) {
    //insere um registro no final do arquivo
    FILE *f = fopen(nomeArquivo, "a+b"); // a de acrescenta (append) para leitura escrita
    if (f == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    fseek(f, sizeof (struct Cliente), SEEK_END);
    fwrite(&cli, sizeof (struct Cliente), 1, f);
    fclose(f);

    return 0;
}

Cliente obterRegistroPorPosicao(int posicao, char nomeArquivo[100]) {

    FILE *f = fopen(nomeArquivo, "rb");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    struct Cliente c;
    fseek(f, posicao * sizeof (struct Cliente), SEEK_SET);
    fread(&c, sizeof (struct Cliente), 1, f);
    fclose(f);
    return c;
}

int listarTodosOsRegistros(char nomeArquivo[100]) {
    FILE *f = fopen(nomeArquivo, "r");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    struct Cliente c;
    rewind(f); //posiciona no primeiro registro
    while (!feof(f)) {
        fread(&c, sizeof (struct Cliente), 1, f); // lê um registro
        if (!feof(f)) {
            printf("Nome: %s Endereço: %s Idade:%d\n", c.nome, c.rua, c.idade);
        }
    }

    return 0;
}

Cliente obterUltimoRegistro(char nomeArquivo[100]) {

    // inserirDadosParaTeste();

    FILE *f = fopen(nomeArquivo, "rb");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    struct Cliente c;
    fseek(f, -sizeof (struct Cliente), SEEK_END);
    fread(&c, sizeof (struct Cliente), 1, f);
    fclose(f);
    return c;
}

int main() {

    // inserirDadosParaTeste("arquivo.txt");


    //    struct Cliente c = obterRegistro(0, "arquivo.txt");
    struct Cliente cli = {"Seis", "666666", 6};

    inserirUmRegistro(cli, "arquivo.txt");

    //    struct Cliente c = obterUltimoRegistro("arquivo.txt");
    //    printf("%s\n%s\n%d\n", c.nome, c.rua, c.idade);

    listarTodosOsRegistros("arquivo.txt");

    return 0;
}

