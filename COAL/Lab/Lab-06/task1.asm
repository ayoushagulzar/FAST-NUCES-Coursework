   ; Write an program that initializes an array named Source containing the string "Hello
   ; Assembly!". The task is to copy exactly 15 characters from Source into another array named Target
   ; using only unconditional jumps (JMP) or the LOOP instruction.
   ; The program should:
   ; 1. Use indexed addressing to access characters from Source and store them into Target.
   ; 2. Continue copying until 15 characters are transferred.
   ; 3. Manually append a null terminator (0) at the end of the Target string.
   ; 4. Display both the original string (Source) and the copied string (Target) on the console.


INCLUDE Irvine32.inc

.data
    Source BYTE "Hello Assembly!", 0
    Target BYTE 16 DUP (?)

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

    mov edx, OFFSET Source
    call WriteString
    call Crlf

    mov edx, OFFSET Target
    call WriteString
    call Crlf

    
main ENDP
END main