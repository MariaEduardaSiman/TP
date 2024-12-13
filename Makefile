# Nome do compilador
g++ = g++

# Flags de compilação
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17

# Diretórios
SRC_DIR = ./src/
BIN_DIR = ./bin/
OBJ_DIR = ./obj/
INCLUDE_DIR = ./include/

# Nome do executável
TARGET = $(BIN_DIR)/run.out

# Arquivos fonte e objeto
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Regra padrão
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJ_FILES)
	$(g++) $(CXXFLAGS) -o $@ $^

# Regra para criar arquivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(g++) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Limpar arquivos gerados
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

# Regras auxiliares
.PHONY: all clean
