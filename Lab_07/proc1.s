.data
m: 	.word 10
n: 	.word 5

.text
MAIN:	la $t0, m		# Load address of m
	lw $a0, 0($t0)		# a0 = m
	la $t0, n			# Load address of n
	lw $a1, 0($t0)		# a1 = n

	# Corrected return address: 0x00400018 is typical for the instruction after 'j' [cite: 30, 34]
	# However, per instruction 12, we eventually replace 'j' with 'jal' [cite: 39]
	jal SUM
	
	addi $a0, $v0, 0	# Print out result
	li $v0, 1		 
	syscall	
	
	li $v0, 10		# Exit program
	syscall

SUM:	add $v0, $a0, $a1   # Calculate sum
	jr $ra              # Return to caller