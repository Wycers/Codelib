# ===========================================
# Exchange the highest 8 bits with the lowest 8 bits in a word
# Author: 11711918 wyc
# ===========================================
.include "macro_print_str.asm"
.text
	li      $v0, 0x5
	syscall

    sll     $a0, $v0, 8
    srl     $a0, $a0, 16
    sll     $a0, $a0, 8

    sll     $t1, $v0, 24
    addu	$a0, $a0, $t1		# $a0 = $t0 + $t1

    srl     $t1, $v0, 24
    addu	$a0, $a0, $t1		# $a0 = $t0 + $t1
    
    li      $v0, 0x1
    syscall

	# Exit
    li      $v0, 0xA
   	syscall
