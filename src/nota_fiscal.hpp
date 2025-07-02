#ifndef NOTA_FISCAL_HPP
#define NOTA_FISCAL_HPP

#include <vector>
#include "produto.hpp"
#include "comprador.hpp"

// ---------- Estrutura que representa um item da venda ----------
struct ItemVenda {
    Produto produto;
    int quantidade;
    float precoTotal;
};

// ---------- Classe da Nota Fiscal ----------
class NotaFiscal {
private:
    Comprador comprador;
    std::vector<ItemVenda> itens;
    float totalVenda;
    float frete;

public:
    // Construtor
    NotaFiscal(Comprador comprador);

    // Adiciona um item à nota
    void adicionarItem(const Produto& produto, int quantidade);

    // Calcula o total da venda (soma de todos os itens)
    void calcularTotal();

    // Emite a nota fiscal (exibição)
    void emitirNota() const;

    // Retorna o valor total da nota (usado nos testes)
    float getTotal() const;
};

#endif
