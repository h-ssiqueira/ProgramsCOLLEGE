class Banco{
    constructor(){
        this._contas = [];
    }
    novaConta(tipo,nome,conta){

    }
    listar(){

    }
    transferencia(contaDesc,valor,contaAcres){

    }
    saque(conta,valor){

    }
    depósito(conta,valor){

    }
    extrato(conta){

    }
}

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

class Platinum extends Conta{
    constructor(conta, nome){
        super(conta, nome);
        this._historico = [];
    }
    listar(){
        return "\n" + this.conta() + "\tPlatinum\tR$" + this.nome();
    }
    sacar(valor){
        this.saldo(this.saldo() - valor);
        this._historico.unshift("\nSaque\tR$" + valor + "\tR$" + this.saldo());
        return true;
    }
    depositar(valor){
        this.saldo(this.saldo() + valor);
        this._historico.unshift("\nDepósito\tR$" + valor + "\tR$" + this.saldo());
        return true;
    }
    extrato(){
        var ext = "";
        for(var i = 0; i < this._historico.length; i++)
            ext += this._historico[i];
        return ext;
    }
    transferencia(conta,valor,recebida){
        if(!recebida){
            this.saldo(this.saldo() - valor);
            this._historico.unshift("\nTransferência (para " + conta + ")\tR$" + valor + "\tR$" + this.saldo());
            return true;
        }
        else{
            this.saldo(this.saldo() + valor);
            this._historico.unshift("\nTransferência (de " + conta + ")\tR$" + valor + "\tR$" + this.saldo());
            return true;
        }
    }
}

class Basica extends Conta{
    constructor(conta, nome){
        super(conta, nome);
        this._historico = [];
        this._extratos = 0;
        this._transferencias = 0;
    }
    set extratos(qtd){
        this._extratos = qtd;
    }
    get extratos(){
        return this._extratos;
    }
    set transferencias(qtd){
        this._transferencias = qtd;
    }
    get transferencias(){
        return this._transferencias;
    }
    listar(){
        return "\n" + this.conta() + "\tBásica\tR$" + this.nome();
    }
    sacar(valor){
        if(valor <= 1000){
            this.saldo(this.saldo() - valor);
            this._historico.unshift("\nSaque\tR$" + valor + "\tR$" + this.saldo());
            return true;
        }
        return false;
    }
    depositar(valor){
        this.saldo(this.saldo() + valor);
        this._historico.unshift("\nDepósito\tR$" + valor + "\tR$" + this.saldo());
        return true;
    }
    operacaoExcedente(){
        this.saldo(this.saldo() - .5);
        this._historico.unshift("\nOp. excedente\tR$0,50\tR$" + this.saldo());
    }
    extrato(){
        this.extratos() < 3 ? this.extratos(this.extratos() + 1) : this.operacaoExcedente();
        var ext = "";
        for(var i = 0; i < this._historico.length; i++)
            ext += this._historico[i];
        return ext;
    }
    transferencia(conta,valor,recebida){
        if(!recebida){
            this.transferencias() < 3 ? this.transferencias(this.transferencias() + 1) : this.operacaoExcedente();
            this.saldo(this.saldo() - valor);
            this._historico.unshift("\nTransferência (para " + conta + ")\tR$" + valor + "\tR$" + this.saldo());
            return true;
        }
        else{
            this.saldo(this.saldo() + valor);
            this._historico.unshift("\nTransferência (de " + conta + ")\tR$" + valor + "\tR$" + this.saldo());
            return true;
        }
    }
    avancarMes(){
        this.extratos(0);
        this.transferencias(0);
    }
}

class Estudante extends Conta{
    constructor(conta, nome){
        super(conta, nome);
        this._historico = [];
        this._extratos = false;
        this._transferencias = false;
    }
    listar(){
        return "\n" + this.conta() + "\tEstudante\tR$" + this.nome();
    }
    sacar(valor){
        if(valor <= 300){
            this.saldo(this.saldo() - valor);
            this._historico.unshift("\nSaque\tR$" + valor + "\tR$" + this.saldo());
            return true;
        }
        return false;
    }
    depositar(valor){
        this.saldo(this.saldo() + valor);
        this._historico.unshift("\nDepósito\tR$" + valor + "\tR$" + this.saldo());
        return true;
    }
    operacaoExcedente(){
        this.saldo(this.saldo() - .5);
        this._historico.unshift("\nOp. excedente\tR$0,50\tR$" + this.saldo());
    }
    extrato(){
        !this._extratos ? this._extratos = true : this.operacaoExcedente();
        var ext = "";
        for(var i = 0; i < this._historico.length; i++)
            ext += this._historico[i];
        return ext;
    }
    transferencia(conta,valor,recebida){
        if(!recebida){
            this._transferencias ? this._transferencias = true : this.operacaoExcedente();
            this.saldo(this.saldo() - valor);
            this._historico.unshift("\nTransferência (para " + conta + ")\tR$" + valor + "\tR$" + this.saldo());
            return true;
        }
        else{
            this.saldo(this.saldo() + valor);
            this._historico.unshift("\nTransferência (de " + conta + ")\tR$" + valor + "\tR$" + this.saldo());
            return true;
        }
    }
    avancarMes(){
        this._extratos = false;
        this._transferencias = false;
    }
}