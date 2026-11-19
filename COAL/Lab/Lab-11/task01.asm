;Create a procedure named Scan_String to find the index of the first occurrence of the character ‘#’
;in the given string.

INCLUDE Irvine32.inc

.data
Str1    BYTE "127&j~3#^&*#*#45^",0
msg     BYTE "Index of first '#' : ",0
msgNF   BYTE "Not found",0

.code
main PROC
    mov  edx, OFFSET msg
    call WriteString

    call Scan_String                 ; EAX = index or -1
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

Scan_String PROC USES ecx edi
    INVOKE Str_length, ADDR Str1     
    mov ecx, eax                    
    jecxz SS_NotFound

    mov  edi, OFFSET Str1
    mov  al, '#'                     
    cld                              ; scan forward
    repne scasb                      ; repeat while [EDI] != AL
    jnz  SS_NotFound                 

    dec  edi                         ; EDI points 1 past the match
    sub  edi, OFFSET Str1            ; index = address - start
    mov  eax, edi
    ret

SS_NotFound:
    mov  eax, -1
    ret
Scan_String ENDP

END main