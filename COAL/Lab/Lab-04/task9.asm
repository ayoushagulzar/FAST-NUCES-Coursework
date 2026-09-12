COMMENT!	
	Write a program which declares a symbolic constant named SecondsInDay using the
	equal-sign directive and assign it an arithmetic expression that calculates the number of seconds
	in a 24-hour period.!

INCLUDE Irvine32.inc

.data
	SecondsInDay = 24 * 60 * 60

.code
main PROC
	mov eax , SecondsInDay

	call DumpRegs
	exit

main ENDP
END main