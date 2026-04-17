.data
str_pq: .asciiz "p + q: "
newline: .asciiz "\n"

.text
# main(): x->$s0, y->$s1, z->$s2 [cite: 72]
MAIN:
	addi $s0, $zero, 2   # x = 2
	addi $s1, $zero, 4   # y = 4
	addi $s2, $zero, 6   # z = 6

	move $a0, $s0        # x
	move $a1, $s1        # y
	move $a2, $s2        # z
	jal FOO
	
	add $t0, $s0, $s1    # x + y
	add $t0, $t0, $s2    # x + y + z
	add $s2, $t0, $v0    # z = x + y + z + foo()

	move $a0, $s2
	li $v0, 1
	syscall              # Print z
	
	li $v0, 10
	syscall

# foo(): p->$s0, q->$s1 | m->$a0, n->$a1, o->$a2 [cite: 73, 75]
FOO:
	addiu $sp, $sp, -28
	sw $ra, 24($sp)
	sw $s0, 20($sp)
	sw $s1, 16($sp)
	sw $a0, 12($sp)      # m
	sw $a1, 8($sp)       # n
	sw $a2, 4($sp)       # o

	# p = bar(m + o, n + o, m + n)
	add $a0, $a0, $a2
	add $a1, $a1, $a2
	lw $t0, 12($sp)      # m
	lw $t1, 8($sp)       # n
	add $a2, $t0, $t1
	jal BAR
	move $s0, $v0        # p

	# q = bar(m - o, n - m, n + n)
	lw $t0, 12($sp)      # m
	lw $t1, 8($sp)       # n
	lw $t2, 4($sp)       # o
	sub $a0, $t0, $t2
	sub $a1, $t1, $t0
	add $a2, $t1, $t1
	jal BAR
	move $s1, $v0        # q

	la $a0, str_pq
	li $v0, 4
	syscall              # Print "p + q: "
	
	add $s0, $s0, $s1    # p + q
	move $a0, $s0
	li $v0, 1
	syscall              # Print result
	
	la $a0, newline
	li $v0, 4
	syscall

	move $v0, $s0        # Return p + q [cite: 77]
	lw $s1, 16($sp)
	lw $s0, 20($sp)
	lw $ra, 24($sp)
	addiu $sp, $sp, 28
	jr $ra

# bar(): a->$a0, b->$a1, c->$a2 [cite: 76]
BAR:
	sub $t0, $a1, $a0    # b - a
	sllv $v0, $t0, $a2   # (b - a) << c
	jr $ra