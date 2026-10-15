

INCLUDE Irvine32.inc

.data
    welcomeMsg BYTE "Welcome to IEEE Xtreme Challenge!", 0

    prompt1 BYTE "Enter lines of code completed by Ghulam Qadir: ", 0
    prompt2 BYTE "Enter lines of code completed by Abdullah Shaikh: ", 0
    prompt3 BYTE "Enter lines of code completed by Waseem Rauf: ", 0

    championMsg BYTE "IEEE Xtreme Code Champion: ", 0

    name1 BYTE "Ghulam Qadir", 0
    name2 BYTE "Abdullah Shaikh", 0
    name3 BYTE "Waseem Rauf", 0

    lines1 DWORD ?
    lines2 DWORD ?
    lines3 DWORD ?

.code
main PROC
	mov edx, OFFSET welcomeMsg
    call WriteString
    call Crlf

    ; Input for Ghulam Qadir
    mov edx, OFFSET prompt1
    call WriteString
    call ReadInt
    mov lines1, eax

    ; Input for Abdullah Shaikh
    mov edx, OFFSET prompt2
    call WriteString
    call ReadInt
    mov lines2, eax

    ; Input for Waseem Rauf
    mov edx, OFFSET prompt3
    call WriteString
    call ReadInt
    mov lines3, eax

    call compareScores
    call displayChampion
    exit

main ENDP

compareScores PROC
    mov eax, lines1             ; assuming lines1 = highest

    cmp eax, lines2        
    jge checkLines3             ; if lines 1 > lines2 , go to checkLines3 (skip eax = lines3)
    mov eax, lines2             ; else eax = lines2

checkLines3:
    cmp eax, lines3             ; compare the value of eax (l1 or l2) with l3
    jge exitfunc                ; if l1/l2 > l3 .. exit
    mov eax, lines3             ; else eax = l3

exitfunc:
    ret
compareScores ENDP


displayChampion PROC

    mov edx, OFFSET championMsg
    call WriteString

    cmp eax, lines1
    je showGhulam

    cmp eax, lines2
    je showAbdullah

    mov edx, OFFSET name3
    jmp showName

showGhulam:
    mov edx, OFFSET name1
    jmp showName

showAbdullah:
    mov edx, OFFSET name2
    jmp showName

showName:
    call WriteString
    call Crlf
    ret
displayChampion ENDP

END main