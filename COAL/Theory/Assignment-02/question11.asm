COMMENT!
	Implement the following pseudocode in x86 assembly language. All variables are 32-bitsigned integers:
	if (num1 > num2 && num3 != num4)
		result = num1 + num3;
	else if (num2 == num4)
		result = num2 - num1;
	else
		result = 0;!

INCLUDE Irvine32.inc

.data
	num1 SDWORD 50
	num2 SDWORD 50
	num3 SDWORD 50
	num4 SDWORD 50
	result SDWORD ?


.code
main PROC
	mov al , z
	mov bl , op1
	mov cl , op2

	LWhile:
		cmp bl , cl
		jg LExit            ; if op1 > op2: exit while loop

		cmp bl , x          ; if op1 < x, go to else
		jl LElse

		cmp bl , y         ; if op1 > y, go to else
		jg LElse

		add al , 10h       ; z+=10
		jmp LEndIf

	LElse:
		sub al , 10h      ; z-=10

	LEndIf:
		dec bl           ; op1--
		jmp LWhile

	LExit:
		mov z , al
		call DumpRegs
		exit

main ENDP
END main