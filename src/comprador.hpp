#ifndef COMPRADOR_HPP
#define COMPRADOR_HPP

#include <string>
#include <vector>

class Comprador {
private:
    std::string nome;
    std::string cpf;
    std::string email;
    std::string rua, bairro, cidade, estado, cep;

public:
    Comprador(); // construtor padrão
    Comprador(std::string nome, std::string cpf, std::string email,
              std::string rua, std::string bairro, std::string cidade,
              std::string estado, std::string cep);

    // Getters
    std::string getCPF() const;
    std::string getNome() const;

    // Setters
    void setNome(std::string nome);
    void setEmail(std::string email);
    void setEndereco(std::string rua, std::string bairro, std::string cidade, std::string estado, std::string cep);

    void exibir() const;
};

// CRUD
void inserirComprador(std::vector<Comprador>& lista, const Comprador& c);
void listarCompradores(const std::vector<Comprador>& lista);
Comprador* buscarComprador(std::vector<Comprador>& lista, const std::string& cpf);
bool removerComprador(std::vector<Comprador>& lista, const std::string& cpf);
bool atualizarComprador(std::vector<Comprador>& lista, const std::string& cpf, std::string novoNome, std::string novoEmail);

#endif
