INCLUDE Irvine32.inc

; Implement the equation in assembly language: b) 45 + 69 + 50 + 75 + 54 + 44o - 0Ah

.code
main PROC

mov eax , 45d
add eax , 69d
add eax , 50d
add eax , 75d
add eax , 54d
add eax , 44o
sub eax , 0Ah

call dumpregs
exit

main ENDP
END main



