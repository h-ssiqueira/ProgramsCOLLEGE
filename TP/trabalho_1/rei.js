function Rei(tipo, posI, posJ, id){
    Peca.call(this, tipo, posI, posJ, id);
    this.primeira = true;
}

Rei.prototype = Object.create(Peca.prototype);

Rei.prototype.checkCheque = function(tabuleiro,i,j){
    var peca;
    for(var a = 0; a < 8; a++){
		for(var b = 0; b < 8; b++){
            if((a != i || a != this.getPosI()) || (b != j && b != this.getPosJ())){
                peca = tabuleiro.getPeca(a,b);
                if(peca != null && peca.mover(tabuleiro,i,j) && peca.getTipo() != this.getTipo())
                    return true;
            }
        }
	}
    return false;
}

Rei.prototype.getPrimeira = function(){
    return this.primeira;
}

Rei.prototype.setPrimeira = function(bool){
    this.primeira = bool;
}

Rei.prototype.posLimpa = function(tabuleiro,i,j){
    var peca;
    for(var a = 0; a < 8; a++){
		for(var b = 0; b < 8; b++){
            if(this.getPosI() != a && a != i && b != j && this.getPosJ() != b){
                peca = tabuleiro.getPeca(a,b);
                if(peca != null && peca.getTipo() != this.getTipo() && peca.getId() != W_KING && peca.getId() != B_KING){
                    if(peca.getId() == B_PAWN && i-1 == peca.getPosI() && Math.abs(j-peca.getPosJ()) == 1){
                        return false;
                    }
                    else if(peca.getId() == W_PAWN && i+1 == peca.getPosI() && Math.abs(j-peca.getPosJ()) == 1){
                        return false;
                    }
                    else if(peca.getId() != B_PAWN && peca.getId() != W_PAWN && peca.mover(tabuleiro,i,j))
                        return false;
                }
            }
        }
    }
    return true;
}

Rei.prototype.mover = function(tabuleiro,i,j){
    var destino = tabuleiro.getPeca(i,j);
    //if(this.posLimpa(tabuleiro,i,j)){
        if((Math.abs(this.getPosI() - i) == 1 || this.getPosI() - i == 0) && (Math.abs(this.getPosJ() - j) == 1 || this.getPosJ() - j == 0)){ // Validade do movimento
            if(destino == null || destino.getTipo() != this.getTipo()){ // Caso não tenha peça do mesmo tipo ou espaço vazio
                if(this.getPrimeira())
                    this.setPrimeira(false);
                return true;
            }
        }
        else if(this.getPrimeira() && destino == null && !this.checkCheque(tabuleiro,this.getPosI(),this.getPosJ())){ // Roque
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
    //}
    return false;
}
/*
Checagem de mesma posição é realizada na função chamadora
  -1 0 1
-1|_|_|_|
 0|_|R|_|
 1|_|_|_|
*/