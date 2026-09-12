COMMENT!
	Store the day and night temperatures (32 and 17). Calculate the difference and increment
	night temperature by 2.!

INCLUDE Irvine32.inc

.data
	dayTemp dword 32
	nightTemp dword 17

.code
main PROC
	mov eax , dayTemp
	sub eax , nightTemp
	INC nightTemp
	INC nightTemp
	mov ebx , nightTemp

	call DumpRegs
	exit

main ENDP
END main