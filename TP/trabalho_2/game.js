class BattleShip{
    constructor(){
        this._tab1 = new Table();
        this._tab2 = new Table();
        this._playerTurn = true;
        this._positioning = true;
        // variables for computer shots
        this._lastI = 0;
        this._lastJ = 0;
        this._totalDestroyed = 0;
        this._lastShot = -1;
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
            if(ret == 0)
                return false;
            return true;
        }
        else if(!this._playerTurn && pc){
            ret = this._tab1.shot(i,j);
            if(this.shipsDestroyedP1 == 10)
                return false;
            if(ret == -1)
                this._playerTurn = true;
            if(ret == 0)
                return false;
            return true;
        }
        return false;
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

    get lastI(){
        return this._lastI;
    }
    get lastJ(){
        return this._lastJ;
    }
    get totalDestroyed(){
        return this._totalDestroyed;
    }
    get lastShot(){
        return this._lastShot;
    }
    set lastI(i){
        this._lastI = i;
    }
    set lastJ(j){
        this._lastJ = j;
    }
    set totalDestroyed(n){
        this._totalDestroyed = n;
    }
    set lastShot(val){
        this._lastShot = val;
    }
    computerShot(){
        var i,j;
        do{ // TODO -> improve shots when hit a ship
            i = randomPos();
            j = randomPos();
        }while(this.shotTab(i,j,true));
    }
}

function randomPos(){
    return Math.round(Math.random() * 9);
}
