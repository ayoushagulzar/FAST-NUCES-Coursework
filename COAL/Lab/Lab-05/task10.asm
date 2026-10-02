COMMENT!
    Declare two arrays: one BYTE array with 5 elements and one WORD array with 3 elements. Write
    a program to find and display the length of both arrays using the LENGTHOF operator.!

INCLUDE Irvine32.inc

.data 
    arrayB BYTE 10h , 20h , 30h , 40h , 50h
    arrayW WORD 20h , 40h , 60

    msg1 BYTE "Length of byte =  " , 0
    msg2 BYTE "Length of word =  " , 0

.code
main PROC
    mov eax , LENGTHOF arrayB
    mov edx , OFFSET msg1
    call WriteString
    call WriteHex
    call crlf

    mov eax , LENGTHOF arrayW
    mov edx , OFFSET msg2
    call WriteString
    call WriteHex

	exit

main ENDP
END main

