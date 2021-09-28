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
    return Number(horaSaida.substr(0,2)) * 60 + Number(horaSaida.substr(3,5)) - (Number(horaEntrada.substr(0,2)) * 60 + Number(horaEntrada.substr(3,5)));
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
let globalID = 1;
/*var carro = Carro("2","abc1234","bmw","preto","hss");
controle.estacionar(carro,"12:31");
controle.estacionar(Carro("1","abc1234","bmw","preto","hss"),"12:00");
controle.liberar("1","13:13");
*/
