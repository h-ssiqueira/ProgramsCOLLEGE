.text
.globl main
main:
	li $s1, 15			# carrega o valor de g
	li $s2, 36			# carrega o valor de h
	addi $s3, $zero, 12 # carrega o valor de i
	addi $s4, $zero, 19	# carrega o valor de j
	
	add $t0, $s1, $s2 	# Realiza a operação g + h
	add $t1, $s3, $s4 	# Realiza a operação i + j
	sub $s0, $t0, $t1 	# Realiza a operação (g + h) - (i + j)
	
	jr $ra
	
	syscall