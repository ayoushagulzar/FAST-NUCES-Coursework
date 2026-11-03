;Given arr SDWORD 5, -3, 0, 12, -8, 0, 7, -1, 9, 0, count how many elements are positive,
;negative and zero, and display the three counts.

INCLUDE Irvine32.inc

.data
    arr SDWORD 5, -3, 0, 12, -8, 0, 7, -1, 9, 0

    positiveCount DWORD 0
    negativeCount DWORD 0
    zeroCount DWORD 0

    msg1 BYTE "Positive elements: ", 0
    msg2 BYTE "Negative elements: ", 0
    msg3 BYTE "Zero elements: ", 0

.code
main PROC

    mov esi, OFFSET arr
    mov ecx, LENGTHOF arr

L1:
    mov eax, [esi]

    cmp eax, 0
    jg Positive

    jl Negative

    ; if neither positive nor negative, its zero
    inc zeroCount
    jmp NextElement

Positive:
    inc positiveCount
    jmp NextElement

Negative:
    inc negativeCount

NextElement:
    add esi, TYPE arr
    loop L1

    ; positive count msg
    mov edx, OFFSET msg1
    call WriteString
    mov eax, positiveCount
    call WriteDec
    call Crlf

    ; negative count msg
    mov edx, OFFSET msg2
    call WriteString
    mov eax, negativeCount
    call WriteDec
    call Crlf

    ; zero countmsg
    mov edx, OFFSET msg3
    call WriteString
    mov eax, zeroCount
    call WriteDec
    call Crlf

    exit

main ENDP
END main