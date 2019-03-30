.include "utils.asm"
.main

    li		$t1, 100		# $t1 = 100        target
    li		$t4, 0		    # $t4 = 0          cnt 
    li		$t0, 2		    # $a0 = 0          i
    li		$t5, 10		    # $t5 = 10
    

loop:
    beq		$t4, $t1, exit	# if $t4 == $t1 then exit
    move 	$a0, $t0		# $a0 = $t0
    jal		test_prime		# jump to test_prime and save position to $ra
    beq		$v0, $0, gg	    # if $v0 == $0 then gg
    move 	$a0, $t0		# $a0 = $t0
    #li		$v0, 1		    # $v0 = 1; $v0 must be 0
    syscall
    addi	$t4, $t4, 1		# $t4 = $t4 + 1

    print_str("\t")
    
    div		$t4, $t5			# $t4 / $t5
    mfhi	$t6					# $t6 = $t4 mod $t5 
    bne		$t6, $0, gg	        # if $t6 != $0 then gg
    endl()    
gg:
    addi	$t0, $t0, 1		    # $t0 = $t0 + 1
    j		loop				# jump to loop
    
exit:
	message()

	li		$v0, 0xA			# $v0 = 0xA
	syscall

test_prime:
    li		$v0, 1		        # $v0 = 1 default as prime
    li		$v1, 2		        # $v1 = 2
loop1:
    mult	$v1, $v1			# $v1 * $v1 = Hi and Lo registers
    mflo	$t2					# copy Lo to $t2
    bgt		$t2, $a0, return	# if $t2 > $a0 then return

    div		$a0, $v1			# $a0 / $v1
    mflo	$t2					# $t2 = floor($a0 / $v1) 
    mfhi	$t3					# $t3 = $a0 mod $v1 
    beq		$t3, $0, find_prime	# if $t3 == $0 then find_prime

    addi	$v1, $v1, 1			# $v1 = $v1 + 1
    j		loop1				# jump to loop1    
find_prime:
    move 	$v0, $0		        # $v0 = $0
return:
    jr		$ra					# jump to $ra