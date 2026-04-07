#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 

int main() {
   
   // Definição das variáveis para armazenar as propriedades das cidades
   char estado1[3], estado2[3];
   char codigo1[5], codigo2[4];
   char cidade1[30], cidade2[30];
   unsigned int populacao1, populacao2;
   float area1, area2;
   float pib1, pib2;
   unsigned int turismo1, turismo2;
    
   printf("========== JOGO SUPER TRUNFO ==========\n\n");
   printf("Menu principal\n\n");
   printf("1 - Iniciar Jogo\n");
   printf("2 - Ver Regras\n");
   printf("3 - Sair\n\n");
   printf("Digite uma opcao: ");
   int menu;
   scanf ("%d", &menu);
   printf("\n");

   switch (menu)
   {
      case 1:
         // Área para entrada de dados
         printf("Vamos comecar?\n\n");
         printf("Digite a sigla estado: \n");
         scanf("%s", estado1);
         printf("Digite o codigo da carta: \n");
         scanf(" %s", codigo1); 
         printf("Digite o nome da cidade (usando '_' no lugar do espaoo): \n");
         scanf("%s", cidade1);
         printf("Digite o numero de habitantes: \n");
         scanf("%u", &populacao1);
         printf("Digite a area dessa cidade: \n");
         scanf("%f", &area1);
         printf("Digite o PIB dessa cidade: \n");
         scanf("%f", &pib1);
         printf("Digite quantos pontos turísticos ha nessa cidade: \n");
         scanf("%u", &turismo1);
         printf("\n");

         strcpy(estado2, "M");
         strcpy(codigo2, "M01");
         strcpy(cidade2, "Cidade_das_Maquinas");
   
         // Geração dos valores para a carta da máquina
         srand(time(0));
         populacao2 = (rand() % 199995001) + 5000;
         area2 = (rand() % 149998) + 3;
         pib2 = ((rand() % 975001) + 25000) / 1000.0;
         turismo2 = (rand() % 50) + 1;
         double percapita1, percapita2;
         double densidade1, densidade2, inversa1, inversa2;

         percapita1 = (pib1 * 1000000000) / populacao1;
         percapita2 = (pib2 * 1000000000) / populacao2;

         densidade1 = (double)populacao1 / area1;
         densidade2 = (double)populacao2 / area2;

         inversa1 = 1.0 / densidade1;
         inversa2 = 1.0 / densidade2;

         double superpoder1, superpoder2;
   
         superpoder1 = populacao1 + area1 + pib1 + turismo1 + percapita1 + inversa1;
         superpoder2 = populacao2 + area2 + pib2 + turismo2 + percapita2 + inversa2;
  
         // Desenvolvolvimento da lógica de comparação entre duas cartas.
      
         printf("Hora de definir o que sera comparado!\n\n");
         printf("Escolha uma categoria para ser o criterio de comparacao para a primeira rodada.\n");
         printf("1 - Populacao\n");
         printf("2 - Area\n");
         printf("3 - PIB\n");
         printf("4 - Turismo\n");
         printf("5 - PIB Percapita\n");
         printf("6 - Densidade Populacional\n");
         printf("7 - Super Poder\n\n");
         printf("O Super Poder e a soma de todos os atributos, porem na densidade e considerado seu valor inverso (1/densidade).\n\n");

         int criterio1, criterio2;

         printf("Digite o numero do criterio da primeira rodada: ");
         scanf("%d", &criterio1);
         printf("\n");

         int resposta1, resposta2;
         double poder1a, poder2a, poderA;
         double poder1b, poder2b, poderB;

         switch(criterio1){
            case 1:
               poder1a = populacao1;
               poder1b = populacao2;
               if (populacao1 == populacao2)
               {
                 resposta1 = 2;
               } else {
                  resposta1 = (populacao1 > populacao2) ? 1 : 0;
               }
               break;
            case 2:
               poder1a = area1;
               poder1b = area2;
               if (area1 == area2)
               {
                 resposta1 = 2;
               } else {
                  resposta1 = (area1 > area2) ? 1 : 0;
               }
               break;
            case 3:
               poder1a = pib1;
               poder1b = pib2;
               if (pib1 == pib2)
               {
                 resposta1 = 2;
               } else {
                 resposta1 = (pib1 > pib2) ? 1 : 0;
               }
               break;
            case 4:
               poder1a = turismo1;
               poder1b = turismo2;
               if (turismo1 == turismo2)
               {
                 resposta1 = 2;
               } else {
                  resposta1 = (turismo1 > turismo2) ? 1 : 0;
               }
               break;
            case 5:
               poder1a = percapita1;
               poder1b = percapita2;
               if (percapita1 == percapita2)
               {
                 resposta1 = 2;
               } else {
                  resposta1 = (percapita1 > percapita2) ? 1 : 0;
               }
               break;
            case 6:
               poder1a = inversa1;
               poder1b = inversa2;
               if (densidade1 == densidade2)
               {
                 resposta1 = 2;
               } else {
                  resposta1 = (densidade1 < densidade2) ? 1 : 0;
               }
               break;
            case 7:
               poder1a = superpoder1;
               poder1b = superpoder2;
               if (superpoder1 == superpoder2)
               {
                 resposta1 = 2;
               } else {
                  resposta1 = (superpoder1 > superpoder2) ? 1 : 0;
               }
            break;
            default:
                printf("Opcao invalida. Tente novamente.\n\n");
                printf("\nPressione ENTER para sair...");
                getchar();
                getchar();
               return 0;
         }

         printf("Escolha uma categoria para ser o criterio de comparação para a segunda rodada.\n");
         if(criterio1 != 1)
         {
         printf("1 - Populacao\n");
         }
         if(criterio1 != 2)
         {
         printf("2 - Area\n");
         }
         if(criterio1 != 3)
         {
         printf("3 - PIB\n");
         }
         if(criterio1 != 4)
         {
         printf("4 - Turismo\n");
         }
         if(criterio1 != 5)
         {
         printf("5 - PIB Percapita\n");
         }
         if(criterio1 != 6)
         {
         printf("6 - Densidade Populacional\n");
         }
         if(criterio1 != 7)
         {
         printf("7 - Super Poder\n\n");
         printf("O Super Poder e a soma de todos os atributos, porem na densidade e considerado seu valor inverso (1/densidade).\n");
         }
         printf("\n");
         printf("Digite o numero do critério da segunda rodada: ");
         scanf("%d", &criterio2);
         printf("\n");

         if (criterio1 != criterio2)
            {
            switch(criterio2){
               case 1:
                  poder2a = populacao1;
                  poder2b = populacao2;
                  if (populacao1 == populacao2)
                  {
                  resposta2 = 2;
                  } else {
                     resposta2 = (populacao1 > populacao2) ? 1 : 0;
                  }
                  break;
               case 2:
                  poder2a = area1;
                  poder2b = area2;
                  if (area1 == area2)
                  {
                  resposta2 = 2;
                  } else {
                     resposta2 = (area1 > area2) ? 1 : 0;
                  }
                  break;
               case 3:
                  poder2a = pib1;
                  poder2b = pib2;
                  if (pib1 == pib2)
                  {
                  resposta2 = 2;
                  } else {
                  resposta2 = (pib1 > pib2) ? 1 : 0;
                  }
                  break;
               case 4:
                  poder2a = turismo1;
                  poder2b = turismo2;
                  if (turismo1 == turismo2)
                  {
                  resposta2 = 2;
                  } else {
                     resposta2 = (turismo1 > turismo2) ? 1 : 0;
                  }
                  break;
               case 5:
                  poder2a = percapita1;
                  poder2b = percapita2;
                  if (percapita1 == percapita2)
                  {
                  resposta2 = 2;
                  } else {
                     resposta2 = (percapita1 > percapita2) ? 1 : 0;
                  }
                  break;
               case 6:
                  poder2a = inversa1;
                  poder2b = inversa2;

                  if (densidade1 == densidade2)
                  {
                  resposta2 = 2;
                  } else {
                     resposta2 = (densidade1 < densidade2) ? 1 : 0;
                  }
                  break;
               case 7:
                  poder2a = superpoder1;
                  poder2b = superpoder2;
                  if (superpoder1 == superpoder2)
                  {
                  resposta2 = 2;
                  } else {
                     resposta2 = (superpoder1 > superpoder2) ? 1 : 0;
                  }
                  break;
               default:
                  printf("Opcao invalida. Tente novamente.\n");
                  return 0;
               }
         } else {
            printf("Os criterios devem ser diferentes. Tente novamente.\n\n");
            printf("\nPressione ENTER para sair...");
            getchar();
            getchar();
            return 0;
         }
   
         printf("Vamos aos resultados?!\n\n");
         printf("Os criterios escolhidos foram.\n\n");

         if(criterio1 == 1)
         {
         printf("Populacao &");
         }
         if(criterio1 == 2)
         {
         printf("Area &");
         }
         if(criterio1 == 3)
         {
         printf("PIB &");
         }
         if(criterio1 == 4)
         {
         printf("Turismo &");
         }
         if(criterio1 == 5)
         {
         printf("PIB Percapita &");
         }
         if(criterio1 == 6)
         {
         printf("Densidade Populacional &");
         }
         if(criterio1 == 7)
         {
         printf("Super Poder &");
         }

         if(criterio2 == 1)
         {
         printf(" Populacao\n\n");
         }
         if(criterio2 == 2)
         {
         printf(" Area\n\n");
         }
         if(criterio2 == 3)
         {
         printf(" PIB\n\n");
         }
         if(criterio2 == 4)
         {
         printf(" Turismo\n\n");
         }
         if(criterio2 == 5)
         {
         printf(" PIB Percapita\n\n");
         }
         if(criterio2 == 6)
         {
         printf(" Densidade Populacional\n\n");
         }
         if(criterio2 == 7)
         {
         printf(" Super Poder\n\n");
         }

         if (resposta1 == 2)
         {
            printf("O resultado da primeira rodada foi: Empate!\n\n");
         } else if (resposta1 == 1){
            printf("O vencedor da primeira rodada foi: %s!\n\n", cidade1);
         } else {
            printf("O vencedor da primeira rodada foi: %s!\n\n", cidade2);

         }

         if (resposta2 == 2)
         {
            printf("O resultado da segunda rodada foi: Empate!\n\n");
         } else if (resposta2 == 1){
            printf("O vencedor da segunda rodada foi: %s!\n\n", cidade1);
         } else {
            printf("O vencedor da segunda rodada foi: %s!\n\n", cidade2);
         }

         poderA = poder1a + poder2a;
         poderB = poder1b + poder2b;

         if (poderA == poderB)
         {
            printf("O resultado da terceira rodada foi: Empate!\n\n");
         } else if(poderA > poderB){
            printf("O vencedor da terceira rodada foi: %s!\n\n", cidade1);
         } else {
            printf("O vencedor da terceira rodada foi: %s!\n\n", cidade2);
         }

         printf("Agora vamos conferir os valores de cada carta para todos os criterios!?\n\n"); 
         printf("S - Sim\n");
         printf("N - Nao\n\n");
         printf("Digite a opcao: ");
         char simounao;
         scanf(" %c", &simounao);
         printf("\n");

         switch (simounao)
         {
         case 'S':
            printf("Carta 1:\n");
            printf("Estado: %s\n", estado1);
            printf("Codigo: %3s\n", codigo1);
            printf("Nome da cidade: %s\n", cidade1);
            printf("Populacao: %i\n", populacao1);
            printf("Area: %.2f km2\n", area1);
            printf("PIB: %.2f bilhoes de reais\n", pib1);
            printf("Numero de pontos turisticos: %i\n", turismo1);
            printf("Densidade Populacional: %.2f hab/km2\n", densidade1);
            printf("PIB per Capita: %.2f reais\n", percapita1);
            printf("Super Poder: %.2f\n\n", superpoder1);
            printf("Poder da terceira rodada (soma dos atributos escolhidos nos criterios 1 e 2): %.2f\n\n", poderA);

            printf("Carta 2:\n");
            printf("Estado: %s\n", estado2);
            printf("Codigo: %3s\n", codigo2);
            printf("Nome da cidade: %s\n", cidade2);
            printf("Populacao: %i\n", populacao2);
            printf("Area: %.2f km2\n", area2);
            printf("PIB: %.2f bilhoes de reais\n", pib2);
            printf("Numero de pontos turisticos: %i\n", turismo2);
            printf("Densidade Populacional: %.2f hab/km2\n", densidade2);
            printf("PIB per Capita: %.2f reais\n", percapita2);
            printf("Super Poder: %.2f\n\n", superpoder2);
            printf("Poder da terceira rodada (soma dos atributos escolhidos nos criterios 1 e 2): %.2f\n\n", poderB);
            break;
         case 's':
            printf("Carta 1:\n");
            printf("Estado: %s\n", estado1);
            printf("Codigo: %3s\n", codigo1);
            printf("Nome da cidade: %s\n", cidade1);
            printf("Populacao: %i\n", populacao1);
            printf("Area: %.2f km2\n", area1);
            printf("PIB: %.2f bilhoes de reais\n", pib1);
            printf("Numero de pontos turisticos: %i\n", turismo1);
            printf("Densidade Populacional: %.2f hab/km2\n", densidade1);
            printf("PIB per Capita: %.2f reais\n", percapita1);
            printf("Super Poder: %.2f\n\n", superpoder1);
            printf("Poder da terceira rodada (soma dos atributos escolhidos nos criterios 1 e 2): %.2f\n\n", poderA);

            printf("Carta 2:\n");
            printf("Estado: %s\n", estado2);
            printf("Codigo: %3s\n", codigo2);
            printf("Nome da cidade: %s\n", cidade2);
            printf("Populacao: %i\n", populacao2);
            printf("Area: %.2f km2\n", area2);
            printf("PIB: %.2f bilhoes de reais\n", pib2);
            printf("Numero de pontos turisticos: %i\n", turismo2);
            printf("Densidade Populacional: %.2f hab/km2\n", densidade2);
            printf("PIB per Capita: %.2f reais\n", percapita2);
            printf("Super Poder: %.2f\n\n", superpoder2);
            printf("Poder da terceira rodada (soma dos atributos escolhidos nos criterios 1 e 2): %.2f\n\n", poderB);
            break;
         case 'N':
            printf("Obrigado por jogar! Espero te ver por aqui novamente.\n");
            printf("====================================\n");
            break;
         case 'n':
            printf("Obrigado por jogar! Espero te ver por aqui novamente.\n");
            printf("====================================\n");
            break;
         default:
            printf("Opcao invalida. Tente novamente.\n\n");
            printf("\nPressione ENTER para sair...");
            getchar();
            getchar();
            return 0;
         }
         
         break;
      case 2:
        printf("========== REGRAS DO JOGO ==========\n\n");

         printf("Objetivo?\n");
         printf("O jogador deve comparar sua carta com a carta da maquina.\n");
         printf("Serão escolhidos dois criterios diferentes.\n");
         printf("Quem vencer mais rodadas ganha o jogo.\n\n");

         printf("Como funciona?\n");
         printf("1 - Voce ira cadastrar uma cidade com seus dados.\n");
         printf("*O codigo e a sigla do estado mais 01. Exemplo: XX01.*\n");
         printf("2 - A maquina gera automaticamente outra carta.\n");
         printf("3 - Voce escolhe o primeiro criterio.\n");
         printf("4 - Voce escolhe o segundo criterio (diferente do primeiro).\n");
         printf("5 - O sistema compara os valores.\n");
         printf("6 - Serao exibidos os vencedores de cada rodada.\n\n");

         printf("Como funcionam as rodadas?\n");
         printf("- Rodada 1: Primeiro criterio escolhido\n");
         printf("- Rodada 2: Segundo criterio escolhido\n");
         printf("- Rodada 3: Soma dos dois criterios anteriores\n\n");

         printf("Quais os criterios disponiveis?\n");
         printf("- Populacao (maior vence)\n");
         printf("- Area (maior vence)\n");
         printf("- PIB (maior vence)\n");
         printf("- Turismo (maior vence)\n");
         printf("- PIB Percapita (maior vence)\n");
         printf("- Densidade Populacional (menor vence)\n");
         printf("- Super Poder (soma geral dos atributos, porém na densidade e considerado seu valor inverso (1/densidade))\n\n");

         printf("Regras Importantes!\n");
         printf("- Nao repetir o mesmo criterio nas duas rodadas\n");
         printf("- Digitar apenas numeros nas opcoes do menu\n");
         printf("- Nao deixar campos vazios\n");
         printf("- Usar '_' no lugar de espacos no nome da cidade\n");
         printf("- Digitar apenas valores positivos\n\n");

         printf("!ATENCAO!\n");
         printf("- Se voce digitar alguma opcao invalida ou cometer erro, o programa sera encerrado.\n");
         printf("- Para jogar novamente, sera necessario abrir o programa novamente.\n\n");

         printf("====================================\n");
         break;
      case 3:
      printf("Aguardo seu retorno. Saindo...\n");
         break;
      default:
      printf("Opcao invalida. Tente novamente.\n");
      break;
   }  

    printf("\nPressione ENTER para sair...");
    getchar();
    getchar();
   return 0;
}
