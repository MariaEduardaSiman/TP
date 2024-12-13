#ifndef LISTA_ENCADEADA_HPP
#define LISTA_ENCADEADA_HPP

#include <stdexcept>
#include <iostream>

// Nó da lista encadeada
template <typename T>
struct No {
    T dado;
    No* proximo;

    No(const T& valor) : dado(valor), proximo(nullptr) {}
};

// Classe da lista encadeada
template <typename T>
class ListaEncadeada {
private:
    No<T>* cabeca;  // Ponteiro para o início da lista
    int tamanho;    // Número de elementos na lista

public:
    // Construtor
    ListaEncadeada() : cabeca(nullptr), tamanho(0) {}

    // Destrutor
    ~ListaEncadeada() {
        limpar();
    }

    // Adicionar elemento no início
    void adicionar(const T& valor) {
        No<T>* novoNo = new No<T>(valor);
        novoNo->proximo = cabeca;
        cabeca = novoNo;
        tamanho++;
    }

    // Buscar elemento (retorna ponteiro ou nullptr se não encontrar)
    T* buscar(const T& valor) {
        No<T>* atual = cabeca;
        while (atual) {
            if (atual->dado == valor) {
                return &(atual->dado);
            }
            atual = atual->proximo;
        }
        return nullptr;
    }

    // Remover elemento pelo valor
    void remover(const T& valor) {
        No<T>* atual = cabeca;
        No<T>* anterior = nullptr;

        while (atual) {
            if (atual->dado == valor) {
                if (anterior) {
                    anterior->proximo = atual->proximo;
                } else {
                    cabeca = atual->proximo;
                }
                delete atual;
                tamanho--;
                return;
            }
            anterior = atual;
            atual = atual->proximo;
        }
        throw std::runtime_error("Elemento nao encontrado");
    }

    // Limpar a lista
    void limpar() {
        while (cabeca) {
            No<T>* temp = cabeca;
            cabeca = cabeca->proximo;
            delete temp;
        }
        tamanho = 0;
    }

    // Retornar o tamanho da lista
    int obterTamanho() const {
        return tamanho;
    }

    // Imprimir elementos da lista (debug)
    void imprimir() const {
        No<T>* atual = cabeca;
        while (atual) {
            std::cout << atual->dado << " ";
            atual = atual->proximo;
        }
        std::cout << std::endl;
    }
};

#endif
