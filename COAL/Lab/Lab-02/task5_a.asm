INCLUDE Irvine32.inc

COMMENT !
Write a program in assembly language that implements following expression:
a) ECX = 001101010010b + 55h - 84o + EBX - ECX + 5
!

.code
main PROC

  ; Using example value for ebx and ecx
    mov ebx, 20h
    mov ecx, 10h

    mov eax, ecx

    add eax, 001101010010b
    add eax, 55h
    sub eax, 64o     ; 84o was invalid because octal numbers can only contain digits 0-7. Therefore, I used 64o instead.
    add eax, ebx
    sub eax, ecx
    add eax, 5
     
    mov ecx, eax

    call DumpRegs

    exit
main ENDP
END main