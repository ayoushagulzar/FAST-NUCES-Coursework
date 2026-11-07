;Write ASM instructions that calculate EAX * 21 using binary multiplication.

INCLUDE Irvine32.inc

.data
    num DWORD 10
    msg BYTE "EAX X 21 = ", 0

.code
main PROC

    mov eax, num      
    mov ebx, eax        ; Saving orignal num

    shl eax, 4          ; EAX = num * 16
    shl ebx, 2          ; EBX = num * 4

    add eax, ebx        ; EAX = num * 20
    add eax, num        ; EAX = num * 21

    mov edx, OFFSET msg
    call WriteString

    call WriteDec
    call Crlf

    exit
main ENDP
END main