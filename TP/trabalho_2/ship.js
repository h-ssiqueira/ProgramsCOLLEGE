class Ship{
    constructor(iS,jS,iE,jE){
        this.posIS = iS;
        this.posJS = jS;
        this.posIE = iE;
        this.posJE = jE;
        this.destroyed = false;
        if(iS == iE && jS == jE)
            this.type = "submarine";
        else if(Math.abs(iS-iE) == 1 || Math.abs(jS-jE) == 1)
            this.type = "destroyer";
        else if(Math.abs(iS-iE) == 2 || Math.abs(jS-jE) == 2)
            this.type = "cruiser";
        else if(Math.abs(iS-iE) == 3 || Math.abs(jS-jE) == 3)
            this.type = "battleship";
        iS == iE ? this.horizontal = true : this.horizontal = false;
    }
    set destroyed(bool){
        this.destroyed = bool;
    }
    get destroyed(){
        return this.destroyed;
    }
    get type(){
        return this.type;
    }
    get horizontal(){
        return this.horizontal;
    }
    get posIS(){
        return this.posIS;
    }
    get posIE(){
        return this.posIE;
    }
    get posJS(){
        return this.posJS;
    }
    get posJE(){
        return this.posJE;
    }
}