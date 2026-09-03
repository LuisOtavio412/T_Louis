//
// Created by luiso on 02/09/2026.
//
#include <stdio.h>
#include "exercicios.h"
//Permutação simples
//Formula: (P_n = n!(onde n! = n * (n-1) * ... * 1)).
//Permutação com repetição
// Formula: (P_n^{a, b, c} = (n!)/(a! * b! * c!) (onde a, b, c são as repetições de cada elemento
//Arranjo simples
// Formula: A(n,k)= (n!)/(n-k)!
int fatorial(int a) {
    int resultado = 1;
    for(int i = 1; i <= a; i++) {
        resultado = resultado * i;
    }
    return resultado;
}
//Combinação simples
// Formula: C(n,k)= (n!)/(k!*(n-k)!)
int combinacao_simples(int a, int b) {

    int x = (b-a);
    long int k = fatorial(a);
    long int n = fatorial(b);
    long int kn = fatorial(x);

    return n/(k*kn);
}


void ex_12() {
    //Quantas saladas contendo 4 frutas distintas podem
    //ser formadas com 7 tipos diferentes de frutas?
    int frutas = 4, tipos = 7;

    int saladas = combinacao_simples(frutas, tipos);

    printf("Vao ter %d", saladas);
}
