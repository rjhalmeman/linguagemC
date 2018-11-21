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

struct cadastro {
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
    struct cadastro cad[4] = {
        "ricardo", "rua ricardo", 1,
        "Carlos", "rua carlos", 2,
        "Ana", "rua da Ana", 3,
        "Bianca", "rua bianca", 4
    };

    fwrite(cad, sizeof (struct cadastro), 4, f);
    fclose(f);

    return 0;
}

cadastro obterRegistro(int posicao, char nomeArquivo[100]) {

    // inserirDadosParaTeste();

    FILE *f = fopen(nomeArquivo, "rb");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    struct cadastro c;
    fseek(f, posicao * sizeof (struct cadastro), SEEK_SET);
    fread(&c, sizeof (struct cadastro), 1, f);
    fclose(f);
    return c;
}

int main() {

    // inserirDadosParaTeste("arquivo.txt");


    struct cadastro c = obterRegistro(1, "arquivo.txt");
    printf("%s\n%s\n%d\n", c.nome, c.rua, c.idade);

    return 0;
}

