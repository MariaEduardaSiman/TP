#include "Base.hpp"

// *MOVER 0 (2,4)
// MOVER 0 (4,1)

// (prioridade) (comando)

void Base::processarComando(std::string comando){
    bool prioridade = false;
    if (comando[0] == '*') {
        prioridade = true;                        // Salva que o comando é prioritário
        comando = comando.substr(1);             // Remove o asterisco do comando
    }

    std::istringstream ss(comando);
    std::string tarefa;  // Ordem de comando a ser executada
    int id;  // Identificador do robo

    char abreParenteses, fechaParenteses, separador; //Identificadores de comando do tipo Ordem k (i, j)
    int x, y; //(i, j)

    // Dividir a string de entrada
    ss >> tarefa >> id >> abreParenteses >> x >> separador >> y >> fechaParenteses;
    if(prioridade){
      std::cout << "Comando com prioridade" << "\n";
    }


    // Verificar se o formato está correto
    //  Ordem k (i, j)
    if (abreParenteses == '(' && fechaParenteses == ')' && separador == ',') {
        std::cout << "Comando: " << tarefa << "\n";
        std::cout << "ID: " << id << "\n";
        std::cout << "Coordenadas: (" << x << ", " << y << ")\n";
    } 
    //  Ordem k
    else {
        std::cout << "Comando: " << tarefa << "\n";
        std::cout << "ID: " << id << "\n";
    }
}

int Base::ativar(int id_robo){
    std::cout << "BASE: ROBO " << id_robo << " SAIU EM MISSAO";
    // if(s)
}