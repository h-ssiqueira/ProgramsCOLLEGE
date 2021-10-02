function Tabuleiro(){
	var tabuleiro = new Array(8);
	for(var i = 0; i < 8; i++){
		tabuleiro[i] = new Array(8);
		for(j = 0; j < 8; j++)
			tabuleiro[i][j] = 0; // ID_1 = 0
	}

    // Esse método retorna um array 8x8 contendo o estado do tabuleiro.
	this.getRepresentacao = function(){
        var tab = new Array(8);
        for(var i = 0; i < 8; i++){
            tab[i] = new Array(8);
            for(j = 0; j < 8; j++)
                tabuleiro[i][j] != 0 ? tab[i][j] = tabuleiro[i][j].getId() : tab[i][j] = 0;
        }
        return tab;
	}

    // Esse método retorna uma referência para o objeto peça que está na posição i,j do tabuleiro.
	// Se a posição não tiver uma peça pertencente ao jogador atual, esse método deve retornar null;
	this.getPeca = function(i, j){
		if(i < 8 && i >= 0 && j < 8 && j >= 0 && tabuleiro[i][j] != 0)
			return tabuleiro[i][j];
		return null;
	}

    // Remove uma peça do tabuleiro
    this.rmPeca = function(i,j){
        if(i > 7 || i < 0 || j > 7 || j < 0)
            return false;
        tabuleiro[i][j] = 0;
        //console.log("Removido da posição antiga");
        return true;
    }

    // Adiciona um peça ao tabuleiro
    this.addPeca = function(peca){
        if(peca.getId() == 0){
            tabuleiro[peca.getPosI()][peca.getPosJ()] = 0;
            //console.log("Posição liberada");
        }
        else{
            tabuleiro[peca.getPosI()][peca.getPosJ()] = peca;
            //console.log("Peça movida para nova posição");
        }
    }

}
