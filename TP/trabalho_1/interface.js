var jogo = new JogoXadrez();

function init(){
	gerar_tabuleiro();
	reiniciar_jogo();
}

function select(i,j){
	var tabuleiro = document.getElementById('tabuleiro');
	var obj = tabuleiro.rows[i].cells[j]
	var vitoria = jogo.confereFinal();
	var id;
	if(vitoria == 2)
		alert("Vitória do jogador com as peças pretas. Reinicie o jogo para mais uma partida!");
	else if(vitoria == 1)
		alert("Vitória do jogador com as peças brancas. Reinicie o jogo para mais uma partida!");
	else if(select.obj_clicado === undefined || select.obj_clicado === null){
		var peca = jogo.getPeca(i, j);
		if(peca == null)
			return;
		select.obj_clicado = obj;
		select.obj_bgcolor = obj.style.backgroundColor;
		select.peca = peca;
		obj.style.backgroundColor = "green";
	}
	else if(jogo.moverPeca(select.peca, i, j)){
		select.obj_clicado.style.backgroundColor = select.obj_bgcolor;
		select.obj_clicado = null;
		vitoria = jogo.confereFinal();
		if(vitoria == 2)
			alert("Vitória do jogador com as peças pretas. Reinicie o jogo para mais uma partida!");
		else if(vitoria == 1)
			alert("Vitória do jogador com as peças brancas. Reinicie o jogo para mais uma partida!");
		else if(jogo.conferePromocao(select.peca)){
			do{
				id = prompt("Digite o número para escolher a promoção do peão:\n1 - Dama\n2 - Cavalo \n3 - Bispo\n4 - Torre");
			}while(!jogo.promocao(select.peca,id));
		}
		atualizar_jogo();
	}
	else{
		select.obj_clicado.style.backgroundColor = select.obj_bgcolor;
		select.obj_clicado = null;
		alert("Movimento invalido!");
	}
}

function atualizar_jogo(){
	const pecas = [" ", "♔", "♕", "♖", "♗", "♘", "♙", "♚", "♛", "♜", "♝", "♞", "♟"];
	let tabuleiro = document.getElementById('tabuleiro');
	let tabData = jogo.getTabuleiro();
	for(var i = 0, n = tabuleiro.rows.length; i < n; i++){
		for(var j = 0, m = tabuleiro.rows[i].cells.length; j < m; j++){
			obj = tabuleiro.rows[i].cells[j]
			obj.innerHTML = pecas[tabData[i][j]];
		}
	}
}

function reiniciar_jogo(){
	jogo.reiniciar();
	atualizar_jogo();
}

function gerar_tabuleiro(){
	var table = "<table id=\"tabuleiro\">";
	var color = false;
	for(var i = 0; i < 8; i++){
		table += "<tr>";
		for(var j = 0; j < 8; j++){
			if(color){
				table += "<td id=\"i" + i + "j" + j + "\" bgcolor=\"silver\" onclick=\"select(" + i + "," + j + ");\"></td>";
			}
			else{
				table += "<td id=\"i" + i + "j" + j + "\" bgcolor=\"white\" onclick=\"select(" + i + "," + j + ");\"></td>";
			}
			color = !color;
		}
		table += "</tr>";
		color = !color;
	}
	table += "</table>";
	document.write(table);
}

init();
