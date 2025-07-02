extern "C" {
    #include "../lib/munit.h"
}

#include "../src/produto.hpp"
#include <vector>
#include <cmath>

// ---------- Teste 1: Inserção de produto ----------
static MunitResult test_inserir_produto(const MunitParameter params[], void* data) {
    std::vector<Produto> lista;
    Produto p("Camisa", 101, 10, 59.90f);
    inserirProduto(lista, p);

    munit_assert_size(lista.size(), ==, 1);
    munit_assert_int(lista[0].getCodigo(), ==, 101);
    munit_assert_string_equal(lista[0].getNome().c_str(), "Camisa");

    return MUNIT_OK;
}

// ---------- Teste 2: Inserção duplicada (deve ignorar) ----------
static MunitResult test_produto_duplicado(const MunitParameter params[], void* data) {
    std::vector<Produto> lista;
    Produto p1("Tênis", 202, 5, 199.99f);
    Produto p2("Tênis 2", 202, 3, 149.99f); // mesmo código

    inserirProduto(lista, p1);
    inserirProduto(lista, p2); // Deve falhar silenciosamente

    munit_assert_size(lista.size(), ==, 1);
    munit_assert_string_equal(lista[0].getNome().c_str(), "Tênis");

    return MUNIT_OK;
}

// ---------- Teste 3: Buscar produto existente ----------
static MunitResult test_buscar_produto_ok(const MunitParameter params[], void* data) {
    std::vector<Produto> lista = {
        Produto("Mouse", 300, 15, 49.99f)
    };

    Produto* p = buscarProduto(lista, 300);
    munit_assert_not_null(p);
    munit_assert_string_equal(p->getNome().c_str(), "Mouse");

    return MUNIT_OK;
}

// ---------- Teste 4: Buscar produto inexistente ----------
static MunitResult test_buscar_produto_fail(const MunitParameter params[], void* data) {
    std::vector<Produto> lista = {
        Produto("Teclado", 400, 8, 99.90f)
    };

    Produto* p = buscarProduto(lista, 999);
    munit_assert_null(p);

    return MUNIT_OK;
}

// ---------- Teste 5: Remover produto ----------
static MunitResult test_remover_produto(const MunitParameter params[], void* data) {
    std::vector<Produto> lista = {
        Produto("Fone", 500, 4, 89.00f)
    };

    bool removido = removerProduto(lista, 500);
    munit_assert_true(removido);
    munit_assert_size(lista.size(), ==, 0);

    return MUNIT_OK;
}

// ---------- Teste 6: Atualizar produto ----------
static MunitResult test_atualizar_produto(const MunitParameter params[], void* data) {
    std::vector<Produto> lista = {
        Produto("Notebook", 777, 2, 2999.99)
    };

    bool ok = atualizarProduto(lista, 777, "Notebook Gamer", 3, 3499.99);
    munit_assert_true(ok);

    Produto* p = buscarProduto(lista, 777);
    munit_assert_string_equal(p->getNome().c_str(), "Notebook Gamer");
    munit_assert_int(p->getEstoque(), ==, 3);

    double esperado = 3499.99;
    double real = p->getPreco();
    munit_assert_true(std::abs(real - esperado) < 0.01);

    return MUNIT_OK;
}

// ---------- Tabela de testes ----------
static MunitTest tests[] = {
    { const_cast<char*>("/produto/inserir"), test_inserir_produto, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { const_cast<char*>("/produto/duplicado"), test_produto_duplicado, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { const_cast<char*>("/produto/buscar-ok"), test_buscar_produto_ok, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { const_cast<char*>("/produto/buscar-fail"), test_buscar_produto_fail, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { const_cast<char*>("/produto/remover"), test_remover_produto, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { const_cast<char*>("/produto/atualizar"), test_atualizar_produto, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// ---------- Suite de testes ----------
static const MunitSuite suite = {
    const_cast<char*>("/meus-testes"), tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}

