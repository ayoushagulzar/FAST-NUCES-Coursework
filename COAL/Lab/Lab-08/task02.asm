;Use cmp and jumps to find the first non-zero value in the given array:
;intArr SWORD 0, 0, 0, 150, 120, 35, -12, 66, 4, 0

INCLUDE Irvine32.inc

.data
    intArr SWORD 0, 0, 0, 150, 120, 35, -12, 66, 4, 0
    msg BYTE "First non-zero value: ", 0

.code
main PROC

    mov esi, OFFSET intArr
    mov ecx, LENGTHOF intArr

L1:
    movsx eax, WORD PTR [esi]
    cmp ax, 0
    jne Found

    add esi, TYPE intArr
    loop L1

    jmp Done

Found:
    mov edx, OFFSET msg
    call WriteString

    call WriteInt
    call Crlf

Done:
    exit

main ENDP
END main