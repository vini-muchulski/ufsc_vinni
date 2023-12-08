#ifndef MINHA_ARVORE_AVL_HPP
#define MINHA_ARVORE_AVL_HPP

#include "ArvoreBinariaDeBusca.h"

/**
 * @brief Representa uma árvore AVL.
 *
 * @tparam T O tipo de dado guardado na árvore.
 */
template <typename T>
class MinhaArvoreAVL final : public ArvoreBinariaDeBusca<T>
{

    void destruir(Nodo<T> *const raiz)
    {
        if (this->raiz == nullptr)
        {
            return;
        }
        destruir(this->raiz->filhoEsquerda);
        destruir(this->raiz->filhoDireita);

        delete raiz;
    }
    // implemente aqui

    virtual bool vazia() const
    {
        if (this->raiz == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    };

    /**
     * @brief Retornar quantidade de chaves na arvore
     * @return Numero natural que representa a quantidade de chaves na arvore
     */
    virtual int quantidade() const
    {
        if (this->raiz == nullptr)
        {
            return 0;
        };
        // return 1 + quantidade(this->raiz->filhoEsquerdaDe) + quantidade(this->raiz->filhoDireitaDe);
        return quantidade_aux(this->raiz);
    };

    int quantidade_aux(Nodo<T> *no) const
    {
        if (no == nullptr)
        {
            return 0;
        }

        return 1 + quantidade_aux(no->filhoEsquerda) + quantidade_aux(no->filhoDireita);
    };

    /**
     * @brief Verifica se a arvore contem uma chave
     * @param chave chave a ser procurada na arvore
     * @return Verdade se a arvore contem a chave
     */
    virtual bool contem(T chave) const
    {
        return contem_aux(this->raiz, chave);
    };

    bool contem_aux(Nodo<T> *no, T dado) const
    {
        if (no == nullptr)
        {
            return false;
        }
        if (no->chave == dado)
        {
            return true;
        } // or
        return contem_aux(no->filhoEsquerda, dado) || contem_aux(no->filhoDireita, dado);
    };

    /**
     * @brief Retorna a altura da (sub)arvore
     * @param chave chave que é raiz da (sub)arvore cuja altura queremos.
     * @return Numero inteiro representando a altura da (subarvore). Se chave nao esta na arvore, retorna std::nullopt
     */
    virtual std::optional<int> altura(T chave) const
    {
        Nodo<T> *auxiliar = this->raiz;

        while (auxiliar != nullptr)
        {
            if (auxiliar->chave == chave)
            {
                return auxiliar->altura;
            }
            else if (auxiliar->chave > chave)
            {
                auxiliar = auxiliar->filhoEsquerda;
            }
            else
            {
                auxiliar = auxiliar->filhoDireita;
            }
        }
        return std::nullopt;
    };

    /**
     * @brief Insere uma chave na arvore
     * @param chave chave a ser inserida
     */
    virtual void inserir(T chave)
    {
        inserir_recursivo(chave, this->raiz, nullptr);

        atualizar_altura(this->raiz);
    };

    /**
     * @brief Remove uma chave da arvore
     * @param chave chave a removida
     */
    virtual void remover(T chave)
    {
        if (this->raiz->chave == chave && this->raiz->filhoEsquerda == nullptr && this->raiz->filhoDireita == nullptr)
        {
            Nodo<T> *nodoDelete = this->raiz;

            delete nodoDelete;

            this->raiz = nullptr;
        }
        else
        {
            remover_recursivo(this->raiz, chave);
        }
        atualizar_altura(this->raiz);

        // diferença de altura positiva- rotacao a direita
    };

    /**
     * @brief Busca a chave do filho a esquerda de uma (sub)arvore
     * @param chave chave da arvore que eh pai do filho a esquerda
     * @return Chave do filho a esquerda. Se chave nao esta na arvore, retorna std::nullopt
     */
    virtual std::optional<T> filhoEsquerdaDe(T chave) const
    {

        Nodo<T> *atual = this->raiz;

        while (atual != nullptr)
        {

            if (atual->chave == chave)
            {
                if (atual->filhoEsquerda != nullptr)
                {
                    return atual->filhoEsquerda->chave;
                }

                else
                {
                    return std::nullopt;
                }
            }
            else
            {
                if (chave < atual->chave)
                {
                    atual = atual->filhoEsquerda;
                }
                else
                {
                    atual = atual->filhoDireita;
                }
            }
        }
        return std::nullopt;
    };

    /**
     * @brief Busca a chave do filho a direita de uma (sub)arvore
     * @param chave chave da arvore que eh pai do filho a direita
     * @return Chave do filho a direita. Se chave nao esta na arvore, retorna nullptr
     */
    virtual std::optional<T> filhoDireitaDe(T chave) const
    {
        Nodo<T> *atual = this->raiz;

        while (atual != nullptr)
        {

            if (atual->chave == chave)
            {
                if (atual->filhoDireita != nullptr)
                {
                    return atual->filhoDireita->chave;
                }

                else
                {
                    return std::nullopt;
                }
            }
            else
            {
                if (chave < atual->chave)
                {
                    atual = atual->filhoEsquerda;
                }
                else
                {
                    atual = atual->filhoDireita;
                }
            }
        }
        return std::nullopt;
    };

    /**
     * @brief Lista chaves visitando a arvore em ordem
     * @return Lista encadeada contendo as chaves em ordem.
     */
    virtual ListaEncadeadaAbstrata<T> *emOrdem() const
    {
        ListaEncadeadaAbstrata<T> *lista = new MinhaListaEncadeada<T>;

        emOrdem_aux(this->raiz, lista);

        return lista;
    };

    void emOrdem_aux(Nodo<T> *no_atual, ListaEncadeadaAbstrata<T> *lista) const
    {
        if (no_atual == nullptr)
        {
            return;
        }

        emOrdem_aux(no_atual->filhoEsquerda, lista);

        lista->inserirNoFim(no_atual->chave);
        emOrdem_aux(no_atual->filhoDireita, lista);
    }

    /**
     * @brief Lista chaves visitando a arvore em pre-ordem
     * @return Lista encadeada contendo as chaves em pre-ordem.
     */
    virtual ListaEncadeadaAbstrata<T> *preOrdem() const
    {
        ListaEncadeadaAbstrata<T> *lista = new MinhaListaEncadeada<T>;

        preOrdem_aux(this->raiz, lista);

        return lista;
    };

    void preOrdem_aux(Nodo<T> *no_atual, ListaEncadeadaAbstrata<T> *lista) const
    {
        if (no_atual == nullptr)
        {
            return;
        }

        lista->inserirNoFim(no_atual->chave);

        preOrdem_aux(no_atual->filhoEsquerda, lista);
        preOrdem_aux(no_atual->filhoDireita, lista);
    }

    /**
     * @brief Lista chaves visitando a arvore em pos-ordem
     * @return Lista encadeada contendo as chaves em pos ordem.
     */
    virtual ListaEncadeadaAbstrata<T> *posOrdem() const
    {
        ListaEncadeadaAbstrata<T> *lista = new MinhaListaEncadeada<T>;

        posOrdem_aux(this->raiz, lista);

        return lista;
    };

    void posOrdem_aux(Nodo<T> *no_atual, ListaEncadeadaAbstrata<T> *lista) const
    {
        if (no_atual == nullptr)
        {
            return;
        }

        posOrdem_aux(no_atual->filhoEsquerda, lista);
        posOrdem_aux(no_atual->filhoDireita, lista);

        lista->inserirNoFim(no_atual->chave);
    }

    // ------------------------------------------------------------------------------------------------

    int atualizar_altura(Nodo<T> *raiz)
    {
        if (raiz == nullptr)
        {
            return -1;
        }

        int altura_esquerda = -1;
        if (raiz->filhoEsquerda != nullptr)
        {
            altura_esquerda = atualizar_altura(raiz->filhoEsquerda);
        }
        int altura_direita = -1;
        if (raiz->filhoDireita != nullptr)
        {
            altura_direita = atualizar_altura(raiz->filhoDireita);
        }

        raiz->altura = std::max(altura_esquerda, altura_direita) + 1;

        return raiz->altura;
    }

    void inserir_recursivo(T chave, Nodo<T> *no, Nodo<T> *pai)
    {

        if (no == nullptr)
        {
            Nodo<T> *novo_no = new Nodo<T>;

            novo_no->altura = 0;
            novo_no->chave = chave;

            novo_no->filhoEsquerda = nullptr;
            novo_no->filhoDireita = nullptr;

            no = novo_no;

            if (pai == nullptr)
            {
                this->raiz = novo_no;
            }
            else if (chave < pai->chave)
            {
                pai->filhoEsquerda = novo_no;

                this->raiz->altura = atualizar_altura(this->raiz);
            }

            else
            {
                pai->filhoDireita = novo_no;

                this->raiz->altura = atualizar_altura(this->raiz);
            }
        }

        else
        {
            if (chave < no->chave)
            {
                inserir_recursivo(chave, no->filhoEsquerda, no);
            }
            else
            {
                inserir_recursivo(chave, no->filhoDireita, no);
            }

            if (no->filhoEsquerda == nullptr && no->filhoDireita == nullptr)
            {
                no->altura = 0;
            }
            else
            {
                //int balanceamento = altura_do_no(no->filhoEsquerda) - altura_do_no(no->filhoDireita);
                int balanceamento = valor_balanceamento(no);

                if (balanceamento > 1)
                {
                    // Nodo<T>* desbalanceado = this->raiz->filhoEsquerda;

                    Nodo<T> *desbalanceado = this->raiz->filhoEsquerda;
                    if (pai == this->raiz)
                    {
                        Nodo<T> *desbalanceado = this->raiz->filhoEsquerda;
                    }
                    else
                    {
                        Nodo<T> *desbalanceado = no;
                    }

                    int alturaEsquerda = -1;
                    if (desbalanceado->filhoEsquerda->filhoEsquerda != nullptr)
                    {
                        alturaEsquerda = desbalanceado->filhoEsquerda->filhoEsquerda->altura;
                    }

                    int alturaDireita = -1;
                    if (desbalanceado->filhoEsquerda->filhoDireita != nullptr)
                    {
                        alturaDireita = desbalanceado->filhoEsquerda->filhoDireita->altura;
                    }

                    int subarvore_balanceamento = alturaEsquerda - alturaDireita;
                    // -1 - 0

                    // chave < desbalanceado->chave
                    if (subarvore_balanceamento < 0)
                    {
                        rotacao_esquerda_direita(desbalanceado);
                    }
                    else
                    {

                        rotacao_simples_direita(desbalanceado);
                    }
                }

                else if (balanceamento < -1)
                {
                    Nodo<T> *desbalanceado = this->raiz->filhoDireita;

                    // Nodo<T>* desbalanceado = pai->filhoDireita;
                    // Nodo<T>* desbalanceado = no->filhoDireita;

                    

                    // int subarvore_balanceamento = alturaEsquerda - alturaDireita;
                    int subarvore_balanceamento = valor_balanceamento(desbalanceado);

                    if (subarvore_balanceamento > 0)
                    {

                        rotacao_direita_esquerda(desbalanceado);
                    }
                    else
                    {
                        rotacao_simples_esquerda(desbalanceado);
                        //rotacao_simples_esquerda_especial(desbalanceado->filhoDireita, desbalanceado);
                    }
                }
            }
        }
    }


   

    Nodo<T> *get_minino_valor(Nodo<T> *raiz)
    {
        Nodo<T> *atual = raiz;

        // vai descaendo e indo para a esquerda, pegando menor valor
        while (atual && atual->filhoEsquerda != nullptr)
        {
            atual = atual->filhoEsquerda;
        }

        return atual;
    }

    Nodo<T> *get_pai(Nodo<T> *raiz, T chave)
    {
        // se for raiz inicial ou for nulo, retorna nulo
        if (raiz == nullptr || raiz->chave == chave)
        {
            return nullptr;
        }
        if ((raiz->filhoEsquerda != nullptr && raiz->filhoEsquerda->chave == chave) || (raiz->filhoDireita != nullptr && raiz->filhoDireita->chave == chave))
        {
            return raiz;
        }

        if (raiz->chave > chave)
        {

            return get_pai(raiz->filhoEsquerda, chave);
        }
        else
        {
            return get_pai(raiz->filhoDireita, chave);
        }
    }

    void remover_recursivo(Nodo<T> *raiz, T chave)
    {
        if (raiz == nullptr)
        {
            return;
        }
        else
        {
            if (raiz->chave == chave)
            {
                if ((raiz->filhoDireita == nullptr) && (raiz->filhoEsquerda == nullptr))
                {
                remover_folha(this->raiz, chave);
                }
                else
                {
                    // eh no
                remover_no(this->raiz, chave);
                }
            }
            else
            {
                if (chave > raiz->chave)
                {
                    remover_recursivo(raiz->filhoDireita, chave);
                }
                else
                {
                    remover_recursivo(raiz->filhoEsquerda, chave);
                    // remover_recursivo(raiz->filhoDireita, chave);
                }
            }
        }
    }

 void rotacao_simples_esquerda_especial(Nodo<T>* no, Nodo<T>* no_pai){
        no_pai->filhoDireita = no->filhoEsquerda;
        no->filhoEsquerda = no_pai;

        if(no_pai->chave == this->raiz->chave){
            this->raiz = no;
        }
        else{
        Nodo<T>* no_avo = get_pai(this->raiz, no_pai->chave);
        
        if(no_avo->filhoDireita->chave == no_pai->chave){
            no_avo->filhoDireita = no;
        }
        else{
            no_avo->filhoEsquerda = no;
        }


        }
    }

    
    void remover_folha(Nodo<T> *no, T chave)
    {
        if (no != nullptr)
        {
            if (no->chave == chave)
            {

                // se for raiz
                if (no->chave == this->raiz->chave)
                {
                    Nodo<T> *temp = no;
                    this->raiz = nullptr;
                    delete temp;
                }
                else
                {
                    Nodo<T> *paizao = get_pai(this->raiz, no->chave);
                    Nodo<T> *temp = no;

                    // se for filho direita
                    if ((paizao->filhoDireita != nullptr) && (paizao->filhoDireita->chave == temp->chave))
                    {
                        delete temp;
                        paizao->filhoDireita = nullptr;
                        atualizar_altura(this->raiz);
                    }

                    else
                    {
                        delete temp;
                        paizao->filhoEsquerda = nullptr;
                        atualizar_altura(this->raiz);
                    }
                }
            }
    // passado a limpo
            else
            {
                if (chave > no->chave)
                {
                    remover_folha(no->filhoDireita, chave);

                    int balanceamento = valor_balanceamento(no);

                    // msm tipo de rotacao do no
                    //ja ok passado a limpo
                    if (valor_balanceamento(no) > 1)
                    {
                        if (valor_balanceamento(no->filhoEsquerda) >= 0)
                        {
                            rotacao_simples_direita(no);
                        }
                        else if (valor_balanceamento(no->filhoEsquerda) < 0)
                        {
                            rotacao_esquerda_direita(no);
                        }
                    }
                    else if (valor_balanceamento(no) < -1)
                    {
                        if (valor_balanceamento(no->filhoDireita) <= 0)
                        {
                            rotacao_simples_esquerda(no);
                        }

                        else if (valor_balanceamento(no->filhoDireita) > 0)
                        {
                            rotacao_direita_esquerda(no);
                        }
                    }
                }
                else
                {
                    remover_folha(no->filhoEsquerda, chave);
                    int balanceamento = valor_balanceamento(no);

                    if (valor_balanceamento(no) > 1)
                    {       int balanceamento_filho = valor_balanceamento(no->filhoEsquerda);
                        if (valor_balanceamento(no->filhoEsquerda) >= 0)
                        {
                            rotacao_simples_direita(no);
                        }
                        else if (valor_balanceamento(no->filhoEsquerda) < 0)
                        {
                            rotacao_esquerda_direita(no);
                        }
                    }
                    else if (valor_balanceamento(no) < -1)
                    {    int balanceamento_filho = valor_balanceamento(no->filhoDireita);
                        if (valor_balanceamento(no->filhoDireita) <= 0)
                        {
                            rotacao_simples_esquerda(no);
                        }
                        else if (valor_balanceamento(no->filhoDireita) > 0)
                        {
                            rotacao_direita_esquerda(no);
                        }
                    }
                }
            }
        }
    }

    int valor_balanceamento(Nodo<T> *no)
    {
        if (no == nullptr)
        {
            return 0;
        }

        int altura_esq = 0;
        if (no->filhoEsquerda != nullptr)
        {
            altura_esq = no->filhoEsquerda->altura;
        }
        else
        {
            altura_esq = -1;
        }

        int altura_dir = 0;
        if (no->filhoDireita != nullptr)
        {
            altura_dir = no->filhoDireita->altura;
        }

        else
        {
            altura_dir = -1;
        }

        return altura_esq - altura_dir;
    }

    void remover_no(Nodo<T> *no, T chave)
    {



            //se for a raiz, atribuir seu successor direto na raiz.
            //testar
        if (chave == this->raiz->chave)
        {
            Nodo<T> *temp = no;

            if (no->filhoDireita != nullptr)
            {
                Nodo<T> *ponta = no->filhoDireita;
                bool buscar = true;

                while (buscar == true)
                {
                    if (ponta->filhoEsquerda != nullptr)
                    {
                        ponta = ponta->filhoEsquerda;
                    }
                    else
                    {
                        buscar = false;
                    }
                }
                Nodo<T> *pai_ponta = get_pai(this->raiz, ponta->chave);
                if (pai_ponta != temp)
                {
                    pai_ponta->filhoEsquerda = ponta->filhoDireita;
                    ponta->filhoDireita = no->filhoDireita;

                    ponta->filhoEsquerda = no->filhoEsquerda;
                }

                else
                {
                    ponta->filhoEsquerda = no->filhoEsquerda;
                }
                this->raiz = ponta;
                delete temp;
                atualizar_altura(this->raiz);
            }
        }

        else if (no->chave == chave)
        {
            Nodo<T> *temp = no;
            bool buscar = true;

            if (no->filhoDireita != nullptr)
            {
                Nodo<T> *ponta = no->filhoDireita;
 //se for a raiz, atribuir seu successor direto na raiz.
                while (buscar == true)
                {
                    if (ponta->filhoEsquerda != nullptr)
                    {
                        ponta = ponta->filhoEsquerda;
                    }
                    else
                    {
                        buscar = false;
                    }
                }

                Nodo<T> *pai_ponta = get_pai(this->raiz, ponta->chave);
                Nodo<T> *pai = get_pai(this->raiz, chave);

                if (pai_ponta != temp)
                {
                    pai_ponta->filhoEsquerda = ponta->filhoDireita;
                    ponta->filhoDireita = no->filhoDireita;
                    ponta->filhoEsquerda = no->filhoEsquerda;
                }
                else
                {
                    ponta->filhoEsquerda = no->filhoEsquerda;
                }
                //pai->filhoDireita = ponta;

                if (pai->filhoDireita->chave == no->chave)
                {
                    pai->filhoDireita = ponta;
                }
                else
                {
                    pai->filhoEsquerda = ponta;
                }

                delete temp; // ver se ta ok - se nao da vazamento
                atualizar_altura(this->raiz);
            }

            else if (no->filhoDireita == nullptr)
            {
                Nodo<T> *temp = no;
                Nodo<T> *pai = get_pai(this->raiz, chave);
                //pai->filhoDireita = no->filhoEsquerda;
                if (pai->filhoDireita->chave == no->chave)
                {
                    pai->filhoDireita = no->filhoEsquerda;
                }
                else
                {
                    pai->filhoEsquerda = no->filhoEsquerda;
                }

                delete temp;
                atualizar_altura(this->raiz);
            }
        }

        else
        {
            if (chave > no->chave)
            {
                remover_no(no->filhoDireita, chave);
            //    remover_no(no->filhoEsquerda, chave);
            //pegar balanceamento com funcao
                if (valor_balanceamento(no) > 1)
                {
                    if (valor_balanceamento(no->filhoEsquerda) >= 0)
                    {
                        rotacao_simples_direita(no);
                    }
                    else if (valor_balanceamento(no->filhoEsquerda) < 0)
                    {
                        rotacao_esquerda_direita(no);
                    }
                }

                else if (valor_balanceamento(no) < -1)
                {
                    if (valor_balanceamento(no->filhoDireita) <= 0)
                    {
                        rotacao_simples_esquerda(no); // poder dar erro - testar
                    }
                    else if (valor_balanceamento(no->filhoDireita) > 0)
                    {
                        rotacao_direita_esquerda(no);
                    }
                }
            }
            else
            {
                remover_no(no->filhoEsquerda, chave);

                if (valor_balanceamento(no) > 1)
                {
                    if (valor_balanceamento(no->filhoEsquerda) >= 0)
                    {
                        rotacao_simples_direita(no);
                    }
                    else if (valor_balanceamento(no->filhoEsquerda) < 0)
                    {
                        rotacao_esquerda_direita(no);
                    }
                }
                else if (valor_balanceamento(no) < -1)
                {
                    if (valor_balanceamento(no->filhoDireita) <= 0)
                    {

                        rotacao_simples_esquerda(no);
                    }
                    else if (valor_balanceamento(no->filhoDireita) > 0)
                    {
                        rotacao_direita_esquerda(no);
                    }
                }
            }
        }
    }

    

    // rotacoes

    int altura_do_no(Nodo<T> *no)
    {
        if (no == nullptr)
        {
            return -1;
        }

        else
        {
            return no->altura;
        }
    }

    void rotacao_simples_direita(Nodo<T> *pai)
    {

        // tirar &
        // pegra avo e guardar e dps colocar ele ==== avo = get_pai
        //              filho = avo

        Nodo<T> *paizao = get_pai(this->raiz, pai->chave);

        if (paizao == nullptr)
        {
            this->raiz = pai->filhoEsquerda;
            pai->filhoEsquerda = this->raiz->filhoDireita;
            this->raiz->filhoDireita = pai;
        }
        else
        {
            paizao->filhoEsquerda = pai->filhoDireita;
            pai->filhoDireita = paizao;
            this->raiz = pai;
            // paizao = pai; //sera?????

            pai->altura = std::max(altura_do_no(pai->filhoEsquerda), altura_do_no(pai->filhoDireita)) + 1;
            paizao->altura = std::max(altura_do_no(paizao->filhoEsquerda), altura_do_no(paizao->filhoDireita)) + 1;
        }

        atualizar_altura(this->raiz);
    }

    void rotacao_simples_esquerda(Nodo<T> *pai)
    {
        Nodo<T> *paizao = get_pai(this->raiz, pai->chave);

        if (paizao == nullptr)
        {
            this->raiz = pai->filhoDireita;
            pai->filhoDireita = this->raiz->filhoEsquerda;
            this->raiz->filhoEsquerda = pai;
        }
        else
        {
            paizao->filhoDireita = pai->filhoEsquerda;
            pai->filhoEsquerda = paizao;

            // pai->filhoDireita = pai->filhoDireita->filhoEsquerda;
            // pai->filhoEsquerda = paizao;
            if (paizao == this->raiz){
              this->raiz = pai;
                //pai->filhoDireita->filhoEsquerda = pai
              
            }
            else
            {
                Nodo<T> *pai_do_paizao = get_pai(paizao, paizao->chave);
                pai_do_paizao->filhoDireita = pai;
            }

            pai->altura = std::max(altura_do_no(pai->filhoEsquerda), altura_do_no(pai->filhoDireita)) + 1;
            paizao->altura = std::max(altura_do_no(paizao->filhoEsquerda), altura_do_no(paizao->filhoDireita)) + 1;
        }
        atualizar_altura(this->raiz);
    }

    void rotacao_direita_esquerda(Nodo<T> *no)
    {
        Nodo<T> *paizao = get_pai(this->raiz, no->chave);

        Nodo<T> *noDireita = no->filhoDireita;
        Nodo<T> *noDirEsq = noDireita->filhoEsquerda;

        if (paizao == nullptr)
        {
            this->raiz = noDirEsq;
            noDireita->filhoEsquerda = noDirEsq->filhoDireita;
            noDirEsq->filhoDireita = noDireita;
            no->filhoDireita = noDirEsq;

            no->filhoDireita = noDirEsq->filhoEsquerda;
            noDirEsq->filhoEsquerda = no;
        }
        else
        {

            // 1
            noDireita->filhoEsquerda = noDirEsq->filhoDireita;
            noDirEsq->filhoDireita = noDireita;
            no->filhoDireita = noDirEsq;

            // 2

            no->filhoDireita = noDirEsq->filhoEsquerda;
            noDirEsq->filhoEsquerda = no;

            // 3
            // this->raiz->filhoDireita = noDirEsq;
            paizao->filhoDireita = noDirEsq;
        }

        atualizar_altura(no);
        atualizar_altura(noDireita);
        atualizar_altura(noDirEsq);

        atualizar_altura(this->raiz);
    }

    void rotacao_esquerda_direita(Nodo<T> *no)
    {

        Nodo<T> *paizao = get_pai(this->raiz, no->chave);

        Nodo<T> *noEsquerda = no->filhoEsquerda;
        Nodo<T> *noEsqDir = noEsquerda->filhoDireita;

        if (paizao == nullptr)
        {
            this->raiz = noEsqDir;
            noEsquerda->filhoDireita = noEsqDir->filhoEsquerda;
            noEsqDir->filhoEsquerda = noEsquerda;
            no->filhoEsquerda = noEsqDir;

            no->filhoEsquerda = noEsqDir->filhoDireita;
            noEsqDir->filhoDireita = no;
        }
        else
        {

            // 1

            noEsquerda->filhoDireita = noEsqDir->filhoEsquerda;
            noEsqDir->filhoEsquerda = noEsquerda;
            no->filhoEsquerda = noEsqDir;

            // 2

            no->filhoEsquerda = noEsqDir->filhoDireita;

            noEsqDir->filhoDireita = no;

            // 3

            // this->raiz->filhoEsquerda = noEsqDir;
            // paizao?
            paizao->filhoEsquerda = noEsqDir;
        }

        atualizar_altura(no);
        atualizar_altura(noEsquerda);
        atualizar_altura(noEsqDir);

        atualizar_altura(this->raiz);
    }
};

#endif