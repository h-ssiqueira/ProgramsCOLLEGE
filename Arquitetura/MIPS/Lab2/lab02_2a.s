.text
.globl main
main:
	move $s0, $gp 		# s0 será o endereço do início do vetor
	addi $s0, $s0, 5000 # s0 está posicionado no início do vetor na memória
	
	move $s2, $s0 		# s2 percorrerá o vetor
	addi $s2, $s2, 400 	# s2 está posicionado no final do vetor
	
	li $t0, 9			# Inicia com 9
dados:
	sw $t0, 0($s0) 		# Guarda o valor da primeira posição do vetor
	addi $s0, $s0, 4 	# Avança 1 posição
	addi $t0, $t0, 9 	# Adiciona 9
	bne $s0, $s2, dados # Se não chegou no limite, pula para dados
	
	jr $ra
	
	syscall