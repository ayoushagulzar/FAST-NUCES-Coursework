COMMENT!
    Declare a DWORD variable and initialize it with 0x12345678. Use the PTR operator to extract the
    lower byte and the lower word, and move them into separate registers. Display both the extracted
    byte and word using WriteHex.!

INCLUDE Irvine32.inc

.data 
    var DWORD 012345678h


    msg1 BYTE "Lower Byte: " , 0
    msg2 BYTE "Lower Word: " , 0

.code
main PROC

    mov al , BYTE PTR var
    movzx eax , al
    mov edx , OFFSET msg1
    call WriteString
    call WriteHex
    call Crlf

    mov bx , WORD PTR var
    movzx eax , bx
    mov edx , OFFSET msg2
    call WriteString
    call WriteHex

	exit

main ENDP
END main



