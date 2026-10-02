COMMENT!
	Initialize a Byte array consisting of elements 71,53,21,62, 35. Sort the given array in ascending
	order directly with the help of registers (you do not need to use a loop here). Use direct-offset
	addressing to access the array elements. (Hint: Use new array for sorted elements). What would
	be changes in code if declared array was of WORD and DWORD size?!

INCLUDE Irvine32.inc

.data 
	array BYTE 71,53,21,62, 35
	sorted_array BYTE 5 DUP(?)
	
	msg1 BYTE "Original Array: ", 0
	msg2 BYTE "Sorted Array: "  , 0

.code
main PROC
     mov al , array+2       ; sorting manually
	 mov bl , array+4
	 mov cl , array+1
	 mov dl , array+3
	 mov ah , array

	 mov sorted_array   , al
	 mov sorted_array+1 , bl
	 mov sorted_array+2 , cl
     mov sorted_array+3 , dl
	 mov sorted_array+4 , ah

	; Printing original array
    mov edx, OFFSET msg1
    call WriteString

    movzx eax, array
    call WriteDec
    mov al, ' '
    call WriteChar

    movzx eax, array+1
    call WriteDec
    mov al, ' '
    call WriteChar

    movzx eax, array+2
    call WriteDec
    mov al, ' '
    call WriteChar

    movzx eax, array+3
    call WriteDec
    mov al, ' '
    call WriteChar

    movzx eax, array+4
    call WriteDec

    call Crlf

    ; Printing sorted array
    mov edx, OFFSET msg2
    call WriteString

    movzx eax, sorted_array
    call WriteDec
    mov al, ' '
    call WriteChar

    movzx eax, sorted_array+1
    call WriteDec
    mov al, ' '
    call WriteChar

    movzx eax, sorted_array+2
    call WriteDec
    mov al, ' '
    call WriteChar

    movzx eax, sorted_array+3
    call WriteDec
    mov al, ' '
    call WriteChar

    movzx eax, sorted_array+4
    call WriteDec

    call Crlf

	exit

main ENDP
END main
