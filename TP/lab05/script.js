function Veiculo(_id,_placa,_marca,_cor,_nomedoProprietario){
    // Sets
    this.setId = function(id){
        _id = id;
    }
    this.setPlaca = function(placa){
        _placa = placa;
    }
    this.setMarca = function(marca){
        _marca = marca;
    }
    this.setCor = function(cor){
        _cor = cor;
    }
    this.setNomeDoProprietario = function(proprietario){
        _nomedoProprietario = proprietario;
    }
    // Gets
    this.getId = function(){
        return _id;
    }
    this.getPlaca = function(){
        return _placa;
    }
    this.getMarca = function(){
        return _marca;
    }
    this.getCor = function(){
        return _cor;
    }
    this.getNomeDoProprietario = function(){
        return _nomedoProprietario;
    }
}

function Moto(_id,_placa,_marca,_cor,_nomedoProprietario){
    var veiculo = new Veiculo(_id,_placa,_marca,_cor,_nomedoProprietario);
    veiculo.calcularValorPago = function(horaEntrada,horaSaida){
        var duracao = calculaMinutos(horaEntrada,horaSaida);
        if(duracao > 0 && duracao < 30)
            return 0;
        if(duracao < 60 && duracao >= 30)
            return 1;
        if(duracao >= 60 && duracao < 240)
            return Math.round(duracao/30.0);
        return 10;
        /*
        até 30min - free
        1h - 2 conto (proporcionalmente até um máximo de 8)
        + de 4h - 10 conto
        */
    }
    return veiculo;
}

function Carro(_id,_placa,_marca,_cor,_nomedoProprietario){
    var veiculo = new Veiculo(_id,_placa,_marca,_cor,_nomedoProprietario);
    veiculo.calcularValorPago = function(horaEntrada,horaSaida){
        var duracao = calculaMinutos(horaEntrada,horaSaida);
        if(duracao > 0 && duracao < 15)
            return 0;
        if(duracao < 60 && duracao >= 15)
            return 2;
        if(duracao >= 60 && duracao < 240)
            return Math.round(duracao/15.0);
        return 20;
        /*
        até 15 min - free
        1h - 4 conto (proporcionalmente até um máximo de 16)
        + de 4h - 20 conto
        */
    }
    return veiculo;
}

function Estacionamento(_numeroDeVagas=20){
    let _vagas = new Array(_numeroDeVagas).fill(undefined); // Vagas de controle ([veiculo,hora entrada])
    let _saldo = 0; // Saldo ganho
    let _histVagas = []; // Histórico de carros ([veiculo, hora entrada, hora saida])
    this.estacionar = function(veiculo,horaEntrada){ // Entrada de veículo
        let i;
        for(i = 0; i < _numeroDeVagas; i++){
            if(_vagas[i] === undefined){
                _vagas[i] = [veiculo,horaEntrada];
                return true;
            }
        }
        return false;
    }
    this.liberar = function(idveiculo,horaSaida){ // Saída de veículo
        let i;
        for(i = 0; i < _numeroDeVagas; i++){
            if(_vagas[i] !== undefined && _vagas[i][0].getId() == idveiculo){
                _saldo += _vagas[i][0].calcularValorPago(_vagas[i][1],horaSaida);
                _histVagas.push([_vagas[i][0],_vagas[i][1],horaSaida]);
                _vagas[i] = undefined;
                return true;
            }
        }
        return false;
    }
    this.gerarRelatorio = function(){ // Hora de entrada e saída de todos os veículos inclusive os estacionados
        let i;
        var rel = "Ocupadas:\nID\tEntrada\t\tSaida\n";
        for(i = 0; i < _numeroDeVagas; i++){
            if(_vagas[i] !== undefined)
                rel += _vagas[i][0].getId() + "\t" + _vagas[i][1] + "\t\t-\n";
        }
        rel += "\nHistórico:\nID\tEntrada\t\tSaida\n";
        for(i = 0; i < _histVagas.length; i++){
            rel += _histVagas[i][0].getId() + "\t" + _histVagas[i][1] + "\t\t" + _histVagas[i][2] + "\n";
        }
        return rel;
    }
    this.getSaldo = function(){ // Saldo atual do estacionamento
        return _saldo;
    }
}

// Função para calcular a diferença da hora de entrada e saída (fomato HH:MM)
function calculaMinutos(horaEntrada,horaSaida){
    return Number(horaSaida.substr(0,2)) * 60 + Number(horaSaida.substr(3,5)) - (Number((horaEntrada.substr(0,2)) * 60 + Number(horaEntrada.substr(3,5))));
}

// Função para conferir o formato da hora
function confereHora(hora){
    var regex = /^([01]\d|2[0-3]):([0-5]\d)$/; // HH:MM
    if(regex.test(hora))
        return true;
    return false;
}

// Função para conferir o formado da placa
function conferePlaca(placa){
    var regex = /^[a-zA-Z]{3}[0-9][a-zA-Z0-9][0-9]{2}$/; // XXX0000 ou XXX0X000
    if(regex.test(placa))
        return true;
    return false;
}

let controle = new Estacionamento();
let globalID = 0;
/*var carro = Carro("2","abc1234","bmw","preto","hss");
controle.estacionar(carro,"12:31");
controle.estacionar(Carro("1","abc1234","bmw","preto","hss"),"12:00");
controle.liberar("1","13:13");
*/