function Torre(tipo, posI, posJ, id){
    Peca.call(this, tipo, posI, posJ, id);
}

Torre.prototype = Object.create(Peca.prototype);
Torre.prototype.mover = function(tabuleiro,i,j){
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
-2|X|X|_|X|X|
-1|X|X|_|X|X|
 0|_|_|P|_|_|
 1|X|X|_|X|X|
 2|X|X|_|X|X|
*/