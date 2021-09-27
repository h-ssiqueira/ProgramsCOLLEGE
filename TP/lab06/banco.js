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
                this._contas[i].novoMes();
        }
    }
}

let banco = new Banco();
let contaN = 1;