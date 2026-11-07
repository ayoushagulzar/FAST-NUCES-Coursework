;Create a program to divide a 16-bit integer by 8 using the SHR instruction and display the result.

INCLUDE Irvine32.inc

.data
    num WORD ?
    msg1 BYTE "Enter a 16-bit integer: ", 0
    msg2 BYTE "Result after dividing by 8: ", 0

.code
main PROC

    mov edx, OFFSET msg1
    call WriteString
    call ReadDec
    mov num, ax

    mov ax, num
    shr ax, 3

    mov edx, OFFSET msg2
    call WriteString
    movzx eax, ax
    call WriteDec
    call Crlf

    exit
main ENDP
END main