#include "Processo.hpp"
#include "FilaProcessos.hpp"
#include <iostream>
#include <string>
#include <iomanip>


void FilaProcessos::adicionar_processo(std::string nome, int prioridade){
    Celula* nova = new Celula;
    nova->processo = new Processo(id_unico,nome,prioridade);
    nova->proximo = nullptr;
    id_unico++;

    if((this->primeiro == nullptr) || this->primeiro->processo->getPrioridade() < prioridade) {
        nova->proximo = this-> primeiro;        //Usado(primeiro) no contrato por isso tem o this
        this->primeiro = nova;      

    }
    else{
        Celula* atual = this->primeiro;

        //Andar e chegar na celula que eu quero inserir
        while(atual->proximo != nullptr && atual->proximo ->processo->getPrioridade() >= prioridade){
            atual = atual->proximo;
        }
        //inserir
        nova->proximo = atual->proximo;
        atual->proximo = nova;

    }
        
}
        //Remove maior prioridade
Processo* FilaProcessos::remover_processo_maior_prioridade() {
    if (this->primeiro == nullptr) {
        return nullptr; 
    }

    Processo* processoRemovido = this->primeiro->processo;      
    Celula* remove = this->primeiro; 
    this->primeiro = this->primeiro->proximo;
        //Libera a célula 
    delete remove;
        //Retorna o processo removido
    return processoRemovido;
}
        //Remove ID
Processo* FilaProcessos::remover_processo_por_id(int id) {
    if (this->primeiro == nullptr) {
        return nullptr; 
    }

    Celula* atual = this->primeiro;
    Celula* anterior = nullptr;
        
    while (atual != nullptr) {
        if (atual->processo->getID() == id) {
            Processo* processoRemovido = atual->processo;

        //Ajustando os ponteiros para remover a celula
            if (anterior == nullptr) {
                this->primeiro = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }

        
            delete atual;
            return processoRemovido;
        }

        // Avança para a próxima célula
        anterior = atual;
        atual = atual->proximo;
    }

    return nullptr;
}
void FilaProcessos::estimativa_tempo_para_execucao(int id) {
    Celula* atual = this->primeiro;
    double tempo = 0.0;
    bool encontrado = false;    //Flag
    std::string nomeProcesso;

    
    while (atual != nullptr) {

        if (atual->processo->getID() == id) {
            nomeProcesso = atual->processo->getNome(); 
            encontrado = true;
            break; 
        }
        tempo += atual->processo->tempo_reservado_processo();
        atual = atual->proximo;
    }
    if (encontrado) {
        std::cout << "Tempo estimado para execução do processo " << nomeProcesso 
                  << " (id=" << id << ") eh " << std::fixed << std::setprecision(1) 
                  << tempo << " segundos." << std::endl;
    } 
    else {
        std::cout << "Processo com ID " << id << " não encontrado." << std::endl;
    }
}
void FilaProcessos::imprimir_fila() {
    Celula* atual = this->primeiro;

    while (atual != nullptr) {
        atual->processo->imprimir_dados(); 
        atual = atual->proximo; 
    }
}
