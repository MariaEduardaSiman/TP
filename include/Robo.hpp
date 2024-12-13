#pragma once
#include "Base.hpp"  // Inclua o cabeçalho da classe Base
// #include "FilaProcessos.hpp"

//O robo não imprime coisas no terminal, a base gerencia as infoormações do robo
class Robo {
  public:
    int id;
    int peçasColetadas = 0;
    bool mover(int i,int j);  // Move o robo para as coordenadas caso não tenha obstaculo retorna true
    //caso true ROBO k: MOVEU PARA (i,j)
    //caso false IMPOSSIVEL COLETAR PEÇA EM (i,j)

    bool coletar(int i,int j); //Coleta a peça nas coordenadas (i, j)
      // IMPOSSIVEL COLETAR PEÇA EM (i,j)
      // – Caso existam peças na posição ’(i,j)’ o robô deverá somar UMA unidade a seu contador de
      // coleta e registrar em seu histórico:
      // ROBO k: PEÇA COLETADA EM (i,j)

    void retornar(); //Retorna o robo para a base
    void executar(); //Executa os comandos da pilha


    // bool adicionarTarefa(std::string nomeDaTarefa, bool prioridade = false); //Aidiciona tarefa na pilha
  private:
    //  FilaProcessos pilhaDeTarefas;
     //Matriz de char M x N
     //Mapa mapa

    //Pilha pilhaDeComandos 
    //variavel que vai salvar todos os comandos 
    //Tipo vector seria perfeito
};