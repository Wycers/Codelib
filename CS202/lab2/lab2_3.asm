# ===========================================
# Exchange the highest 8 bits with the lowest 8 bits in a word
# Author: 11711918 wyc
# ===========================================
.include "utils.asm"
.text
    print_str("Input: ")
	li      $v0, 0x5
	syscall
    move    $t2, $v0

    print_str("Result: ")
    sll     $t0, $t2, 3
    sll     $t1, $t2, 1
    add		$a0, $t0, $t1		# $a0 = $t0 + $t1
    
    li      $v0, 0x1
    syscall
    endl()

	# Exit
    message()
    li      $v0, 0xA
   	syscall
