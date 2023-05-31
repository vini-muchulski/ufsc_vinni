#include <iostream>
#include <vector>

using namespace std;

class Scheduler {
protected:
    vector<size_t>& vetor_ids; 

public:
    Scheduler(vector<size_t>& vetor_p) : vetor_ids(vetor_p) {}

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
        } else {
            cout << "Elemento já existe" << endl;
        }
    }

    virtual void processar() {
       
    }
};

class Politica_1 : public Scheduler {
public:
    Politica_1(vector<size_t>& vetor_p) : Scheduler(vetor_p) {}

    virtual void show_ids() {
        size_t i;
        for (i = 0; i < vetor_ids.size(); i++) {
            cout << "Vector Position: " << i << " ID: " << vetor_ids[i] << endl;
        }
    }

    //primeira tarefa a chegar é executada antes, as demais vao fazendo fila
    virtual void processar() {
        vetor_ids.erase(vetor_ids.begin());

       
    }
};

class Politica_2 : public Scheduler {
public:
    Politica_2(vector<size_t>& vetor_p) : Scheduler(vetor_p) {}

    virtual void show_ids() {
        size_t i;
        for (i = 0; i < vetor_ids.size(); i++) {
            cout << "Vector Position: " << i << " ID: " << vetor_ids[i] << endl;
        }
    }

    //ULTIMA tarefa a chegar é executada antes
    virtual void processar() {
        vetor_ids.pop_back();
    }
};

int main() {
    int opcao = 0;
    size_t id;
    vector<size_t> vetor_ids;

    Scheduler tarefas(vetor_ids);
    Politica_1 pol1(vetor_ids);
    Politica_2 pol2(vetor_ids);

    while (opcao != 5) {
        cout << "\nTAREFAS \n1-Schedule a task to process \n2-Pick up a task to process using policy 1 \n3-Pick up a task to process using policy 2 \n4-Print Tasks \n5-Exit\n" << endl;
        cin >> opcao;

        switch (opcao) {
        case 1:
            cout << "Digite um ID: ";
            cin >> id;
            tarefas.add_elemento(id);
            break;

        case 2:
            
            //Policy1 *p = (Policy1*)&tarefas;
            // p->processar();
            pol1.processar();
            break;

        case 3:
            
            pol2.processar();
            break;

        case 4:
            tarefas.show_ids();
            break;

        default:
            break;
        }
    }

    return 0;
}