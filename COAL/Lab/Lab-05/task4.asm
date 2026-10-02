COMMENT!

	Initialize two arrays:
	array1 BYTE 50, 60, 70, 80
	array2 BYTE 4 DUP (?)
	Copy elements of array1 into array2 in reverse order using either indirect addressing or direct-
	offset addressing. Use ESI and EDI Registers. (Hint: INC and DEC of OFFSET).!

INCLUDE Irvine32.inc

.data 
	array1 BYTE 50, 60, 70, 80
	array2 BYTE 4 DUP (?)
	msg1 BYTE "Array 1: " , 0
    msg2 BYTE "Array 2: " , 0

.code
main PROC
	mov esi , OFFSET array1
	add esi , 3

	mov edi , OFFSET array2
	mov ecx , 4 

	L1: 
		mov al, [esi]
		mov [edi], al
		dec esi
		inc edi

		Loop L1
	
	; Printing array1
    mov edx, OFFSET msg1
    call WriteString

    mov esi, OFFSET array1
    mov ecx, LENGTHOF array1

	L2:
		movzx eax, BYTE PTR [esi]
		call WriteDec

		mov al, ' '
		call WriteChar

		inc esi
		loop L2

	call Crlf

	; Printing array2
	mov edx, OFFSET msg2
	call WriteString

	mov esi, OFFSET array2
	mov ecx, LENGTHOF array2

	L3:
		movzx eax, BYTE PTR [esi]
		call WriteDec

		mov al, ' '
		call WriteChar

		inc esi
    loop L3

	exit

main ENDP
END main
