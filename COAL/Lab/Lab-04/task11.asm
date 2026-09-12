COMMENT!	
	Use this data for the following questions: (.data was provided in question)
	Tasks:
        i. Write an instruction to increment the value stored in val2.
        ii. Write an instruction to subtract the contents of val3 from the EAX register.
        iii. Write instructions to subtract the contents of val4 from the contents of val2.
        iv. Write an instruction to move the value stored in val1 into the BL register.!

INCLUDE Irvine32.inc

.data
    val1 BYTE 10h
    val2 WORD 8000h
    val3 DWORD 0FFFFh
    val4 WORD 7FFFh

    msg1 BYTE "After incrementing val2: ", 0
    msg2 BYTE "After subtracting val3 from EAX: ", 0
    msg3 BYTE "After subtracting val4 from val2: ", 0
    msg4 BYTE "Value of BL after moving val1: ", 0

.code
main PROC

    ; task (i) -> Increment val2
	mov ax , val2 
    INC ax                     
    mov edx, OFFSET msg1
    call WriteString
    movzx eax, ax
    call WriteHex
    call Crlf

    ; task (ii) -> eax - val3
	sub eax , val3              
    mov edx, OFFSET msg2
    call WriteString
    movzx eax, ax
    call WriteHex
    call Crlf
	
    ; task (iii) -> val2 - val4
    mov bx , val2
    sub bx , val4               
    mov edx, OFFSET msg3
    call WriteString
    movzx ebx, bx
    call WriteHex
    call Crlf

    ; task (iv) -> move val1 to bl reg
    mov bl , val1              
    mov edx, OFFSET msg4
    call WriteString
    movzx ebx, bl
    call WriteHex
    call Crlf

	call DumpRegs
	exit

main ENDP
END main