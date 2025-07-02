#include <iostream>
#include <vector>
#include <string>
#include <cmath> // <- para std::abs
#include "nota_fiscal.hpp"
#include "produto.hpp"
#include "comprador.hpp"
#include "../lib/munit.h"

// ---------- Teste 1: Criar nota fiscal vazia ----------
MunitResult teste_nota_vazia(const MunitParameter params[], void* data) {
    Comprador c("João", "123", "joao@email.com", "Rua A", "Bairro B", "Cidade C", "Estado D", "00000-000");
    NotaFiscal nota(c);

    // Total esperado: 0.0
    double esperado = 0.0;
    double resultado = nota.getTotal();
    munit_assert(std::abs(esperado - resultado) < 0.001);
    return MUNIT_OK;
}

// ---------- Teste 2: Adicionar um item ----------
MunitResult teste_adicionar_item(const MunitParameter params[], void* data) {
    Comprador c("Maria", "456", "maria@email.com", "Rua B", "Bairro C", "Cidade D", "Estado E", "11111-111");
    Produto p("Mouse", 1, 50, 100.0);

    NotaFiscal nota(c);
    nota.adicionarItem(p, 2); // Adiciona 2 unidades de R$100,00

    double esperado = 200.0;
    double resultado = nota.getTotal();
    munit_assert(std::abs(esperado - resultado) < 0.001);
    return MUNIT_OK;
}

// ---------- Teste 3: Adicionar múltiplos itens ----------
MunitResult teste_varios_itens(const MunitParameter params[], void* data) {
    Comprador c("Carlos", "789", "carlos@email.com", "Rua C", "Bairro D", "Cidade E", "Estado F", "22222-222");
    Produto p1("Teclado", 2, 10, 150.0);
    Produto p2("Fone", 3, 20, 200.0);

    NotaFiscal nota(c);
    nota.adicionarItem(p1, 1); // R$150,00
    nota.adicionarItem(p2, 2); // R$400,00

    double esperado = 550.0;
    double resultado = nota.getTotal();
    munit_assert(std::abs(esperado - resultado) < 0.001);
    return MUNIT_OK;
}

// ---------- Registro dos testes ----------
static MunitTest tests[] = {
    { "/nota/vazia", teste_nota_vazia, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/nota/adicionar-item", teste_adicionar_item, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/nota/varios-itens", teste_varios_itens, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// ---------- Execução da suíte de testes ----------
static const MunitSuite suite = {
    "/meus-testes/nota", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
