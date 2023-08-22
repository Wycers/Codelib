.include "utils.asm"
.main
    print_str("Input a integer n = ")
    li		$v0, 5		    # $v0 = 5
    syscall

    move 	$v1, $v0		# $v1 = $v0
	move 	$t2, $v1		# $t2 = $v1

	li		$v0, 2			# $v0 = 2
	li		$t0, 0			# $t0 = 0
	li		$t1, 1			# $t1 = 1
	
	blt		$v1, $v0, exit	# if $v1 < $v0 then r

loop:
	add		$t2, $t1, $t0	# $t2 = $t1 + $t0
	beq		$v0, $v1, exit	# if $v0 == $v1 then exit
	move 	$t0, $t1		# $t0 = $t1
	move 	$t1, $t2		# $t1 = $t2
	addi	$v0, $v0, 1		# $v0 = $v0 + 1
	j		loop			# jump to loop
	
exit:
    print_str("fib(n) is ")
	move 	$a0, $t2		# $a0 = $t2
	li		$v0, 1			# $v0 = 1
	syscall

    endl()
    message()

	li		$v0, 0xA		# $v0 = 0xA; terminate
	syscall