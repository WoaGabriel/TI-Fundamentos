#include "comprador.hpp"
#include <iostream>

// Construtor padrão
Comprador::Comprador()
    : nome(""), cpf(""), email(""), rua(""), bairro(""), cidade(""), estado(""), cep("") {}

// Construtor completo
Comprador::Comprador(std::string nome, std::string cpf, std::string email,
                     std::string rua, std::string bairro, std::string cidade,
                     std::string estado, std::string cep)
    : nome(nome), cpf(cpf), email(email), rua(rua), bairro(bairro),
      cidade(cidade), estado(estado), cep(cep) {}

// Getters
std::string Comprador::getCPF() const { return cpf; }
std::string Comprador::getNome() const { return nome; }

// Setters
void Comprador::setNome(std::string nome) { this->nome = nome; }
void Comprador::setEmail(std::string email) { this->email = email; }

void Comprador::setEndereco(std::string rua, std::string bairro, std::string cidade, std::string estado, std::string cep) {
    this->rua = rua;
    this->bairro = bairro;
    this->cidade = cidade;
    this->estado = estado;
    this->cep = cep;
}

// Exibe tudo
void Comprador::exibir() const {
    std::cout << "Nome: " << nome << "\n"
              << "CPF: " << cpf << "\n"
              << "Email: " << email << "\n"
              << "Endereço: " << rua << ", " << bairro << ", "
              << cidade << " - " << estado << " | CEP: " << cep << "\n";
}

// Inserir novo comprador
void inserirComprador(std::vector<Comprador>& lista, const Comprador& c) {
    for (const Comprador& comp : lista) {
        if (comp.getCPF() == c.getCPF()) {
            std::cout << "Erro: CPF já cadastrado.\n";
            return;
        }
    }
    lista.push_back(c);
    std::cout << "Comprador inserido com sucesso!\n";
}

// Listar todos os compradores
void listarCompradores(const std::vector<Comprador>& lista) {
    if (lista.empty()) {
        std::cout << "Nenhum comprador cadastrado.\n";
        return;
    }
    for (const Comprador& c : lista) {
        c.exibir();
        std::cout << "------------------------\n";
    }
}

// Buscar por CPF
Comprador* buscarComprador(std::vector<Comprador>& lista, const std::string& cpf) {
    for (Comprador& c : lista) {
        if (c.getCPF() == cpf) {
            return &c;
        }
    }
    return nullptr;
}

// Remover comprador
bool removerComprador(std::vector<Comprador>& lista, const std::string& cpf) {
    for (auto it = lista.begin(); it != lista.end(); ++it) {
        if (it->getCPF() == cpf) {
            lista.erase(it);
            std::cout << "Comprador removido com sucesso!\n";
            return true;
        }
    }
    std::cout << "CPF não encontrado.\n";
    return false;
}

// Atualizar nome e email
bool atualizarComprador(std::vector<Comprador>& lista, const std::string& cpf, std::string novoNome, std::string novoEmail) {
    Comprador* c = buscarComprador(lista, cpf);
    if (c != nullptr) {
        c->setNome(novoNome);
        c->setEmail(novoEmail);
        std::cout << "Dados do comprador atualizados.\n";
        return true;
    }
    std::cout << "CPF não encontrado.\n";
    return false;
}
