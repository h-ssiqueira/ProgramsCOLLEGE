class Estudante extends Conta{
    constructor(conta, nome){
        super(conta, nome);
        this._historico = [];
        this._extratos = false;
        this._transferencias = false;
    }
    set extratos(bool){
        this._extratos = bool;
    }

    get extratos(){
        return this._extratos;
    }

    set transferencias(bool){
        this._transferencias = bool;
    }

    get transferencias(){
        return this._transferencias;
    }

    listar(){
        return "\n" + this.conta + "\tEstudante\t" + this.nome;
    }

    sacar(valor){
        if(valor <= 300){
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
        !this._extratos ? this._extratos = true : this.operacaoExcedente();
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
            this._transferencias ? this._transferencias = true : this.operacaoExcedente();
            this.saldo -= Number(valor);
            this._historico.unshift("\nTransferência (para conta " + conta + ")\tR$" + Number(valor) + "\tR$" + Number(this.saldo));
        }
    }

    novoMes(){
        this.extratos = false;
        this.transferencias = false;
    }
}