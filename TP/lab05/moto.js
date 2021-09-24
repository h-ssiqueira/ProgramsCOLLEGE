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