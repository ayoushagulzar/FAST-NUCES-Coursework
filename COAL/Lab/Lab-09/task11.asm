COMMENT!
	The time stamp field of a file directory entry uses bits 0 through 4 for the seconds, bits 5 through
	10 for the minutes, and bits 11 through 15 for the hours. Write instructions that extract the minutes and copy
	the value to a byte variable named bMinutes.!

INCLUDE Irvine32.inc

.data
    timeStamp WORD  5A40h
    bMinutes  BYTE  ?

    msg1 BYTE "Original timestamp: ", 0
    msg2 BYTE "Extracted minutes: ", 0

.code
main PROC
    mov edx, OFFSET msg1
    call WriteString

    movzx eax, timeStamp
    call WriteHex
    call Crlf

    ;extracting minutes
    mov ax, timeStamp
    shr ax, 5         
    and al, 00111111b
    mov bMinutes, al

    mov edx, OFFSET msg2
    call WriteString

    movzx eax, bMinutes
    call WriteDec
    call Crlf

    exit
main ENDP
END main