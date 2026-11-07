; Implement a procedure named Extended Add to add two 64-bit integers.

INCLUDE Irvine32.inc

.data
    ; first 64-bit number
    num1Low  DWORD 100
    num1High DWORD 1

    ;second 64-bit number
    num2Low  DWORD 200
    num2High DWORD 2

    ; result
    resultLow  DWORD ?
    resultHigh DWORD ?

    msg BYTE "64-bit: ", 0

.code

ExtendedAdd PROC

    ; EAX = lower half of first number
    ; EBX = upper half of first number
    ; ECX = lower half of second number
    ; EDX = upper half of second number

    add eax, ecx       
    adc ebx, edx       ; adding upper half with carry

    ret
ExtendedAdd ENDP


main PROC
    
    ;first number
    mov eax, num1Low
    mov ebx, num1High

    ;second number
    mov ecx, num2Low
    mov edx, num2High

    call ExtendedAdd

    mov resultLow, eax
    mov resultHigh, ebx

    mov edx, OFFSET msg
    call WriteString

    mov eax, resultHigh
    call WriteDec

    mov eax, resultLow
    call WriteDec
    call Crlf

    exit
main ENDP
END main