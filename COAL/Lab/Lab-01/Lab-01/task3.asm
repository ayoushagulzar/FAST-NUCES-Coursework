TITLE My First Program
INCLUDE Irvine32.inc


.code

main PROC

    mov eax , 10h
    mov ebx , 25h
    add eax , ebx

    mov ebx , 12h
    add eax , ebx

    call dumpRegs
    exit

main ENDP
END main