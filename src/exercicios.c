//
// Created by luiso on 02/09/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include "exercicios.h"

int fatorial(int a) {
    int resultado = 1;
    for(int i = 1; i <= a; i++) {
        resultado = resultado * i;
    }
    return resultado;
}
int combinacao_repeticao(int a, int b) {
    return fatorial(a+b-1)/(fatorial(b)*fatorial(a-1));
}
//Combinação simples
// Formula: C(n,k)= (n!)/(k!*(n-k)!)
int combinacao_simples(int a, int b) {
    return fatorial(b)/(fatorial(a)*fatorial(b-a));
}
//probabilidade básica
float prop_basica(float a, float b) {
    return a/b;
}
void ex_12() {
    //Quantas saladas contendo 4 frutas distintas podem
    //ser formadas com 7 tipos diferentes de frutas?
    int n, k;
    //n = total de elementos disponiveis
    //k = quantidade de elementos escolhidos
    printf("Entre com o total de elementos disponiveis: ");
    scanf("%d", &n);
    printf("Entre com a quantidade de elementos escolhidos: ");
    scanf("%d", &k);
    if ((k-n)<=0) {
        exit(EXIT_FAILURE);
    }
    int C = combinacao_simples(n, k);

    printf("Vao ter %d", C);
}
void ex_15() {
    //De quantos modos diferentes podemos escolher 6 pessoas, incluindo pelo menos duas mulheres,em um grupo de 7 homens e 4 mulheres?
    int homens = 7, mulheres = 4;

    int caso_1 = combinacao_simples(2,mulheres)*(combinacao_simples(4, homens));
    int caso_2 = combinacao_simples(3,mulheres)*(combinacao_simples(3, homens));
    int caso_3 = combinacao_simples(4,mulheres)*(combinacao_simples(2, homens));

    int total = caso_1 + caso_2 + caso_3;

    printf("No caso um %d, no caso dois %d e no ultimo caso %d, tendo um total de %d modos diferentes\n",
        caso_1, caso_2, caso_3, total);

}
void ex_20() {
    int n, k;

    printf("Entre com o total de sucos disponiveis disponiveis: ");
    scanf("%d", &n);
    printf("Entre com a quantidade de sucos que vai escolher: ");
    scanf("%d", &k);
    if ((n-k)<=0) {
        exit(EXIT_FAILURE);
    }
    int C = combinacao_repeticao(n, k);

    printf("Vao ter %d maneiras distintas de pedir o suco", C);
}
void ex_79() {
    //Em uma caixa h´a 2 fichas amarelas, 5 fichas azuis e 7 fichas verdes. Se retirarmos uma ´unica
    //ficha, qual a probabilidade dela ser verde ou amarela?
    float total/*(Total de casos)*/, amarelas, azuis, verdes;

    printf("Entres com o numero de cores das fichas amarelas, azuis e verdes: ");
    scanf("%f %f %f", &amarelas, &azuis, &verdes);

    total = amarelas + azuis + verdes;
    amarelas = prop_basica(amarelas, total);
    azuis = prop_basica(azuis, total);
    verdes = prop_basica(verdes, total);

    printf("A probabilidade de ser amarela e %.2f, azuis  %.2f, verdes %.2f", amarelas, azuis, verdes);

}
void ex_155() {

}
void ex_221() {
    //Considere o lancamento simultaneo de dois dados comuns, de seis faces. Determine: a.) Qual a probabilidade de obter uma soma das
    //faces ser igual a 8? b.) Qual a probabilidade de se obter o modulo da diferenca entre as faces igual a 3?
    int dado_1 = 6, dado_2 = 6;
    float n, total_comb = 36.0, diferenca = 0.0, soma_de_dados = 0.0;


    for (int i = 1; i <= dado_1; ++i) {
        for (int j = 1; j <= dado_2; ++j) {
            if (i + j == 8) {
                soma_de_dados++;
            }
            //abs o modulo
            if (abs(i - j) == 3) {
                diferenca++;
            }
        }
    }
    float prob_cas = prop_basica(soma_de_dados, total_comb);
    float prob_dif = prop_basica(diferenca, total_comb);

    printf("A probabilidade de obter uma das somas igual a 8 é %.2f", prob_cas);
    printf("A probabilidade de obter o modulo da diferenca entre as faces igual a 3 é %.2f", prob_dif);

}