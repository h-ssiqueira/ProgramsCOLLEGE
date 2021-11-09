class Table{
    constructor(){
        this.tab = new Array(10);
	    for(var i = 0; i < 10; i++){
		    this.tab[i] = new Array(10);
		    for(var j = 0; j < 10; j++)
                this.tab[i][j] = 0;
	    }
    }

    get representation(){
        return this.tab;
    }

    shot(i,j){
        if(this.tab[i][j] == 0){ // Case shot in water
            this.tab[i][j] = 1;
            return true;
        }
        else if(this.tab[i][j] instanceof Object && this.tab[i][j].destroyed == false){ // Case shot in ship
            this.tab[i][j].destroyed = true;
            return true;
        }
        return false; // Neither shot in water nor ship -> shot already done
    }

    restart(){
        for(var i = 0; i < 10; i++){
		    for(var j = 0; j < 10; j++)
                this.tab[i][j] = 0;
	    }
    }

    setShip(ship){
        var i,j;
        switch(ship.type){
            case "submarine":
                if(this.tab[ship.posIS][ship.posJS] == 0){
                    this.tab = ship;
                    return true;
                }
                return false;
            case "destroyer":
            case "cruiser":
            case "battleship":
                if(ship.horizontal){
                    j = ship.posJS;
                    while(j <= ship.posJE){ // Check if all positions are clear
                        if(tab[ship.posIS][j] != 0)
                            return false;
                    }
                    j = ship.posJS;
                    while(j <= ship.posJE) // To put the ship
                        tab[ship.posIS][j] = ship;
                    return true;
                }
                else{
                    i = ship.posIS;
                    while(i <= ship.posIE){ // Check if all positions are clear
                        if(tab[i][ship.posJE] != 0)
                            return false;
                    }
                    i = ship.posIS;
                    while(i <= ship.posIE) // To put the ship
                        tab[i][ship.posJE] = ship;
                    return true;
                }
        }
        return false;
    }
}