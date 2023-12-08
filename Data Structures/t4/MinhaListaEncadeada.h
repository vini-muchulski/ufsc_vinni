#ifndef MINHALISTAENCADEADA_H
#define MINHALISTAENCADEADA_H

#include "ListaEncadeadaAbstrata.h"

template <typename T>
class MinhaListaEncadeada :  public ListaEncadeadaAbstrata<T>
{
    //Implemente aqui as funcões marcadas com virtual na ListaEncadeadaAbstrata
    //Lembre-se de implementar o construtor e destrutor da classe

    public:
    MinhaListaEncadeada(){
        this->_primeiro = nullptr;
        this->_tamanho = 0;
    }
    virtual ~MinhaListaEncadeada(){
       /*  Elemento<T>* elemento = this->_primeiro;
         std:size_t i = 1;

         for(i=1;i < this->_tamanho;i++){
            Elemento<T>* elemento_to_remove =  elemento;
            elemento = elemento->proximo;
            delete elemento_to_remove;

         }

         delete elemento; */

         while(!this->vazia()){
             this->removerDoInicio();
         }
    }; 

    /**
     * @brief Obtém a quantidade de itens na lista.
     * 
     * @return Um inteiro maior ou igual a 0.
     */
    virtual std::size_t tamanho() const {
        return this->_tamanho;
    };
    /**
     * @brief Indica se há algum item na lista ou não.
     * 
     * @return false se houver algum item na lista; true caso contrário.
     */
    virtual bool vazia() const {
        if(this->_tamanho <=0){
            return true;
        }
        else{
            return false;
        }
    };

    /**
     * @brief Obtém a posição de um item na lista. Lança
     * ExcecaoListaEncadeadaVazia caso a lista esteja vazia ou
     * ExcecaoDadoInexistente caso o item não esteja contido na lista.
     * 
     * @param dado O item cuja posição deseja-se obter.
     * @return Um inteiro na faixa [0, tamanho); se houver mais que um mesmo
     * item na lista, a posição da primeira ocorrência.
     */
    virtual std::size_t posicao(T dado) const {
        std:size_t i = 0;

       if(this->vazia()){
            throw ExcecaoListaEncadeadaVazia();
        }

        if(this->contem(dado) == false){
            throw ExcecaoDadoInexistente();
        }

        

        Elemento<T>* elemento_atual = this->_primeiro;

        while (elemento_atual != nullptr){
            if(elemento_atual->dado == dado){
                return i;
            }
            else{
            i++;
            elemento_atual = elemento_atual->proximo;
            }

        }

        throw ExcecaoDadoInexistente();
    };
    /**
     * @brief Indica se um dado item está contido na lista ou não.
     * 
     * @param dado O item sendo buscado.
     * @return true se o item está contido na lista; false caso contrário.
     */
    virtual bool contem(T dado) const {
        
        Elemento<T>* elemento = this->_primeiro;

        
        

        while (elemento != nullptr)
        {
           if(elemento->dado == dado){
            return true;
           }
           elemento = elemento->proximo;


        }
        return false;
    };

    /**
     * @brief Insere um item no início da lista.
     * 
     * @param dado O item sendo inserido.
     */
    virtual void inserirNoInicio(T dado) {
        Elemento<T>* elemento_inicio = new Elemento<T>(dado, this->_primeiro);
        this->_tamanho++;
        this->_primeiro = elemento_inicio;
        
    };
    /**
     * @brief Insere um item em uma posição específica da lista. Lança
     * ExcecaoPosicaoInvalida caso a posição não esteja na faixa
     * [0, tamanho].
     * 
     * @param posicao Um inteiro dentro da faixa [0, tamanho]. Ao se inserir em
     * uma posição já ocupada, a posição do item que já estava naquela posição
     * será posicao + 1; inserir-se na posicao tamanho significa inserir-se no
     * fim da lista.
     * @param dado O item sendo inserido.
     */
    virtual void inserir(std::size_t posicao, T dado) {
         if(posicao < 0  || posicao > this->_tamanho){
            throw ExcecaoPosicaoInvalida();
        }
        Elemento<T>* elemento = new Elemento<T>(dado);

        if(posicao == 0){
            elemento->proximo = this->_primeiro;
            this->_primeiro = elemento;
            // o ponteiro do elemento a ser add passa a apontar para o antigo primeiro elemento

        }
        else{
            Elemento<T>* elemento_1 = this->_primeiro;
            std:size_t i = 0;

            for(i=0;i<posicao -1;i++){
                elemento_1 = elemento_1->proximo;
            }
            elemento->proximo = elemento_1->proximo;
            elemento_1->proximo = elemento;
            // faz a troca de ponteiros

        }
        this->_tamanho++;

    };
    /**
     * @brief Insere um item no fim da lista.
     * 
     * @param dado O item sendo inserido.
     */
    virtual void inserirNoFim(T dado) {
    Elemento<T>* elemento = new Elemento<T>(dado);

    if(this->_primeiro == nullptr){
        this->_primeiro = elemento;
    }
    else{
        Elemento<T>* elemento_atual = this->_primeiro;
        while(elemento_atual->proximo != nullptr){
          elemento_atual =  elemento_atual->proximo;
        }

    elemento_atual->proximo = elemento;
    
    }
    this->_tamanho++;

    };

    /**
     * @brief Remove o primeiro item da lista. Lança ExcecaoListaEncadeadaVazia
     * caso não haja nenhum item na lista.
     * 
     * @return O item removido.
     */
    virtual T removerDoInicio() {
        if(this->_primeiro == nullptr){
            throw ExcecaoListaEncadeadaVazia();
        }

        Elemento<T>* elemento_to_remove = this->_primeiro;
        T dado_to_remove = elemento_to_remove->dado;

       this->_primeiro = this->_primeiro->proximo;
       this->_tamanho--;
       delete elemento_to_remove;
       return dado_to_remove;
    };
    /**
     * @brief Remove um item de uma posição específica da lista. Lança
     * ExcecaoPosicaoInvalida caso a posição não esteja na faixa [0, tamanho).
     * 
     * @param posicao Um inteiro dentro da faixa [0, tamanho).
     * @return O item removido.
     */
    virtual T removerDe(std::size_t posicao) {
        
        if(posicao >= this->_tamanho || posicao < 0   ){
            throw ExcecaoPosicaoInvalida();
        }
        Elemento<T>* elemento_atual = this->_primeiro;
        std:size_t i = 0;
        if(posicao ==0){
            return this->removerDoInicio();
        }

        

        while(i<posicao-1){
            elemento_atual = elemento_atual->proximo;
            i++;
        }

        Elemento<T>* elemento_to_remove = elemento_atual->proximo;
        T dado_to_remove = elemento_to_remove->dado;
        // troca de ponteiros
        elemento_atual->proximo = elemento_to_remove->proximo;

        this->_tamanho--;
        delete elemento_to_remove;
        return dado_to_remove;
        };





    /**
     * @brief Remove o último item da lista. Lança ExcecaoListaEncadeadaVazia
     * caso não haja nenhum item na lista.
     * 
     * @return O item removido.
     */
    virtual T removerDoFim() {

        if(this->_primeiro == nullptr){
            throw ExcecaoListaEncadeadaVazia();
        }

        if(this->_primeiro->proximo == nullptr){
            return this->removerDoInicio();
        }

        /*if(this->_primeiro == nullptr){
            //return this->removerDoInicio();
            throw ExcecaoListaEncadeadaVazia();
        }*/
       
        Elemento<T>* elemento_1 = this->_primeiro;
        
        //if()
        //if(elemento_1->proximo == nullptr){
        //    return elemento_1->dado ;
        //}

        /*if(elemento_1->proximo == nullptr){
             T dado_to_remove = elemento_1->dado;
                this->_primeiro = nullptr;
                delete elemento_1;
                this->_tamanho--;
                return dado_to_remove;

        if(elemento_1->proximo == nullptr){

        Elemento<T>* elemento_atual = nullptr;
        }

        else{
        Elemento<T>* elemento_atual = elemento_1->proximo;
        }
        
        }*/
        
        Elemento<T>* elemento_atual = elemento_1->proximo;


        while(elemento_atual->proximo != nullptr){
          elemento_1 =  elemento_atual;
          elemento_atual = elemento_atual->proximo;



        }

        T dado_to_remove = elemento_atual->dado;
        this->_tamanho--;

         elemento_1->proximo = nullptr;

        

        delete elemento_atual;
        
        return dado_to_remove;
        

        
    };
    /**
     * @brief Remove um item específico da lista. Lança
     * ExcecaoListaEncadeadaVazia caso não haja nenhum item na lista ou
     * ExcecaoDadoInexistente caso o item não esteja contido na lista.
     * 
     * @param dado O item a ser removido. Se houver mais que um item com
     * o mesmo valor, remove a primeira ocorrência.
     */
     virtual void remover(T dado) {
        if(this->_primeiro == nullptr){
            throw ExcecaoListaEncadeadaVazia();
        }

        size_t i;
        bool existe = false;
        Elemento<T>* elemento_atual =this->_primeiro;
        Elemento<T>* elemento_anterior = nullptr;



        if(elemento_atual->dado == dado){
            elemento_anterior = elemento_atual;
            this->_primeiro = elemento_atual->proximo;
            existe = true;
        }
        

        else
        {


    for(i=1;i<this->_tamanho-1;i++){
            
             if( elemento_atual->proximo->dado == dado  ){
                elemento_anterior = elemento_atual->proximo;
                elemento_atual->proximo = elemento_atual->proximo->proximo;
                existe = true;

                
                break;
             }

             elemento_atual = elemento_atual->proximo;
  
        }
        }
        

        
        if(existe == true){
            this->_tamanho--;
        }
        if(existe == false){
            throw ExcecaoDadoInexistente();
        }
        
        if(elemento_anterior != nullptr){
            delete elemento_anterior;
        }
        

    }; 



};

#endif