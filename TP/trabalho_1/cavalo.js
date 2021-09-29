function Cavalo(tipo, posI, posJ, id){
    Peca.call(this, tipo, posI, posJ, id);
}

Cavalo.prototype = Object.create(Peca.prototype);
Cavalo.prototype.mover = function(tabuleiro,i,j){
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
-2|X|_|X|_|X|
-1|_|X|X|X|_|
 0|X|X|P|X|X|
 1|_|X|X|X|_|
 2|X|_|X|_|X|
*/