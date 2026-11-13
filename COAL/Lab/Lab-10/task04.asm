COMMENT!
	Write a program to take 4 input numbers from the users. Then make two procedures CheckPrime and 
    LargestPrime. The program should first check if a given number is a prime number or not. If all
    of the input numbers are prime numbers then the program should call the procedure LargestPrime.

    CheckPrime: This procedure tests if a number is prime or not.
    LargestPrime: This procedure finds and displays the largest of the four prime numbers.!

INCLUDE Irvine32.inc

.data
    arr DWORD 4 DUP(?)

    inputMsg BYTE "Enter a number: ", 0
    primeMsg BYTE "All numbers are prime.", 0
    notPrimeMsg BYTE "Not all numbers are prime.", 0
    largestMsg BYTE "Largest Prime = ", 0

.code
main PROC
    mov esi, OFFSET arr
    mov ecx, 4

InputLoop:
    mov edx, OFFSET inputMsg
    call WriteString
    call ReadInt

    mov [esi], eax
    add esi, 4

    loop InputLoop

    ; Check all four numbers
    mov esi, OFFSET arr
    mov ecx, 4

CheckLoop:
    push ecx
    push esi

    push DWORD PTR [esi]
    call CheckPrime

    pop esi
    pop ecx

    cmp eax, 0           ;check prime return 0 for not prime
    je NotAllPrime
    add esi, 4
    loop CheckLoop

   ; All numbers are prime
    mov edx, OFFSET primeMsg
    call WriteString
    call Crlf

    push OFFSET arr
    call LargestPrime
    jmp ExitProgram

NotAllPrime:
    mov edx, OFFSET notPrimeMsg
    call WriteString
    call Crlf

ExitProgram:
    exit

	exit
main ENDP

;----------------------------------------
; CheckPrime
; Receives one number through stack
; Returns EAX = 1 if prime, 0 otherwise
;----------------------------------------

CheckPrime PROC

    push ebp
    mov ebp, esp

    push ebx
    push ecx
    push edx

    mov eax, [ebp+8]

    ; numbers less than 2 are not prime
    cmp eax, 2
    jl NotPrime

    ; 2 is prime
    je IsPrime

    ; Even numbers greater than 2 are not prime
    test eax, 1
    jz NotPrime

    mov ebx, 2

PrimeLoop:
    mov eax, [ebp+8]
    xor edx, edx          ;edx stores the remainder
    div ebx

    ; If remainder is zero, not prime
    cmp edx, 0
    je NotPrime

    inc ebx

    ; Check divisors until divisor < number
    mov eax, [ebp+8]
    cmp ebx, eax
    jl PrimeLoop

IsPrime:
    mov eax, 1
    jmp PrimeDone

NotPrime:
    mov eax, 0

PrimeDone:
    pop edx
    pop ecx
    pop ebx

    pop ebp
    ret 4

CheckPrime ENDP

;---------------------------------------
; LargestPrime
; Receives array address through stack
; Finds and displays largest number
;---------------------------------------

LargestPrime PROC

    push ebp
    mov ebp, esp

    push esi
    push ecx
    push ebx

    mov esi, [ebp+8]

    mov ebx, [esi]       ; Assume first is largest

    mov ecx, 3           ; Remaining 3 elements
    add esi, 4

LargestLoop:
    mov eax, [esi]

    cmp eax, ebx
    jle NextNumber

    mov ebx, eax         ; Update largest

NextNumber:
    add esi, 4
    loop LargestLoop

    mov edx, OFFSET largestMsg
    call WriteString

    mov eax, ebx
    call WriteInt
    call Crlf

    pop ebx
    pop ecx
    pop esi
    pop ebp

    ret 4
LargestPrime ENDP

END main