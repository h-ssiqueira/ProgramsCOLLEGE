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
		if(game.shotTab(i, j, false) != 0){
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
function select(i,j){
	if(game.positioning){
		var table = document.getElementById('table1');
		var obj = table.rows[i].cells[j];
		var position1 = game.getShip(i, j);
		if(select.previousObj === undefined || select.previousObj === null){ // Case a ship is not selected yet
			if(position1 == -1) // Position selected is not a ship
				return;
			select.previousObj = obj;
			select.position1 = position1;
			// Highlight the selected ship
			if(position1.type == "submarine")
				obj.style.backgroundColor = "yellow";
			else if(position1.horizontal){
				var column = position1.posJS;
				while(column <= position1.posJE){
					table.rows[position1.posIS].cells[column].style.backgroundColor = "yellow";
					column++;
				}
			}
			else{
				var row = position1.posIS;
				while(row <= position1.posIE){
					table.rows[row].cells[position1.posJS].style.backgroundColor = "yellow";
					row++;
				}
			}
			return;
		}
		else if(select.position1 == position1 && position1.type != "submarine"){ // Case the ship is the same, rotate
			if(position1.horizontal){ // Horizontal -> vertical
				var dif = position1.posJE - position1.posJS;
				game.removeShip(position1);
				if(select.position1.posIS+dif <= 9){
					if(!game.setShip(new Ship(select.position1.posIS,select.position1.posJS,select.position1.posIS+dif,select.position1.posJS)))
						game.setShip(select.position1);
				}
				else
					game.setShip(select.position1);
			}
			else{ // Vertical -> horizontal
				var dif = position1.posIE - position1.posIS;
				game.removeShip(position1);
				if(select.position1.posJS+dif <= 9){
					if(!game.setShip(new Ship(select.position1.posIS,select.position1.posJS,select.position1.posIS,select.position1.posJS+dif)))
						game.setShip(select.position1);
				}
				else
					game.setShip(select.position1);
			}
		}
		else if(position1 == -1){ // New position for the ship
			game.removeShip(select.position1);
			position1 = select.position1;
			if(position1.type == "submarine")
				game.setShip(new Ship(i,j,i,j));
			else if(position1.horizontal){
				switch(position1.type){
					case "destroyer":
						if(j+1 <= 9){
							if(!game.setShip(new Ship(i,j,i,j+1)))
								game.setShip(select.position1);
						}
						else
							game.setShip(select.position1);
						break;
					case "cruiser":
						if(j+2 <= 9){
							if(!game.setShip(new Ship(i,j,i,j+2)))
								game.setShip(select.position1);
						}
						else
							game.setShip(select.position1);
						break;
					case "battleship":
						if(j+3 <= 9){
							if(!game.setShip(new Ship(i,j,i,j+3)))
								game.setShip(select.position1);
						}
						else
							game.setShip(select.position1);
						break;
				}
			}
			else{
				switch(position1.type){
					case "destroyer":
						if(i+1 <= 9){
							if(!game.setShip(new Ship(i,j,i+1,j)))
								game.setShip(select.position1);
						}
						else
							game.setShip(select.position1);
						break;
					case "cruiser":
						if(i+2 <= 9){
							if(!game.setShip(new Ship(i,j,i+2,j)))
								game.setShip(select.position1);
						}
						else
							game.setShip(select.position1);
						break;
					case "battleship":
						if(i+3 <= 9){
							if(!game.setShip(new Ship(i,j,i+3,j)))
								game.setShip(select.position1);
						}
						else
							game.setShip(select.position1);
						break;
				}
			}
		}
		else // Ship has been selected but tried to move to another ship position
			alert("Invalid movement!");
		select.previousObj = null;
		update_game();
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
			//else if(tabData[i][j] instanceof Object) /*DEBUG*/
			//	obj.style.backgroundColor = "white";
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
			table += "<td id=\"i" + i + "j" + j + "\" bgcolor=\"grey\" onclick=\"select(" + i + "," + j + ");\"></td>";
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
