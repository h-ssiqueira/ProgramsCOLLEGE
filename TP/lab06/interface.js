function novaConta(){
    if(document.novo.nome.value !== "" && document.novo.tipo.value !== ''){
        if(document.novo.tipo.value === "Premium")
            banco.novaConta(1,document.novo.nome.value,contaN++);
        else if(document.novo.tipo.value === "Básica")
            banco.novaConta(2,document.novo.nome.value,contaN++);
        else if(document.novo.tipo.value === "Estudante")
            banco.novaConta(3,document.novo.nome.value,contaN++);
        else
            document.saida.bloco.value = "Selecione um tipo.";
        document.saida.bloco.value = "Conta criada.";
    }
    else
        document.saida.bloco.value = "Informações ausentes para criação de nova conta.";
}

function listar(){
    document.saida.bloco.value = banco.listar();
}

function transferencia(){
    if(document.transf.contaRem.value !== "" && document.transf.valor.value !== "" && document.transf.contaDest.value !== "" && document.transf.contaRem.value !== document.transf.contaDest.value){
        if(banco.transferencia(document.transf.contaRem.value,document.transf.valor.value,document.transf.contaDest.value))
            document.saida.bloco.value = "Transferência efetuada.";
        else
            document.saida.bloco.value = "Conta não encontrada.";
    }
    else
        document.saida.bloco.value = "Informações ausentes para transferência de valores entre contas.";
}

function saque(){
    if(document.saqueEdeposito.conta.value !== "" && document.saqueEdeposito.valor.value !== ""){
        if(banco.saque(document.saqueEdeposito.conta.value,document.saqueEdeposito.valor.value))
            document.saida.bloco.value = "Saque efetuado.";
        else
            document.saida.bloco.value = "Saque recusado: Limite atingido ou conta não encontrada.";
    }
    else
        document.saida.bloco.value = "Informações ausentes para sacar valores de uma conta.";
}

function deposito(){
    if(document.saqueEdeposito.conta.value !== "" && document.saqueEdeposito.valor.value !== ""){
        if(banco.deposito(document.saqueEdeposito.conta.value,document.saqueEdeposito.valor.value))
            document.saida.bloco.value = "Depósito efetuado.";
        else
            document.saida.bloco.value = "Conta não encontrada.";
    }
    else
        document.saida.bloco.value = "Informações ausentes para depositar valores em uma conta.";
}

function extrato(){
    var txt;
    if(document.extrat.conta.value !== ""){
        txt = banco.extrato(document.extrat.conta.value);
        if(txt == false)
            document.saida.bloco.value = "Conta não encontrada.";
        else
            document.saida.bloco.value = txt;
    }
    else
        document.saida.bloco.value = "Número de conta ausente";
}

function limpar(){
    document.novo.nome.value = "";
    document.novo.tipo.checked = false;
    document.transf.contaRem.value = "";
    document.transf.valor.value = "";
    document.transf.contaDest.value = "";
    document.saqueEdeposito.conta.value = "";
    document.saqueEdeposito.valor.value = "";
    document.extrat.conta.value = "";
    document.saida.bloco.value = "";
}

function avancar(){
    banco.avancarmes();
    document.saida.bloco.value = "Limite das contas zerado para o próximo mês.";
}