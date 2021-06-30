.data
	msg1: .asciiz "\nInsira um elemento para o vetor: "
	msg2: .asciiz "\nVetor ordenado:"
	space: .asciiz " "
	array: .word 1, 1, 1, 1, 1
	size: .byte 20 				# Tamanho do vetor

.text
.globl main
main:
	addi $sp, $sp, -4			# Armazena na pilha o endereço que chamou a main
	sw $ra, 0($sp)
	
	move $t0, $zero
	lw $a2, size				# Coleta o tamanho do array
	
ler:
	li $v0, 4
	la $a0, msg1				# Exibe a msg de entrada
	syscall
	
	li $v0, 5					# Coleta um número
	syscall
	
	sw $v0, array($t0) 			# Armazena o valor no array
	
	addi $t0, $t0, 4
	bne $a2, $t0, ler			# Verifica se chegou ao final do array
	
	jal sort					# Ordena
	
	move $t0, $zero
	lw $a2, size				# Coleta o tamanho do array

	li $v0, 4
	la $a0, msg2				# Exibe a msg de demonstração do vetor
	syscall
	
exibir:	
	li $v0, 4
	la $a0, space				# Exibe um espaço para separação dos números
	syscall
	
	li $v0, 1					# Comando para exibir o valor
	lw $a0, array($t0)			# Carrega o valor para exibir
	syscall
	
	addi $t0, $t0, 4
	bne $t0, $a2, exibir		# Verifica se chegou ao final do array
	
	lw $ra, 0($sp)				# Retira da pilha o endereço que foi chamada a main
	addi $sp, $sp, 4
	
	jr $ra
	
swap:
	addi $t4, $s1, 4			# Carrega j+1
	lw $t1, array($s1)			# Carrega array[j]
	lw $t2, array($t4)			# Carrega array[j+1]

	sw $t2, array($s1)			# Array[j] = array[j+1]
	sw $t1, array($t4)			# Array[j+1] = array[j]
	jr $ra						# Retorna para o loop
	
sort:
	addi $sp, $sp, -4			# Armazena na pilha o endereço de retorno
	sw $ra, 0($sp)
	
	move $s0, $a2				# i = size
	
loop1:
	blt $s0, 1, exit1			# Verifica se i < 1
	move $s1, $zero				# j = 0
	
loop2:
	slt $t0, $s1, $s0			# Verifica se j < i
	beq $t0, $zero, exit2		

	addi $t5, $s1, 4
	
	lw $t3, array($s1)			# $t3 recebe array[j]
	lw $t4, array($t5)			# $t4 recebe array[j+1]

	blt $t3, $t4, continua		# se array[j+1] > array[j] está ordenado e continua no loop

	jal swap

continua:	
	addi $s1, $s1, 4			# Incrementa uma posição em j (4 bytes = 1 word)
	j loop2
	
exit2:
	addi $s0, $s0, -4			# Decrementa uma posição do i, (4 bytes = 1 word)
	j loop1
	
exit1:
	lw $ra, 0($sp)				# Retira da pilha o endereço de retorno
	addi $sp, $sp, 4
	
	jr $ra