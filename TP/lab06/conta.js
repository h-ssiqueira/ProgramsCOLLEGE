class Conta{
    constructor(conta, nome){
        this._conta = conta;
        this._nome = nome;
        this._saldo = 0;
    }

    set conta(conta){
        this._conta = conta;
    }

    set nome(nome){
        this._nome = nome;
    }

    set saldo(saldo){
        this._saldo = saldo;
    }

    get conta(){
        return this._conta;
    }

    get nome(){
        return this._nome;
    }

    get saldo(){
        return this._saldo;
    }
}
