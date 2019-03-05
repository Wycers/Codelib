# ===========================================
# Change "abc" to "ABC"
# Author: 11711918 wyc
# ===========================================

.data
	str:	.asciiz	"abc"
	message: 	.asciiz	"By 11711918 wyc"
.text
	la		$t1, str
	
	lb		$t0, 0($t1)
	subu	$t2, $t0, 32
	sb		$t2, 0($t1)

	lb		$t0, 1($t1)
	subu	$t2, $t0, 32
	sb		$t2, 1($t1)
	
	lb		$t0, 2($t1)
	subu	$t2, $t0, 32
	sb		$t2, 2($t1)
	
	la		$a0, str
	li		$v0, 4
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
