.macro print_string(%str)
.data
    pstr: .asciiz %str
.text
    la $a0,pstr
    li $v0,4
    syscall
.end_macro

.macro endl
    li $v0,10
    syscall
.end_macro