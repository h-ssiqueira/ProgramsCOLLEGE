Fila * transforma( Pilha *P){
    Pilha *aux = Cria_Pilha();
    Fila *F = Cria_Fila();
    
    while(vazia_P(P)) //inverte a pilha para uma auxiliar
        push(aux,pop(P));
        
    while(vazia_P(aux)){ //esvazia a pilha auxiliar para a fila para ficar na ordem correta
        insere_F(F,pop(aux));
    }
    libera_P(P); //desaloca a pilha recebida
    libera_P(aux); //desaloca a pilha auxiliar
    return F;
}
