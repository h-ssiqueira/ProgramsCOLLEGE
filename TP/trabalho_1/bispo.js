function Bispo(tipo, posI, posJ, id){
    Peca.call(this, tipo, posI, posJ, id);
}

Bispo.prototype = Object.create(Peca.prototype);
Bispo.prototype.mover = function(tabuleiro,i,j){
    var destino = tabuleiro.getPeca(i,j);
    /*if(this.posI - i <= 1 && this.posI - i >= -1 && this.posJ - j <= 1 && this.posJ - j >= -1 && destino.tipo != this.tipo){
        console.log("entrou");
        return true;
    }
    return false;*/
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