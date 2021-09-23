class Banco{
    constructor(){
        this._contas = [];
    }

    novaConta(tipo,nome,conta){
        switch(tipo){
            case 1:
                this._contas.unshift(new Platinum(conta,nome));
                break;
            case 2:
                this._contas.unshift(new Basica(conta,nome));
                break;
            case 3:
                this._contas.unshift(new Estudante(conta,nome));
                break;
        }
    }

    listar(){
        var info = "Conta\tTipo\t\tProprietário";
        for(let i = 0; i < this._contas.length; i++)
            info += this._contas[i].listar();
        return info;
    }

    transferencia(contaDesc,valor,contaAcres){
        var desconto = -1, credito = -1;
        for(let i = 0; i < this._contas.length; i++){
            if(this._contas[i].conta == contaDesc)
                desconto = i;
            else if(this._contas[i].conta == contaAcres)
                credito = i;
        }
        if(desconto > -1 && credito > -1){
            this._contas[desconto].transferencia(contaAcres,valor,false);
            this._contas[credito].transferencia(contaDesc,valor,true);
            return true;
        }
        return false;
    }

    saque(conta,valor){
        for(let i = 0; i < this._contas.length; i++){
            if(this._contas[i].conta == conta){
                if(this._contas[i].sacar(valor))
                    return true;
                else
                    return false;
            }
        }
        return false;
    }

    deposito(conta,valor){
        for(let i = 0; i < this._contas.length; i++){
            if(this._contas[i].conta == conta){
                this._contas[i].depositar(valor);
                return true;
            }
        }
        return false;
    }

    extrato(conta){
        for(let i = 0; i < this._contas.length; i++){
            if(this._contas[i].conta == conta)
                return this._contas[i].extrato();
        }
        return false;
    }

    avancarmes(){
        for(let i = 0; i < this._contas.length; i++){
            if(this._contas[i] instanceof Basica || this._contas[i] instanceof Estudante)
                this.contas[i].novoMes();
        }
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

let banco = new Banco();
let contaN = 1;