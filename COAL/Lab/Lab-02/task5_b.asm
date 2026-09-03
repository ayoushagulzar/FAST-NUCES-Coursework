INCLUDE Irvine32.inc

COMMENT !
Write a program in assembly language that implements following expression:
b) EDX = EAX + 3 + EBX - ECX + 0Ah - 65o + 44d
!

.code
main PROC

    mov eax, 10h
    mov ebx, 20h
    mov ecx, 05h

    add eax, 3
    add eax, ebx
    sub eax, ecx
    add eax, 0Ah
    sub eax, 65o
    add eax, 44d

    mov edx, eax

    call DumpRegs

    exit
main ENDP
END main