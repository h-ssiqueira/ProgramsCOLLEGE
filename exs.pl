%Fatos
digito(0).
digito(1).
%Regra
binario(N):-
N=(A,B,C,D),
digito(A),
digito(B),
digito(C),
digito(D).


%Fatos
homem(roberto).
homem(joao).
homem(tomas).
mulher(luisa).
mulher(ana).
mulher(patricia).
mulher(paula).
um_dos_pais(paula, roberto).
um_dos_pais(tomas, roberto).
um_dos_pais(tomas, luisa).
um_dos_pais(roberto, ana).
um_dos_pais(roberto, patricia).
um_dos_pais(patricia, joao).

%Regras
um_dos_filhos(Y, X) :-
    um_dos_pais(X, Y).
mae(X, Y) :-
    um_dos_pais(X, Y),
    mulher(X).
um_dos_avos(X, Z) :-
    um_dos_pais(X, Y),
    um_dos_pais(Y, Z).
antepassado(X, Z) :-
    um_dos_pais(X, Y),
    antepassado(Y, Z).
diferente(X, Y) :-
    X \= Y.
irma(X, Y) :-
    um_dos_pais(Z, X),
    um_dos_pais(Z, Y),
    mulher(X),
    diferente(X, Y).
tia(X, Y) :-
    um_dos_pais(Z, Y),
    irma(X, Z).
tem_filho(X) :- 
    um_dos_pais(X,_).

    
%Fato
pertence(X,[X|[]]).
%Regras
pertence(X,[_|Z]) :- pertence(X,Z).
ultimo(L,X) :- pertence(X,L).


dentro(X,[X|_]).
dentro(X,[_|T]) :- dentro(X,T).


exiba([]).
exiba([X|Y]) :- writeln(X), exiba(Y).


concatenar([],L,L).
concatenar([X|L1],L2,[X|L3]) :- concatenar(L1,L2,L3).


acrescentar(X,L,[X|L]).


acresfim(X,[],[X]).
acresfim(X,[Y|L1],[Y|L2]) :- acresfim(X,L1,L2).


remove([],_,[]).
remove([X|C],X,Y) :- remove(C,X,Y),!.
remove([Y|C],X,[Y|C1]) :- remove(C,X,C1),!.


sublista(S,L) :- concatenar(_L1,L2,L), concatenar(S,_L3,L2).


tamanho([],0).
tamanho([_|Y],T) :- tamanho(Y,R), T is R+1.

%corte verde
f(X,0) :- X<5,!.
f(X,1) :- X>=5,X=<9,!.
f(X,2) :- X>9.

%corte vemelho
%f(X,0) :- X<5,!.
%f(X,1) :- X=<9,!.
%f(_,2).

par(A) :- 0 is mod(A,2).
num_ele([],0).
num_ele(X,[T|C]) :- par(T),fail, num_ele(C,Z), X is Z+1.


%somar(N,R1) :- R is 1/N.
%decrementa(X) :- N is X-1.

soma(0,_).
soma(N,R) :- soma(M,Y),M is (N-1),Y is R+(1/N).

somar1(R,S1) :- S is R + S1, R is R-1.
soma_impar(0,_).
soma_impar(R,S) :- (R mod 2) =:= 1,D is R,G is R-1,soma(G,D).


mesmo([X,Y]):- X == Y , !.
mesmo([A,B|Z]):- A == B , mesmo([B|Z]).

impar(X) :- 1 is mod(X,2).
sum(0,0).
sum(X,R) :- X1 is X-1, sum(X1,R1), impar(X) R is R1+X,!.


