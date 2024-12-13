#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Base.hpp"  // Inclua o cabeçalho da classe Base
// #include "../include/Base.hpp"

//Criar matriz para carregar mapa
void carregarMapa(const std::string& arquivoMapa) {
    std::ifstream arquivo(arquivoMapa);
    if (!arquivo.is_open()) {
        throw std::runtime_error("Erro ao abrir o arquivo do mapa: " + arquivoMapa);
    }

    int linhas, colunas;
    arquivo >> linhas >> colunas;
    arquivo.ignore(); // Ignorar a linha restante

    std::string linha;
    while (std::getline(arquivo, linha)) {
        // mapa.push_back(linha);
        // std::cout << linha;
    }
}

void executarComandos(const std::string& arquivoComandos, Base& base) {
    std::ifstream arquivo(arquivoComandos);
    if (!arquivo.is_open()) {
        throw std::runtime_error("Erro ao abrir o arquivo de comandos: " + arquivoComandos);
    }

    std::string comando;
    while (std::getline(arquivo, comando)) {
        base.processarComando(comando);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Uso: ./run.out <mapa.txt> <comandos.txt>\n";
        return 1;
    }

    std::string arquivoMapa = argv[1];
    std::string arquivoComandos = argv[2];

    try {
        // std::vector<std::string> mapa;
        carregarMapa(arquivoMapa);
        // Base base(mapa);  // Inicializa a base com o mapa carregado

        Base base; //instancia de base
        executarComandos(arquivoComandos, base);

        base.relatorio();
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
