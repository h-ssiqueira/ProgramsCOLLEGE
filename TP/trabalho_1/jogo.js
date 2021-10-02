function JogoXadrez(){

	var tabuleiro = new Tabuleiro();
	// Esse método retorna um array 8x8 contendo o estado do tabuleiro.
	this.getTabuleiro = function(){
		return tabuleiro.getRepresentacao();
	}

	// Esse método reinicia o jogo.
	this.reiniciar = function(){
		var j = 0;
		jogadorW = true;
		vitoriaB = vitoriaW = false;
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
		if(i > 7 || i < 0 || j > 7 || j < 0 || (peca.getPosI() == i && peca.getPosJ() == j))
			return false;
		var anterior = tabuleiro.getPeca(i,j);
		var roque;
		if((!vitoriaB || !vitoriaW) && peca.getTipo() == "branca" && jogadorW || peca.getTipo() == "preta" && !jogadorW){
			if(peca.mover(tabuleiro,i,j)){
				if((peca.getId() == W_KING || peca.getId() == B_KING) && Math.abs(peca.getPosJ() - j) == 2){
					if(j > peca.getPosJ()){ // Roque menor
						roque = tabuleiro.getPeca(i,j+1);
						roque.setPrimeira(false);
						roque.setPosJ(peca.getPosJ()+1);
						tabuleiro.rmPeca(i,j+1);
						tabuleiro.addPeca(roque);
					}
					else{ // Roque maior
						roque = tabuleiro.getPeca(i,j-2);
						roque.setPrimeira(false);
						roque.setPosJ(peca.getPosJ()-1);
						tabuleiro.rmPeca(i,j-2);
						tabuleiro.addPeca(roque);
					}
				}
				if(tabuleiro.rmPeca(peca.getPosI(),peca.getPosJ())){
					peca.setPosI(i);
					peca.setPosJ(j);
					tabuleiro.addPeca(peca);
					if(anterior != null){ // Conferência de vitória
						if(anterior.getId() == B_KING)
							vitoriaW = true;
						else if(anterior.getId() == W_KING)
							vitoriaB = true;
					}
					if(movimentoant != null && (movimentoant.getId() == B_PAWN || movimentoant.getId() == W_PAWN) && movimentoant.getLePassant()){ // Conferência de le passant
						movimentoant.setLePassant(false);
						if(peca.getPosJ() == movimentoant.getPosJ() && (peca.getId() == B_PAWN || peca.getId() == W_PAWN) && peca.getId() != movimentoant.getId()){
							if(peca.getPosI() == 2 && movimentoant.getPosI() == 3 || peca.getPosI() == 5 && movimentoant.getPosI() == 4)
								tabuleiro.rmPeca(movimentoant.getPosI(),movimentoant.getPosJ());
						}
						else
							tabuleiro.addPeca(movimentoant);
					}
					jogadorW = !jogadorW;
					movimentoant = peca;
					return true;
				}
				else
					console.log("Não foi possível remover");
			}
		}
		return false;
	}

	// Confere se houve vitória para algum jogador
	this.confereFinal = function(){
		if(vitoriaB)
			return 2;
		else if(vitoriaW)
			return 1;
		return 0;
	}

	this.conferePromocao = function(peca){
		if(peca.getId() == W_PAWN && peca.getPosI() == 0 || peca.getId() == B_PAWN && peca.getPosI() == 7)
			return true;
		return false;
	}

	this.promocao = function(peca,id){
		if(id == 1){
			if(peca.getId() == W_PAWN)
				tabuleiro.addPeca(new Dama(peca.getTipo(),peca.getPosI(),peca.getPosJ(),W_QUEEN));
			else if(peca.getId() == B_PAWN)
				tabuleiro.addPeca(new Dama(peca.getTipo(),peca.getPosI(),peca.getPosJ(),B_QUEEN));
			return true;
		}
		else if(id == 2){
			if(peca.getId() == W_PAWN)
				tabuleiro.addPeca(new Cavalo(peca.getTipo(),peca.getPosI(),peca.getPosJ(),W_KNIGHT));
			else if(peca.getId() == B_PAWN)
				tabuleiro.addPeca(new Cavalo(peca.getTipo(),peca.getPosI(),peca.getPosJ(),B_KNIGHT));
			return true;
		}
		else if(id == 3){
			if(peca.getId() == W_PAWN)
				tabuleiro.addPeca(new Bispo(peca.getTipo(),peca.getPosI(),peca.getPosJ(),W_BISHOP));
			else if(peca.getId() == B_PAWN)
				tabuleiro.addPeca(new Bispo(peca.getTipo(),peca.getPosI(),peca.getPosJ(),B_BISHOP));
			return true;
		}
		else if(id == 4){
			if(peca.getId() == W_PAWN)
				tabuleiro.addPeca(new Torre(peca.getTipo(),peca.getPosI(),peca.getPosJ(),W_ROOK));
			else if(peca.getId() == B_PAWN)
				tabuleiro.addPeca(new Torre(peca.getTipo(),peca.getPosI(),peca.getPosJ(),B_ROOK));
			return true;
		}
		return false;
	}
}



let jogadorW = true; // booleano para a vez do jogador das peças brancas
let vitoriaB = false, vitoriaW = false; // booleanos para vitória de algum dos jogadores
var movimentoant = null;
