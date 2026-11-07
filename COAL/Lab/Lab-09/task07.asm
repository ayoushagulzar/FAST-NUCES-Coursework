;Write a program that adds two 16-bit integers and displays the result.

INCLUDE Irvine32.inc

.data
    num1 WORD 120
    num2 WORD 250
    msg BYTE "Sum: ", 0

.code
main PROC

    mov ax, num1
    add ax, num2

    mov edx, OFFSET msg
    call WriteString

    movzx eax, ax
    call WriteDec
    call Crlf

    exit
main ENDP
END main