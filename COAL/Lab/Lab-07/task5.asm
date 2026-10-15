; Write a function that asks the user for a number n and prints the sum of the numbers 1 to n


INCLUDE Irvine32.inc

.data
    msg BYTE "Enter n to calculate the sum from 1 to n: ", 0
    resultMsg BYTE "Sum = ", 0

.code
main PROC
    mov edx, OFFSET msg
    call WriteString
    call ReadInt

    call calculateSum

    mov edx, OFFSET resultMsg
    call WriteString
    call WriteDec
    call Crlf

    exit
main ENDP

calculateSum PROC
    mov ecx, eax        ; ecx = n
    mov eax, 0          ; sum = 0
    mov ebx, 1          ; i = 1

L1:
    add eax, ebx        ; sum += i
    inc ebx             ; i++
    loop L1

    ret
calculateSum ENDP

END main
