COMMENT!
	Initialize a value 20. Increment it 3 times, and then decrement it 2 times.!

INCLUDE Irvine32.inc

.data
	num dword 20

.code
main PROC
	mov eax , num

	;INCREMENTATION
	INC eax
	INC eax
	INC eax

	;DECREMENTATION

	DEC eax
	DEC eax

	call DumpRegs
	exit

main ENDP
END main

