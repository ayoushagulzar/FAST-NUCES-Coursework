INCLUDE Irvine32.inc

COMMENT !
Write an Assembly program to calculate the total memory allocated (in bytes).
01) An integer array of size 5 (DWORD each → 4 bytes)
02) A character string of 10 chars (BYTE each → 1 byte)
03) A double variable (QWORD → 8 bytes) !

.data
array DWORD 1, 2, 3, 4, 5
char_string BYTE "Ayousha123"
doubleVar QWORD 789456


.code
main PROC

    mov eax , SIZEOF array                 ; 20 bytes -> 14h
    mov ebx , SIZEOF char_string           ; 10 bytes -> 0Ah
    mov ecx , SIZEOF doubleVar             ; 8 bytes  -> 08h

    call DumpRegs

    exit
main ENDP
END main




