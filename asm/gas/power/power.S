.section .data

.section .text
.globl _start

_start:
	pushq	$0		# second arg, exp
	pushq	$2		# first arg, base
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
#	exp
#
# VARIABLES
# 	BASE %num
#	EXP %rbx
#	ANS %rax
#
# RETURNS
#	answer
.type power, @function
power:
	pushq	%rbp				# save the base pointer of caller
	mov	%rsp,		%rbp		# make the top of the stack the base for this function 

	movq	16(%rbp),	%rcx		# load base
	movq	24(%rbp),	%rbx		# load exp
	cmpq	$0,		%rbx
	movq	$1,		%rax
	je	exit
	movq	%rcx,		%rax		# init ANS

loop:
	imulq	%rcx, %rax			# BASE * ANS = ANS
	decq	%rbx
	cmpq	$1,	%rbx			# test exp === 1
	jne	loop				# if false loop again else return answer
	
exit:
	movq	%rbp, %rsp	# make bottom of stack the top of the stack
	popq	%rbp		# restore the base pointer of the caller
	ret			# return to caller
