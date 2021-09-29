function Peao(tipo, posI, posJ, id){
    Peca.call(this, tipo, posI, posJ, id);
    tipo == "branca" ? this.acres = false : this.acres = true;
    this.enPassant = false;
}

Peao.prototype = Object.create(Peca.prototype);
Peao.prototype.mover = function(tabuleiro,i,j){
    var destino = tabuleiro.getPeca(i,j);
    return true;
    /*if(this.posI - i <= 1 && this.posI - i >= -1 && this.posJ - j <= 1 && this.posJ - j >= -1 && destino.tipo != this.tipo){
        console.log("entrou");
        
    }
    return false;*/
}
/*
Checagem de mesma posição é realizada na função chamadora
  -1 0 1
-2|X|_|X|
-1|_|_|_|
 0|X|P|X|
 1|_|_|_|
 2|X|_|X|
*/