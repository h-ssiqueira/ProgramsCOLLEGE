.text
.globl main
main:
	move $s0, $gp 		# s0 será o endereço do início do vetor
	addi $s0, $s0, 5000 # s0 está posicionado no início do vetor na memória
	
	move $s2, $s0 		# s2 percorrerá o vetor
	addi $s2, $s2, 400 	# s2 está posicionado no final do vetor
	
	li $t0, 9 			# Inicia com 9
dados:
	sw $t0, 0($s0) 		# Guarda o valor da primeira posição do vetor
	addi $s0, $s0, 4 	# Avança 1 posição
	addi $t0, $t0, 9 	# Adiciona 9 na variável temporária para armazenar no vetor
	bne $s0, $s2, dados # Se não chegou no limite, pula para dados
	
	move $s0, $gp 		# s0 será o endereço de início do vetor
	addi $s0, $s0, 5000 # Retorna a posição inicial do vetor
	
	move $s1, $gp 		# s1 será o final do vetor 2
	addi $s1, $s1, 6000 # Retorna a posição ao final da memória (final do vetor)
	
transfere:
	lw $t0, 0($s0) 			# Carrega a posição (inicio-fim vetor)
	sw $t0, 0($s1) 			# Salva a posição (fim-inicio vetor)
	addi $s0, $s0, 4 		# Adiciona 4 para mudar de posição no vetor
	addi $s1, $s1, 4 		# Adiciona 4 para mudar de posição no vetor
	bne $s0, $s2, transfere # Se não chegou no limite, pula para dados
	
	jr $ra
	
	syscall