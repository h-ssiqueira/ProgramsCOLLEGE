function Torre(tipo, posI, posJ, id){
    Peca.call(this, tipo, posI, posJ, id);
    this.primeira = true;
}

Torre.prototype = Object.create(Peca.prototype);
Torre.prototype.getPrimeira = function(){
    return this.primeira;
}

Torre.prototype.setPrimeira = function(bool){
    this.primeira = bool;
}

Torre.prototype.mover = function(tabuleiro,i,j){
    var destino = tabuleiro.getPeca(i,j),index;
    if(destino == null || destino.getTipo() != this.getTipo()){ // Caso não tenha peça do mesmo tipo ou espaço vazio
        if(this.getPosI() == i){ // Validade do movimento
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
            if(this.getPrimeira())
                this.setPrimeira(false);
            return true;
        }
        else if(this.getPosJ() == j){ // Validade do movimento
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
            if(this.getPrimeira())
                this.setPrimeira(false);
            return true;
        }
    }
    return false;
}
/*
Checagem de mesma posição é realizada na função chamadora
  -2-1 0 1 2
-2|X|X|_|X|X|
-1|X|X|_|X|X|
 0|_|_|T|_|_|
 1|X|X|_|X|X|
 2|X|X|_|X|X|
*/