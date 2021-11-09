//var game = new BattleShip();

function init(){
	generate_table();
	restart_game();
}

function select(i,j){
	var table = document.getElementById('table1');
	var obj = table.rows[i].cells[j]
	var vitoria = game.confereFinal(); //////TODO
	if(vitoria == 2)
		alert("Vitória do jogador 2. Reinicie o game para mais uma partida!");
	else if(vitoria == 1)
		alert("Vitória do jogador 1. Reinicie o game para mais uma partida!");
	else if(select.obj_clicado === undefined || select.obj_clicado === null){
		var peca = game.getPeca(i, j);
		if(peca == null)
			return;
		select.obj_clicado = obj;
		select.obj_bgcolor = obj.style.backgroundColor;
		select.peca = peca;
		obj.style.backgroundColor = "green";
	}
	else if(game.moverPeca(select.peca, i, j)){
		select.obj_clicado.style.backgroundColor = select.obj_bgcolor;
		select.obj_clicado = null;
		vitoria = game.confereFinal();
		if(vitoria == 2)
			alert("Vitória do jogador 2. Reinicie o game para mais uma partida!");
		else if(vitoria == 1)
			alert("Vitória do jogador 1. Reinicie o game para mais uma partida!");
		atualizar_game();
	}
	else{
		select.obj_clicado.style.backgroundColor = select.obj_bgcolor;
		select.obj_clicado = null;
		alert("Movimento invalido!");
	}
}

// Change the color of a cell according with the number in matrix
function update_game(){
	let tab = document.getElementById('table1');
	let tabData = game.getTab();
	for(var i = 0, n = tab.rows.length; i < n; i++){
		for(var j = 0, m = tab.rows[i].cells.length; j < m; j++){
            obj = tab.rows[i].cells[j]
            if(tabData[i][j] == 1) // Shot in water
                obj.style.backgroundColor = "aqua";
            else if(tabData[i][j] instanceof Object && tabData[i][j].destroyed) // Shot in ship
                obj.style.backgroundColor = "red";
            else
                obj.style.backgroundColor = "grey";
		}
	}
}

function restart_game(){
	game.restart();
	update_game();
}

function generate_table(){
	var table = "<table id=\"table1\" class=\"tables\">";
	for(var i = 0; i < 10; i++){
		table += "<tr>";
		for(var j = 0; j < 10; j++){
			table += "<td id=\"i" + i + "j" + j + "\" bgcolor=\"grey\" onclick=\"select(" + i + "," + j + ");\"></td>";
		}
		table += "</tr>";
	}
	table += "</table>";
	document.write(table);
    table = "<table id=\"table2\" class=\"tables\">";
	for(var i = 0; i < 10; i++){
		table += "<tr>";
		for(var j = 0; j < 10; j++){
			table += "<td id=\"i" + i + "j" + j + "\" bgcolor=\"grey\" onclick=\"select(" + i + "," + j + ");\"></td>";
		}
		table += "</tr>";
	}
	table += "</table>";
	document.write(table);
}

init();
