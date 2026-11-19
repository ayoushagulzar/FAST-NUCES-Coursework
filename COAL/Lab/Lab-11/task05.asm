;Write the procedure to get_frequency Find the frequency of characters:

INCLUDE Irvine32.inc

Get_frequencies PROTO, pString:PTR BYTE, pTable:PTR DWORD

.data
target    BYTE  "AAEBDCFBBC",0
freqTable DWORD 256 DUP(0)

.code
main PROC
    INVOKE Get_frequencies, ADDR target, ADDR freqTable

    ; ---- Display characters that appear at least once ----
    mov  esi, OFFSET freqTable
    mov  ecx, 256
    mov  ebx, 0                 ; ebx = ASCII code (table index)
L2:
    mov  eax, [esi + ebx*4]     ; frequency of this character
    cmp  eax, 0
    je   skip
    push eax
    mov  al, bl
    call WriteChar              
    mov  al, ' '
    call WriteChar
    mov  al, '='
    call WriteChar
    mov  al, ' '
    call WriteChar
    pop  eax
    call WriteDec               ; print count of char
    call Crlf
skip:
    inc  ebx
    loop L2

    exit
main ENDP

Get_frequencies PROC USES eax esi edi, pString:PTR BYTE, pTable:PTR DWORD

    mov  esi, pString           ; ESI -> source string
    mov  edi, pTable            ; EDI -> frequency table
    cld                         

L1:
    mov  eax, 0                 ; clear upper bits of EAX
    lodsb                       ; AL = [ESI], ESI++
    cmp  al, 0                
    je   done
    inc  DWORD PTR [edi + eax*4]   ; freqTable[AL]++
    jmp  L1

done:
    ret
Get_frequencies ENDP

END main