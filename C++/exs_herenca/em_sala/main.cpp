//#include "client.hpp"
#include "cc.hpp"

int main()
{
    //Client client1;
    Client client2("Antonio Carlos", "Rua das Oliveiras, 3333", "Pesquisador", 49000);

    Client client3("Joao da Silva");
    Client client4("Cristian Ribeiro", "Rua das Bromelias");
    Client client5("Ricardo Silva", "Rua sem nome", "Mecanico");

    Client *client6 = new Client("Maria da Silva", "None", "Vendedora", 5000);

    //cout << client1.GetInfo() << endl;
    cout << client2.GetInfo() << endl;
    cout << client3.GetInfo() << endl;
    cout << client4.GetInfo() << endl;
    cout << client5.GetInfo() << endl;

    ContaCorrente cc1(&client3, 100000);
    ContaCorrente cc2(&client5, 50000);
    ContaCorrente cc3(&client3, 20000);
    ContaCorrente cc4(client6, 30000);


    delete client6;


    return 0;
}
