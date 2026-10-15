;Take an array of 10 numbers move word-type of data into another empty array using stack push and pop technique.

INCLUDE Irvine32.inc

.data
	arr1 WORD 10 , 20 , 30 , 40 ,50 ,60 ,70 ,80 ,90 , 100
	arr2 WORD 10 DUP(?)
.code
main PROC
	mov esi , OFFSET arr1
	mov ecx , LENGTHOF arr1

L1:
	movzx eax , WORD PTR [esi]
	push eax
	add esi , TYPE arr1
	Loop L1


	mov esi , OFFSET arr2
	mov ecx , LENGTHOF arr2
L2:
	pop eax
	mov WORD PTR [esi] , ax
	add esi , TYPE arr2
	Loop L2

	mov esi , OFFSET arr2
	mov ecx , LENGTHOF arr2
L3:
	movzx eax, WORD PTR [esi]
	call WriteDec
	
	mov al , ' '
	call writeChar
	add esi , TYPE arr2
	Loop L3

	exit
main ENDP
END main
