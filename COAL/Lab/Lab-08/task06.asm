;Write a program to check whether a character is alphabet or not.

INCLUDE Irvine32.inc

.data
    msg1 BYTE "Enter a character: ", 0
    alphabetMsg BYTE "It is an alphabet.", 0
    notAlphabetMsg BYTE "It is not an alphabet.", 0

.code
main PROC

    mov edx, OFFSET msg1
    call WriteString

    call ReadChar

    ; Check uppercase (A-Z)
    cmp al, 'A'
    jb NotAlphabet

    cmp al, 'Z'
    jbe Alphabet

    ; Check lowercase (a-z)
    cmp al, 'a'
    jb NotAlphabet

    cmp al, 'z'
    jbe Alphabet

NotAlphabet:
    mov edx, OFFSET notAlphabetMsg
    call WriteString
    jmp Done

Alphabet:
    mov edx, OFFSET alphabetMsg
    call WriteString

Done:
    call Crlf
    exit

main ENDP
END main