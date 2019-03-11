# ===========================================
# Calculate the bit inversion (0->1,1->0) of the odd digits in a word.
# Author: 11711918 wyc
# ===========================================
.include "utils.asm"
.text
    print_str("Input: ")
	li      $v0, 0x5
	syscall

    move    $t0, $v0

    print_str("Before: ")
    move    $a0, $t0
    li      $v0, 0x23
    syscall
    endl()

    print_str("After:  ")
    xori    $a0, $t0, 0x55555555
    li      $v0, 0x23
    syscall
    endl()

	# Exit
    message()
    li      $v0, 0xA
   	syscall
