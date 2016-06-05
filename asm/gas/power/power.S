.section .data

.section .text
.globl _start

_start:
	pushq	$3		# second arg, POW
	pushq	$2		# first arg, NUM
	call	power
	addq	$16,	%rsp	# remove the 2 args from the stack

	movq	%rax,	%rdi	# save answer in exit code
	movq	$60,	%rax	# exit
	syscall

# CALCULATES POWER OF NUMBER
# 2*2*2 = 2^3
# 2*2 = 4 * 2 = 8
#
# ARGS
#	NUM
#	POW
#
# VARIABLES
# 	NUM %num
#	POW %rbx
#	CUR %rax
#
# RETURNS
#	answer
.type power, @function
power:
	pushq	%rbp				# save the base pointer of caller
	mov	%rsp,		%rbp		# make the top of the stack the base for this function 

	movq	16(%rbp),	%rcx		# load NUM
	movq	24(%rbp),	%rbx		# load POW
	movq	%rcx,		%rax		# init CUR

loop:
	imulq	%rcx, %rax			# NUM * CUR = CUR
	decq	%rbx
	cmpq	$1,	%rbx			# test POW === 1
	jne	loop				# if false loop again else return answer
	
	movq	%rbp, %rsp	# make bottom of stack the top of the stack
	popq	%rbp		# restore the base pointer of the caller
	ret			# return to caller
