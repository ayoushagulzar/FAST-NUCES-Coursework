;Create a program to subtract two 32-bit integers, considering signed values.

INCLUDE Irvine32.inc

.data
    num1 SDWORD 100
    num2 SDWORD 150
    msg BYTE "Difference: ", 0

.code
main PROC
    mov eax, num1
    sub eax, num2

    mov edx, OFFSET msg
    call WriteString

    call WriteInt
    call Crlf

    exit
main ENDP
END main