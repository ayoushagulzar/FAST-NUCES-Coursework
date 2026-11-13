;Write a program which contains a procedure named BubbleSort that sorts an array, which is passed
;through a stack using indirect addressing.

INCLUDE Irvine32.inc

.data
    arr DWORD 45, 12, 89, 7, 34, 23, 56, 3
    sortedMsg BYTE "Sorted Array: ", 0

.code
main PROC

    push LENGTHOF arr
    push OFFSET arr
    call BubbleSort

    ; Display sorted array
    mov edx, OFFSET sortedMsg
    call WriteString

    mov esi, OFFSET arr
    mov ecx, LENGTHOF arr

DisplayLoop:
    mov eax, [esi]
    call WriteDec
    
    mov al , ' '
    call WriteChar

    add esi, 4
    loop DisplayLoop
    call Crlf
    exit
main ENDP


BubbleSort PROC

    push ebp
    mov ebp, esp

    push esi
    push ebx
    push ecx
    push eax
    push edx

    mov esi, [ebp+8]       ; array address
    mov ebx, [ebp+12]      ; array size

    dec ebx                ; cuz for bubble sort outer loop = n-1 passes

OuterLoop:
    mov esi, [ebp+8]       ; Start from first element
    mov ecx, ebx           ; Inner loop count

InnerLoop:
    mov eax, [esi]
    cmp eax, [esi+4]
    jle NoSwap             ; if left <= right, no swap

    ; Swap adjacent elements
    mov edx, [esi+4]
    mov [esi], edx
    mov [esi+4], eax

NoSwap:
    add esi, 4             ; move to next element
    loop InnerLoop

    dec ebx
    jnz OuterLoop

    pop edx
    pop eax
    pop ecx
    pop ebx
    pop esi

    pop ebp
    ret 8                  

BubbleSort ENDP

END main