/*EX2 -> Explique por que nao e possivel igualar uma lista a outra apenas igualando dois ponteiros.
 
 Ao utilizar um ponteiro para indicar uma lista significa que tal ponteiro guarda o endereço do inicio de tal lista e nao as informaçoes armazenadas na lista em questao. Caso nao haja esse ponteiro apontando para o inicio da lista, todos os dados alocados na memoria seriam perdidos na execuçao do programa, porem eles ainda continuariam alocados e ocupando espaço da memoria RAM. Assim, ao igualar dois ponteiros, ha apenas a criaçao de um novo ponteiro que faz a funçao de guardar o endereço da primeira partiçao da lista, sendo este util para loops. Para que uma lista seja igual a outra, e necessario que haja a alocaçao de uma outra lista e copiar as informaçoes de cada subconjunto da lista para a nova lista, assim havera uma igualdade de listas, ou seja, as informaçoes seriam iguais, mas os ponteiros indicando o inicio da lista teriam valores diferentes, pois cada lista ocuparia um lugar distinto na memoria RAM.
*/

///EX4 -> o codigo abaixo esta correto? Justifique.
void  troca (int  *i,  int  *j){
    int  *temp = *i;
    *i = *j;
    *j = *temp;
} 
/*
    O codigo acima nao esta correto, pois a utilizaçao da variavel "temp" esta incorreta, a funçao considera "temp" como um ponteiro que recebe o valor contido em "i" e nao seu endereço, assim, ao executar o programa havera o erro de falha de segmentaçao para corrigir tal erro, deve-se inicializar e realizar a manipulaçao da mesma sem o ponteiro (*), pois o objetivo da funçao e de trocar os valores passados por parametro e, por isso, e necessario que a variavel declarada seja do tipo inteiro que consiga receber o valor do ponteiro inteiro "i".
 */
