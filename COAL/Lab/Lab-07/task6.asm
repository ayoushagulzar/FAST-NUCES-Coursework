COMMENT!
	During a Software Engineering team meeting, Ghulam Qadir and his teammates review three
	modules of their group project.
	Each teammate gives points (out of 10) for code quality, documentation, and testing.
	You have to write an Assembly program that collects these three scores and calculates the total review
	points using stack operations and nested procedure calls.
	 Display a welcome message: “Code Review Evaluation by Ghulam Qadir”
	 Ask the user to input three integer scores.
	 Use PUSH to store the entered scores.
	 Use nested procedures to calculate the total using POP and addition.
	 Display the total score at the end.!

INCLUDE Irvine32.inc

.data
	welcomeMsg BYTE "Code Review Evaluation by Ghulam Qadir" , 0
	qualityScore BYTE "Enter score for Code Quality (out of 10): " , 0
	docScore BYTE "Enter score for Documentation (out of 10): " , 0
	testingScore BYTE "Enter score for Testing (out of 10): " , 0
	outputMsg BYTE "Total review points: " , 0
	score1 DWORD ?
	score2 DWORD ?
	score3 DWORD ?

.code
main PROC
	mov edx , OFFSET welcomeMsg
	call WriteString
	call Crlf

	mov edx , OFFSET qualityScore
	call WriteString
	call readInt
	mov score1 , eax
	push score1

	mov edx , OFFSET docScore
	call WriteString
	call readInt
	mov score2 , eax
	push score2
	
	mov edx , OFFSET testingScore
	call WriteString
	call readInt
	mov score3 , eax
	push score3

	call Crlf

	mov edx , OFFSET outputMsg
	call WriteString

	call calculate
	call writeInt

	exit

main ENDP

	;outer procedure
	calculate PROC
		call total
		ret
	calculate ENDP

	;inner procedure
	total PROC
		pop ebx      ;Return address of total (from CALL total)
		pop ecx      ;Return address of main  (from CALL calculate)
		pop score3
		pop score2
		pop score1

		mov eax , score3
		add eax , score2
		add eax , score1

		push ecx
		push ebx
		ret
	total ENDP

END main