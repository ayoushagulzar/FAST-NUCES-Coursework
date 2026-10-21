COMMENT!
	Use the TEST instruction to do each of the following.
	a. Set ZF if the contents of AX is zero.
	b. Clear ZF If BX contains an odd number.
	c. Set SF if DX contains a negative number.
	d. Set ZF if DX contains a zero or positive number.
	e. Set PF if BL contains an even number of 1 bits.!

INCLUDE Irvine32.inc

.code
main PROC
	;set ZF if ax = 0
	mov ax , 0
	test ax , ax
	call DumpRegs

	;clear ZF if BX contains odd number
	test bx , 1h               
	call DumRegs

	;set SF if dx coontains positive number


main ENDP
END main