function Bispo(tipo, posI, posJ, id){
    Peca.call(this, tipo, posI, posJ, id);
}

Bispo.prototype = Object.create(Peca.prototype);
Bispo.prototype.mover = function(tabuleiro,i,j){
    var destino = tabuleiro.getPeca(i,j),indexi,indexj;
    if(destino == null || destino.tipo != this.tipo){ // Caso não tenha peça do mesmo tipo ou espaço vazio
        if(Math.abs(this.posI - i) === Math.abs(this.posJ-j)){ // Validade do movimento
            if(this.posI - i > 0){ // Confere se há peças acima
                indexi = this.posI-1;
                if(this.posJ - j > 0){ // E na esquerda
                    indexj = this.posJ-1;
                    while(indexi > i){
                        destino = tabuleiro.getPeca(indexi,indexj);
                        if(destino != null)
                            return false;
                        indexi--;
                        indexj--;
                    }
                }
                else if(this.posJ - j < 0){ // E na direita
                    indexj = this.posJ+1;
                    while(indexi > i){
                        destino = tabuleiro.getPeca(indexi,indexj);
                        if(destino != null)
                            return false;
                        indexi--;
                        indexj++;
                    }
                }
            }
            else if(this.posI - i < 0){ // Confere se há peças abaixo
                indexi = this.posI+1;
                if(this.posJ - j > 0){ // E na esquerda
                    indexj = this.posJ-1;
                    while(indexi < i){
                        destino = tabuleiro.getPeca(indexi,indexj);
                        if(destino != null)
                            return false;
                        indexi++;
                        indexj--;
                    }
                }
                else if(this.posJ - j < 0){ // E na direita
                    indexj = this.posJ+1;
                    while(indexi < i){
                        destino = tabuleiro.getPeca(indexi,indexj);
                        if(destino != null)
                            return false;
                        indexi++;
                        indexj++;
                    }
                }
            }
            return true;
        }
    }
    return false;
}
/*
Checagem de mesma posição é realizada na função chamadora
  -2-1 0 1 2
-2|_|X|X|X|_|
-1|X|_|X|_|X|
 0|X|X|P|X|X|
 1|X|_|X|_|X|
 2|_|X|X|X|_|
*/