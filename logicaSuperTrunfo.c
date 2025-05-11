#include <stdio.h>
#include <stdlib.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio

    
    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);
    // 
    // (Repita para cada propriedade)

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

 

    // Declaração de variáveis
    char estado[50], estado1[50];
    char cidade[50], cidade1[50];
    char nome[50], nome1[50];
    int populacao, populacao1;
    float area, area1;
    float pib, pib1;
    int pontosT, pontosT1;

    float densidadeP, densidadeP1;
    float pibCapita, pibCapita1;

    int opcao1, opcao2;
    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;
    float soma1 = 0, soma2 = 0;

    printf("Cadastro da Primeira Cidade:\n");
    printf("Digite a sigla do Estado: "); scanf("%s", estado);
    printf("Digite o código da Cidade: "); scanf("%s", cidade);
    printf("Nome da Cidade: "); scanf("%s", nome);
    printf("População: "); scanf("%d", &populacao);
    printf("Área (Km²): "); scanf("%f", &area);
    printf("PIB (em bilhões): "); scanf("%f", &pib);
    printf("Pontos turísticos: "); scanf("%d", &pontosT);

    printf("\nCadastro da Segunda Cidade:\n");
    printf("Digite a sigla do Estado: "); scanf("%s", estado1);
    printf("Digite o código da Cidade: "); scanf("%s", cidade1);
    printf("Nome da Cidade: "); scanf("%s", nome1);
    printf("População: "); scanf("%d", &populacao1);
    printf("Área (Km²): "); scanf("%f", &area1);
    printf("PIB (em bilhões): "); scanf("%f", &pib1);
    printf("Pontos turísticos: "); scanf("%d", &pontosT1);

    // Cálculos adicionais
    densidadeP = populacao / area;
    densidadeP1 = populacao1 / area1;
    pibCapita = pib / populacao;
    pibCapita1 = pib1 / populacao1;

    // Menu dinâmico para escolha do primeiro atributo
    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Populacional\n6. PIB per Capita\n");
    scanf("%d", &opcao1);

    // Menu dinâmico para escolha do segundo atributo (excluindo o primeiro)
    printf("\nEscolha o segundo atributo para comparar (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) {
        if (i == opcao1) continue;
        switch(i) {
            case 1: printf("1. População\n"); break;
            case 2: printf("2. Área\n"); break;
            case 3: printf("3. PIB\n"); break;
            case 4: printf("4. Pontos Turísticos\n"); break;
            case 5: printf("5. Densidade Populacional\n"); break;
            case 6: printf("6. PIB per Capita\n"); break;
        }
    }
    scanf("%d", &opcao2);
    if (opcao1 == opcao2 || opcao2 < 1 || opcao2 > 6) {
        printf("Opção inválida. Encerrando programa.\n");
        return 1;
    }

    // Função para atribuir valores de comparação
    for (int i = 1; i <= 2; i++) {
        int op = (i == 1) ? opcao1 : opcao2;
        float *carta1 = (i == 1) ? &valor1_carta1 : &valor2_carta1;
        float *carta2 = (i == 1) ? &valor1_carta2 : &valor2_carta2;

        switch(op) {
            case 1: *carta1 = populacao; *carta2 = populacao1; break;
            case 2: *carta1 = area; *carta2 = area1; break;
            case 3: *carta1 = pib; *carta2 = pib1; break;
            case 4: *carta1 = pontosT; *carta2 = pontosT1; break;
            case 5: *carta1 = densidadeP; *carta2 = densidadeP1; break;
            case 6: *carta1 = pibCapita; *carta2 = pibCapita1; break;
            default: printf("Erro ao escolher atributo.\n"); return 1;
        }
    }

    // Exibição dos dados
    printf("\nComparando as cidades: %s e %s\n", nome, nome1);
    printf("Atributo 1: ");
    switch(opcao1) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Populacional\n"); break;
        case 6: printf("PIB per Capita\n"); break;
    }

    printf("%s: %.2f\n", nome, valor1_carta1);
    printf("%s: %.2f\n", nome1, valor1_carta2);

    printf("Atributo 2: ");
    switch(opcao2) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Populacional\n"); break;
        case 6: printf("PIB per Capita\n"); break;
    }

    printf("%s: %.2f\n", nome, valor2_carta1);
    printf("%s: %.2f\n", nome1, valor2_carta2);

    // Comparação dos atributos
    float pontos1 = 0, pontos2 = 0;

    // Regra especial para densidade (menor vence)
    pontos1 += (opcao1 == 5) ? (valor1_carta1 < valor1_carta2 ? 1 : 0) : (valor1_carta1 > valor1_carta2 ? 1 : 0);
    pontos2 += (opcao1 == 5) ? (valor1_carta2 < valor1_carta1 ? 1 : 0) : (valor1_carta2 > valor1_carta1 ? 1 : 0);

    pontos1 += (opcao2 == 5) ? (valor2_carta1 < valor2_carta2 ? 1 : 0) : (valor2_carta1 > valor2_carta2 ? 1 : 0);
    pontos2 += (opcao2 == 5) ? (valor2_carta2 < valor2_carta1 ? 1 : 0) : (valor2_carta2 > valor2_carta1 ? 1 : 0);

    // Soma total dos atributos
    soma1 = valor1_carta1 + valor2_carta1;
    soma2 = valor1_carta2 + valor2_carta2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", nome, soma1);
    printf("%s: %.2f\n", nome1, soma2);

    // Resultado final
    printf("\nResultado Final:\n");
    if (soma1 == soma2)
        printf("Empate!\n");
    else
        printf("Vencedor: %s\n", (soma1 > soma2) ? nome : nome1);

   
    return 0;
}
