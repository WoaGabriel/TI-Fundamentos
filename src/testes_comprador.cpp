extern "C" {
    #include "../lib/munit.h"
}

#include "../src/comprador.hpp"
#include <vector>

// ---------- Teste 1: Inserção de comprador ----------
static MunitResult test_inserir_comprador(const MunitParameter params[], void* data) {
    std::vector<Comprador> lista;
    Comprador c("João", "123.456.789-00", "joao@email.com", "Rua A", "Centro", "BH", "MG", "30100-000");

    inserirComprador(lista, c);

    munit_assert_size(lista.size(), ==, 1);
    munit_assert_string_equal(lista[0].getCPF().c_str(), "123.456.789-00");

    return MUNIT_OK;
}

// ---------- Teste 2: CPF duplicado ----------
static MunitResult test_comprador_duplicado(const MunitParameter params[], void* data) {
    std::vector<Comprador> lista;
    Comprador c1("Maria", "111.111.111-11", "maria@email.com", "Rua B", "Bairro", "SP", "SP", "00000-000");
    Comprador c2("Maria 2", "111.111.111-11", "maria2@email.com", "Rua C", "Bairro", "SP", "SP", "00000-000");

    inserirComprador(lista, c1);
    inserirComprador(lista, c2);

    munit_assert_size(lista.size(), ==, 1); // deve continuar com só 1

    return MUNIT_OK;
}

// ---------- Teste 3: Buscar comprador existente ----------
static MunitResult test_buscar_comprador_ok(const MunitParameter params[], void* data) {
    std::vector<Comprador> lista = {
        Comprador("Lucas", "999.999.999-99", "lucas@email.com", "Rua D", "Bairro", "RJ", "RJ", "20000-000")
    };

    Comprador* c = buscarComprador(lista, "999.999.999-99");
    munit_assert_not_null(c);
    munit_assert_string_equal(c->getNome().c_str(), "Lucas");

    return MUNIT_OK;
}

// ---------- Teste 4: Buscar comprador inexistente ----------
static MunitResult test_buscar_comprador_fail(const MunitParameter params[], void* data) {
    std::vector<Comprador> lista = {
        Comprador("Ana", "888.888.888-88", "ana@email.com", "Rua E", "Bairro", "PR", "PR", "80000-000")
    };

    Comprador* c = buscarComprador(lista, "000.000.000-00");
    munit_assert_null(c);

    return MUNIT_OK;
}

// ---------- Teste 5: Remover comprador ----------
static MunitResult test_remover_comprador(const MunitParameter params[], void* data) {
    std::vector<Comprador> lista = {
        Comprador("Carlos", "555.555.555-55", "carlos@email.com", "Rua F", "Bairro", "CE", "CE", "60000-000")
    };

    bool ok = removerComprador(lista, "555.555.555-55");
    munit_assert_true(ok);
    munit_assert_size(lista.size(), ==, 0);

    return MUNIT_OK;
}

// ---------- Teste 6: Atualizar comprador ----------
static MunitResult test_atualizar_comprador(const MunitParameter params[], void* data) {
    std::vector<Comprador> lista = {
        Comprador("Pedro", "777.777.777-77", "pedro@email.com", "Rua G", "Bairro", "SC", "SC", "88000-000")
    };

    bool ok = atualizarComprador(lista, "777.777.777-77", "Pedro Silva", "pedro.silva@email.com");
    munit_assert_true(ok);

    Comprador* c = buscarComprador(lista, "777.777.777-77");
    munit_assert_string_equal(c->getNome().c_str(), "Pedro Silva");

    return MUNIT_OK;
}

// ---------- Tabela de testes ----------
static MunitTest tests[] = {
    { const_cast<char*>("/comprador/inserir"), test_inserir_comprador, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { const_cast<char*>("/comprador/duplicado"), test_comprador_duplicado, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { const_cast<char*>("/comprador/buscar-ok"), test_buscar_comprador_ok, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { const_cast<char*>("/comprador/buscar-fail"), test_buscar_comprador_fail, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { const_cast<char*>("/comprador/remover"), test_remover_comprador, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { const_cast<char*>("/comprador/atualizar"), test_atualizar_comprador, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// ---------- Suite de testes ----------
static const MunitSuite suite = {
    const_cast<char*>("/comprador-testes"), tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
