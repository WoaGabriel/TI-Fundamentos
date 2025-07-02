#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>
#include <vector>

class Produto {
private:
    std::string nome;
    int codigo;
    int estoque;
    float preco;

public:
    // Construtor padrão (necessário pra criar Produto vazio)
    Produto();

    // Construtor completo
    Produto(std::string nome, int codigo, int estoque, float preco);

    // Getters
    std::string getNome() const;
    int getCodigo() const;
    int getEstoque() const;
    float getPreco() const;

    // Setters
    void setNome(std::string nome);
    void setEstoque(int estoque);
    void setPreco(float preco);

    // Exibe os dados formatados no terminal
    void exibir() const;
};

// Funções auxiliares para gerenciar produtos em memória
void inserirProduto(std::vector<Produto>& lista, const Produto& p);
void listarProdutos(const std::vector<Produto>& lista);
Produto* buscarProduto(std::vector<Produto>& lista, int codigo);
bool removerProduto(std::vector<Produto>& lista, int codigo);
bool atualizarProduto(std::vector<Produto>& lista, int codigo, std::string novoNome, int novoEstoque, float novoPreco);

#endif
