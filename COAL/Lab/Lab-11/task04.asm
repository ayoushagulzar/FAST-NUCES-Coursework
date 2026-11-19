;Create a Str_Reverse procedure to reverse strings.

INCLUDE Irvine32.inc

Str_Reverse PROTO, pStr:PTR BYTE

.data
myStr   BYTE "Assembly Language",0
msg1    BYTE "Original : ",0
msg2    BYTE "Reversed : ",0

.code
main PROC
    mov  edx, OFFSET msg1
    call WriteString
    mov  edx, OFFSET myStr
    call WriteString
    call Crlf

    INVOKE Str_Reverse, ADDR myStr

    mov  edx, OFFSET msg2
    call WriteString
    mov  edx, OFFSET myStr
    call WriteString
    call Crlf

    call WaitMsg
    exit
main ENDP


Str_Reverse PROC USES eax ebx ecx esi edi, pStr:PTR BYTE
    INVOKE Str_length, pStr          
    cmp  eax, 2
    jb   SR_Done                     ; 0 or 1 char: nothing to do
    mov  ebx, eax                    ; save length

    ; push all character
    mov  esi, pStr
    mov  ecx, ebx
    cld                             
SR_Push:
    lodsb                            ; AL = [ESI], ESI++
    movzx eax, al
    push eax
    loop SR_Push

    ; pop chars back in reverse order
    mov  edi, pStr
    mov  ecx, ebx
SR_Pop:
    pop  eax
    stosb                            ; [EDI] = AL, EDI++
    loop SR_Pop
SR_Done:
    ret
Str_Reverse ENDP

END main