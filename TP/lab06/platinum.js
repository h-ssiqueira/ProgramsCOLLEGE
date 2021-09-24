class Platinum extends Conta{
    constructor(conta, nome){
        super(conta, nome);
        this._historico = [];
    }

    listar(){
        return "\n" + this.conta + "\tPlatinum\t" + this.nome;
    }

    sacar(valor){
        this.saldo -= Number(valor);
        this._historico.unshift("\nSaque\t\t\tR$" + Number(valor) + "\tR$" + Number(this.saldo));
        return true;
    }

    depositar(valor){
        this.saldo += Number(valor);
        this._historico.unshift("\nDepósito\t\tR$" + Number(valor) + "\tR$" + Number(this.saldo));
    }

    extrato(){
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
            this.saldo -= Number(valor);
            this._historico.unshift("\nTransferência (para conta " + conta + ")\tR$" + Number(valor) + "\tR$" + Number(this.saldo));
        }
    }
}