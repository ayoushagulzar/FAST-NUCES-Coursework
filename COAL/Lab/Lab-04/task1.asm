COMMENT!
	Write an assembly program to store marks of two subjects (e.g., 55 and 65). Use ADD to
	calculate the total and SUB to find the difference between the two marks.!

INCLUDE Irvine32.inc

.data
	marks1 dword 55
	marks2 dword 65
.code
main PROC
	mov eax , marks1
	mov ebx , marks2
	add eax , ebx

	call DumpRegs
	exit

main ENDP
END main