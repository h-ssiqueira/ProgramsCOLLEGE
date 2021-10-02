function Cavalo(tipo, posI, posJ, id){
    Peca.call(this, tipo, posI, posJ, id);
}

Cavalo.prototype = Object.create(Peca.prototype);
Cavalo.prototype.mover = function(tabuleiro,i,j){
    var destino = tabuleiro.getPeca(i,j);
    if(!(this.getPosI() == i || this.getPosJ() == j || Math.abs(this.getPosI() - i) === Math.abs(this.getPosJ()-j)) && Math.abs(this.getPosI() - i) < 3 && Math.abs(this.getPosJ() - j) < 3){ // Validade do movimento
        if(destino == null || destino.getTipo() != this.getTipo()) // Caso não tenha peça do mesmo tipo ou espaço vazio
            return true;
    }
    return false;
}
/*
Checagem de mesma posição é realizada na função chamadora
  -2-1 0 1 2
-2|X|_|X|_|X|
-1|_|X|X|X|_|
 0|X|X|C|X|X|
 1|_|X|X|X|_|
 2|X|_|X|_|X|
*/