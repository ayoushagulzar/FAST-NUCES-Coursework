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
    mov ecx, 32

L1:
    test ebx, 1   
    jz SkipAdd     ;cuz multiplier can not be zero.

    add edx, eax

SkipAdd:
    shl eax, 1
    shr ebx, 1

    loop L1

    ret
Multiply ENDP


main PROC

    ; Display multiplicand
    mov edx, OFFSET msg1
    call WriteString
    mov eax, num1
    call WriteDec
    call Crlf

    ; Display multiplier
    mov edx, OFFSET msg2
    call WriteString
    mov eax, num2
    call WriteDec
    call Crlf

    ; Call multiplication procedure
    mov eax, num1
    mov ebx, num2
    call Multiply

    ; Display product
    mov edx, OFFSET msg3
    call WriteString
    mov eax, edx
    call WriteDec
    call Crlf

    exit
main ENDP
END main