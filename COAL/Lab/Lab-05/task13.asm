COMMENT!
    Declare an array of 4 DWORD elements: 100, 200, 300, 400. Use the TYPE operator and scale
    factors to calculate the sum of the first and third elements and the second and fourth elements.
    Store the results in separate registers and display them.!

INCLUDE Irvine32.inc

.data 
    array DWORD 100, 200, 300, 400
    
     msg1 BYTE "SUM of  1st and 3rd element:  " , 0
     msg2 BYTE "SUM of  2nd and 4th element:  " , 0

.code
main PROC
    mov esi , 0
    mov eax , array[esi * TYPE array]
    add esi , 2
    mov ebx , array[esi * TYPE array]
    add eax , ebx

    mov edx , OFFSET msg1
    call WriteString
    call WriteInt
    call crlf

    mov esi , 1
    mov eax , array[esi * TYPE array]
    add esi , 2
    mov ebx , array[esi * TYPE array]
    add eax , ebx

    mov edx , OFFSET msg2
    call WriteString
    call WriteInt

    exit

main ENDP
END main