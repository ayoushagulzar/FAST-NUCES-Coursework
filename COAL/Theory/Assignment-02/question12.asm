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
	x byte 15
	y byte 20
	z byte 10
	op1 byte 17
	op2 byte 21

.code
main PROC
	mov al , z
	mov bl , op1
	mov cl , op2

	LWhile:
		cmp bl , cl
		ja LExit            ; if op1 > op2: exit while loop

		cmp bl , x          ; if op1 < x, go to else
		jb LElse

		cmp bl , y         ; if op1 > y, go to else
		ja LElse

		add al , 10       ; z+=10
		jmp LEndIf

	LElse:
		sub al , 10      ; z-=10

	LEndIf:
		dec bl           ; op1--
		jmp LWhile

	LExit:
		movzx eax , al
		call writeDec
		exit

main ENDP
END main