class Table{
    constructor(){
        this._tab = new Array(10);
	    for(var i = 0; i < 10; i++){
		    this._tab[i] = new Array(10);
		    for(var j = 0; j < 10; j++)
                this._tab[i][j] = -1;
	    }
        // Counters for destroyed ships
        this._bShip = false;
        this._cruiser = 0;
        this._destroyer = 0;
        this._submarine = 0;
    }

    get representation(){
        return this._tab;
    }

    set bShip(bool){
        this._bShip = bool;
    }

    get bShip(){
        return this._bShip;
    }

    set cruiser(n){
        this._cruiser = n;
    }

    get cruiser(){
        return this._cruiser;
    }

    set destroyer(n){
        this._destroyer = n;
    }

    get destroyer(){
        return this._destroyer;
    }

    set submarine(n){
        this._submarine = n;
    }

    get submarine(){
        return this._submarine;
    }

    shot(i,j){
        if(this._tab[i][j] == -1){ // Case shot in water
            this._tab[i][j] = 1;
            return true;
        }
        else if(this._tab[i][j] instanceof Object && this._tab[i][j].destroyed == false){ // Case shot in ship
            this._tab[i][j].destroyed = true;
            if(this._tab[i][j].type == "submarine"){ // Add one to submarines counter
                this._submarine++;
            }
            else{
                if(this._tab[i][j].horizontal){ // Check all other positions (horizontally) checking if the ship is totally destroyed
                    var index = this._tab[i][j].posJS;
                    while(index <= this._tab[i][j].posJE){
                        if(!this._tab[i][index].destroyed) // If one position is not destroyed yet, return true
                            return true;
                        index++;
                    }
                    if(this._tab[i][j].type == "cruiser") // Case all positions are already destroyed, increment the counter of corresponding ship
                        this._cruiser++;
                    else if(this._tab[i][j].type == "destroyer")
                        this._destroyer++;
                    else
                        this._bShip = true;
                }
                else{ // Case the ship is positioned vertically
                    var index = this._tab[i][j].posIS;
                    while(index <= this._tab[i][j].posIE){
                        if(!this._tab[index][j].destroyed) // If one position is not destroyed yet, return true
                            return true;
                        index++;
                    }
                    if(this._tab[i][j].type == "cruiser") // Case all positions are already destroyed, increment the counter of corresponding ship
                        this._cruiser++;
                    else if(this._tab[i][j].type == "destroyer")
                        this._destroyer++;
                    else
                        this._bShip = true;
                }
            }
            return true;
        }
        return false; // Neither shot in water nor ship -> shot already done
    }

    restart(){
        for(var i = 0; i < 10; i++){
		    for(var j = 0; j < 10; j++)
                this._tab[i][j] = -1;
	    }
        this._submarine = 0;
        this._cruiser = 0
        this._destroyer = 0;
        this._bShip = false;
    }

    // Method that check if the game has already a winner
    checkWin(){
        if(this._submarine == 4 && this._destroyer == 3 && this._cruiser == 2 && this._bShip)
            return true;
        return false;
    }

    shipsDestroyed(){
        if(this._bShip){
            return 1 + this._destroyer + this._cruiser + this._bShip;
        }
        return this._destroyer + this._cruiser + this._bShip;
    }

    setShip(ship){
        var i,j;
        switch(ship.type){
            case "submarine":
                if(this._tab[ship.posIS][ship.posJS] == -1){ // Check if position is clear
                    this._tab[ship.posIS][ship.posJS] = ship;
                    return true;
                }
                return false;
            case "destroyer":
            case "cruiser":
            case "battleship":
                if(ship.horizontal){
                    j = ship.posJS;
                    while(j <= ship.posJE){ // Check if all positions are clear
                        if(this._tab[ship.posIS][j] != -1)
                            return false;
                        j++;
                    }
                    j = ship.posJS;
                    while(j <= ship.posJE){ // To put the ship
                        this._tab[ship.posIS][j] = ship;
                        j++;
                    }
                    return true;
                }
                else{
                    i = ship.posIS;
                    while(i <= ship.posIE){ // Check if all positions are clear
                        if(this._tab[i][ship.posJE] != -1)
                            return false;
                        i++;
                    }
                    i = ship.posIS;
                    while(i <= ship.posIE){ // To put the ship
                        this._tab[i][ship.posJE] = ship;
                        i++;
                    }
                    return true;
                }
        }
        return false;
    }

    setShipRandom(pos){
        var i,j,vertical;
        i = randomPos();
        j = randomPos();
        vertical = Math.random() < 0.5;
        while(i+pos > 9 && j+pos > 9){
            i = randomPos();
            j = randomPos();
        }
        if(vertical && i+pos <= 9){
            if(this.setShip(new Ship(i,j,i+pos,j)))
                return true;
        }
        else if(!vertical && j+pos <= 9){
            if(this.setShip(new Ship(i,j,i,j+pos)))
                return true;
        }
        return false;
    }

    removeShip(ship){
        if(ship.type == "submarine")
            this._tab[ship.posIE][ship.posJE] = -1;
        else{
            if(ship.horizontal){
                var index = ship.posJS;
                while(index <= ship.posJE){
                    this._tab[ship.posIS][index] = -1;
                    index++;
                }
            }
            else{
                var index = ship.posIS;
                while(index <= ship.posIE){
                    this._tab[index][ship.posJS] = -1;
                    index++;
                }
            }
        }
    }
}