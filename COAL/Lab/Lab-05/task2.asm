COMMENT!
	Initialize a register with a value of 5. Subtract the same value from it using the SUB instruction
	and observe the Zero flag. Write a program that demonstrates the Zero flag being set and reset.!

INCLUDE Irvine32.inc

.code
main PROC
	mov eax, 5
	sub eax, 5        ; sets zero flag
	call DumpRegs

	mov eax, 5
	sub eax, 3        ; resets zero flag
	call DumpRegs

	exit

main ENDP
END main
