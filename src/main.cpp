#include <iostream>
#include <vector>
#include <windows.h> // Para SetConsoleOutputCP no Windows
#include <cmath>

#include "produto.hpp"
#include "comprador.hpp"
#include "nota_fiscal.hpp"


void testeNotaFiscalManual() {
    // [TESTE MANUAL] Criando nota fiscal com itens...

    Comprador comprador("Gabriel Teste", "00000000000", "gabriel@email.com", "Rua Teste", "Bairro Legal", "Cidade Show", "Estado X", "12345-678");

    Produto p1("Mouse Gamer", 1, 50, 100.00);
    Produto p2("Teclado Mecânico", 2, 20, 250.00);

    NotaFiscal nota(comprador);
    nota.adicionarItem(p1, 2);
    nota.adicionarItem(p2, 1);

    nota.calcularTotal();
    nota.emitirNota();

    float esperado = 450.0;
    float total = nota.getTotal();

    if (std::fabs(total - esperado) < 0.01) {
        std::cout << "[SUCESSO V] Total calculado corretamente: R$" << total << "\n";
    } else {
        std::cout << "[FALHA X] Total incorreto! Esperado: R$" << esperado << " | Obtido: R$" << total << "\n";
    }
}
int main() {
    SetConsoleOutputCP(65001); // Ativa UTF-8 no terminal do Windows

    std::vector<Produto> listaProdutos;
    std::vector<Comprador> listaCompradores;

    int opcao;

    do {
        std::cout << "\n===== MENU PRINCIPAL =====\n";
        std::cout << "1. Menu de Produtos\n";
        std::cout << "2. Menu de Compradores\n";
        std::cout << "3. Emitir Nota Fiscal\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(9999, '\n');
            std::cout << "Entrada inválida.\n";
            continue;
        }

        // -------------------- PRODUTOS --------------------
        if (opcao == 1) {
            int op;
            do {
                std::cout << "\n--- MENU DE PRODUTOS ---\n";
                std::cout << "1. Inserir produto\n";
                std::cout << "2. Listar produtos\n";
                std::cout << "3. Buscar produto\n";
                std::cout << "4. Atualizar produto\n";
                std::cout << "5. Remover produto\n";
                std::cout << "0. Voltar\n";
                std::cout << "Escolha uma opção: ";
                std::cin >> op;

                int cod, est;
                float preco;
                std::string nome;

                switch (op) {
                    case 1:
                        std::cout << "Nome: "; std::cin.ignore(); std::getline(std::cin, nome);
                        std::cout << "Código: "; std::cin >> cod;
                        std::cout << "Estoque: "; std::cin >> est;
                        std::cout << "Preço: "; std::cin >> preco;
                        inserirProduto(listaProdutos, Produto(nome, cod, est, preco));
                        break;

                    case 2:
                        listarProdutos(listaProdutos);
                        break;

                    case 3:
                        std::cout << "Código: "; std::cin >> cod;
                        if (Produto* p = buscarProduto(listaProdutos, cod)) {
                            p->exibir();
                        } else {
                            std::cout << "Produto não encontrado.\n";
                        }
                        break;

                    case 4:
                        std::cout << "Código: "; std::cin >> cod;
                        std::cout << "Novo nome: "; std::cin.ignore(); std::getline(std::cin, nome);
                        std::cout << "Novo estoque: "; std::cin >> est;
                        std::cout << "Novo preço: "; std::cin >> preco;
                        atualizarProduto(listaProdutos, cod, nome, est, preco);
                        break;

                    case 5:
                        std::cout << "Código: "; std::cin >> cod;
                        removerProduto(listaProdutos, cod);
                        break;

                    case 0:
                        std::cout << "Voltando ao menu principal...\n";
                        break;

                    default:
                        std::cout << "Opção inválida.\n";
                        break;
                }
            } while (op != 0);

        }

        // -------------------- COMPRADORES --------------------
        else if (opcao == 2) {
            int op;
            do {
                std::cout << "\n--- MENU DE COMPRADORES ---\n";
                std::cout << "1. Inserir comprador\n";
                std::cout << "2. Listar compradores\n";
                std::cout << "3. Buscar comprador\n";
                std::cout << "4. Atualizar comprador\n";
                std::cout << "5. Remover comprador\n";
                std::cout << "0. Voltar\n";
                std::cout << "Escolha uma opção: ";
                std::cin >> op;

                std::string nome, cpf, email, rua, bairro, cidade, estado, cep;

                switch (op) {
                    case 1:
                        std::cin.ignore();
                        std::cout << "Nome: "; std::getline(std::cin, nome);
                        std::cout << "CPF: "; std::getline(std::cin, cpf);
                        std::cout << "Email: "; std::getline(std::cin, email);
                        std::cout << "Rua: "; std::getline(std::cin, rua);
                        std::cout << "Bairro: "; std::getline(std::cin, bairro);
                        std::cout << "Cidade: "; std::getline(std::cin, cidade);
                        std::cout << "Estado: "; std::getline(std::cin, estado);
                        std::cout << "CEP: "; std::getline(std::cin, cep);
                        inserirComprador(listaCompradores, Comprador(nome, cpf, email, rua, bairro, cidade, estado, cep));
                        break;

                    case 2:
                        listarCompradores(listaCompradores);
                        break;

                    case 3:
                        std::cin.ignore();
                        std::cout << "CPF do comprador: "; std::getline(std::cin, cpf);
                        if (Comprador* c = buscarComprador(listaCompradores, cpf)) {
                            c->exibir();
                        } else {
                            std::cout << "Comprador não encontrado.\n";
                        }
                        break;

                    case 4:
                        std::cin.ignore();
                        std::cout << "CPF do comprador: "; std::getline(std::cin, cpf);
                        std::cout << "Novo nome: "; std::getline(std::cin, nome);
                        std::cout << "Novo email: "; std::getline(std::cin, email);
                        atualizarComprador(listaCompradores, cpf, nome, email);
                        break;

                    case 5:
                        std::cin.ignore();
                        std::cout << "CPF do comprador: "; std::getline(std::cin, cpf);
                        removerComprador(listaCompradores, cpf);
                        break;

                    case 0:
                        std::cout << "Voltando ao menu principal...\n";
                        break;

                    default:
                        std::cout << "Opção inválida.\n";
                        break;
                }
            } while (op != 0);
        }

        // -------------------- NOTA FISCAL --------------------
        else if (opcao == 3) {
            std::cin.ignore();
            std::string cpf;
            std::cout << "CPF do comprador: ";
            std::getline(std::cin, cpf);

            Comprador* c = buscarComprador(listaCompradores, cpf);
            if (c == nullptr) {
                std::cout << "Comprador não encontrado.\n";
                continue;
            }

            NotaFiscal nota(*c);
            char continuar;
            do {
                int codigo, quantidade;
                std::cout << "Código do produto: ";
                std::cin >> codigo;

                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Código inválido. Tente novamente.\n";
                    continue;
                }

                Produto* p = buscarProduto(listaProdutos, codigo);


                if (p == nullptr) {
                    std::cout << "Produto não encontrado.\n";
                } else {
                    std::cout << "Quantidade: ";
                    std::cin >> quantidade;
                    nota.adicionarItem(*p, quantidade);
                    std::cout << "Produto adicionado à nota.\n";
                }

                std::cout << "Deseja adicionar mais um produto? (s/n): ";
                std::cin >> continuar;
            } while (continuar == 's' || continuar == 'S');

            nota.calcularTotal();
            nota.emitirNota();
        }

        else if (opcao == 0) {
            std::cout << "Saindo do programa...\n";
        }

        else {
            std::cout << "Opção inválida.\n";
        }

    } while (opcao != 0);

    // Rodando teste manual de nota fiscal
    testeNotaFiscalManual();


    return 0;
}
