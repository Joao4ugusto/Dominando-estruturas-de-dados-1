#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "portuguese");
    int opcao;

    // Digitar o tamanho da matriz de adjacência
    int tamanho;
    do{
    	printf("Digite o tamanho da matriz de adjacência de no maximo 10: ");
    	scanf("%d", &tamanho);
   		system ("cls");
	}while (tamanho > 10 || tamanho <=0);

    int matrizAdjacencia[tamanho][tamanho];

    // Digitar os valores da matriz de adjacência
    printf("Digite os valores da matriz de adjacência:\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            scanf("%d", &matrizAdjacencia[i][j]);
        }
    }

    do {
        printf("\nSelecione uma opção:\n");
        printf("1. Verificar o grau do vértice\n");
        printf("2. Verificar se o grafo é euleriano\n");
        printf("3. Verificar se o grafo é um multigrafo\n");
        printf("4. Verificar se existe caminho entre 3 nós/vértices e se é um ciclo\n");
        printf("5. Verificar se o grafo criado é conexo ou não conexo\n");
        printf("Digite o número da opção desejada: ");
        scanf("%d/n", &opcao);

        if (opcao == 1) {
            // Calcular o grau de cada vértice
            printf("Grau de cada vértice:\n");
            for (int i = 0; i < tamanho; i++) {
                int grau = 0;
                for (int j = 0; j < tamanho; j++) {
                    if (matrizAdjacencia[i][j] != 0) {
                        grau=grau + matrizAdjacencia[i][j];
                    }
                }
                printf("Vértice %d: %d\n", i, grau);
            }
            
            
            
        } else if (opcao == 2) {
            // Verificar se o grafo é euleriano
            int euleriano = 1;
            for (int i = 0; i < tamanho; i++) {
                int grau = 0;
                for (int j = 0; j < tamanho; j++) {
                    if (matrizAdjacencia[i][j] != 0) {
                        grau=grau + matrizAdjacencia[i][j];
                    }
                }
                if (grau % 2 != 0) {
                    euleriano = 0; // Se um vértice de grau ímpar for encontrado, o grafo não é euleriano
                    break; // Sai do loop, pois já sabemos o resultado
                }
            }
            if (euleriano == 1) {
                printf("O grafo é euleriano.\n");
            } else {
                printf("O grafo não é euleriano.\n");
            }
            
            
            
        
        } else if (opcao == 3) {
            // Verificar se o grafo é um multigrafo
            int multigrafo = 0;
            for (int i = 0; i < tamanho; i++) {
                for (int j = 0; j < tamanho; j++) {
                    if (matrizAdjacencia[i][j] > 1) {
                        multigrafo = 1;
                        break;
                    }
                }
                if (multigrafo) {
                    break;
                }
            }
            if (multigrafo) {
                printf("O grafo é um multigrafo.\n");
            } else {
                printf("O grafo é um grafo simples.\n");
            }
            
            

        } else if (opcao == 4) {
            // Verificar se existe caminho entre 3 vértices e se é um ciclo
            int vertice1, vertice2, vertice3;
			printf("Digite o valor do primeiro vértice: ");
			scanf("%d", &vertice1);
			printf("Digite o valor do segundo vértice: ");
			scanf("%d", &vertice2);
			printf("Digite o valor do terceiro vértice: ");
			scanf("%d", &vertice3);
            if (matrizAdjacencia[vertice1][vertice2] != 0 && matrizAdjacencia[vertice2][vertice3] != 0) {
                printf("Existe um caminho entre os vértices %d, %d e %d.\n", vertice1, vertice2, vertice3);

                // Verificar se o caminho entre os três vértices forma um ciclo
                if (matrizAdjacencia[vertice3][vertice1] != 0) {
                    printf("O caminho entre os vértices %d, %d e %d forma um ciclo.\n", vertice1, vertice2, vertice3);
                } else {
                    printf("O caminho entre os vértices %d, %d e %d não forma um ciclo.\n", vertice1, vertice2, vertice3);
                }
            } else {
                printf("Não existe um caminho entre os vértices %d, %d e %d, portanto não existe um ciclo.\n", vertice1, vertice2, vertice3);
            }
            
            
            
            
        } else if (opcao == 5) {
            // Verificar se o grafo é conexo ou não conexo
            int visitados[tamanho];
            int contadorVisitados = 0;

            for (int i = 0; i < tamanho; i++) {
                visitados[i] = 0;
            }

            visitados[0] = 1;
            contadorVisitados++;

            while (contadorVisitados < tamanho) {
                int encontrado = 0;
                for (int i = 0; i < tamanho; i++) {
                    if (visitados[i]) {
                        for (int j = 0; j < tamanho; j++) {
                            if (!visitados[j] && matrizAdjacencia[i][j] != 0) {
                                visitados[j] = 1;
                                contadorVisitados++;
                                encontrado = 1;
                                break;
                            }
                        }
                        if (encontrado) {
                            break;
                        }
                    }
                }
                if (!encontrado) {
                    break;
                }
            }

            // Verificar se todos os vértices foram visitados
            int conexo = (contadorVisitados == tamanho);
            if (conexo) {
                printf("A matriz adjacente representa um grafo conexo.\n");
            } else {
                printf("A matriz adjacente não representa um grafo conexo.\n");
            }
            
            
        } else {
            printf("Opção inválida.\n");
        }
    } while (opcao >= 1 && opcao <= 5);
}
