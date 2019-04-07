.include "utils.asm"
.data
	a: 		.float	0, 1, 2, 3, 4, 5, 6, 7, 1, 9,
					1, 2, 3, 4, 5, 6, 7, 8, 2, 9,
					2, 1, 4, 3, 6, 5, 8, 7, 3, 9,
					1, 2, 3, 4, 5, 6, 7, 8, 2, 9,
					0, 1, 2, 3, 4, 5, 6, 7, 1, 9
	n:		.float 	10
	zero:	.float	0
.text
	la		$s0, a				# 
	addi	$s7, $s0, 200		# $s7 = $s0 + 50
loop1:
	beq		$s0, $s7, exit1		# if $s0 == $s7 then exit1
	lwc1	$f0, 0($s0)
	add.s	$f1, $f1, $f0
	addi	$s0, $s0, 4			# $s0 = $s0 + 4
	j		loop1				# jump to loop1
exit1:
	la		$t1, n				# 
	lwc1 	$f3, 0($t1)
	div.s	$f2, $f1, $f3
	
	la		$s0, a				# 
	addi	$s1, $s0, 40		# $s1 = $s0 + 40
	addi	$s2, $s1, 40		# $s2 = $s1 + 40
	addi	$s3, $s2, 40		# $s3 = $s2 + 40
	addi	$s4, $s3, 40		# $s4 = $s3 + 40

	li		$t1, 0		# $t1 = 0
	
	la		$t1, zero		# 
	lwc1	$f4, 0($t1)
	li		$t1, 0		# $t1 = 0
loop2:
	beq		$s4, $s7, exit2		# if $s0 == $s7 then exit2
	mov.s	$f1, $f4
	lwc1	$f0, 0($s0)
	add.s	$f1, $f1, $f0
	lwc1	$f0, 0($s1)
	add.s	$f1, $f1, $f0
	lwc1	$f0, 0($s2)
	add.s	$f1, $f1, $f0
	lwc1	$f0, 0($s3)
	add.s	$f1, $f1, $f0
	lwc1	$f0, 0($s4)
	add.s	$f1, $f1, $f0

	c.lt.s 	$f1, $f2
	bc1t 	print
back:
	addi	$s0, $s0, 4			# $s0 = $s0 + 4
	addi	$s1, $s1, 4			# $s1 = $s1 + 4
	addi	$s2, $s2, 4			# $s2 = $s2 + 4
	addi	$s3, $s3, 4			# $s3 = $s3 + 4
	addi	$s4, $s4, 4			# $s4 = $s4 + 4
	addi	$t1, $t1, 1			# $t1 = $t1 + 1
	j		loop2				# jump to loop2
exit2:
	endl()
	message()
	li		$v0, 0xA		# $v0 = 0xA; terminate
	syscall
print:
	move 	$a0, $t1		# $a0 = $t1
	li		$v0, 1		# $v0 = 1
	syscall
	print_str(" ")
	j		back				# jump to back
	