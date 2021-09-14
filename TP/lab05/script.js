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
    Veiculo.call(this, "Moto");
    this.calcularValorPago = function(horaEntrada,horaSaida){
        var duracao = calculaMinutos(horaEntrada,horaSaida);
        if(duracao > 0 && duracao < 30)
            return 0;
        if(duracao < 60 && duracao >= 30)
            return 1;
        if(duracao >= 60 && duracao < 240)
            return duracao/30;
        return 10;
        /*
        até 30min - free
        1h - 2 conto
        + de 4h - 10 conto
        */
    }
}

function Carro(_id,_placa,_marca,_cor,_nomedoProprietario){
    Veiculo.call(this, "Carro");
    this.calcularValorPago = function(horaEntrada,horaSaida){
        var duracao = calculaMinutos(horaEntrada,horaSaida);
        if(duracao > 0 && duracao < 15)
            return 0;
        if(duracao < 60 && duracao >= 15)
            return 2;
        if(duracao >= 60 && duracao < 240)
            return duracao/15.0;
        return 20;
        /*
        até 15 min - free
        1h - 4 conto
        + de 4h - 20 conto
        */
    }
}

function Estacionamento(_numeroDeVagas=20){
    let _vagas = new Array(_numeroDeVagas); // Vagas de controle ([veiculo,hora entrada])
    let _saldo = 0; // Saldo ganho
    let _histVagas = []; // Histórico de carros ([veiculo, hora entrada, hora saida])
    this.estacionar = function(veiculo,horaEntrada){ // Entrada de veículo
        let i;
        for(i ^= i; i < _numeroDeVagas; i++){
            if(_vagas[i] === null || _vagas[i] === undefined){
                _vagas[i] = [veiculo,horaEntrada];
                return true;
            }
        }
        return false;
    }
    this.liberar = function(idveiculo,horaSaida){ // Saída de veículo
        let i;
        for(i ^= i; i < _numeroDeVagas; i++){
            if(_vagas[i].veiculo.getId() === idveiculo){
                _saldo += _vagas[i].veiculo.calcularValorPago(_vagas[i].horaEntrada,horaSaida);
                _histVagas.push([_vagas[i],horaSaida]);
                _vagas[i] = null;
                return true;
            }
        }
        return false;
    }
    this.gerarRelatorio = function(){ // Hora de entrada e saída de todos os veículos inclusive os estacionados
        let i;
        var rel = "ID\tEntrada\tSaida\n";
        for(i ^= i; i < _numeroDeVagas; i++){
            rel += _vagas[i].veiculo.getId() + "\t" + _vagas[i].horaEntrada + "\t-\n";
        }
        for(i ^= i; i < _histVagas.length; i++){
            rel += _histVagas[i].veiculo.getId() + "\t" + _histVagas[i].horaEntrada + "\t" + _histVagas[i].horaSaida + "\n";
        }
        return rel;
    }
    this.getSaldo = function(){ // Saldo atual do estacionamento
        return _saldo;
    }
}

// Função para calcular a diferença da hora de entrada e saída
function calculaMinutos(horaEntrada,horaSaida){
    return Number(horaSaida.substr(0,2)) * 60 + Number(horaSaida.substr(3,5)) - (Number((horaEntrada.substr(0,2)) * 60 + Number(horaEntrada.substr(3,5))));
}

// Função para conferir o formato da hora
function confereHora(hora){
    var regex = /^([01][0-9]|2[0-3]):([0-5][0-9])$/; // HH:MM
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
let Moto = new Moto();
let Carro = new Carro();

function estacionar(){
    // TODO
}

function listar(){
    document.centro.bloco.value = controle.gerarRelatorio();
}

function saldo(){
    document.centro.bloco.value = controle.getSaldo();
}

function limpar(){
    document.entrada.identifica.value = "";
    document.entrada.nome.value = "";
    document.entrada.tipo1.checked = false;
    document.entrada.tipo2.checked = false;
    document.entrada.placa.value = "";
    document.entrada.marca.value = "";
    document.entrada.cor.value = "";
    document.entrada.horaEntrada.value = "";
    document.centro.bloco.value = "";
    document.saida.identifica.value = "";
    document.saida.horaSaida.value = "";
}

function liberar(){
    // TODO
}
