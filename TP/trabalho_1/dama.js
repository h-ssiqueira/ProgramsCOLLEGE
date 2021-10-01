function Dama(tipo, posI, posJ, id){
    Peca.call(this, tipo, posI, posJ, id);
}

Dama.prototype = Object.create(Peca.prototype);
Dama.prototype.mover = function(tabuleiro,i,j){
    var destino = tabuleiro.getPeca(i,j),index,indexi,indexj;
    if(destino == null || destino.getTipo() != this.getTipo()){ // Caso não tenha peça do mesmo tipo ou espaço vazio
        if(Math.abs(this.getPosI() - i) === Math.abs(this.getPosJ()-j)){ // Validade do movimento nas diagonais
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
        else if(this.getPosI() == i){ // Validade do movimento na vertical
            if(this.getPosJ() > j){ // Confere se há peças a esquerda da peça
                index = this.getPosJ()-1;
                while(index > j){
                    destino = tabuleiro.getPeca(i,index);
                    if(destino != null)
                        return false;
                    index--;
                }
            }
            else{ // Confere se há peças a direita da peça
                index = this.getPosJ()+1;
                while(index < j){
                    destino = tabuleiro.getPeca(i,index);
                    if(destino != null)
                        return false;
                    index++;
                }
            }
            return true;
        }
        else if(this.getPosJ() == j){ // Validade do movimento na horizontal
            if(this.getPosI() > i){ // Confere se há peças acima da peça
                index = this.getPosI()-1;
                while(index > i){
                    destino = tabuleiro.getPeca(index,j);
                    if(destino != null)
                        return false;
                    index--;
                }
            }
            else{
                index = this.getPosI()+1;
                while(index < i){ // Confere se há peças abaixo da peça
                    destino = tabuleiro.getPeca(index,j);
                    if(destino != null)
                        return false;
                    index++;
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
-2|_|X|_|X|_|
-1|X|_|_|_|X|
 0|_|_|P|_|_|
 1|X|_|_|_|X|
 2|_|X|_|X|_|
*/