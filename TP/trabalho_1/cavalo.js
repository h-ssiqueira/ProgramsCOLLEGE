function Cavalo(tipo, posI, posJ, id){
    Peca.call(this, tipo, posI, posJ, id);
}

Cavalo.prototype = Object.create(Peca.prototype);
Cavalo.prototype.mover = function(tabuleiro,i,j){
    var destino = tabuleiro.getPeca(i,j);
    if(!(this.posI == i || this.posJ == j || Math.abs(this.posI - i) === Math.abs(this.posJ-j)) && Math.abs(this.posI - i) < 3 && Math.abs(this.posJ - j) < 3){ // Validade do movimento
        if(destino == null || destino.tipo != this.tipo) // Caso não tenha peça do mesmo tipo ou espaço vazio
            return true;
    }
    return false;
}
/*
Checagem de mesma posição é realizada na função chamadora
  -2-1 0 1 2
-2|X|_|X|_|X|
-1|_|X|X|X|_|
 0|X|X|P|X|X|
 1|_|X|X|X|_|
 2|X|_|X|_|X|
*/