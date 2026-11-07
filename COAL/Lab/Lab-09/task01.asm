;Create a program that takes a byte value, rotates it left by one bit, and displays the result. Show the
;original and rotated values.

INCLUDE Irvine32.inc

.data
    num BYTE 10
    msg1 BYTE "Original value: ", 0
    msg2 BYTE "After rotating left: ", 0

.code
main PROC
    mov edx, OFFSET msg1
    call WriteString

    movzx eax, num
    call WriteDec
    call Crlf

    ; rotate left -> 1 bit
    mov al, num
    rol al, 1

    mov edx, OFFSET msg2
    call WriteString

    movzx eax, al
    call WriteDec
    call Crlf

    exit
main ENDP
END main