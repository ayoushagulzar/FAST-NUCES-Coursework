COMMENT! 
	The store manager intends to display a welcome message on the screen, but wishes to skip
	the advertisement section and proceed directly to the billing notice. Write an Assembly Language
	program that uses an unconditional JMP instruction to bypass the advertisement message and
	display only the welcome message followed by the billing notice.!


INCLUDE Irvine32.inc

.data
    welcomeMsg BYTE "Welcome to our store!", 0
    adMsg      BYTE "Advertisement: Special discounts today!", 0
    billMsg    BYTE "Please proceed to billing.", 0

.code
main PROC
	mov edx , OFFSET welcomeMsg
	call WriteString
	call Crlf

	jmp Billing

	mov edx , OFFSET adMsg
	call WriteString
	call Crlf

	Billing:
			mov edx , OFFSET billMsg
			call WriteString

	exit

main ENDP
END main