.data
    matz:     .float  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    matx:     .float  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    maty:     .float  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    leia:     .asciiz "\nInsira um valor para a matriz: "
    imprimir: .asciiz "\nMatriz:"
    resul:    .asciiz "\n\nResultado:"
    space:    .asciiz " "
    line:     .asciiz "\t\n"  
.text
.globl main
main:
    addi $sp, $sp, -4           # Empilha o endereço de retorno da main
    sw $ra, 0($sp)
    
    la $a3, matx                # Carrega o endereço da matriz X

    jal ler                     # Leitura da matriz X

    jal exibir                  # Exibição da matriz X

    la $a3, maty                # Carrega o endereço da matriz Y

    jal ler                     # Leitura da matriz Y

    jal exibir                  # Exibição da matriz Y

    jal calcula                 # Z = X + Y

    li $v0, 4
    la $a0, resul               # Imprime a mensagem de resultado para separação das matrizes
    syscall

    la $a3, matz                # Carrega o endereço da matriz Z

    jal exibir                  # Exibição da matriz Z

    lw $ra, 0($sp)              # Desempilha o endereço de retorno da main
    addi $sp, $sp, 4
    li $v0, 10
    syscall
    jr $ra

#-----------------------------------------------------------------------------------

ler:
    addi $sp, $sp, -4           # Empilha o endereço de retorno para a main
    sw $ra, 0($sp)

    li $s0, 0                   # i = 0

    loop1:
        li $s1, 0               # j = 0

        beq $s0, 64, exit1      # Verifica se i == 64 para sair da função

    loop2:
        beq $s1, 16, exit2      # Verifica se j == 16 para ler outra linha da matriz (zerar j e incrementar i)

        li $v0, 4               # Imprime a mensagem de entrada
        la $a0, leia
        syscall

        add $s3, $s0, $s1       # i+j para chegar a posição do elemento na matriz
        add $s3, $s3, $a3       # i+j + posição da matriz na memória

        li $v0, 6               # lê o número do usuário
        syscall
        swc1 $f0, 0($s3)        # ou s.s

        addi $s1, $s1, 4       # j += 4
        j loop2

    exit2:
        add $s0, $s0, $s1       # i += 16
        j loop1

    exit1:
        lw $ra, 0($sp)          # Desempilha o endereço de retorno para a main
        addi $sp, $sp, 4
        jr $ra

#-------------------------------------------------------------------------

exibir:
    addi $sp, $sp, -4           # Empilha o endereço de retorno para a main
    sw $ra, 0($sp)

    li $s0, 0                   # i = 0

    li $v0, 4                   # Imprime a mensagem de entrada
    la $a0, imprimir
    syscall

    loopi:
        li $s1, 0               # j = 0

        beq $s0, 64, exiti      # Verifica se i == 64 para sair da função

        li $v0, 4
        la $a0, line            # Pula linha para separação correta da matriz na impressão
        syscall

    loopj:
        beq $s1, 16, exitj      # Verifica se j == 16 para imprimir outra linha da matriz

        add $s3, $s0, $s1       # i+j para chegar a posição do elemento na matriz
        add $s3, $s3, $a3       # i+j + posição da matriz na memória

        li $v0, 2               # Exibe o número para o usuário
        lwc1 $f12, 0($s3)       # ou l.s
        syscall

        li $v0, 4               # Exibe um espaço para separação dos números
        la $a0, space
        syscall

        addi $s1, $s1, 4       # j += 4
        j loopj

    exitj:
        add $s0, $s0, $s1       # i += 16
        j loopi

    exiti:
        li $v0, 4
        la $a0, line            # Pula uma linha para separação de informações no console
        syscall                 

        lw $ra, 0($sp)          # Desempilha o endereço de retorno para a main
        addi $sp, $sp, 4
        jr $ra

#------------------------------------------------------------------------

calcula:
    addi $sp, $sp, -4           # Empilha o endereço de retorno para a main
    sw $ra, 0($sp)

    la $a0, matx
    la $a1, maty
    la $a2, matz

    li $s0, 0                   # i = 0

    for1:
        li $s1, 0               # j = 0

        beq $s0, 64, saida1     # Verifica se i == 64 para sair da função

    for2:
        beq $s1, 16, saida2     # Verifica se j == 16 para ler outra linha da matriz (zerar j e incrementar i)

        add $t0, $s0, $s1       # i+j para chegar a posição do elemento na matriz X
        
        add $t1, $t0, $a0       # i+j + posição da matriz X na memória
        lwc1 $f2, 0($t1)        # Carrega o valor do elemento da matriz X (ou l.s)

        add $t2, $t0, $a1       # i+j + posição da matriz Y na memória
        l.s $f4, 0($t2)        # Carrega o valor do elemento da matriz Y (ou lwc1)

        add.s $f5, $f2, $f4     # Realiza a soma dos dois elementos das matrizes X e Y

        add $t3, $t0, $a2       # i+j + posição da matriz Z na memória
        s.s $f5, 0($t3)        # Salva o resultado da soma na matriz Z (s.wc1)

        addi $s1, $s1, 4       # j += 4
        j for2

    saida2:
        add $s0, $s0, $s1       # i += 16
        j for1

    saida1:
        lw $ra, 0($sp)          # Desempilha o endereço de retorno para a main
        addi $sp, $sp, 4
        jr $ra