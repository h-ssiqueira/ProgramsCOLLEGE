function Rei(tipo, posI, posJ, id){
    Peca.call(this, tipo, posI, posJ, id);
}

Rei.prototype = Object.create(Peca.prototype);
Rei.prototype.mover = function(tabuleiro,i,j){
    var destino = tabuleiro.getPeca(i,j);
    if((Math.abs(this.getPosI() - i) == 1 || this.getPosI() - i == 0) && (Math.abs(this.getPosJ() - j) == 1 || this.getPosJ() - j == 0)){ // Validade do movimento
        if(destino == null || destino.getTipo() != this.getTipo()) // Caso não tenha peça do mesmo tipo ou espaço vazio
            return true;
    }
    return false;
}
/*
Checagem de mesma posição é realizada na função chamadora
  -1 0 1
-1|_|_|_|
 0|_|P|_|
 1|_|_|_|
*/