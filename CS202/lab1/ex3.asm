# ===========================================
# Change "abc" to "ABC"
# Author: 11711918 wyc
# ===========================================

.data
	str:	.asciiz	"abc"
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
