.data
	const1: .byte 1
	const2: .word 4
	array1: .byte 9, 21, 16, 18, 38
	tam1: 	.byte 5
	array2: .word 206, 1543, 348, 709, 7000, 994
	tam2: 	.byte 24
	
.text
.globl main
main:
	lb $s0, const1			# Carrega um byte em s0
	lw $s1, const2			# Carrega uma word em s1
	
	add $s2, $zero, $zero	# Inicia s2 com zero
	add $t0, $zero, $zero	# Inicia t0 com zero
	lb $t1, tam1			# Carrega 5 bytes em t1
	
soma1:
	lb $t2, array1($t0)
	add $s2, $s2, $t2
	add $t0, $t0, $s0
	bne $t0, $t1, soma1
	
	add $s3, $zero, $zero	# Zera s3
	add $t0, $zero, $zero	# Zera t0
	lb $t1, tam2			# Carrega 24 bytes em t1
	
soma2:
	lw $t2, array2($t0)
	add $s3, $s3, $t2
	add $t0, $t0, $s1
	bne $t0, $t1, soma2
	
	jr $ra
	
	syscall
	