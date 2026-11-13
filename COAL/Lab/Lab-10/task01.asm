;Write a program which contains a procedure named ThreeProd that displays the product of three
;numeric parameters passed through a stack.

INCLUDE Irvine32.inc

.data
    num1 DWORD 2
    num2 DWORD 15
    num3 DWORD 3

    msg BYTE "Product = ", 0

.code
main PROC
	push num1
    push num2
    push num3

    call ThreeProd
	exit
main ENDP

ThreeProd PROC
    push ebp
    mov ebp , esp

    mov eax , [ebp+8]          ;eax = num3
    imul eax , [ebp+12]        ;eax = num3 * num2
    imul eax , [ebp+16]        ;eax = num3 * num2 * num1

    mov edx, OFFSET msg
    call WriteString
    call WriteDec

    pop ebp
    ret 12                     ; 4 * 3(no: of arguments)
ThreeProd ENDP
END main
