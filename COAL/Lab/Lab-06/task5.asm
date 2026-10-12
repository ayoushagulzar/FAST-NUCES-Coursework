COMMENT!
	Write a program that uses nested loops with only the LOOP and JMP instructions to
	display the star pattern: !

INCLUDE Irvine32.inc

.code
main PROC 

	mov ecx , 4

	L1:
		push ecx
		mov eax , 4
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

	exit

main ENDP
END main