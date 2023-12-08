#ifndef MINHA_TABELA_ESPALHAMENTO_H
#define MINHA_TABELA_ESPALHAMENTO_H

#include "MinhaListaEncadeada.h"
// MinhaListaEncadeada
#include "TabelaEspalhamentoAbstrata.h"
// TabelaEspalhamentoAbstrata
#include "excecoes.h"
// ExcecaoDadoInexistente
#include <cmath>

template<typename T, std::size_t capac>
class MinhaTabelaEspalhamento final:
    public TabelaEspalhamentoAbstrata<T, capac>
{
    public:
        //Implemente as funções públicas aqui

     /*   virtual ~MinhaTabelaEspalhamento(){

           std::size_t i;

        for(i = 0; i < capac;i++){
        //this->tabela[i].~MinhaListaEncadeada(); 
    }

            //delete[] this->tabela;
         }; */

    /**
     * @brief Obtém a capacidade da tabela.
     * 
     * @return Um inteiro maior do que 0.
     */
    virtual std::size_t capacidade() const {
        //aqui é o tamanho da tabela
        return capac;
    };

    /**
     * @brief Insere um dado na tabela. Se a tabela já contiver o dado, ele não
     * é inserido novamente.
     * 
     * @param dado O dado a ser inserido.
     */
    virtual void inserir(T dado) {
        
        //if(!contem(dado)){
            std::size_t posicao;
            posicao = funcaoEspalhamento(dado);
            this->tabela[posicao].inserirNoFim(dado);
        //}
       
    


    };
    /**
     * @brief Remove um dado da tabela. Se a tabela não contiver o dado, uma
     * exceção ExcecaoDadoInexistente é lançada.
     * 
     * @param dado O dado a ser removido.
     */
    virtual void remover(T dado) {
        if(contem(dado)== false){
            throw ExcecaoDadoInexistente();
        }
        else{
            std::size_t posicao;
            posicao = funcaoEspalhamento(dado);
            this->tabela[posicao].remover(dado);
        }

    };

    /**
     * @brief Verifica se \p dado está contido na tabela.
     * 
     * @param dado O dado sendo buscado.
     * @return true se o dado está contido na tabela; false caso contrário.
     */
    virtual bool contem(T dado) const {

        std::size_t posicao;
        bool contem = false;
        for(posicao = 0; posicao < capac; posicao++){
            if(this->tabela[posicao].contem(dado)){
                contem = true;
                return true;
            }
        }
        //return false;
        if(contem == false){
            return false;
            }
            
    };

    /**
     * @brief Obtém a quantidade de dados contidos na árvore.
     * 
     * @return Um inteiro maior ou igual a 0.
     */
    virtual std::size_t quantidade() const {
        std::size_t quantidade = 0;
        std::size_t i;

        for(i = 0; i < capac; i++){
            quantidade += this->tabela[i].tamanho();
        }

        return quantidade;
    };

    /**
     * @brief Obtém a posição de um dado na tabela e o tamanho da lista em que
     * se encontra.
     * 
     * @param dado O dado sendo buscado.
     * @return A posição do dado na tabela estando ele ou não na tabela e, caso
     * esteja, a posição na lista.
     */

    //Posicao posicao(T dado) const;
    /*
    {
        std::size_t posicao = funcaoEspalhamento(dado);

        if(tabela[posicao].contem(dado)){
            std::size_t posicaoLista = tabela[posicao].posicao(dado);
            //this->tabela
            //return posicaoLista;
            //return {pos, tabela[pos].tamanho(), posLista};
            return {posicao, this->tabela[posicao].tamanho(), posicaoLista};
            //return {posicao, this->tabela[posicao].tamanho()};
        }
        else{
            throw ExcecaoDadoInexistente();
        }
    } 
    */
        

    
    protected:
        //Implemente as funções protegidas aqui


         /**
     * @brief A matriz de dados.
     * 
     */
    //std::array<MinhaListaEncadeada<T>, capac> tabela;

    /**
     * @brief Obtém a posição correspondente na tabela para o dado.
     * 
     * @param dado O dado.
     * @return Um inteiro na faixa [0, capacidade).
     */
    virtual std::size_t funcaoEspalhamento(T dado) const {
        
        if(std::is_integral_v<T>){
            return codigoEspalhamento(dado) % capac;
        } 
        else if(std::is_same_v<T, std::string>){
            return codigoEspalhamento(dado) % capac;
        }
        else{
            return 0;
        }
        
    };
    //std::size_t funcaoEspalhamento(T dado) const;



    
    private:
        /**
         * @brief Calcula a representação numérica de um tipo integral.
         * 
         * @tparam U O tipo integral.
         * @param integral Um valor integral.
         * @return Um inteiro calculado através de static_cast<std::size_t>(integral)
         */
        template<typename U>
        std::size_t codigoEspalhamento(U integral) const
        {
            //Implemente aqui. Dica use std::is_integral_v<U> para garantir que U é um tipo integral

            //static_assert(std::is_integral_v<U>);
            return static_cast<std::size_t>(integral);
           
        }
        
    
        /**
         * @brief Calcula a representação numérica de um string.
         * 
         * @param s um string.
         * @return Um inteiro calculado conforme s[0]*31^(n-1) + s[1]*31^(n-2) + ... + s[n-1].
         */
        std::size_t codigoEspalhamento(std::string const& string) const
        {
            //Implemente aqui.

            std::size_t hash = 0;
            std::size_t i;
            //hash é o ID do dado
//            std::size_t tamanho = string.length();
            for(i = 0; i <string.length(); i++){
                hash += string[i] * pow(31, string.length() - (i+1));
            }
            
            return hash;
            //return 0;
        }
    };

#endif
