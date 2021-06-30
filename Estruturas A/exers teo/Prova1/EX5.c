int  ElementoComun( Fila *F1,  Fila *F2){
    Fila *aux1 = Cria_Fila(),*aux2 = Cria_Fila();
    int n = 0, conf, verificacao, flag = 0;
    
    while(vazia_F(F1)){
        verificacao = remove_F(F1); //retira um elemento da primeira fila 
        
        while(vazia_F(F2)){ //para conferir com todos os demais da segunda
            conf = remove_F(F2);
            
            if(verificacao == conf)
                flag++; //caso seja elementos iguais a flag eh acionada
                
            insere_F(aux2,conf); //colocando os valores da segunda numa auxiliar
        }
        
        while(vazia_F(aux2)) //retorna os valores da auxiliar da segunda para F2
            insere_F(F2,remove_F(aux2));
        
        if(flag != 0){ //verificaçao de elementos iguais
            n++;
            flag = 0;
        }
        
        insere_F(aux1,verificacao);//colocando os valores da primeira numa auxiliar
    }
    
    while(vazia_F(aux1)) //retorna os valores da auxiliar da primeira para F1
        insere_F(F1,remove_F(aux1));
    
    libera_F(aux1);
    libera_F(aux2);   
    return n;
}
