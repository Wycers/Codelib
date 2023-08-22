.include "utils.asm"
.data
    dight:  .space, 20
.main
    print_str("Input a integer n = ")
    li		$v0, 5		    # $v0 = 5
    syscall

	andi	$t0, $v0, 0x80000000
	bne		$t0, $0, negative	# if $t0 != $0 then negative

	la		$s0, dight		# 
	move 	$s1, $s0		# $s1 = $s0
	li		$v1, 10			# $v1 = 10
	
deal:
	div		$v0, $v1		# $v0 / 10

	mfhi	$t2				# $t2 = $v0 mod 10 
	sb		$t2, 0($s1)		# 
	addi	$s1, $s1, 1		# $s1 = $s1 + 1
	
	mflo	$t1				# $t1 = floor($v0 / 10) 
	move 	$v0, $t1		# $v0 = $t1
	bne		$v0, $0, deal	# if $v0 == $0 then deal

loop:
	subi	$s1, $s1, 1			# $s1 = $s1 - 1
	lb		$t0, 0($s1)			# 

	li		$t1, 0				# $t1 = 0
	beq		$t0, $t1, r0		# if $t0 == $t1 then 0

	addi	$t1, $t1, 1			# $t1 = $t1 + 1
	beq		$t0, $t1, r1		# if $t0 == $t1 then 0

	addi	$t1, $t1, 1			# $t1 = $t1 + 1
	beq		$t0, $t1, r2		# if $t0 == $t1 then 0
	
	addi	$t1, $t1, 1			# $t1 = $t1 + 1
	beq		$t0, $t1, r3		# if $t0 == $t1 then 0
	
	addi	$t1, $t1, 1			# $t1 = $t1 + 1
	beq		$t0, $t1, r4		# if $t0 == $t1 then 0
	
	addi	$t1, $t1, 1			# $t1 = $t1 + 1
	beq		$t0, $t1, r5		# if $t0 == $t1 then 0
	
	addi	$t1, $t1, 1			# $t1 = $t1 + 1
	beq		$t0, $t1, r6		# if $t0 == $t1 then 0
	
	addi	$t1, $t1, 1			# $t1 = $t1 + 1
	beq		$t0, $t1, r7		# if $t0 == $t1 then 0
	
	addi	$t1, $t1, 1			# $t1 = $t1 + 1
	beq		$t0, $t1, r8		# if $t0 == $t1 then 0
	
	addi	$t1, $t1, 1			# $t1 = $t1 + 1
	beq		$t0, $t1, r9		# if $t0 == $t1 then 0
end:
	print_str(".")
gg:
	endl()
	message()

	li		$v0, 0xA			# $v0 = 0xA
	syscall

r0:
	print_str("Zero")
	j		back				# jump to back
r1:
	print_str("One")
	j		back				# jump to back
r2:
	print_str("Two")
	j		back				# jump to back
r3:
	print_str("Three")
	j		back				# jump to back
r4:
	print_str("Four")
	j		back				# jump to back
r5:
	print_str("Five")
	j		back				# jump to back
r6:
	print_str("Six")
	j		back				# jump to back
r7:
	print_str("Seven")
	j		back				# jump to back
r8:
	print_str("Eight")
	j		back				# jump to back
r9:
	print_str("Nine")
	j		back				# jump to back
back:
	beq		$s1, $s0, end		# if $s1 != $s0 then end
	print_str(" ")
	j		loop				# jump to loop
negative:
	print_str("Invalid input.")
	j		gg				# jump to gg