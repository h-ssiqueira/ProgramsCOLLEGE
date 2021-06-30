.text
.globl main
main:
	addi $t3, $zero, 2
	addi $t2, $zero, 5
	
	li $v0,1
	move $a0,$t3
	syscall
	
	li $v0,1
	move $a0,$t2
	syscall
	
	
	####Valor absoluto
	#addu $t2,$zero,$t3
	#bgez $t3,next
	#sub $t2,$zero,$t3
	#next:

	
	####NOT em MIPS
	#nor $t3,$t3,$t3
	
	####XCHG em MIPS
	#add $at, $zero, $t3
	#add $t3, $zero, $t2
	#add $t2, $zero, $at
	
	
	
	li $v0,1
	move $a0,$t3
	syscall
	
	li $v0,1
	move $a0,$t2
	syscall
	
	li $v0, 10
	syscall
