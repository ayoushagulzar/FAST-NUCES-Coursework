COMMENT!
    Create an array of 10 DWORD elements and use indirect addressing with a loop to calculate the
    sum of all the elements. Store the sum in a register and display it. Use ESI or EDI as the index
    pointer.!

INCLUDE Irvine32.inc

.data 
    arrayD DWORD 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

    msg BYTE "SUM =  " , 0

.code
main PROC
    mov ecx , 10
    mov ebx , 0
    mov esi , OFFSET arrayD

    L1:
        add ebx , [esi]
        add esi , 4
        Loop L1

    mov eax , ebx
    mov edx , OFFSET msg
    call WriteString
    call WriteInt

	exit

main ENDP
END main