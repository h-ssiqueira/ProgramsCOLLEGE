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
        document.agenda.bloco.value = "";
        if(_contatos.length !== 0){
            var rm = _contatos.findIndex(pessoa => pessoa.getId() === id); // Encontra a posição a ser removida
            if(rm !== -1){
                _contatos.splice(rm,1); // Remove 1 elemento do índice indicado
                document.agenda.bloco.value = "Contact removed";
            }
        }
        else
            document.agenda.bloco.value = "Contact not found";
    }   
    this.buscar = function(id){
        var found = _contatos.find(pessoa => pessoa.getId() === id);
        document.agenda.bloco.value = "";
        if(found === undefined || found === null){
            document.agenda.bloco.value = "Contact not found";
        }
        else{
            document.agenda.bloco.value = found.getId() + ". " + found.getNome() + " -> " + found.getTelefone();
        }
    }    
    this.listar = function(){
        document.agenda.bloco.value = "";
        if(_contatos.length === 0)
            document.agenda.bloco.value = "No contacts found";
        else{
            _contatos.sort(function (x, y){ // Ordena os contatos alfabeticamente
                if(x.getNome() > y.getNome())
                    return 1;
                if(x.getNome() < y.getNome())
                    return -1;
                return 0;
            });

            _contatos.forEach(function(pessoa){ // Exibe cada contato
                document.agenda.bloco.value += pessoa.getId() + ". " + pessoa.getNome() + " -> " + pessoa.getTelefone() + "\n";
            });
        }
    }
    this.check = function(id){
        var found = _contatos.find(pessoa => pessoa.getId() === id);
        if(found === undefined || found === null)
            return false;
        return true;
    }
}

let a = new Agenda();
//a.inserir(new Contato("1","hss","3256-"));
//a.inserir(new Contato("2","ssh","3256-1429"));
//a.inserir(new Contato("3","abc","3256-1429"));
//a.buscar(7);
//a.listar();
//a.remover(2);

//a.listar();

function lista(){
    a.listar();
}

function reset(){
    document.agenda.bloco.value = "";
}

function telefone(tel){
    var regex = /\(\d{2}\)\s\d{4,5}-?\d{4}/; // (xx) xxxx-xxxx ou (xx) xxxxx-xxxx
    if(regex.test(tel))
        return true;
    return false;
}

function novo(){
    if(document.agenda.identifica.value !== "" && document.agenda.nome.value !== "" && document.agenda.telefone.value !== ""){ // Input vazio
        if(!a.check(document.agenda.identifica.value)){ // IDs duplicados
            if(telefone(document.agenda.telefone.value)){ // Formato inválido de telefone
                a.inserir(new Contato(document.agenda.identifica.value,document.agenda.nome.value,document.agenda.telefone.value))
                document.agenda.bloco.value = "Contact added";
            }
            else
                document.agenda.bloco.value = "Wrong phone number format";
        }
        else
            document.agenda.bloco.value = "Contact already exists in database";
    }
    else
        document.agenda.bloco.value = "Missing information for new contact";
}

function busca(){
    a.buscar(document.agenda.identifica.value);
}

function remover(){
    a.remover(document.agenda.identifica.value);
}