# ===========================================
# Exchange the highest 8 bits with the lowest 8 bits in a word
# Author: 11711918 wyc
# ===========================================
.include "macro_print_str.asm"
.text
	li      $v0, 0x5
	syscall

    srl     $t0, $v0, 31
    beq		$t0, 1, opt	# if $t0 == 1 then opt
    move 	$a0, $v0		# $a0 = $v0

output:
    li      $v0, 0x1
    syscall

	# Exit
    li      $v0, 0xA
   	syscall

opt:
    xori    $a0, $v0, 0xFFFFFFFF
    addi	$a0, $a0, 1			# $a0 = $a0 + 1
    j output