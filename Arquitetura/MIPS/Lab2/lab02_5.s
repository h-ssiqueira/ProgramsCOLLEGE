.data
	msg1: .asciiz "\nEntre o número de avalizações da disciplina: "
	msg2: .asciiz "\nEntre um valor para a nota "
	msg3: .asciiz ": "
	msg4: .asciiz "\nA média das notas é: "

.text
.globl main
main:
	add $t0, $zero, $zero 	# Zera t0
	add $t1, $zero, $zero	# Zera t1

numnotas:
	li $v0, 4				# Carrega v0 com 4
	la $a0, msg1			# Carrega o endereço da msg1
	
	syscall
	
	li $v0, 5				# Carrega v0 com 5 (ler inteiros)
	
	syscall
	
	add $s0, $v0, $zero		# Copia o valor de v0 para s0 (nlúmero de notas)
	
loopnotas:
	addi $t0, $t0, 1		# Adiciona 1 a t0 (incrementar loop)
	li $v0, 4				# Carrega v0 com 4 (escrever string)
	la $a0, msg2			# Carrega o endereço de msg2
	
	syscall
	
	li $v0, 1				# Carrega v0 com 1 (escrever inteiros)
	add $a0, $zero, $t0		# Move o valor de t0 para a0
	
	syscall
	
	li $v0, 4				# Carrega v0 com 4 (escrever string)
	la $a0, msg3			# Carrega o endereço de msg3
	
	syscall
	
	li $v0, 5				# Carrega v0 com 5 (ler inteiros)
	
	syscall
	
	add $t1, $t1, $v0		# Soma a nota ao total
	
	bne $t0, $s0, loopnotas	# Se não preencheu todas as notas, permanece no loop
	
Calcula:
	div $t1, $s0			# Divide a soma das notas pelo total de provas
	mflo $t2				# Move (Move from LO (s0)) o resultado em t2
	
	li $v0, 4				# Carrega v0 com 4 (escrever string)
	la $a0, msg4			# Carrega o endereço de msg4

	syscall
	
	li $v0, 1				# Carrega v0 com 1 (escrever inteiros)
	add $a0, $zero, $t2		# Move o valor de t2 para a0
	
	syscall
	
	li $v0, 5				# Carrega v0 com 5 (ler inteiros)
	
	syscall