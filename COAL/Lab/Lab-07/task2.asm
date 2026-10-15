; Write a program, which displays the addition of three integers through a stack.

INCLUDE Irvine32.inc

.data
	msg BYTE "SUM = " , 0
.code
main PROC
	mov eax , 12
	mov ebx , 13
	mov ecx , 14

	push eax
	push ebx
	push ecx

	pop ecx
	pop ebx
	pop eax

	add eax , ebx
	add eax , ecx

	mov edx , OFFSET msg
	call WriteString
	call WriteDec
	
	exit
main ENDP
END main
