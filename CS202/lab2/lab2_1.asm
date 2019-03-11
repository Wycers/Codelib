# ===========================================
# Exchange the highest 8 bits with the lowest 8 bits in a word
# Author: 11711918 wyc
# ===========================================
.include "utils.asm"
.text
    print_str("Input: ")
	li      $v0, 0x5
	syscall

	move 	$t0, $v0

    print_str("Before: ")
    move    $a0, $t0
    li      $v0, 0x22
    syscall
    endl()
    print_str("After:  ")
	
    sll     $a0, $t0, 8
    srl     $a0, $a0, 16
    sll     $a0, $a0, 8

    sll     $t1, $t0, 24
    addu	$a0, $a0, $t1		# $a0 = $t0 + $t1

    srl     $t1, $t0, 24
    addu	$a0, $a0, $t1		# $a0 = $t0 + $t1
    
    li      $v0, 0x22
    syscall
    endl()

	# Exit
    message()
    li      $v0, 0xA
   	syscall
