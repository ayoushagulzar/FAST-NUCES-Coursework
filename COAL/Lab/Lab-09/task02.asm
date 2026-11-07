;Implement a program that shifts an integer to the left by 3 bits and to the right by 2 bits. Display the
;results after each shift operation.

INCLUDE Irvine32.inc

.data
    num DWORD 8

    msg1 BYTE "Original value: ", 0
    msg2 BYTE "After shifting left by 3 bits: ", 0
    msg3 BYTE "After shifting right by 2 bits: ", 0

.code
main PROC

    mov edx, OFFSET msg1
    call WriteString

    mov eax, num
    call WriteDec
    call Crlf

    ; Shift left by 3 bits
    mov eax, num
    shl eax, 3

    mov edx, OFFSET msg2
    call WriteString
    call WriteDec
    call Crlf

    ; Shift right by 2 bits
    shr eax, 2

    mov edx, OFFSET msg3
    call WriteString
    call WriteDec
    call Crlf

    exit
main ENDP
END main