.data 0x0000
   dta1:    .word 0x007f2810
   val1:    .word 0x00000001
   val2:    .word 0x00000002
   val3:    .word 0x00000003
   val5:    .word 0x00000005
   val6:    .word 0x00000006
   val7:    .word 0x00000007
   buf:     .word 0x0000ffff
   odd:     .word 0x00005555
.text 0x0000
start:  lui $1, 0xFFFF
        ori $28, $1, 0xF000  # $28=0xFFFFF000

        lw $10, 4($0)   #$10=1
        lw $11, 8($0)   #$11=2
        lw $12, 12($0)   #$12=3
        lw $13, 16($0)   #$13=5
        lw $14, 20($0)   #$14=6
        lw $15, 24($0)   #$15=7
        lw $21, 28($0)
        lw $t0, 32($0)
        and $4, $4, $0
input:  lw $1, 3186($28)
        srl $1, $1, 5
        beq $1, $10, case1
        beq $1, $11, case2
        beq $1, $12, case3
        beq $1, $13, case5
        beq $1, $14, case6
        beq $1, $15, case7

        lw $29, 0($0)
loop:   addi $29, $29, 0xFFFF
        bne $29, $0, loop
        xori $t0, $t0, 0xFFFF
        sw $t0, 3168($28)
        j input
case1:  lw $1, 3184($28)
        andi $4, $1, 0xFFFFFFFF
        j printi
case2:  addi $4, $4, 1
        j print
case3:  addiu $4, $4, -1
        j print
case5:  sll $4, $4, 1
        and $4, $4, $21
        j print
case6:  sll $5, $4, 16
        sra $5, $5, 1
	    srl $4, $5, 16
        j print
case7:  srl $4, $4, 1
        j print

print:  lw $29, 0($0)
qwq:    addi $29, $29, 0xFFFF
        bne $29, $0, qwq
printi: sw $4, 3168($28)
        j input
