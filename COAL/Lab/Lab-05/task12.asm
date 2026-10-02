COMMENT!
    Declare an array of 6 BYTE elements: 15, 3, 22, 7, 9, 12. Sort the array in ascending order using
    indirect addressing (use ESI and EDI registers). Display the sorted array.!

INCLUDE Irvine32.inc

.data 
    array BYTE 15, 3, 22, 7, 9, 12
    
    msg BYTE "Sorted Array: ", 0

.code
main PROC

    mov ecx, 5 ; we need 5 passes to sort an array of length 6

    ; OUTER LOOP
    L1:
        mov esi, OFFSET array ; we reset esi to begining of each pass
        mov edi, 5 ; it keep track of how many elements we still need to compare in this pass

        ; INNER LOOP
        L2:
            mov al, [esi]
            mov bl, [esi+1]

            cmp al, bl
            jle noSwap

            ;if al > bl , swap them
            mov [esi], bl
            mov [esi+1], al

        noSwap:
            inc esi
            dec edi     ;decreasing no: of comparisons
            jnz L2      ; if edi != 0 , go back to L2

        loop L1  ; end of outer loop


        mov edx, OFFSET msg
        call WriteString

        mov esi, OFFSET array
        mov ecx, 6

    ; loop for printing sorted array
    L3:
        movzx eax, BYTE PTR [esi]
        call WriteDec

        mov al, ' '
        call WriteChar

        inc esi
        loop L3

    exit

main ENDP
END main