# ===========================================
# Exchange the highest 8 bits with the lowest 8 bits in a word
# Author: 11711918 wyc
# ===========================================
.include "utils.asm"
.text
    print_str("Input: ")
	li      $v0, 0x5
	syscall
    move    $t1, $v0

    srl     $t0, $t1, 31
    beq		$t0, 1, opt	# if $t0 == 1 then opt
    move 	$a0, $t1		# $a0 = $v0

output:
    li      $v0, 0x1
    syscall
    endl()
    
	# Exit
    message()
    li      $v0, 0xA
   	syscall

opt:
    xori    $a0, $t1, 0xFFFFFFFF
    addi	$a0, $a0, 1			# $a0 = $a0 + 1
    j output