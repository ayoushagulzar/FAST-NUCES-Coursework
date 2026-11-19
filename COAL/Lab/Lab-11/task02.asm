;Modify the procedure (in task1) to take offset of string1 and the character to be searched as argument.

INCLUDE Irvine32.inc

Scan_String PROTO, pString:PTR BYTE, char:BYTE

.data
Str1    BYTE '127&j~3#^&*#*#45^',0
msg     BYTE "Index of first '#' : ",0
msgNF   BYTE "Not found",0

.code
main PROC
    mov  edx, OFFSET msg
    call WriteString

    INVOKE Scan_String, ADDR Str1, '#'   ; EAX = index or -1
    cmp  eax, -1
    je   NotFound
    call WriteDec
    jmp  Done
NotFound:
    mov  edx, OFFSET msgNF
    call WriteString
Done:
    call Crlf
    call WaitMsg
    exit
main ENDP

Scan_String PROC USES ecx edi, pString:PTR BYTE, char:BYTE
    INVOKE Str_length, pString       ; EAX = length
    mov  ecx, eax
    jecxz SS_NotFound

    mov  edi, pString
    mov  al, char
    cld
    repne scasb
    jnz  SS_NotFound

    dec  edi
    sub  edi, pString
    mov  eax, edi
    ret
SS_NotFound:
    mov  eax, -1
    ret
Scan_String ENDP

END main