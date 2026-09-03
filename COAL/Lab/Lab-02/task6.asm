INCLUDE Irvine32.inc


COMMENT!
Debug the below program and note down the values of all the registers after the execution
of each line. !

.code
main PROC

	mov eax , 57h
	mov ebx , 38h
	mov ecx , 50h

	add eax , ebx
	add eax , ecx

	mov ebx , 65h
	mov ecx , 84h

	add eax , ebx
	add eax , ecx

	call dumpregs
	exit

main ENDP
END main