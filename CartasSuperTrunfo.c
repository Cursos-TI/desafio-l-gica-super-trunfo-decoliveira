#include <stdio.h>

int main(){
    char estado1, estado2;
    char numero1[4], numero2[4];
    char cidade1[50], cidade2[50];
    char sigla1[4], sigla2[4];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontosturisticos1, pontosturisticos2;
    float densidadepopulacional1, densidadepopulacional2;
    float pibpercapita1, pibpercapita2;
    float superpoder1, superpoder2;

    // ENTRADAS - CARTA 1
    printf("\n\nCARTA 1\n\n");
    printf("Digite a letra de um Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Digite um número(1-4): ");
    scanf("%s", numero1);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", cidade1); // aceita nomes compostos

    printf("Digite a sigla do Estado: ");
    scanf(" %s", &sigla1);

    printf("Digite a população: ");
    scanf("%lu", &populacao1);

    printf("Digite a área da cidade(km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &pontosturisticos1);

    // ENTRADAS - CARTA 2
    printf("\n\nCARTA 2\n\n");
    printf("Digite a letra de um Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Digite um número(1-4): ");
    scanf("%s", numero2);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", cidade2);

    printf("Digite a sigla do Estado: ");
    scanf(" %s", &sigla2);

    printf("Digite a população: ");
    scanf("%lu", &populacao2);

    printf("Digite a área da cidade(km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &pontosturisticos2);

    // CÁLCULOS CARTA 1
    densidadepopulacional1 = (float)populacao1 / area1;
    pibpercapita1 = (pib1 * 1000000000) / populacao1;
    superpoder1 = populacao1 + area1 + (pib1 * 1000000000) + 
                  pontosturisticos1 + pibpercapita1 + (1 / densidadepopulacional1);

    // CÁLCULOS CARTA 2
    densidadepopulacional2 = (float)populacao2 / area2;
    pibpercapita2 = (pib2 * 1000000000) / populacao2;
    superpoder2 = populacao2 + area2 + (pib2 * 1000000000) + 
                  pontosturisticos2 + pibpercapita2 + (1 / densidadepopulacional2);

    // SAÍDA - CARTA 1
    printf("\n\nDADOS - CARTA 1 \n\n");
    printf("Estado: %c \n", estado1);
    printf("Código da Carta: %c0%s \n", estado1, numero1);
    printf("Cidade: %s \n", cidade1);
    printf("População: %lu habitantes \n", populacao1);
    printf("Área (em km²): %.2f km² \n", area1);
    printf("PIB: %.2f bilhões de reais \n", pib1);
    printf("Número de Pontos Turísticos: %d \n", pontosturisticos1);
    printf("Densidade Populacional: %.2f hab/km² \n", densidadepopulacional1);
    printf("PIB per Capita: %.2f reais \n", pibpercapita1);
    printf("Super Poder: %.2f \n", superpoder1);

    // SAÍDA - CARTA 2
    printf("\n\nDADOS - CARTA 2 \n\n");
    printf("Estado: %c \n", estado2);
    printf("Código da Carta: %c0%s \n", estado2, numero2);
    printf("Cidade: %s \n", cidade2);
    printf("População: %lu habitantes \n", populacao2);
    printf("Área (em km²): %.2f km² \n", area2);
    printf("PIB: %.2f bilhões de reais \n", pib2);
    printf("Número de Pontos Turísticos: %d \n", pontosturisticos2);
    printf("Densidade Populacional: %.2f hab/km² \n", densidadepopulacional2);
    printf("PIB per Capita: %.2f reais \n", pibpercapita2);
    printf("Super Poder: %.2f \n", superpoder2);

    // COMPARAÇÕES
    printf("\n\nCOMPARAÇÃO DE CARTAS\n\n");
    printf("População: Carta 1 venceu (%d)\n", populacao1 > populacao2);
    printf("Área: Carta 1 venceu (%d)\n", area1 > area2);
    printf("PIB: Carta 1 venceu (%d)\n", pib1 > pib2);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", pontosturisticos1 > pontosturisticos2);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", densidadepopulacional1 < densidadepopulacional2);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", pibpercapita1 > pibpercapita2);
    printf("Super Poder: Carta 1 venceu (%d)\n", superpoder1 > superpoder2);
    
    printf("\n\nCOMPETIÇÃO DE CARTAS\n\n");
    if (populacao1 > populacao2)
    {
        printf("Carta 1 - %s (%s): %lu\n", cidade1, sigla1, populacao1);
        printf("Carta 2 - %s (%s): %lu\n", cidade2, sigla2, populacao2);
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    } else
    {
        printf("Carta 1 - %s: %lu\n", cidade1, populacao1);
        printf("Carta 2 - %s: %lu\n", cidade2, populacao2);
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);    
    }  

    return 0;
}
