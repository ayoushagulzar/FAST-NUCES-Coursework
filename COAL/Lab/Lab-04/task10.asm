COMMENT!	
	Let A = 0FF10h and B = 0E10Bh, you need to write an assembly language code to swap
	the contents.!

INCLUDE Irvine32.inc

.data
	A = 0FF10h 
	B = 0E10Bh

.code
main PROC
	mov eax , A
	mov ebx , B
	XCHG eax , ebx

	call DumpRegs
	exit

main ENDP
END main