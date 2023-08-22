.include "utils.asm"
.main
	print_str("Welcome to use the simple arithmetic calculator on unsigned 31bit number:")
	endl()
	
    print_str("Please input operator: ")
    li		$v0, 0xC		# $v0 = 0xC
    syscall
	move 	$s0, $v0		# $s0 = $v0
	endl()
	
	beq		$s0, 0x2A, MUL	# if $s0 == 0x2A then MUL
	beq		$s0, 0x2B, PLUS	# if $s0 == 0x2B then PLUS

    print_str("The operator ")
	move 	$a0, $s0		# $a0 = $s0
	li		$v0, 0xB		# $v0 = 0xB
	syscall
	print_str(" is not supported, exit")
END:
	endl()
	message()
	li		$v0, 0xA		# $v0 = 0xA; terminate
	syscall

PLUS:
	# Input addend
    print_str("Please input addend: ")
    li		$v0, 0x5		# $v0 = 0x5
    syscall
	move 	$t0, $v0		# $t0 = $v0
	# Input augend
    print_str("Please input augend: ")
    li		$v0, 0x5		# $v0 = 0x5
    syscall
	move 	$t1, $v0		# $t1 = $v0
	addu	$t2, $t0, $t1
	move 	$t3, $t2		# $t3 = $t2
	srl		$t3, $t3, 31
	teqi	$t3, 1
	beq		$t3, 1, END	# if $t2 == 1 then END

	print_str("The sum of ")
	move 	$a0, $t0		# $a0 = $t0
	li		$v0, 0x1		# $v0 = 0x1
	syscall
	print_str(" and ")
	move 	$a0, $t1		# $a0 = $t1
	li		$v0, 0x1		# $v0 = 0x1
	syscall
	print_str(" is : ")
	move 	$a0, $t2		# $a0 = $t2
	li		$v0, 0x1		# $v0 = 0x1
	syscall

	j		END				# jump to END
MUL:
	# Input multiplicand
    print_str("Please input multiplicand: ")
    li		$v0, 0x5		# $v0 = 0x5
    syscall
	move 	$t0, $v0		# $t0 = $v0
	# Input multiplier
    print_str("Please input multiplier: ")
    li		$v0, 0x5		# $v0 = 0x5
    syscall
	move 	$t1, $v0		# $t1 = $v0

	mult	$t0, $t1			# $t0 * $t1 = Hi and Lo registers
	mflo	$t2					# copy Lo to $t2
	
	mfhi	$t3
	sgt		$t3, $t3, $0
	teqi	$t3, 1
	beq		$t3, 1, END	# if $t3 == 1 then END
	
	print_str("The product of ")
	move 	$a0, $t0		# $a0 = $t0
	li		$v0, 0x1		# $v0 = 0x1
	syscall
	print_str(" with ")
	move 	$a0, $t1		# $a0 = $t1
	li		$v0, 0x1		# $v0 = 0x1
	syscall
	print_str(" is : ")
	move 	$a0, $t2		# $a0 = $t2
	li		$v0, 0x1		# $v0 = 0x1
	syscall

	j		END				# jump to END

.ktext 0x80000180
	beq		$s0, 0x2A, MULE	# if $s0 == 0x2A then MULE
	kprint_str("Runtime exception at ")
	mfc0 	$k0, $14 
	move 	$a0, $k0		# $a0 = $k0
	li		$v0, 0x22		# $v0 = 0x22
	syscall

	addi 	$k0, $k0, 4 
	mtc0 	$k0, $14
	
	kprint_str(", the sum is overflow")
	eret

MULE:
	kprint_str("Runtime exception at ")
	mfc0 	$k0, $14 
	move 	$a0, $k0		# $a0 = $k0
	li		$v0, 0x22		# $v0 = 0x22
	syscall
	
	addi 	$k0, $k0, 4 
	mtc0 	$k0, $14

	kprint_str(", the product is bigger than the Max value of a word.")
	eret