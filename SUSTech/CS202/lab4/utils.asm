.macro print_str(%str)
.data
    pstr: .asciiz %str
.text
    la $a0,pstr
    li $v0,4
    syscall
.end_macro

.macro endl
    # Print LF
	li $a0, 0xA
    li $v0, 0xB
   	syscall
.end_macro

.macro end
    li $v0,10
    syscall
.end_macro

.macro message
.data 
	msg: 	.asciiz	"By 11711918 wyc"
.text
    # Homeword required
	la $a0, msg
    li $v0, 0x4
   	syscall
.end_macro
