;Implement the following C++ expression in assembly language, using 32-bit signed operands:
;      val1 = (val2/val3) * (val1/val2);

INCLUDE Irvine32.inc

.data
    val1 SDWORD 100
    val2 SDWORD 20
    val3 SDWORD 5

    msg BYTE "Result: ", 0

.code
main PROC

    ; calculating val2 / val3
    mov eax, val2
    cdq                    ;converting dword to qword
    idiv val3

    mov ebx, eax          ; Storing first quotient

    ; calculating val1 / val2
    mov eax, val1
    cdq
    idiv val2

    ; multiplying both quotients
    imul eax, ebx

    ; now store results in val1
    mov val1, eax

    mov edx, OFFSET msg
    call WriteString

    mov eax, val1
    call WriteInt
    call Crlf

    exit
main ENDP
END main