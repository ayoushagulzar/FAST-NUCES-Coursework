;Write a program that rotates an 8-bit value in a register by a varying number of bits, controlled by
;user input. Display the original and rotated values after each rotation.

INCLUDE Irvine32.inc

.data
    num BYTE ?
    noOfBits BYTE ?

    inputValue BYTE "Enter an 8-bit value (0-255): ", 0
    inputBits BYTE "Enter number of bits to rotate: ", 0
    msg1 BYTE "Original value: ", 0
    msg2 BYTE "Rotated value: ", 0

.code
main PROC

    mov edx, OFFSET inputValue
    call WriteString
    call ReadDec
    mov num, al

    mov edx, OFFSET inputBits
    call WriteString
    call ReadDec
    mov noOfBits, al

    mov edx, OFFSET msg1
    call WriteString
    movzx eax, num
    call WriteDec
    call Crlf

    mov al, num
    mov cl, noOfBits
    rol al, cl

    mov edx, OFFSET msg2
    call WriteString
    movzx eax, al
    call WriteDec
    call Crlf

    exit
main ENDP
END main