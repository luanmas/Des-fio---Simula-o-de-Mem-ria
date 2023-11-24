Desafio - Simulação de Memória
Introdução

O objetivo deste desafio é simular o funcionamento de um sistema de gerenciamento de memória simples, onde a memória é representada por um conjunto de espaços, alguns preenchidos e outros disponíveis. O usuário poderá solicitar a alocação de um processo na memória, e o algoritmo tentará encontrar o primeiro espaço disponível para alocar o processo.
Requisitos

    Linguagem de programação: Pode ser utilizado qualquer linguagem de programação de sua escolha.
    Utilize o conceito de arrays ou estruturas de dados adequadas para representar a memória.
    A memória pode ser representada como uma lista, onde cada elemento representa um bloco de memória.

Passos do Desafio
#1. Criar uma Simulação de Memória

Crie uma função que simule a memória, inicializando-a com uma quantidade específica de espaços (por exemplo, 2000 espaços). Essa memória deve ser representada como uma lista ou estrutura de dados equivalente.

#2. Função para Preencher Aleatoriamente a Memória

Desenvolva uma função que preencha aleatoriamente a memória com espaços disponíveis e preenchidos. Por exemplo, você pode definir que 80% dos espaços são inicialmente disponíveis, e 20% são preenchidos.

#3. Mostrar Espaços Disponíveis para o Usuário

Crie uma função que exiba para o usuário os espaços disponíveis na memória. Isso pode ser feito de maneira gráfica ou textual.

#4. Função para Alocar um Processo na Memória (First Fit)

Implemente uma função que permita ao usuário solicitar a alocação de um processo na memória. O algoritmo utilizado deve ser o "First Fit", ou seja, encontrar o primeiro espaço disponível que seja grande o suficiente para alocar o processo.

#5. Verificação de Alocação e Mensagem de Erro

Após tentar alocar o processo, verifique se a alocação foi bem-sucedida. Se sim, mostre uma mensagem indicando que o processo foi alocado com sucesso. Se não, exiba uma mensagem informando que não há memória suficiente para alocar o processo.

#6. Desafio Adicional: Implementar o "Best Fit"

Como desafio adicional, implemente uma versão do algoritmo que utiliza o "Best Fit", ou seja, encontra o espaço disponível que seja o mais próximo possível do tamanho do processo.
