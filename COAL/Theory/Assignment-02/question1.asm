;Multiply Ax by 26 using shift and addition instruction. Ax = 3

INCLUDE Irvine32.inc

.data
	msg BYTE " 3 * 26 = " , 0
.code
main PROC
	mov ax , 3
	mov bx , ax    ; preserving original value of ax

	shl ax , 4     ; 3 * 2^4 = 48            
	mov cx , 0
	add cx , ax    ; cx = 48
	
	mov ax , bx
	shl ax , 3     ; 3 * 2^3 = 24
	add cx , ax    ; cx = 48 + 24 = 72

	mov ax , bx
	shl ax , 1     ; 3 * 2^1 = 6
	add cx , ax    ; cx = 72 + 6 = 78

	movzx eax , cx
	mov edx , OFFSET msg
	call WriteString
	call WriteDec

	exit

main ENDP
END main