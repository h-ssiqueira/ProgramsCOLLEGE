function Rei(tipo, posI, posJ, id){
    Peca.call(this, tipo, posI, posJ, id);
    this.primeira = true;
}

Rei.prototype = Object.create(Peca.prototype);
Rei.prototype.getPrimeira = function(){
    return this.primeira;
}

Rei.prototype.setPrimeira = function(bool){
    this.primeira = bool;
}

Rei.prototype.mover = function(tabuleiro,i,j){
    var destino = tabuleiro.getPeca(i,j);
    if((Math.abs(this.getPosI() - i) == 1 || this.getPosI() - i == 0) && (Math.abs(this.getPosJ() - j) == 1 || this.getPosJ() - j == 0)){ // Validade do movimento
        if(destino == null || destino.getTipo() != this.getTipo()){ // Caso não tenha peça do mesmo tipo ou espaço vazio
            if(this.getPrimeira())
                this.setPrimeira(false);
            return true;
        }
    }
    else if(this.getPrimeira() && destino == null){ // Roque
        if(j-this.getPosJ() == 2){ // Roque menor
            destino = tabuleiro.getPeca(i,j+1);
            if(tabuleiro.getPeca(i,j-1) == null && destino != null && (destino.getId() == W_ROOK || destino.getId() == B_ROOK) && destino.getPrimeira()){
                this.setPrimeira(false);
                return true;
            }
        }
        else if(this.getPosJ()-j == 2){ // Roque maior
            destino = tabuleiro.getPeca(i,j-2);
            if(tabuleiro.getPeca(i,j-1) == null && tabuleiro.getPeca(i,j) == null && tabuleiro.getPeca(i,j+1) == null && destino != null && (destino.getId() == W_ROOK || destino.getId() == B_ROOK) && destino.getPrimeira()){
                this.setPrimeira(false);
                return true;
            }
        }
    }
    return false;
}
/*
Checagem de mesma posição é realizada na função chamadora
  -1 0 1
-1|_|_|_|
 0|_|R|_|
 1|_|_|_|
*/