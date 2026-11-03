COMMENT!
    Write a program for sequential search. Take an input from the user and find if it occurs in
    the following array:
    arr WORD 10, 4, 7, 14, 299, 156, 3, 19, 29, 300, 20!

INCLUDE Irvine32.inc

.data
    arr WORD 10, 4, 7, 14, 299, 156, 3, 19, 29, 300, 20

    msg1 BYTE "Enter a number to search: ", 0
    foundMsg BYTE "Number found!", 0
    notFoundMsg BYTE "Number not found!", 0

.code
main PROC

    mov edx, OFFSET msg1
    call WriteString
    call ReadInt

    mov bx, ax                  ; Storing value in bx

    mov esi, OFFSET arr
    mov ecx, LENGTHOF arr

L1:
    cmp bx, [esi]               
    je Found

    add esi, TYPE arr          
    loop L1

    ; if element not found
    mov edx, OFFSET notFoundMsg
    call WriteString
    jmp Done

Found:
    mov edx, OFFSET foundMsg
    call WriteString

Done:
    call Crlf
    exit

main ENDP
END main