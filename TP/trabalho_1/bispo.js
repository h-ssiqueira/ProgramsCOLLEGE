function Bispo(tipo, posI, posJ, id){
    Peca.call(this, tipo, posI, posJ, id);
}

Bispo.prototype = Object.create(Peca.prototype);
Bispo.prototype.mover = function(tabuleiro,i,j){
    var destino = tabuleiro.getPeca(i,j),indexi,indexj;
    if(destino == null || destino.getTipo() != this.getTipo()){ // Caso não tenha peça do mesmo tipo ou espaço vazio
        if(Math.abs(this.getPosI() - i) === Math.abs(this.getPosJ()-j)){ // Validade do movimento
            if(this.getPosI() - i > 0){ // Confere se há peças acima
                indexi = this.getPosI()-1;
                if(this.getPosJ() - j > 0){ // E na esquerda
                    indexj = this.getPosJ()-1;
                    while(indexi > i){
                        destino = tabuleiro.getPeca(indexi,indexj);
                        if(destino != null)
                            return false;
                        indexi--;
                        indexj--;
                    }
                }
                else if(this.getPosJ() - j < 0){ // E na direita
                    indexj = this.getPosJ()+1;
                    while(indexi > i){
                        destino = tabuleiro.getPeca(indexi,indexj);
                        if(destino != null)
                            return false;
                        indexi--;
                        indexj++;
                    }
                }
            }
            else if(this.getPosI() - i < 0){ // Confere se há peças abaixo
                indexi = this.getPosI()+1;
                if(this.getPosJ() - j > 0){ // E na esquerda
                    indexj = this.getPosJ()-1;
                    while(indexi < i){
                        destino = tabuleiro.getPeca(indexi,indexj);
                        if(destino != null)
                            return false;
                        indexi++;
                        indexj--;
                    }
                }
                else if(this.getPosJ() - j < 0){ // E na direita
                    indexj = this.getPosJ()+1;
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