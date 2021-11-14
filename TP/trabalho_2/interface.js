//var game = new BattleShip();

function init(){
	generate_table();
	restart_game();
}

function finished(){
	var win = game.checkWinner();
	if(win == 1){
		alert("Computer is the winner. Press restart to begin another game. Better luck next time!");
		finish = true;
	}
	else if(win == 2){
		alert("You are the winner, congratulations! Press restart to begin another game.");
		finish = true;
	}
}

// Choose a position to make the shot
function shotOpponent(i,j){
	if(!game.positioning && !finish && game.playerTurn){
		if(game.shotTab(i, j, false)){
			finished();
			update_game();
			if(finish)
				return;
			while(!game.playerTurn){
				game.computerShot();
				finished();
				update_game();
			}
		}
		else
			alert("Invalid shot!");
	}
	else if(game.positioning)
		alert("Click on \"Start Game\" to begin.");
	else if(finish)
		alert("Current game is over. Click on \"Restart Game\" to start a new game.");
}

// For organizing the ships
function select(i,j){ // TODO -> let player organize the ships
	if(game.positioning){
	var table = document.getElementById('table1');
	var obj = table.rows[i].cells[j];
	/*if(select.obj_clicado === undefined || select.obj_clicado === null){
		var peca = game.getPeca(i, j);
		if(peca == null)
			return;
		select.obj_clicado = obj;
		select.obj_bgcolor = obj.style.backgroundColor;
		select.peca = peca;
		obj.style.backgroundColor = "yellow";
	}
	else if(game.moverPeca(select.peca, i, j)){
		select.obj_clicado.style.backgroundColor = select.obj_bgcolor;
		select.obj_clicado = null;
		win = game.confereFinal();
		if(win == 2)
			alert("Vitória do jogador 2. Reinicie o game para mais uma partida!");
		else if(win == 1)
			alert("Vitória do jogador 1. Reinicie o game para mais uma partida!");
		atualizar_game();
	}
	else{
		select.obj_clicado.style.backgroundColor = select.obj_bgcolor;
		select.obj_clicado = null;
		alert("Movimento invalido!");
	}
*/
	}
}

// Change the color of a cell according with the number in matrix
function update_game(){
	let tab = document.getElementById('table1');
	let tabData = game.getTab1();
	for(var i = 0, n = tab.rows.length; i < n; i++){
		for(var j = 0, m = tab.rows[i].cells.length; j < m; j++){
            obj = tab.rows[i].cells[j]
            if(tabData[i][j] == 1) // Shot in water
                obj.style.backgroundColor = "aqua";
            else if(tabData[i][j] instanceof Object)
				if(tabData[i][j].destroyed) // Shot in ship
                	obj.style.backgroundColor = "red";
				else // Ship not destroyed yet
					obj.style.backgroundColor = "green";
            else // Position not shotted yet
                obj.style.backgroundColor = "grey";
		}
	}
	tab = document.getElementById('table2');
	tabData = game.getTab2();
	for(var i = 0, n = tab.rows.length; i < n; i++){
		for(var j = 0, m = tab.rows[i].cells.length; j < m; j++){
            obj = tab.rows[i].cells[j]
            if(tabData[i][j] == 1) // Shot in water
                obj.style.backgroundColor = "aqua";
            else if(tabData[i][j] instanceof Object && tabData[i][j].destroyed) // Shot in ship
                obj.style.backgroundColor = "red";
			else if(tabData[i][j] instanceof Object) /*DEBUG*/
				obj.style.backgroundColor = "white";
            else // Position not shotted yet
                obj.style.backgroundColor = "grey";
		}
	}
}

function restart_game(){
	game.restart();
	game.randomize(1);
	game.randomize(2);
	update_game();
	finish = false;
}

function start_game(){
	game.positioning = false;
	update_game();
}

function randomize(){
	game.randomize(1);
	update_game();
}

function generate_table(){
	var table = "<table id=\"table1\" class=\"tables\">";
	for(var i = 0; i < 10; i++){
		table += "<tr>";
		for(var j = 0; j < 10; j++){
			table += "<td id=\"i" + i + "j" + j + "\" draggable=\"true\" bgcolor=\"grey\" onclick=\"select(" + i + "," + j + ");\"></td>";
		}
		table += "</tr>";
	}
    table += "</table><table id=\"table2\" class=\"tables\">";
	for(var i = 0; i < 10; i++){
		table += "<tr>";
		for(var j = 0; j < 10; j++){
			table += "<td id=\"i" + i + "j" + j + "\" bgcolor=\"grey\" onclick=\"shotOpponent(" + i + "," + j + ");\"></td>";
		}
		table += "</tr>";
	}
	table += "</table>";
	document.write(table);
}

let game = new BattleShip();
var finish = false;
init();
