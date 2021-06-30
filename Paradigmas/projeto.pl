%Henrique_Sartori_Siqueira_19240472
%Jemis_Dievas_Jose_Manhica_19076272
%Rafael_Silva_Barbon_19243633


%Fatos(Disponibilizado pelo professor)
sexo(paulo, masculino).
sexo(jose, masculino).
sexo(rosa, feminino).
sexo(saulo, masculino).
sexo(maria, feminino).
sexo(fabio, masculino).
sexo(joao, masculino).
sexo(douglas, masculino).
sexo(lucia, feminino).

idade(paulo, 73).
idade(jose, 33).
idade(rosa, 23).
idade(saulo, 99).
idade(maria, 70).
idade(fabio, 20).
idade(joao, 45).
idade(douglas, 66).
idade(lucia, 61).

tempoDeServico(paulo, 40).
tempoDeServico(jose, 10).
tempoDeServico(rosa, 2).
tempoDeServico(saulo, 50).
tempoDeServico(maria, 40).
tempoDeServico(fabio, 1).
tempoDeServico(joao, 15).
tempoDeServico(douglas, 34).
tempoDeServico(lucia, 32).

contribuicao(paulo, 35).
contribuicao(jose, 5).
contribuicao(rosa, 0).
contribuicao(saulo, 50).
contribuicao(maria, 30).
contribuicao(fabio, 1).
contribuicao(joao, 15).
contribuicao(douglas, 31).
contribuicao(lucia, 29).

tempoNaCarreira(paulo, 20).
tempoNaCarreira(saulo, 27).
tempoNaCarreira(maria, 30).
tempoNaCarreira(douglas, 10).

tempoNoCargo(paulo, 10).
tempoNoCargo(saulo, 20).
tempoNoCargo(maria, 25).
tempoNoCargo(douglas, 5).

maior(X,Y):- 
    X >= Y.
    
%REGRA1 
aposen_compusoria(X) :-
    idade(X,Y),%X nome e Y idade 
    maior(Y,70),%Verifica se a idade e maior ou igual a 70
    writeln(X),fail.%Imprime o nome e força uma outra avaliaçao  

%REGRA2
aposen_homem(X) :- 
    sexo(X,masculino),%X recebe o nome do homem 
    idade(X,Y),%X nome e Y idade
    maior(Y,65),%Verifica se a idade e maior ou igual a 65
    writeln(X),fail.%Imprime o nome e força uma outra avaliaçao

%REGRA3
aposen_mulher(X) :- 
    sexo(X,feminino),%X recebe o nome da mulher
    idade(X,Y),%X nome e Y idade
    maior(Y,60),%Verifica se a idade e maior ou igual a 60
    writeln(X),fail.%Imprime o nome e força uma outra avaliaçao

%REGRA4
aposen_volun_caso1(X) :- 
    sexo(X,masculino),%X recebe o nome do homem
    idade(X,Y),%X nome e Y idade
    maior(Y,60),%Verifica se a idade e maior ou igual a 60
    contribuicao(X,A),%A recebe o tempo de contribuicao e depois verifica se e maior 35 
    maior(A,35),
    tempoDeServico(X,B),%B recebe o tempo de serviço de X e depois verifica se e maior que 10
    maior(B,10),
    tempoNoCargo(X,C),%C recebe o tempo no cargo de X e verifica que eh maior de 5
    maior(C,5),
    writeln(X),fail;%Imprime o nome e força uma outra avaliaçao
    %ou
    sexo(X,feminino), %Regras se for mulher(Funcionamento igual a parte superior)
    idade(X,Y),
    maior(Y,55),
    contribuicao(X,A),
    maior(A,30),
    tempoDeServico(X,B),
    maior(B,10),
    tempoNoCargo(X,C),
    maior(C,5),
    writeln(X),fail.

%Regra5
aposen_volun_caso2(X) :- 
    sexo(X,masculino),%X recebe o nome do homem
    idade(X,Y),%X recebe o nome e Y idade e verifica se e maior que 60 
    maior(Y,60),
    contribuicao(X,A),%A recebe o tempo de contribuicao e depois verifica se e maior 35 
    maior(A,35),
    tempoDeServico(X,B),%B recebe o tempo de serviço de X e depois verifica se e maior que 20
    maior(B,20),
    tempoNaCarreira(X,C),%C recebe o tempo de X na carreira e verifica se e maior que 10
    maior(C,10),
    tempoNoCargo(X,D),%D recebe o tempo de X no cargo e verifica se e maior que 15
    maior(D,15),
    writeln(X),fail;%Imprime o nome e força uma outra avaliaçao
    %ou 
    sexo(X,feminino),%Regras se for mulher(Funcionamento igual a parte superior)
    idade(X,Y),
    maior(Y,55),
    contribuicao(X,A),
    maior(A,30),
    tempoDeServico(X,B),
    maior(B,20),
    tempoNaCarreira(X,C),
    maior(C,10),
    tempoNoCargo(X,D),
    maior(D,15),
    writeln(X),fail.
    
