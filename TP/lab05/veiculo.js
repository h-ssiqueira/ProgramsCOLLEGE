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