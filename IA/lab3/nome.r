
#Derek Freire Quaresma 18706986
#Henrique Sartori Siqueira 19240472
#Rafael Silva Barbon 19243633
#João Lucas Fernandes da Silva 19088582
#Rafael Andrade Daiher Daibes 19086818

install.packages('igraph')


library(igraph)


matriz <- read.table(row.names=1,file=file.choose(),header = TRUE,sep = ',')

matriz

matriz_de_adjacencia <- as.matrix(matriz)

grafo <- graph_from_adjacency_matrix(matriz_de_adjacencia, mode='undirected',weighted=TRUE)

tkplot(grafo, vertex.color="light green")

degree(grafo)

closeness(grafo)

bfs(grafo,"SA")

cores <- c('green', 'red', 'blue', 'yellow')
print(cores)

tkplot(grafo, vertex.color=cores[1])
tkplot(grafo, vertex.color=cores[2])
tkplot(grafo, vertex.color=cores[3])
tkplot(grafo, vertex.color=cores[4])