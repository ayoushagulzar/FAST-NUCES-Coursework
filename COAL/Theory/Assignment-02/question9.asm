COMMENT!
	Input a student's marks (0–100) and display grade:
	 A if ≥ 80
	 B if ≥ 60
	 C if ≥ 40
	 F otherwise!

INCLUDE Irvine32.inc

.data
	inputPrompt BYTE "Enter marks (0-100): ", 0
	msgA BYTE "Grade: A" , 0
	msgB BYTE "Grade: B" , 0
	msgC BYTE "Grade: C" , 0
	msgF BYTE "Grade: F" , 0
	msgInvalid BYTE "Invalid! Marks should be in the range of 0-100" , 0
	marks SDWORD ?

.code
main PROC
	mov edx , OFFSET inputPrompt
	call WriteString
	call ReadInt
	mov marks , eax

	cmp marks , 100
	jg LInvalid              ;marks > 100 -> invalid
		
	cmp marks , 0
	jl LInvalid              ;marks < 0 -> invalid

	; check for A grade
	cmp marks , 80
	jge GradeA

	; check for B grade
	cmp marks , 60
	jge GradeB

	; check for C grade
	cmp marks , 40
	jge GradeC

	jmp GradeF

	
GradeA:
	mov edx , OFFSET msgA
	call writeString
	call Crlf
	jmp LExit

GradeB:
	mov edx , OFFSET msgB
	call writeString
	call Crlf
	jmp LExit

GradeC:
	mov edx , OFFSET msgC
	call writeString
	call Crlf
	jmp LExit

GradeF:
	mov edx , OFFSET msgF
	call writeString
	call Crlf
	jmp LExit

LInvalid:
	mov edx , OFFSET msgInvalid
	call writeString
	call Crlf
	jmp LExit

LExit:
	exit
main ENDP
END main