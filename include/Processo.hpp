#pragma once

#include <iostream>
#include <string>

struct Processo
{
    //Atributos
    int _id;
    int _prioridade;
    std::string _nome;

    //Métodos
int getID();
int getPrioridade();
std::string getNome();
double tempo_reservado_processo();
void imprimir_dados();

    //Método construtor
Processo(int id, std::string nome, int prioridade);
};
