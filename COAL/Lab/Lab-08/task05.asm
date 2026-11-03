;Write a program for bubble sort on this array.
;arr WORD 10, 4, 7, 14, 299, 156, 3, 19, 29, 300, 20

INCLUDE Irvine32.inc

.data
    arr WORD 10, 4, 7, 14, 299, 156, 3, 19, 29, 300, 20

    msg1 BYTE "Array before sorting: ", 0
    msg2 BYTE "Array after sorting: ", 0

.code
main PROC

    ; original array
    mov edx, OFFSET msg1
    call WriteString

    mov esi, OFFSET arr
    mov ecx, LENGTHOF arr

Display1:
    movzx eax, WORD PTR [esi]
    call WriteDec
    mov al, ' '
    call WriteChar
    add esi, TYPE arr
    loop Display1

    call Crlf

    ; Bubble Sort
    mov ecx, LENGTHOF arr
    dec ecx                 ; Outer loop runs n-1 times

OuterLoop:
    mov esi, OFFSET arr
    mov ebx, ecx            ; Inner loop counter

InnerLoop:
    mov ax, [esi]
    cmp ax, [esi+2]
    jbe NoSwap              ; If current <= next, no swap

    ; Swap adjacent elements
    mov dx, [esi+2]
    mov [esi+2], ax
    mov [esi], dx

NoSwap:
    add esi, TYPE arr
    dec ebx
    jnz InnerLoop   ;if ebx!= 0 ->ebx = inner loop counter

    loop OuterLoop

    ; Displaying sorted array
    mov edx, OFFSET msg2
    call WriteString

    mov esi, OFFSET arr
    mov ecx, LENGTHOF arr

Display2:
    movzx eax, WORD PTR [esi]
    call WriteDec
    mov al, ' '
    call WriteChar
    add esi, TYPE arr
    loop Display2

    call Crlf
    exit

main ENDP
END main