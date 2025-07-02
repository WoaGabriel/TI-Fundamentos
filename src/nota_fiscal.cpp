#include "nota_fiscal.hpp"
#include <iostream>
#include <iomanip>

// ---------- Construtor ----------
NotaFiscal::NotaFiscal(Comprador comprador)
    : comprador(comprador), totalVenda(0.0f), frete(0.0f) {}

// ---------- Adiciona um item à nota ----------
void NotaFiscal::adicionarItem(const Produto& produto, int quantidade) {
    float total = produto.getPreco() * quantidade;
    itens.push_back({produto, quantidade, total});
    totalVenda += total;
}

// ---------- Calcula o frete com base no valor total ----------
void NotaFiscal::calcularTotal() {
    if (totalVenda <= 100.0f) {
        frete = 30.0f;
    } else if (totalVenda <= 300.0f) {
        frete = 20.0f;
    } else {
        frete = 0.0f;
    }
}

// ---------- Exibe a nota fiscal formatada ----------
void NotaFiscal::emitirNota() const {
    std::cout << "\n====== NOTA FISCAL ======\n";
    comprador.exibir();

    std::cout << "\n--- Itens Comprados ---\n";
    for (const auto& item : itens) {
        std::cout << "- " << item.produto.getNome()
                  << " | Qtd: " << item.quantidade
                  << " | Preço unitário: R$ " << std::fixed << std::setprecision(2) << item.produto.getPreco()
                  << " | Total: R$ " << item.precoTotal << "\n";
    }

    std::cout << "\nTotal da venda: R$ " << totalVenda;
    std::cout << "\nFrete: R$ " << frete;
    std::cout << "\nTotal geral: R$ " << (totalVenda + frete) << "\n";
    std::cout << "=========================\n";
}

// ---------- Retorna o total da venda (sem frete) ----------
float NotaFiscal::getTotal() const {
    return totalVenda;
}
