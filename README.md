# Sistema de Comércio Eletrônico

Este repositório contém o trabalho interdisciplinar individual referente às disciplinas de **Fundamentos de Engenharia de Software** e **Algoritmos e Estruturas de Dados I**, com o desenvolvimento de um sistema de comércio eletrônico utilizando a linguagem C++.

## Descrição Geral

O sistema permite o cadastro de produtos e compradores, bem como a emissão de notas fiscais com cálculo automático do valor total. A implementação contempla funcionalidades completas, testes automatizados com a biblioteca MUnit e documentação detalhada.

## Funcionalidades Implementadas

- Cadastro, listagem, busca, atualização e remoção de produtos
- Cadastro, listagem, busca, atualização e remoção de compradores
- Emissão de nota fiscal com cálculo do total
- Teste manual e testes automatizados com MUnit

## Compilação e Execução

Para compilar e executar o programa principal:

g++ main.cpp produto.cpp comprador.cpp nota_fiscal.cpp -o sistema
./sistema
Testes Automatizados
Os testes foram implementados utilizando a biblioteca MUnit.

Para compilar e rodar os testes:

gcc -o test_comprador test_comprador.c comprador.cpp -lstdc++
./test_comprador

gcc -o test_produto test_produto.c produto.cpp -lstdc++
./test_produto

gcc -o test_nota_fiscal test_nota_fiscal.c nota_fiscal.cpp comprador.cpp produto.cpp -lstdc++
./test_nota_fiscal
Certifique-se de ter a biblioteca MUnit disponível localmente para compilar os testes.

Documentação
Toda a documentação está disponível no arquivo DocumentaçãoFinal.pdf, incluindo:

Backlog e organização das sprints

Documentação das funcionalidades

Planejamento e execução dos testes

Códigos-fonte comentados

Relatório final da implementação

Apresentação em Vídeo
A apresentação do projeto pode ser encontrada no arquivo video_apresentacao.mp4.

Observações
Este projeto foi desenvolvido individualmente conforme as diretrizes para alunos não matriculados em AED I, com a implementação de 3 opções de menu: Produtos, Compradores e Emissão de Nota Fiscal.

