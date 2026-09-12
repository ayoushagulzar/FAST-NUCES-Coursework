COMMENT!
	Load a signed byte value -10 into a register and extend it to word size using MOVSX. Do
	the same with MOVZX.!

INCLUDE Irvine32.inc

.data
	signedNum byte -10

.code
main PROC
	mov al , signedNum

    movsx ax, al       ; AX = FFF6h (-10)
    movzx bx, al       ; BX = 00F6h (246) -> wrong approach for signed numbers

	call DumpRegs
	exit

main ENDP
END main

