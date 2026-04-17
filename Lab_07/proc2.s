.data
x:	.word 5
y:	.word 10
m:	.word 15
b:	.word 2

.text
MAIN:	la $t0, x
	lw $s0, 0($t0)		# s0 = x
	la $t0, y
	lw $s1, 0($t0)		# s1 = y
	
	addu $a0, $zero, $s0	# Set a0 as input argument for SUM
	jal SUM
	
	addu $t0, $s1, $s0      # Calculate y + x
	addu $s1, $t0, $v0      # Add sum(x) result
	move $a0, $s1           # Prepare result for printing
	li $v0, 1		 
	syscall	
	
	li $v0, 10              # Proper Exit
	syscall
		
SUM: 	# Prologue: SUM calls another function, so it must save $ra and $s0 [cite: 66, 67]
	addiu $sp, $sp, -12
	sw $ra, 8($sp)
	sw $s0, 4($sp)
	sw $a0, 0($sp)          # Save n to add later [cite: 58]

	la $t0, m
	lw $s0, 0($t0)		# s0 = m
	addu $a0, $s0, $a0	# a0 = m + n
	jal SUB
	
	lw $a0, 0($sp)          # Restore original n [cite: 62]
	addu $v0, $a0, $v0      # v0 = n + sub(m + n)
	
	# Epilogue
	lw $s0, 4($sp)
	lw $ra, 8($sp)
	addiu $sp, $sp, 12
	jr $ra		
		
SUB:	la $t0, b
	addiu $sp, $sp -4
	sw $s0, 0($sp)		# Backup s0 from SUM
	lw $s0, 0($t0)		# s0 = b
	subu $v0, $a0, $s0      # return a - b
	lw $s0, 0($sp)		# Restore s0 from SUM
	addiu $sp, $sp 4
	jr $ra