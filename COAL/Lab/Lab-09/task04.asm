;Write a program that multiplies a given number by 4 using left shifts and displays the result.

INCLUDE Irvine32.inc

.data
    num DWORD ?
    msg1 BYTE "Enter a number: ", 0
    msg2 BYTE "Result after multiplying by 4: ", 0

.code
main PROC

    mov edx, OFFSET msg1
    call WriteString
    call ReadDec
    mov num, eax

    mov eax, num
    shl eax, 2

    mov edx, OFFSET msg2
    call WriteString
    call WriteDec
    call Crlf

    exit
main ENDP
END main