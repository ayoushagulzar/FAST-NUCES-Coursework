INCLUDE Irvine32.inc

; Implement the equation in assembly language: a) 01110010 – D83h + 285+20 + 10001101 – 0E+0F

.code
main PROC

mov eax , 01110010b
sub eax , 0D83h
add eax , 285d
add eax , 20d
add eax , 10001101b
sub eax , 0Eh
add eax , 0Fh

call dumpregs
exit

main ENDP
END main



