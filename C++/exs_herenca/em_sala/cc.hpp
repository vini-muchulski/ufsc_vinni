#include <iostream>
#include "client.hpp"

using namespace std;

class ContaCorrente
{
protected:
    Client *m_client;
    float m_balance;

public:
    ContaCorrente(Client *client, float balance) : m_client(client), m_balance(balance) {};

};
