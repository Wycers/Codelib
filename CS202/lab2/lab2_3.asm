# ===========================================
# Exchange the highest 8 bits with the lowest 8 bits in a word
# Author: 11711918 wyc
# ===========================================
.include "macro_print_str.asm"
.text
	li      $v0, 0x5
	syscall

    sll     $t0, $v0, 3
    sll     $t1, $v0, 1
    add		$a0, $t0, $t1		# $a0 = $t0 + $t1
    
    li      $v0, 0x1
    syscall

	# Exit
    li      $v0, 0xA
   	syscall
