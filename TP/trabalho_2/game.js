class BattleShip{
    constructor(){
        this._tab1 = new Table();
        this._tab2 = new Table();
        this._playerTurn = true;
        this._positioning = true;
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
    }

    checkWinner(){
        if(this._tab1.checkWin())
            return 1;
        if(this._tab2.checkWin())
            return 2;
        return 0;
    }

    getTab1(){
        return this._tab1.representation;
    }

    getTab2(){
        return this._tab2.representation;
    }

    shot(i,j){
        if(this._playerTurn && this._tab1.shot(i,j)){
            this._playerTurn = false;
            return true;
        }
        else if(!this._playerTurn && this._tab2.shot(i,j)){
            this._playerTurn = true;
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
}

function randomPos(){
    return Math.round(Math.random() * 9);
}
