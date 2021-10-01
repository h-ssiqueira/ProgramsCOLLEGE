function Peao(tipo, posI, posJ, id){
    Peca.call(this, tipo, posI, posJ, id);
    this.primeira = true;
}

Peao.prototype = Object.create(Peca.prototype);
Peao.prototype.getPrimeira = function(){
    return this.primeira;
}

Peao.prototype.setPrimeira = function(bool){
    this.primeira = bool;
}

Peao.prototype.mover = function(tabuleiro,i,j){
    var destino = tabuleiro.getPeca(i,j);
    if(this.getTipo() == "preta"){
        if(this.getPrimeira() && this.getPosI() == i-2 && j == this.getPosJ() && destino == null){
            this.setPrimeira(false);
            return true;
        }
        else if(this.getPosI() == i-1 && j == this.getPosJ() && destino == null){
            if(this.getPrimeira())
                this.setPrimeira(false);
            return true;
        }
        else if(this.getPosI() == i-1 && 1 == Math.abs(this.getPosJ() - j) && destino != null && destino.getTipo() == "branca"){
            if(this.getPrimeira())
                this.setPrimeira(false);
            return true;
        }
    }
    else if(this.getTipo() == "branca"){
        if(this.getPrimeira() && this.getPosI() == i+2 && j == this.getPosJ() && destino == null){
            if(this.getPrimeira())
                this.setPrimeira(false);
            return true;
        }
        else if(this.getPosI() == i+1 && j == this.getPosJ() && destino == null){
            if(this.getPrimeira())
                this.setPrimeira(false);
            return true;
        }
        else if(this.getPosI() == i+1 && 1 == Math.abs(this.getPosJ() - j) && destino != null && destino.getTipo() == "preta"){
            if(this.getPrimeira())
                this.setPrimeira(false);
            return true;
        }
    }
    return false;
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