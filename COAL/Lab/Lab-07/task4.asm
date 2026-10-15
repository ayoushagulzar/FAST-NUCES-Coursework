; Print the following pattern using a function call in which number of columns is pass through a variable.

INCLUDE Irvine32.inc

.data
	col DWORD 5
.code
main PROC 
	call printStar
	exit

main ENDP

printStar PROC
	mov ecx , col
	L1:
		push ecx
		mov eax , col
		sub eax , ecx
		inc eax
		mov ecx, eax

		L2:
			mov al, '*'
			call WriteChar

			mov al, ' '
			call WriteChar
		loop L2

		call Crlf
		pop ecx
	Loop L1

	ret
	printStar ENDP

END main