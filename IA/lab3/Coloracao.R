#Coloração de grafos através de uma matriz de adjacência
#Definir o Tamanho da Matriz na variavel Tam

#Grupo
#Rafael Silva Barbon
#Henrique Sartori Siqueira
#Derek Freire Quaresma
#Joao Lucas
#Rafael Daibes

library(igraph)

# Tamanho de linhas/colunas da matriz de adjacencia
# No caso do Brasil, 26 estados e o DF
Tam <- 27
# Lê o arquivo CSV com dados separados por vírgula
matriz <- read.table(row.name = 1, file=file.choose(), header = TRUE, sep=',')
# Para montar a matriz
matriz_adjacencia <- as.matrix(matriz)
# E transformá-la em grafo
Grafo <- graph_from_adjacency_matrix(matriz_adjacencia, mode='undirected', weighted=TRUE)
# Para calcular o grau de cada vértice
GrauDegree <- degree(Grafo)
# E ordenar decrescivamente
GrCGrauD = sort(GrauDegree, decreasing = TRUE)
# Colorindo todos os vértices em preto, simbolizando que não foram coloridos ainda
for(i in 1:Tam){ #27_vértices
    V(Grafo)[i]$color <- c("black")
}

# Exibe o grafo
plot.igraph(Grafo)

# Atribui a lista de cores possíveis
colors <- c("green", "yellow", "blue", "white", "orange", "red", "purple", "brown")# Precisa de no máximo 8 cores, de acordo com o maior grau
# Index para a lista de cores
cor <- 0
# Loop do algoritmo para colorir todos os vértices, iniciando no vértice de maior grau
for(i in 1:Tam){ #27_vértices
    # Encontra um vértice sem cor
    if(V(Grafo)[names(GrCGrauD[i])]$color == "black"){
        # Atribui uma nova cor
        cor <- cor + 1
        if(cor == 8){ # Reinicia o index se passar do limite da lista
            cor <- 1
        }
        # Pinta o vértice com a cor selecionada
        V(Grafo)[names(GrCGrauD[i])]$color <- c(colors[cor])
        # Atualiza na exibição do grafo
        plot.igraph(Grafo)
        # Usado para debug e também para observar o passo a passo na coloração do grafo, pressione enter para continuar a execução
        browser()
        # Coleta o nome da cor que será usada
        cc <- V(Grafo)[names(GrCGrauD[i])]$color
        # Isola o vértice em que as posições não adjacentes ao mesmo serão analisadas
        Vertice <- V(Grafo)[names(GrCGrauD[i])]
        # Percorre a lista de vertices ordenados por grau e colore o próximo vértice da lista não adjacente a ele
        for(j in i:Tam){
            # Coleta um vértice do grafo
            VerticeProx <- V(Grafo)[names(GrCGrauD[j])]
            # E verifica se ambos não são adjacentes e se o próximo ainda não foi colorido
            if(Grafo[names(Vertice)][names(VerticeProx)] == 0 && V(Grafo)[names(VerticeProx)]$color == "black"){
                # flag para indicar se é possível pintar
                Flag <- 0
                # Verifica se algum dos vértices adjacentes de Vertice prox possui cc(a cor que o vértice será pintado), se sim, não pinta
                for(k in 1:Tam){
                    # Caso ache um vértice adjacente que possui a mesma cor que receberia o vértice atual
                    if(Grafo[names(VerticeProx)][k] == 1 && V(Grafo)[names(Grafo[names(VerticeProx)][k])]$color == cc)
                        # Seta a flag, invalidando a coloração
                        Flag <- 1
                }
                # Verifica se é possível colorir sem que haja dois vértices adjacentes com a mesma cor
                if(Flag == 0){
                    # Atribui a cor ao vértice
                    V(Grafo)[VerticeProx]$color <- cc
                    # Atualiza a exibição do grafo
                    plot.igraph(Grafo)
                    # Usado para debug e também para observar o passo a passo na coloração do grafo, pressione enter para continuar a execução
                    browser()
                }
            }
        }
    }
}

plot.igraph(Grafo)