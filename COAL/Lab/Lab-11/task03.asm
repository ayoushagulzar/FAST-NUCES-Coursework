;Create IsCompare procedure to compare two strings.

INCLUDE Irvine32.inc

IsCompare PROTO, string1:PTR BYTE, string2:PTR BYTE

.data
str1        BYTE "HELLO",0
str2        BYTE "HELLO",0

msgEqual    BYTE "Strings are EQUAL",0
msgGreater  BYTE "First string is GREATER",0
msgLess     BYTE "First string is LESS",0

.code
main PROC
    INVOKE IsCompare, ADDR str1, ADDR str2   ; EAX = 0 / 1 / -1

    cmp  eax, 0
    je   Equal
    jg   Greater
    mov  edx, OFFSET msgLess
    jmp  Print
Equal:
    mov  edx, OFFSET msgEqual
    jmp  Print
Greater:
    mov  edx, OFFSET msgGreater
Print:
    call WriteString
    call Crlf

    call WaitMsg
    exit
main ENDP

IsCompare PROC USES ecx esi edi, string1:PTR BYTE, string2:PTR BYTE
    INVOKE Str_length, string1       
    mov  ecx, eax
    inc  ecx                         ; include the null byte

    mov  esi, string1                
    mov  edi, string2                
    cld                              
    repe cmpsb                       ; compare while equal
    je   IC_Equal                    ; all bytes matched

    ja   IC_Greater                
    mov  eax, -1
    ret
IC_Greater:
    mov  eax, 1
    ret
IC_Equal:
    mov  eax, 0
    ret
IsCompare ENDP

END main



