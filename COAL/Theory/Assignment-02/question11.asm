;Implement the following pseudocode in x86 assembly language. All variables are 32-bitsigned integers:
;	if (num1 > num2 && num3 != num4)
;		result = num1 + num3;
;	else if (num2 == num4)
;		result = num2 - num1;
;	else
;		result = 0;

INCLUDE Irvine32.inc

.data
	num1 SDWORD 50
	num2 SDWORD 25
	num3 SDWORD 17
	num4 SDWORD 34
	result SDWORD ?


.code
main PROC
	mov eax , num1
	mov ebx , num2
	mov ecx , num3
	mov edx , num4

	;checking first condition of if
	cmp eax , ebx
	jng ElseIfBlock

	;checking second condition of if
	cmp ecx , edx
	je ElseIfBlock 

	;when both conditions are true..
	mov esi , num1
	add esi , num3
	mov result , esi
	jmp LExit

ElseIfBlock:
	cmp ebx , edx
	jne ElseBlock
	mov esi , num2
	sub esi , num1
	mov result , esi
	jmp LExit

ElseBlock:
	mov result , 0
	jmp LExit

LExit:
	mov eax , result
	call writeInt
	exit

main ENDP
END main