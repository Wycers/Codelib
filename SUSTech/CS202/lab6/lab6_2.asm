.include "utils.asm"
.data
	zero:	.float	0
	two:	.float	2
	a:		.word	0
.text
	print_str("Please input number x: ")
	li		$v0, 6		# $v0 = 6
	syscall

	la		$t1, zero		# 
	lwc1	$f10, 0($t1)
	c.lt.s 	$f0, $f10
	bc1t 	end

	mov.s	$f1, $f0
	la		$t1, two		# 
	lwc1	$f5, 0($t1)

	la		$s0, a		

	swc1  	$f0, 0($s0)  
	lw		$t0, 0($s0)	

	srl		$t1, $t0, 1
	addi	$t0, $t1, 0x1fbd1df5	

	sw		$t0, 0($s0)
	lwc1	$f2, 0($s0)

	print_str("Please input percision p: ")
	li		$v0, 6		# $v0 = 6
	syscall
loop:
	mul.s	$f4, $f2, $f2
	sub.s	$f4, $f4, $f1
	abs.s	$f4, $f4
	# | x * x - n | < p

	c.lt.s 	$f4, $f0
	bc1t 	exit

	div.s	$f4, $f1, $f2
	add.s 	$f4, $f4, $f2
	div.s 	$f2, $f4, $f5

	j		loop				# jump to loop
exit:
	mov.s   $f12, $f2
	li		$v0, 2		# $v0 = 
	syscall

back:
	endl()
	message()
	li		$v0, 0xA		# $v0 = 0xA; terminate
	syscall
end:
	print_str("Please input a positive number!")
	endl()
	j		back				# jump to back