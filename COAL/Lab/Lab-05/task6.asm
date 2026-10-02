COMMENT!
    Declare three variables: a BYTE, a WORD, and a DWORD. Use the OFFSET operator to move
    the addresses of these variables into registers and display the addresses using Irvine32's WriteHex
    procedure.!

INCLUDE Irvine32.inc

.data 
    varB BYTE   6
    varW WORD   12
    varD DWORD  20 

    msg1 BYTE "BYTE Address: " , 0
    msg2 BYTE "WORD Address: " , 0
    msg3 BYTE "DWORD Address: " , 0

.code
main PROC

    mov eax , OFFSET varB
    mov edx , OFFSET msg1
    call WriteString
    call WriteHex
    call Crlf

    mov eax , OFFSET varW
    mov edx , OFFSET msg2
    call WriteString
    call WriteHex
    call Crlf

    mov eax , OFFSET varD
    mov edx , OFFSET msg3
    call WriteString
    call WriteHex
    call Crlf

	exit

main ENDP
END main

; NOTE: WriteHex only displays the value of eax.
