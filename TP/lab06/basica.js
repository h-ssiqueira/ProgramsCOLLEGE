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
        return "\n" + this.conta + "\tBásica\t\t" + this.nome;
    }

    sacar(valor){
        if(valor <= 1000){
            this.saldo -= Number(valor);
            this._historico.unshift("\nSaque\t\t\tR$" + Number(valor) + "\tR$" + Number(this.saldo));
            return true;
        }
        return false;
    }

    depositar(valor){
        this.saldo += Number(valor);
        this._historico.unshift("\nDepósito\t\tR$" + Number(valor) + "\tR$" + Number(this.saldo));
    }

    operacaoExcedente(){
        this.saldo -= .5;
        this._historico.unshift("\nOp. excedente\t\tR$0.5\tR$" + Number(this.saldo));
    }

    extrato(){
        this.extratos < 3 ? this.extratos += 1 : this.operacaoExcedente();
        var ext = "Desc\t\t\tValor\tSaldo";
        for(var i = 0; i < this._historico.length; i++)
            ext += this._historico[i];
        return ext;
    }

    transferencia(conta,valor,recebida){
        if(recebida){
            this.saldo += Number(valor);
            this._historico.unshift("\nTransferência (de conta " + conta + ")\tR$" + Number(valor) + "\tR$" + Number(this.saldo));
        }
        else{
            this.transferencias < 3 ? this.transferencias =+ 1 : this.operacaoExcedente();
            this.saldo -= Number(valor);
            this._historico.unshift("\nTransferência (para conta " + conta + ")\tR$" + Number(valor) + "\tR$" + Number(this.saldo));
        }
    }

    novoMes(){
        this.extratos = 0;
        this.transferencias = 0;
    }
}
