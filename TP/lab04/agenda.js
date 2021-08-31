/* Contato: (id, nome, telefone) Agenda: inserir(contato) remover(id) buscar(id) listar() (ordem por nome) */
function Contato(_id,_nome,_telefone){
    this.getId = function(){
        return _id;
    }
    this.getNome = function(){
        return _nome;
    }
    this.getTelefone = function(){
        return _telefone;
    }
};
function Agenda(){
    let _contatos = [];
    let _i = 0;
    this.inserir = function(newuser){
        _contatos[_i++] = newuser;
    }    
    this.remover = function(id){
        var rm = _contatos.findIndex(pessoa => pessoa.getId() == id); // Encontra a posição a ser removida
        if(rm !== -1)
            _contatos.splice(rm,1); // Remove 1 elemento do índice indicado
    }   
    this.buscar = function(id){
        var found = _contatos.find(pessoa => pessoa.getId() == id);
        if(found === undefined || found === null)
            console.log("Contato inexistente");
        else
            console.log(found);
    }    
    this.listar = function(){
        _contatos.sort(function (x, y){ // Ordena os contatos alfabeticamente
            if(x.getNome() > y.getNome())
                return 1;
            if(x.getNome() < y.getNome())
                return -1;
            return 0;
        });
        document.agenda.visor.bloco = "";
        _contatos.forEach(function(pessoa){ // Exibe cada contato
            console.log(pessoa.getNome() + " -> " + pessoa.getTelefone());
            document.agenda.visor.bloco += pessoa.getNome() + " -> " + pessoa.getTelefone() + "\n";
        });
    }
}


let a = new Agenda();
a.inserir(new Contato("1","hss","3256-"));
a.inserir(new Contato("2","ssh","3256-1429"));
a.inserir(new Contato("3","abc","3256-1429"));
//a.buscar(7);
//a.listar();
//a.remover(2);

//a.listar();

function lista(){
    a.listar();
}

function novo(){
    console.log(document.agenda.visor.identifica);
    a.inserir(new Contato(document.agenda.visor.identifica.value,document.agenda.visor.nome.value,document.agenda.visor.telefone.value))
}