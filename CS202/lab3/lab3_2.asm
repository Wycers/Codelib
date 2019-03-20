# ===========================================
# Exchange the highest 8 bits with the lowest 8 bits in a word
# Author: 11711918 wyc
# ===========================================
.include "utils.asm"
.data
    str:  .space, 60
    res:  .space, 60
.text
    la		$s0, str		# 
    
    print_str("Please input a string(within 50 characters)\n")

    move 	$a0, $s0		# $a0 = $s0
    addi	$a1, $0, 50		# $a1 = $0 + 50
    li		$v0, 0x8		# $v0 = 0x8
    syscall
    

    move 	$s1, $s0		# $s1 = $s0
    la		$s2, res		#

loop:
    lb		$t0, 0($s1)		# 
    beq		$t0, $0, loop1	# if $t0 == $0 then exit
    addi	$s1, $s1, 1		# $s1 = $s1 + 1
    j		loop			# jump to loop

exit:

    la		$a0, res		# 
    li		$v0, 0x4		# $v0 = 0x4
   	syscall
       
    endl()
	# Exit
    message()
    li      $v0, 0xA
   	syscall
    
loop1:
    addi	$s1, $s1, -1	# $s1 = $s1 + -1
    lb		$t1, 0($s1)		# 
    sb		$t1, 0($s2)		# 
    addi	$s2, $s2, 1		# $s2 = $s2 + 1
    
    beq		$s1, $s0, exit	# if $s1 == $s0 then exit
    j		loop1			# jump to loop1
    