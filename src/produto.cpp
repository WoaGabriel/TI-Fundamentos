#include "produto.hpp"
#include <iostream>

// Construtor padrão
Produto::Produto() : nome(""), codigo(0), estoque(0), preco(0.0f) {}

// Construtor completo
Produto::Produto(std::string nome, int codigo, int estoque, float preco)
    : nome(nome), codigo(codigo), estoque(estoque), preco(preco) {}

// Getters
std::string Produto::getNome() const { return nome; }
int Produto::getCodigo() const { return codigo; }
int Produto::getEstoque() const { return estoque; }
float Produto::getPreco() const { return preco; }

// Setters
void Produto::setNome(std::string nome) { this->nome = nome; }
void Produto::setEstoque(int estoque) { this->estoque = estoque; }
void Produto::setPreco(float preco) { this->preco = preco; }

// Exibir informações do produto
void Produto::exibir() const {
    std::cout << "Nome: " << nome << "\n"
              << "Código: " << codigo << "\n"
              << "Estoque: " << estoque << "\n"
              << "Preço: R$" << preco << "\n";
}

// Inserir novo produto, checando código duplicado
void inserirProduto(std::vector<Produto>& lista, const Produto& p) {
    for (const Produto& prod : lista) {
        if (prod.getCodigo() == p.getCodigo()) {
            std::cout << "Erro: Já existe um produto com esse código!\n";
            return;
        }
    }
    lista.push_back(p);
    std::cout << "Produto inserido com sucesso!\n";
}

// Listar todos os produtos
void listarProdutos(const std::vector<Produto>& lista) {
    if (lista.empty()) {
        std::cout << "Nenhum produto cadastrado.\n";
        return;
    }
    for (const Produto& p : lista) {
        p.exibir();
        std::cout << "------------------------\n";
    }
}

// Buscar produto por código
Produto* buscarProduto(std::vector<Produto>& lista, int codigo) {
    for (Produto& p : lista) {
        if (p.getCodigo() == codigo) {
            return &p;
        }
    }
    return nullptr;
}

// Remover produto
bool removerProduto(std::vector<Produto>& lista, int codigo) {
    for (auto it = lista.begin(); it != lista.end(); ++it) {
        if (it->getCodigo() == codigo) {
            lista.erase(it);
            std::cout << "Produto removido com sucesso!\n";
            return true;
        }
    }
    std::cout << "Produto não encontrado.\n";
    return false;
}

// Atualizar informações do produto
bool atualizarProduto(std::vector<Produto>& lista, int codigo, std::string novoNome, int novoEstoque, float novoPreco) {
    Produto* p = buscarProduto(lista, codigo);
    if (p != nullptr) {
        p->setNome(novoNome);
        p->setEstoque(novoEstoque);
        p->setPreco(novoPreco);
        std::cout << "Produto atualizado com sucesso!\n";
        return true;
    }
    std::cout << "Produto não encontrado.\n";
    return false;
}
