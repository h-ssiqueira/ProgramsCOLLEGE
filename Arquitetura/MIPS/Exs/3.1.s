.text
.globl main
main:
	li $a1, 6
	addi $t0, $zero, 0
	addi $t1, $zero, 1
	loop:
		slt	$t2, $a1, $t1
		bne	$t2, $zero, finish

		add $t0, $t0, $t1
		addi $t1,$t1,2
		j loop
	finish:
		add	$a0, $t0, $zero
		
		li $v0, 1
		syscall
		
		li $v0, 10
		syscall