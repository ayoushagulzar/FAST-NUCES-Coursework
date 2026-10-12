COMMENT!
	Write an assembly language program that displays the first 10 even numbers on the
	console.
	 Use a loop instruction (LOOP) to control the iteration.
	 Start from the number 2 and increment by 2 each time.
	 Display the numbers on a single line separated by spaces.

	Sample Output:
	2 4 6 8 10 12 14 16 18 20 !

INCLUDE Irvine32.inc

.code
main PROC
	mov eax , 2
	mov ecx , 10

	L1:
		call WriteDec    
		push eax         ; Saving number before changing AL
		mov al, ' '      ; AL is part of EAX, so this overwrites part of the number and give us wrong output
		call WriteChar
		pop eax          ; restoring original number
		add eax , 2
		Loop L1

	exit

main ENDP
END main