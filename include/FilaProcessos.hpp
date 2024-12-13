#ifndef FILAPROCESSOS_HPP
#define FILAPROCESSOS_HPP

#include "Processo.hpp"
#include <iostream>
#include <string>

    //Nó
struct Celula
{
    Processo* processo;     
    Celula* proximo;
};
struct FilaProcessos
{
    Celula*primeiro = nullptr;
    int id_unico = 1;

    //Métodos
void adicionar_processo(std::string nome, int prioridade);
Processo* remover_processo_maior_prioridade();
Processo* remover_processo_por_id(int id);
void estimativa_tempo_para_execucao(int id);
void imprimir_fila();

};

#endif