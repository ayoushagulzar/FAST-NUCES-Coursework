;Write a program that takes four input integers from the user. Then compare and display
;a message whether these integers are equal or not.

INCLUDE Irvine32.inc

.data
    msg1 BYTE "Enter four integers: ", 0
    equalMsg BYTE "All four integers are equal.", 0
    notEqualMsg BYTE "The integers are not equal.", 0

    num1 SDWORD ?
    num2 SDWORD ?
    num3 SDWORD ?
    num4 SDWORD ?

.code
main PROC

    mov edx, OFFSET msg1
    call WriteString

    call ReadInt
    mov num1, eax

    call ReadInt
    mov num2, eax

    call ReadInt
    mov num3, eax

    call ReadInt
    mov num4, eax

    ; Compare the integers
    mov eax, num1
    cmp eax, num2
    jne NotEqual

    cmp eax, num3
    jne NotEqual

    cmp eax, num4
    jne NotEqual

    ; All integers are equal
    mov edx, OFFSET equalMsg
    call WriteString
    jmp ExitProgram

NotEqual:
    mov edx, OFFSET notEqualMsg
    call WriteString

ExitProgram:
    call Crlf
    exit

main ENDP
END main