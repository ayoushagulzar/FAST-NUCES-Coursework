COMMENT!
    Initialize an array of 5 WORD values: 100h, 200h, 300h, 400h, 500h. Use indexed addressing to
    calculate the sum of the second and fourth elements and store the result in a register. Display the
    sum using WriteInt.!

INCLUDE Irvine32.inc

.data 
    arrayW WORD 100h, 200h, 300h, 400h, 500h

    msg1 BYTE "Sum =  " , 0

.code
main PROC
    mov esi , 2
    mov ax , arrayW[esi]
    mov bx , arrayW[esi+4]

    add ax , bx
    movzx eax , ax

    mov edx , OFFSET msg1
    call WriteString
    call WriteInt

	exit

main ENDP
END main
