class BattleShip{
    constructor(){
        this._tab1 = new Table();
        this._tab2 = new Table();
        this._playerTurn = true;
        this._positioning = true;
        // Queue for computer movements
        this._queue = [];
    }
    set playerTurn(bool){
        this._playerTurn = bool;
    }
    get playerTurn(){
        return this._playerTurn;
    }
    set positioning(bool){
        this._positioning = bool;
    }
    get positioning(){
        return this._positioning;
    }

    restart(){
        this._tab1.restart();
        this._tab2.restart();
        this._positioning = true;
        this._playerTurn = true;
        // For computer player
        this.lastI = 0;
        this.lastJ = 0;
        this.totalDestroyed = 0;
        this.lastShot = -1;
    }

    checkWinner(){
        if(this._tab1.checkWin())
            return 1;
        if(this._tab2.checkWin())
            return 2;
        return 0;
    }

    shipsDestroyedP1(){
        return this._tab1.shipsDestroyed();
    }

    shipsDestroyedP2(){
        return this._tab2.shipsDestroyed();
    }

    getShip(i,j){
        return this._tab1.getPos(i,j);
    }

    getTab1(){
        return this._tab1.representation;
    }

    getTab2(){
        return this._tab2.representation;
    }

    shotTab(i,j,pc){
        var ret;
        if(this._playerTurn && !pc){
            ret = this._tab2.shot(i,j);
            if(ret == -1)
                this._playerTurn = false;
            return ret;
        }
        else if(!this._playerTurn && pc){
            ret = this._tab1.shot(i,j);
            if(this.shipsDestroyedP1 == 10)
                return -1;
            if(ret == -1)
                this._playerTurn = true;
            return ret;
        }
        return 0;
    }

    randomize(player){
        if(this._positioning){ // Only on positioning phase can be randomized the ships
            var bts = false,cru = 0,des = 0,sub = 0;
            if(player == 1){
                this._tab1.restart();
                while(!bts || cru != 2 || des != 3 || sub != 4){
                    if(!bts)
                        bts = this._tab1.setShipRandom(3);
                    if(cru != 2){
                        if(this._tab1.setShipRandom(2))
                            cru++;
                    }
                    if(des != 3){
                        if(this._tab1.setShipRandom(1))
                            des++;
                    }
                    if(sub != 4){
                        if(this._tab1.setShipRandom(0))
                            sub++;
                    }
                }
            }
            else if(player == 2){
                this._tab2.restart();
                while(!bts || cru != 2 || des != 3 || sub != 4){
                    if(!bts)
                        bts = this._tab2.setShipRandom(3);
                    if(cru != 2){
                        if(this._tab2.setShipRandom(2))
                            cru++;
                    }
                    if(des != 3){
                        if(this._tab2.setShipRandom(1))
                            des++;
                    }
                    if(sub != 4){
                        if(this._tab2.setShipRandom(0))
                            sub++;
                    }
                }
            }
        }
    }

    removeShip(ship){
        return this._tab1.removeShip(ship);
    }

    setShip(ship){
        return this._tab1.setShip(ship);
    }

    computerShot(){
        var i,j, hit = 0, before;
        do{
            if(this._queue.length == 0){
                i = randomPos();
                j = randomPos();
            }
            else{
                var next = this._queue.shift();
                i = next[0];
                j = next[1];
            }
            before = this._tab1.totalHits;
            hit = this.shotTab(i,j,true);
            if(before != this._tab1.totalHits){ // Enqueue the possible adjacent movements as the computer have been hit a ship
                if(i != 9)
                    this._queue.push([i+1,j]);
                if(j != 9)
                    this._queue.push([i,j+1]);
                if(i != 0)
                    this._queue.push([i-1,j]);
                if(j != 0)
                    this._queue.push([i,j-1]);
            }
        }while(hit != -1); // Finish computers turn when hits water
    }
}

function randomPos(){
    return Math.round(Math.random() * 9);
}
