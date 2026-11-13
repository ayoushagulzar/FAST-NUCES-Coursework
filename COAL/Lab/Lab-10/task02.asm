;Write a program which contains a procedure named MinMaxArray that displays the minimum &
;maximum values in an array. Pass a size-20 array by reference to this procedure.

INCLUDE Irvine32.inc

.data
    arr DWORD 12, 45, 7, 89, 23, 56, 3, 91, 34, 18, 67, 5, 42, 100, 29, 11, 76, 8, 54, 31
    minMsg BYTE "Minimum Value: " , 0
    maxMsg BYTE "Maximum Value: " , 0

.code
main PROC
    push offset arr
    call MinMaxArray
	exit
main ENDP

MinMaxArray PROC
    push ebp
    mov ebp , esp

    push esi
    push ecx
    push eax
    push ebx

    mov esi, [ebp+8]               ; Address of array

    mov eax, [esi]                 ; Assume first element is minimum
    mov ebx, [esi]                 ; Assume first element is maximum

    mov ecx, LENGTHOF arr - 2      ; -2 cuz , we are need loop for n-1 elements (loop over 19 elements)
    add esi, 4                     ; move to second element

L1:
    cmp [esi], eax
    jge CheckMax
    mov eax, [esi]        ; Update minimum

  CheckMax:
    cmp [esi], ebx
    jle NextElement
    mov ebx, [esi]        ; Update maximum

  NextElement:
    add esi, 4            ; next DWORD
    loop L1

    mov edx, OFFSET minMsg
    call WriteString
    call WriteInt
    call Crlf

    mov edx, OFFSET maxMsg
    call WriteString
    mov eax, ebx
    call WriteInt
    call Crlf

    pop ebx
    pop eax 
    pop ecx 
    pop esi

    pop ebp
    ret 4                  
MinMaxArray ENDP
END main