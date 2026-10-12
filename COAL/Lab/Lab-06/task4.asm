COMMENT!
	A mathematics teacher wishes to display the first ten multiples of 5 on the console as part
	of a classroom exercise. Develop an Assembly Language program that utilizes the LOOP
	instruction with a counter register to repeatedly add 5 and display each result using the WriteDec
	procedure.!

INCLUDE Irvine32.inc

.code
main PROC
	mov eax , 5
	mov ecx , 10

	L1:
		call WriteDec
		call Crlf
		add eax , 5
		Loop L1

	exit

main ENDP
END main