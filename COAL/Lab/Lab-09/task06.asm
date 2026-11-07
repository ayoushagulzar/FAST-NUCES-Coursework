;Implement a procedure that performs unsigned 32-bit multiplication using only shifting and addition.
;Call the procedure with a multiplier and display the product.

INCLUDE Irvine32.inc

.data
    num1 DWORD 25
    num2 DWORD 4

    msg1 BYTE "Multiplicand: ", 0
    msg2 BYTE "Multiplier: ", 0
    msg3 BYTE "Product: ", 0

.code

; ---- procedure -----
Multiply PROC
    ; EAX = multiplicand
    ; EBX = multiplier
    ; EDX = product

    mov edx, 0
    mov ecx, 32    ; processing all 32-bits

L1:
    test ebx, 1   
    jz SkipAdd     ; if the current multiplier bit is zero, we don't need to add the multiplicand

    add edx, eax

SkipAdd:
    shl eax, 1
    shr ebx, 1

    loop L1

    ret
Multiply ENDP


main PROC

    ; display multiplicand
    mov edx, OFFSET msg1
    call WriteString
    mov eax, num1
    call WriteDec
    call Crlf

    ; display multiplier
    mov edx, OFFSET msg2
    call WriteString
    mov eax, num2
    call WriteDec
    call Crlf

    ; call multiplication procedure
    mov eax, num1
    mov ebx, num2
    call Multiply    ;will return edx

    ; Display product
    mov eax, edx
    push eax

    mov edx, OFFSET msg3
    call WriteString

    pop eax
    call WriteDec
    call Crlf

    exit
main ENDP
END main