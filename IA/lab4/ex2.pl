% Realizar a execução com o comando "viajar(Luiz, Arnaldo, Paulo, Mariana)"

viajar(Luiz, Arnaldo, Paulo, Mariana) :-
    % Define os fatos do enunciado
    n_viajou(Luiz, salvador),
	n_viajou(Luiz, fortaleza),
	n_viajou(Arnaldo, salvador),
	n_viajou(Paulo, goiania),
	viajou(Mariana, curitiba),
    % Define que não haja repetições de pessoas viajando para uma mesma cidade
   	viajar_diferente(Luiz, Arnaldo),
    viajar_diferente(Luiz, Paulo),
    viajar_diferente(Luiz, Mariana),
    viajar_diferente(Paulo, Arnaldo),
   	viajar_diferente(Paulo, Mariana),
    viajar_diferente(Mariana, Arnaldo).

% Define quem não viajou, também verificando que não é possível atribuir a pessoa à cidade de destino
n_viajou(A,B) :-
    cidade(A),
    not(A = B).

% Atribui a pessoa à cidade de destino
viajou(A,B) :-
    A = B.

% Define que não há possibilidade de duas pessoas terem o mesmo destino
viajar_diferente(A, B) :-
    diferente(A, B).
viajar_diferente(A, B) :-
    diferente(B, A).

% Estabelece as cidades
cidade(fortaleza).
cidade(goiania).
cidade(curitiba).
cidade(salvador).

% Estabelece que as cidades não são iguais entre si
diferente(fortaleza, goiania).
diferente(fortaleza, salvador).
diferente(fortaleza, curitiba).

diferente(goiania, salvador).
diferente(goiania, curitiba).

diferente(curitiba, salvador).
