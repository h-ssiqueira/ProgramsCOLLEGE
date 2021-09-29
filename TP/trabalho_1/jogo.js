function JogoXadrez(){

	var tabuleiro = new Tabuleiro();
	// Esse método retorna um array 8x8 contendo o estado do tabuleiro.
	this.getTabuleiro = function(){
		return tabuleiro.getRepresentacao();
	}

	// Esse método reinicia o jogo.
	this.reiniciar = function(){
		var j = 0;
		while(j < 8){
			switch(j){
				case 0: // Colocando as torres pretas
				case 7:
					tabuleiro.addPeca(new Torre("preta",0,j,B_ROOK));
					break;
				case 1: // Colocando os cavalos pretos
				case 6:
					tabuleiro.addPeca(new Cavalo("preta",0,j,B_KNIGHT));
					break;
				case 2: // Colocando os bispos pretos
				case 5:
					tabuleiro.addPeca(new Bispo("preta",0,j,B_BISHOP));
					break;
				case 3: // Colocando a rainha preta
					tabuleiro.addPeca(new Dama("preta",0,j,B_QUEEN));
					break;
				case 4: // Colocando o rei preto
					tabuleiro.addPeca(new Rei("preta",0,j,B_KING));
					break;
			}
			j++;
		}
		j = 0;
		while(j < 8){
			tabuleiro.addPeca(new Peao("preta",1,j,B_PAWN));
			j++;
		}
		for(var i = 2; i < 6; i++){
			for(j = 0; j < 8; j++)
				tabuleiro.addPeca(new Peao("",i,j,0)); // ID_1 = 0
		}
		j = 0;
		while(j < 8){
			tabuleiro.addPeca(new Peao("branca",6,j,W_PAWN));
			j++;
		}
		j = 0;
		while(j < 8){
			switch(j){
				case 0: // Colocando as torres brancas
				case 7:
					tabuleiro.addPeca(new Torre("branca",7,j,W_ROOK));
					break;
				case 1: // Colocando os cavalos brancos
				case 6:
					tabuleiro.addPeca(new Cavalo("branca",7,j,W_KNIGHT));
					break;
				case 2: // Colocando os bispos brancos
				case 5:
					tabuleiro.addPeca(new Bispo("branca",7,j,W_BISHOP));
					break;
				case 3: // Colocando a rainha branca
					tabuleiro.addPeca(new Dama("branca",7,j,W_QUEEN));
					break;
				case 4: // Colocando o rei branco
					tabuleiro.addPeca(new Rei("branca",7,j,W_KING));
					break;
			}
			j++;
		}
	}

	// Esse método retorna uma referência para o objeto peça que está na posição i,j do tabuleiro.
	// Se a posição não tiver uma peça pertencente ao jogador atual, esse método deve retornar null;
	this.getPeca = function(i, j){
		return tabuleiro.getPeca(i,j);
	}

	// Esse método move a peça para a posição i, j do tabuleiro.
	// Se o movimento não for possível, esse método deve retornar false. Caso contrário, deve retornar true;
	// Não é necessário se preocupar com a existência de outra peça. Caso a posição final da peça esteja ocupada por outra, a peça deverá ser substituída pela nova.
	// Sempre que esse método for executado com sucesso (retornando true) o turno deve ser atualizado, passando o controle para o outro jogador. Obs: não é permitido que o usuário mova uma peça de outro jogador.
	this.moverPeca = function(peca, i, j){
		// Não pode mover uma peça para fora do tabuleiro e nem para o mesmo lugar
		if(i > 7 || i < 0 || j > 7 || j < 0 || (peca.posI == i && peca.posJ == j))
			return false;
		if(peca.mover(tabuleiro,i,j)){
			if(tabuleiro.rmPeca(peca.posI,peca.posJ))
				console.log("Removido da posição antiga");
			else
				console.log("Não foi possível remover");
			peca.posI = i;
			peca.posJ = j;
			tabuleiro.addPeca(peca);
			return true;
		}
		return false;
	}
}
