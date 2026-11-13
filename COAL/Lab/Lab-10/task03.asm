COMMENT!
	Write a program which contains a procedure named LocalSquare. The procedure must declare a local variable.
    Initialize this variable by taking an input value from the user and then display its square. Use
	ENTER & LEAVE instructions to allocate and de-allocate the local variable.!

INCLUDE Irvine32.inc

.data
    msg BYTE "Enter a number: ", 0
    resultMsg BYTE "Square = ", 0

.code
main PROC
    call LocalSquare
	exit
main ENDP

LocalSquare PROC
    enter 4 , 0             ;allocation

    mov edx, OFFSET msg
    call WriteString
    call ReadInt

    mov [ebp-4], eax       ; Store input in local variable
    mov eax , [ebp-4]
    imul eax               ;eax*=eax

    mov edx, OFFSET resultMsg
    call WriteString

    call WriteInt
    call Crlf

    leave                  ;de-allocation
    ret                 
LocalSquare ENDP
END main
