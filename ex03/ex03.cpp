#include <iostream>
#include <string.h>
using namespace std;

#include "fila-circular-char.hpp"
#include "pilha-char.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f1;
    Pilha p1;
    int tamFila, tamPilha;
    char valor[100];
    string frase_desenfileirada, frase_desenpilhada;
    bool palindromo = true;

    cout << "Digite uma palavra: ";
    cin >> valor;

    // Percorrendo a palavra
    for (int i = 0; i < strlen(valor); i++)
    {
        tamFila += i;
        tamPilha += i;
    }
    // Inicializa f1 com o tamanho da palavra
    inicializaF(&f1, tamFila);

    // Inicializa p1 com o tamanho da palavra
    inicializaP(&p1, tamPilha);

    for (int i = 0; i < strlen(valor); i++)
    {
        enfileiraF(&f1, valor[i]);
        empilhaP(&p1, valor[i]);
    }
    
    while (vaziaF(&f1) == false && vaziaP(&p1) == false)
    {
        frase_desenfileirada = desenfileiraF(&f1);
        frase_desenpilhada = desempilhaP(&p1);

        if (frase_desenfileirada != frase_desenpilhada)
            palindromo = false;
    }

    cout<<(palindromo?"Palindromo":"Nao e um palindromo");

    return EXIT_SUCCESS;
}