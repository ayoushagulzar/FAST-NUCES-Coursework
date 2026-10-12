;Initialize an array of integers and use a loop with indexed addressing to print each element.


INCLUDE Irvine32.inc

.data
    arrInt DWORD 10, 20, 30, 40, 50

.code
main PROC
    mov esi, 0
    mov ecx, LENGTHOF arrInt

L1:
    mov eax, arrInt[esi]
    call WriteInt
    call Crlf

    add esi , TYPE arrInt
    loop L1

    exit
main ENDP
END main
