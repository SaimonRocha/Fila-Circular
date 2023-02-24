#include <iostream>
#include <fstream>
using namespace std;

#include "filacircular.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    fstream arq;


    //apagar o arquivo já existente
    arq.open("revisa.txt", ios::out | ios::trunc );
    arq.close();


    Fila f1;
    int tamFila=8;
    inicializaF(&f1, tamFila);
    float valor;

    enfileiraF(&f1, 7.2);
    enfileiraF(&f1, 6.2);
    enfileiraF(&f1, 3.2);
    enfileiraF(&f1, 2.2);


    mostraF(&f1);

    while(vaziaF(&f1) == false)
    {
        valor = desenfileiraF(&f1);

        arq.open("revisa.txt", ios::out | ios::app);
        arq << valor << endl;
        arq.close();
    }

    arq.open("revisa.txt", ios::in); // abrir para a leitura
    float soma=0;
    cout << "\n\nARQUIVO:\n";
    while(arq.eof()== false)
    {
        if(arq >> valor)
        {
            cout << valor << endl;
            soma += valor;
        }
    }

    cout << "\n\nSOMA: " << soma << endl;

    mostraF(&f1);


    return EXIT_SUCCESS;

}//final do main

