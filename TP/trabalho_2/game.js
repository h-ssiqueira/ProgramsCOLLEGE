class BattleShip{
    constructor(){
        this.tab = new Table();
    }
    restart(){
        this.tab.restart();
    }
    getTab(){
        return this.tab.representation;
    }
    shot(i,j){
        return this.tab.shot(i,j);
    }
}

let game = new BattleShip();
