# ===========================================
# Calculate (a + b * c) / d
# Author: 11711918 wyc
# ===========================================

.data
	a:	.word	1
	b: 	.word	2
	c:	.word	3
	d:	.word 	4
	quotient: 	.asciiz "Quotient of expression is "
	remainder: 	.asciiz	"Remainder of expression is "
	message: 	.asciiz	"By 11711918 wyc"
.text
	# Input
	la		$t0, a
	li $v0, 0x5
	syscall
	sw		$v0, ($t0)

	la		$t0, b
	li $v0, 0x5
	syscall
	sw		$v0, ($t0)

	la		$t0, c
	li $v0, 0x5
	syscall
	sw		$v0, ($t0)

	la		$t0, d
	li $v0, 0x5
	syscall
	sw		$v0, ($t0)
	
    # Calculate b * c
	lw $t0, b
	lw $t1, c
	mult $t0, $t1
		
    # Calculate a + res
	lw $t0, a
	mflo $t1
	add $t0, $t0, $t1
	
    # Calculate res / d
	lw $t1, d
	div $t0, $t1
	
    # Print quotient
	la $a0, quotient
    li $v0, 0x4
   	syscall
   	
	mflo $a0
	li $v0, 0x1
	syscall
	
    # Print LF
	li $a0, 0xA
    li $v0, 0xB
   	syscall
   	
    # Print remainder
	la $a0, remainder
    li $v0, 0x4
   	syscall
   	
	mfhi $a0
	li $v0, 0x1
	syscall
	
    # Print LF
	li $a0, 0xA
    li $v0, 0xB
   	syscall
	
	
    # Homeword required
	la $a0, message
    li $v0, 0x4
   	syscall

	# Exit
    li $v0, 0xA
   	syscall
