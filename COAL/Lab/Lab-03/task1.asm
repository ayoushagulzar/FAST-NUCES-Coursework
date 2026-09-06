INCLUDE Irvine32.inc

COMMENT !
	Convert the following high-level instruction into Assembly Language:
	ebx = { (a+b) – (a-b) + c } +d
	a= 10h, b=12h, c=30h, d=20h !

.data
a_value DWORD 10h
b_value DWORD 12h
c_value DWORD 30h
d_value DWORD 20h

.code
main PROC

mov ebx , a_value
mov eax , b_value
add ebx , eax

mov eax , a_value
mov ecx , b_value
sub eax , ecx

sub ebx , eax
mov eax , c_value
add ebx , eax

mov eax , d_value
add ebx , eax

call Dumpregs
exit

main ENDP
END main



