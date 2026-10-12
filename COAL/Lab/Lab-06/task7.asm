;Write a program using LOOP that counts down from 10 to 1 and displays each value on the screen.

INCLUDE Irvine32.inc

.code
main PROC
    mov ecx , 10

    L1:
        mov eax , ecx
        call WriteDec
        call Crlf
    Loop L1

    exit
main ENDP
END main