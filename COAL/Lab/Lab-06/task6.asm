;Write a program that prints two different messages but skips the second message using JMP.


INCLUDE Irvine32.inc

.data
    msg1 BYTE "COAL LAB 06.", 0
    msg2 BYTE "This is Task-06.", 0

.code
main PROC
    mov edx, OFFSET msg1
    call WriteString
    call Crlf

    jmp SkipMsg2

    mov edx, OFFSET msg2
    call WriteString
    call Crlf

SkipMsg2:
    exit
main ENDP
END main
