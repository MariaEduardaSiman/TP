#include "Processo.hpp"

// Método construtor à definir
Processo::Processo(int id, std::string nome, int prioridade) {
    _id = id;
    _prioridade = prioridade;
    _nome = nome;
}

// Métodos à definir
int Processo::getID() {
    return _id;
}

std::string Processo::getNome() {
    return _nome;
}

int Processo::getPrioridade() {
    return _prioridade;
}

double Processo::tempo_reservado_processo() {
    switch (_prioridade) {
        case 0:
            return 0.5;     // BAIXA PRIORIDADE
        case 1:
            return 1.5;     // MEDIA PRIORIDADE
        case 2:
            return 3.0;     // ALTA PRIORIDADE
        default:            // Caso nem uma das condições   
            return 0.0;
    }
}

void Processo::imprimir_dados() {
    std::string status; 

    // Status da prioridade se é BAIXA, MEDIA OU ALTA  
    switch (_prioridade) {
        case 0:
            status = "BAIXA";
            break;
        case 1:
            status = "MEDIA";
            break;
        case 2:
            status = "ALTA";
            break;
        default:
            status = "INDEFINIDA";
            break;
    }

    std::cout << _id << "\t" << _nome << "\t" << status << std::endl; // Impressão dos dados 
}
