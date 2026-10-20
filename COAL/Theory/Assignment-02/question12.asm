COMMENT!
	Convert the following High Level Language code to equivalent assembly language:
	While (op1 <= op2)
	{
		if (op1 >= x && op1 =< y)
		{ z += 10; }
		else
		{ z -= 10;}
	op1--; } !

INCLUDE Irvine32.inc

.data
	;using hexadex values
	x byte 15h
	y byte 20h
	z byte 10h
	op1 byte 17h
	op2 byte 21h

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