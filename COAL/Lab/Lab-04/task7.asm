COMMENT!
	Define a constant PI = 3. Use it in a program to calculate PI * 4.!

INCLUDE Irvine32.inc

.data
	PI dword 3

.code
main PROC
	mov eax, PI
    mov ebx, 4
    mul ebx

	call DumpRegs
	exit

main ENDP
END main

