.text
.globl main
main:
	li $a0, 5				# Carrega o valor para o fatorial de 5
	jal Fatorial
	
	move $s0, $v0			# Move o resultado (v0) para s0
	li $v0, 10				# Carrega v0 com 10 (Exit)
	
	syscall
	
Fatorial:
	sub $sp, $sp, 4			# Atualiza a pilha
	sw $ra, 0($sp)			# Guarda na pilha o valor de retorno (ra)
	li $t1, 1				# Carrega o valor 1
	slti $t0, $a0, 2		# Verifica se é menor que 2
	
	beq $t0, $zero, Calcula	# Se não for, pular  para Calcula
	
	add $v0, $zero, $zero	# Zera o registrador
	beq $a0, $zero, Sai		# Verifica se é fatorial de zero
	add $v0, $t1, $zero		# Soma 1 ao v0 (1!)
	
Sai:
	lw $ra, 0($sp)			# Carrega o valor de ra da pilha
	add $sp, $sp, 4			# Atualiza o stack pointer
	jr $ra					# Retorna para a main
	
Calcula:
	add $a1, $a0, $zero		# Adiciona o valor do fatorial para um registrador auxiliar
	
Loop:
	sub $a1, $a1, $t1		# Subtrai 1
	jal Multiplica
	
	add $a0, $v0, $zero		# Move o resultado para a0
	bne $a1, $t1, Loop		# Verifica se o valor chegou em 1 para sair do loop
	j Sai
	
Multiplica:
	mult $a0, $a1			# Multiplica o valor * valor - 1
	mflo $v0				# Move (Move from LO (a1)) o resultado em v0
	jr $ra					# Retorna ao loop
	