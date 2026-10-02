COMMENT!
    Create a byte array with 5 elements (10h, 20h, 30h, 40h, 50h). Access and display the first and
    third elements using direct-offset addressing. Use WriteInt to display the values.!

INCLUDE Irvine32.inc

.data 
    arrayB BYTE 10h , 20h , 30h , 40h , 50h


    msg1 BYTE "1st Element: " , 0
    msg2 BYTE "3rd Element: " , 0

.code
main PROC

    movzx eax , [arrayB]
    mov edx , OFFSET msg1
    call WriteString
    call WriteInt
    call Crlf

    movzx eax , [arrayB+2]
    mov edx , OFFSET msg2
    call WriteString
    call WriteInt

	exit

main ENDP
END main

; NOTE: WriteInt only displays the value of eax.

