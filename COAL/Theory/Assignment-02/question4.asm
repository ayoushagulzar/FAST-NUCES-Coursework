COMMENT!
	The time stamp field of a file directory entry uses bits 0 through 4 for the seconds, bits
	5 through 10 for the minutes, and bits 11 through 15 for the hours.
	(a) Write instructions that extract the seconds and copy the value to a byte variable named BSeconds.
	(b) Write instructions that extract the minutes and copy the value to a byte variable named BMinutes.
	Consider 16 bits: DX = 0101100111011010 .!

INCLUDE Irvine32.inc

.data
	BSeconds BYTE ?
	BMinutes BYTE ?
	BHours   BYTE ?

	msgSeconds BYTE "Seconds : " , 0
	msgMinutes BYTE "Minutes : " , 0

.code
main PROC
	mov dx , 0101100111011010b
	mov ax , dx
	AND al , 00011111b
	mov BSeconds , al

	mov bx , dx               ;preserving orignal value of dx
	movzx eax , BSeconds
	mov edx , OFFSET msgSeconds
	call WriteString
	call WriteDec
	call Crlf
	
	mov dx , bx
	mov ax , 0
	mov ax , dx
	SHR ax , 5               ; ax = 00000010 11001110 , al = 11001110 
	AND al , 00111111b       ; al = 00001110 
	mov BMinutes , al

	movzx eax , BMinutes
	mov edx , OFFSET msgMinutes
	call WriteString
	call WriteDec
	call Crlf

	exit

main ENDP
END main