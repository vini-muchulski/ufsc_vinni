#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Scheduler {
protected:
    vector<size_t> vetor_ids;

public:
    Scheduler(vector<size_t> vetor_p) {
        vetor_ids = vetor_p;
    }

    virtual void show_ids() {
        size_t i;
        for (i = 0; i < vetor_ids.size(); i++) {
            cout << "ID: " << vetor_ids[i] << endl;
        }
    }

    void add_elemento(size_t id) {
        int duplo = 0;
        size_t i;

        for (i = 0; i < vetor_ids.size(); i++) {
            if (vetor_ids[i] == id) {
                duplo++;
            }
        }

        if (duplo == 0) {
            vetor_ids.push_back(id);
            duplo = 0;
        }
        else {
            cout << "Elemento já existe" << endl;
        }
    }
};

class Politica_1 : public Scheduler {
public:
    Politica_1(vector<size_t> vetor_p) : Scheduler(vetor_p) {}

    void show_ids() override {
        // implementação da política 1 para mostrar os IDs
        // na ordem definida pela política
        size_t i;
        for (i = 0; i < vetor_ids.size(); i++) {
            cout << "Vector Position: " << i << " ID: " << vetor_ids[i] << endl;
        }
    }

    void processar(size_t id) {
        size_t i;
        int posicao = -1;

        for (i = 0; i < vetor_ids.size(); i++) {
            if (vetor_ids[i] == id) {
                posicao = i;
            }
        }

        if (posicao != -1) {
            cout << "Executada Tarefa " << id << endl;
            vetor_ids.erase(vetor_ids.begin() + posicao);
        }
        else {
            cout << "Elemento não encontrado" << endl;
        }
    }
};

class Politica_2 : public Scheduler {
public:
    Politica_2(vector<size_t> vetor_p) : Scheduler(vetor_p) {}

     void show_ids() override {
        // implementação da política 2 para mostrar os IDs
        // na ordem definida pela política
        size_t i;
        for (i = vetor_ids.size(); i > 0; i--) {
            cout << "Vector Position: " << vetor_ids.size() - i << " ID: " << vetor_ids[i - 1] << endl;
        }
    }

    void processar(size_t id) {
        size_t i;
        int posicao = -1;

        for (i = 0; i < vetor_ids.size(); i++) {
            if (vetor_ids[i] == id) {
                posicao = i;
            }
        }

        if (posicao != -1) {
            cout << "Executada Tarefa " << id << endl;
            vetor_ids.erase(vetor_ids.begin() + posicao);
        }
        else {
            cout << "Elemento não encontrado" << endl;
        }
    }
};

int main() {
    int opcao = 0;
    size_t id;
    vector<size_t> vetor_ids;

    Scheduler* tarefas = new Scheduler(vetor_ids);
    Politica_1* pol1 = new Politica_1(vetor_ids);
    Politica_2* pol2 = new Politica_2(vetor_ids);

    while (opcao != 5) {
        cout << "\nTAREFAS \n1-Schedule a task to process \n2-Pick up a task to process using policy 1 \n3-Pick up a task to process using policy 2 \n4-Print Tasks \n5-Exit" << endl;
        cin >> opcao;

        switch (opcao) {
        case 1:
            cout << "Digite um ID: ";
            cin >> id;
            tarefas->add_elemento(id);
            break;

        case 2:
            cout << "Digite um ID para processar - política 1: ";
            cin >> id;
            tarefas = pol1;
            pol1->processar(id);
            break;

        case 3:
            cout << "Digite um ID para processar - política 2: ";
            cin >> id;
            tarefas = pol2;
            pol2->processar(id);
            break;

        case 4:
            tarefas->show_ids();
            break;

        default:
            break;
        }
    }

    delete tarefas;
    delete pol1;
    delete pol2;

    return 0;
}
