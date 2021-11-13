class Ship{
    constructor(iS,jS,iE,jE){
        this._posIS = iS;
        this._posJS = jS;
        this._posIE = iE;
        this._posJE = jE;
        this._destroyed = false;
        if(iS == iE && jS == jE)
            this._type = "submarine";
        else if(iE-iS == 1 || jE-jS == 1)
            this._type = "destroyer";
        else if(iE-iS == 2 || jE-jS == 2)
            this._type = "cruiser";
        else if(iE-iS == 3 || jE-jS == 3)
            this._type = "battleship";
        iS == iE ? this._horizontal = true : this._horizontal = false;
    }
    set destroyed(bool){
        this._destroyed = bool;
    }
    get destroyed(){
        return this._destroyed;
    }
    get type(){
        return this._type;
    }
    get horizontal(){
        return this._horizontal;
    }
    get posIS(){
        return this._posIS;
    }
    get posIE(){
        return this._posIE;
    }
    get posJS(){
        return this._posJS;
    }
    get posJE(){
        return this._posJE;
    }
}