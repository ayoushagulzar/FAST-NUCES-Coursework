; Initialize an array named Source and use a loop with indexed addressing to copy a string
; represented as an array of bytes with a null terminator value in an array named as target.

INCLUDE Irvine32.inc

.data
    Source BYTE "Ayousha Gulzar", 0
    Target BYTE 16 DUP (?)
    msg1 BYTE "Source: " , 0
    msg2 BYTE "Target: " , 0

.code
main PROC
    mov esi, OFFSET Source
    mov edi, OFFSET Target
    mov ecx, 15

L1:
    mov al, [esi]
    mov [edi], al
    inc esi
    inc edi
    loop L1

    mov BYTE PTR [edi], 0

    mov edx, OFFSET msg1
    call WriteString
    mov edx, OFFSET Source
    call WriteString
    call Crlf

    mov edx, OFFSET msg2
    call WriteString
    mov edx, OFFSET Target
    call WriteString
    call Crlf

    exit
main ENDP
END main