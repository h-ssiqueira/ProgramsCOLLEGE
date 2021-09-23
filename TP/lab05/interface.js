function estacionar(){
    if(document.entrada.tipo1.checked === true || document.entrada.nome.value !== "" || document.entrada.marca.value !== "" || document.entrada.cor.value !== ""){
        if(confereHora(document.entrada.horaEntrada.value)){
            if(conferePlaca(document.entrada.placa.value)){
                if(document.entrada.tipo1.value == "Carro"){
                    controle.estacionar(Carro(globalID,document.entrada.placa.value,document.entrada.marca.value,document.entrada.cor.value,document.entrada.nome.value),document.entrada.horaEntrada.value) ? (document.centro.bloco.value = "Carro estacionado.",globalID++) : document.centro.bloco.value = "Estacionamento cheio.";
                }
                else if(document.entrada.tipo1.value == "Moto"){
                    controle.estacionar(Moto(globalID,document.entrada.placa.value,document.entrada.marca.value,document.entrada.cor.value,document.entrada.nome.value),document.entrada.horaEntrada.value) ? (document.centro.bloco.value = "Moto estacionada.",globalID++) : document.centro.bloco.value = "Estacionamento cheio.";
                }
            }
            else
                document.centro.bloco.value = "Formato errado de placa.";
        }
        else
            document.centro.bloco.value = "Formato errado de hora.";
    }
    else
        document.centro.bloco.value = "Informações faltantes para estacionar um veículo.";
}

function listar(){
    document.centro.bloco.value = controle.gerarRelatorio();
}

function saldo(){
    document.centro.bloco.value = "Saldo do estacionamento: R$" + controle.getSaldo() + ",00";
}

function limpar(){
    document.entrada.nome.value = "";
    document.entrada.tipo1.checked = false;
    document.entrada.placa.value = "";
    document.entrada.marca.value = "";
    document.entrada.cor.value = "";
    document.entrada.horaEntrada.value = "";
    document.centro.bloco.value = "";
    document.saida.identifica.value = "";
    document.saida.horaSaida.value = "";
}

function liberar(){
    if(confereHora(document.saida.horaSaida.value) || document.saida.identifica.value !== ""){
        controle.liberar(document.saida.identifica.value, document.saida.horaSaida.value) ? document.centro.bloco.value = "Veículo liberado." : document.centro.bloco.value = "Veículo não encontrado.";
    }
    else
        document.centro.bloco.value = "Entrada em formato errado.";
}