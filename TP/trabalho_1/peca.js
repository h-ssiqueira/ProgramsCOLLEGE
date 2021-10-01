// Classe abstrata para as demais peças
function Peca(tipo, posI, posJ, id){
    this.tipo = tipo;
    this.posI = posI;
    this.posJ = posJ;
    this.id = id;
}

// Getters
Peca.prototype.getTipo = function(){
    return this.tipo;
}

Peca.prototype.getPosI = function(){
    return this.posI;
}

Peca.prototype.getPosJ = function(){
    return this.posJ;
}

Peca.prototype.getId = function(){
    return this.id;
}

// Setters
Peca.prototype.setTipo = function(tipo){
    this.tipo = tipo;
}

Peca.prototype.setPosI = function(i){
    this.posI = i;
}

Peca.prototype.setPosJ = function(j){
    this.posJ = j;
}

Peca.prototype.setId = function(id){
    this.id = id;
}

Peca.prototype.mover = function(tabuleiro, i, j){
    console.log("Movendo peça...\n");
}

// Identificador de cada peça!
// Brancas
const W_KING   = 1;  // "&#9812" ♔
const W_QUEEN  = 2;  // "&#9813" ♕
const W_ROOK   = 3;  // "&#9814" ♖
const W_BISHOP = 4;  // "&#9815" ♗
const W_KNIGHT = 5;  // "&#9816" ♘
const W_PAWN   = 6;  // "&#9817" ♙
// Pretas
const B_KING   = 7;  // "&#9818" ♚
const B_QUEEN  = 8;  // "&#9819" ♛
const B_ROOK   = 9;  // "&#9820" ♜
const B_BISHOP = 10; // "&#9821" ♝
const B_KNIGHT = 11; // "&#9822" ♞
const B_PAWN   = 12; // "&#9823" ♟