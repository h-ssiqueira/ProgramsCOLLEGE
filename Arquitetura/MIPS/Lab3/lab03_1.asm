.data
	msg1: .asciiz "\nEntre com um numero: "
	msg2: .asciiz "\nO fatorial do numero: "
	
.text
.globl main
main:
	addi $sp, $sp, -4	# Guarda na pilha o endereço de retorno da main
	sw $ra, 0($sp)

	li $v0, 4
	la $a0, msg1		# Exibe a msg de entrada
	syscall
	
	li $v0, 5			# Coleta um número
	syscall
	
	add $a1, $zero, $v0	# Coloca o número em a1
	
	jal fatorial		# Chama a função
	
	li $v0, 4			
	la $a0, msg2		# Exibe a msg de resultado
	syscall
	
	li $v0, 1			# Comando para exibir o resultado
	add $a0, $zero, $v1	# Carrega o resultado para exibir
	syscall
	
	li $v0, 5			# Esperar o enter
	syscall
	
	lw $ra, 0($sp)		# Retira da pilha o endereço de retorno da main
	addi $sp, $sp, 4
	
	jr $ra
	
fatorial:
	blt $a1, 2, sai  	# Verifica se o valor é menor que 2 para não entrar na recursão
	
	addi $sp, $sp, -8	# Abre espaço na pilha
	
	sw $a1, 4($sp)		# Coloca o valor anterior do numero para multiplicar posteriormente
	sw $ra, 0($sp)		# Coloca o valor do endereço de retorno da função para realizar a recursão
	
	addi $a1, $a1, -1	# Decrementa o numero para recursão
	
	jal fatorial		# Recursão
	
	lw $ra, 0($sp)		# Carrega o endereço de retorno
	lw $a1, 4($sp)		# Carrega o valor anterior
	
	addi $sp, $sp, 8	# Move o StackPointer para ajustar o topo da pilha
	
	mul $v1, $a1, $v1	# Multiplica o resultado pelo numero presente
	
	jr $ra				# Retorna para a main
	
sai:					# Se for menor que 2
	addi $v1, $zero, 1	# Adiciona 1 para retorno
	jr $ra				# Retorna para a main