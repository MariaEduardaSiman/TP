// base.processarComando(comando);
// base.imprimirRelatorioGeral();

#pragma once //evitar redundância

#include <iostream>
#include <string>
#include <sstream>
#include "listaEncadeada.hpp"
#include "Robo.hpp"

class Base{

public:

   void processarComando(std::string comando); // Passa o comando para a pilha do robo
   void receberRobo(); // Coletar as ferramentas salvas no robo e os seus resultados (BASE: ROBO 0 RETORNOU PEÇAS 1)
   void relatorio(); //  Passar as informações salvas na base (BASE: TOTAL DE PEÇAS 1)
   void executarComando();  // Chamar o robo na lista encadeada e executar a pilha de comandos
   int ativar(int id_robo);  // Criar e adicionar o robo na lista encadeada
   
private:
  ListaEncadeada<Robo> robos;
};
