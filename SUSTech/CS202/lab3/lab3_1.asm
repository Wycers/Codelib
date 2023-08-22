# ===========================================
# Exchange the highest 8 bits with the lowest 8 bits in a word
# Author: 11711918 wyc
# ===========================================
.include "utils.asm"
.data
    array:  .space, 401
.text
    la		$s0, array		    # 
    li      $v1, 1
    
    li		$t0, 1		        # $t0 = 1
loop1:
    bgt		$t0, 20, exit1	    # if $t0 > 20 then exit1
    li		$t1, 1		        # $t1 = 1

loop2:
    bgt		$t1, 20, exit2	    # if $t1 > 20 then exit2
    li		$t2, 1		        # $t2 = 1
loop3:
    bgt		$t2, 20, exit3	    # if $t2 > 20 then exit3

    add		$t3, $t0, $t1		# $t3 = $t0 + $t1
    add		$t4, $t0, $t2		# $t4 = $t0 + $t2
    add		$t5, $t1, $t2		# $t5 = $t1 + $t2

    mult	$t3, $t3			# $t3 * $t3 = Hi and Lo registers
    mflo	$t3					# copy Lo to $t0
    mult	$t4, $t4			# $t4 * $t4 = Hi and Lo registers
    mflo	$t4					# copy Lo to $t1
    mult	$t5, $t5			# $t5 * $t5 = Hi and Lo registers
    mflo	$t5					# copy Lo to $t2

    add		$t3, $t3, $t4		# $t0 = $t0 + $t1
    add		$t3, $t3, $t5		# $t0 = $t0 + $t2
    
    srl     $t3, $t3, 1         # $t0 = $t0 / 2

    bgt		$t3, 400, continue3	# if $t3 > 400 then continue3
    add		$s1, $s0, $t3		# $s1 = $s0 + $t3
    sb		$v1, 0($s1)		    # 
continue3:
    addi	$t2, $t2, 1			# $t2 = $t2 + 1
    j		loop3				# jump to loop3
exit3:
    addi	$t1, $t1, 1			# $t1 = $t1 + 1
    j		loop2				# jump to loop2
exit2:
    addi	$t0, $t0, 1			# $t0 = $t0 + 1
    j		loop1				# jump to loop1
exit1:
    li		$t0, 1		        # $t0 = 1
loop0:
    beq		$t0, 401, exit0	    # if $t0 == 400 then exit0
    
    add		$s1, $s0, $t0		# $s1 = $s0 + $t0
    
    lb		$t1, 0($s1)		    # 
    beq		$t1, 0, continue	# if $t1 == 0 then continue
    
    move 	$a0, $t0		    # $a0 = $t0
    li		$v0, 1		        # $v0 = 1
    syscall
	endl()
	
continue:
    addi	$t0, $t0, 1			# $t0 = $t0 + 1
    j		loop0				# jump to loop0
exit0:

	# Exit
    message()
    li      $v0, 0xA
   	syscall
