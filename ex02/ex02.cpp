#include <iostream>
using namespace std;

#include "filacircular.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f1;
    aviao valor;
    int tamFila, opcaoMenu;
    bool resultado;
    
    do
    {
        system("cls");
        cout << "--------------MENU--------------" << endl;
        cout << "1: Numero de Avioes para Decolar\n";
        cout << "2: Entrada de Aviao\n";
        cout << "3: Decolagem do aviao\n";
        cout << "4: Mostrar aviao à espera para decolar\n";
        cout << "5: Listar as características do próximo aviao a decolar\n";
        cout << "0: Sair\n";
        cout << "Escolha a opçao: ";
        cin >> opcaoMenu;

        if (opcaoMenu == 1)
        {
            cout << "Digite a Quantidade de avioes: ";
            cin >> tamFila;

            inicializaF(&f1, tamFila);
        }
        else if (opcaoMenu == 2)
        {
            for (int i = 0; i < tamFila; i++)
            {
                cout << "Dados do Aviao"<<endl;
                
                cout << "Codigo dos avioes que estao entrando: ";
                cin>>valor.codigo_aviao;
                
                cout << "numero de passageiros: ";
                cin>>valor.numero_passageiros;
                
                cout << "empresa: ";
                cin>>valor.empresa;

                resultado = enfileiraF(&f1, valor);
            }

            if (resultado == true)
                cout << "\n Todos os valores foram enfileirados com sucesso!\n";
        }
        else if (opcaoMenu == 3)
        {
            cout << "Digite o cod do aviao: ";
            cin >> valor.codigo_aviao;
            if (vaziaF(&f1) == false)
            {
                valor = desenfileiraF(&f1);
                cout <<"O Aviao: " << valor.codigo_aviao<<endl;
                cout<<"Empresa: " << valor.empresa<<endl;
                cout<<"Aviao tem: " << valor.numero_passageiros<<" Passageiros"<<endl;
                
                cout<<"Aviao decolou com sucesso!";
            }
        }
        else if (opcaoMenu == 4)
        {
            cout<<"Aviao para decolar"<<endl;
            mostraF(&f1);
        }
        else if (opcaoMenu == 5)
        {
            mostraF(&f1);
        }

        if (opcaoMenu > 0)
            system("pause");

    } while (opcaoMenu != 0);

    return EXIT_SUCCESS;

} // final do main