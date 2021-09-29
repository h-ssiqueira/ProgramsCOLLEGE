function Rei(tipo, posI, posJ, id){
    Peca.call(this, tipo, posI, posJ, id);
}

Rei.prototype = Object.create(Peca.prototype);
Rei.prototype.mover = function(tabuleiro,i,j){
    var destino = tabuleiro.getPeca(i,j);
    //console.log(destino);
    if(this.posI - i <= 1 && this.posI - i >= -1 && this.posJ - j <= 1 && this.posJ - j >= -1){
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