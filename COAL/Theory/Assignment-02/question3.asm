COMMENT!	
	Write an assembly code to shift right and left a Dword (2345ABCDh) as WORD level
	2times, considering no bit should be lost.!

INCLUDE Irvine32.inc

.data
	num DWORD 2345ABCDh
	msg1 BYTE "Before Shift: " , 0
	msg2 BYTE "After Shift Left: " , 0
	msg3 BYTE "After Shift Right: " , 0

.code
main PROC
	mov eax , num
	mov edx , OFFSET msg1
	call WriteString
	call WriteHex
	call Crlf

	; Shift left by one word (16 bits) , 4 times 
	ROL eax , 16 
	ROL eax , 16 

	mov edx , OFFSET msg2
	call WriteString
	call WriteHex
	call Crlf

	mov eax , num

	; Shift Right 
	ROR eax , 16  
	ROR eax , 16 

	mov edx , OFFSET msg3
	call WriteString
	call WriteHex
	call Crlf

	exit

main ENDP
END main