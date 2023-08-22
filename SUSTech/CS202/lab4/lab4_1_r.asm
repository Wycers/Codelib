.include "utils.asm"
.main
    print_str("Input a integer n = ")
    li		$v0, 5		    # $v0 = 5
    syscall

    move 	$v1, $v0		# $v1 = $v0

    move 	$a0, $v1		# $a0 = $v1
	jal		fib				# jump to fib and save position to $ra

    move 	$v1, $v0		# $v1 = $v0

    print_str("fib(n) is ")

	move 	$a0, $v1		# $a0 = $v0
	li		$v0, 1			# $v0 = 1
	syscall

    endl()
    message()

	li		$v0, 0xA		# $v0 = 0xA; terminate
	syscall

fib:
	slti	$t0, $a0, 2 	# $t0 = $a0 < 2
	bne		$t0, $0, R		# if $t0 != $0 then R

	addi	$sp, $sp, -12
	sw		$ra, 4($sp)		# store ra
	sw		$a0, 0($sp)		# store a0
	
	addi	$a0, $a0, -1	# cal fib(n - 1)
	jal		fib
	sw		$v0, 8($sp)		# save result of fib(n - 1)
	
	lw		$a0, 0($sp)
	addi	$a0, $a0, -2	# cal fib(n - 2)
	jal		fib
	
	lw		$ra, 4($sp)
	lw		$v1, 8($sp)		# load result of fib(n - 2)
	add		$v0, $v0, $v1	# return fib(n - 1) + fib(n - 2)
	addi	$sp, $sp, 12
	jr		$ra
R:
	move 	$v0, $a0		# $v0 = $a0
	jr		$ra