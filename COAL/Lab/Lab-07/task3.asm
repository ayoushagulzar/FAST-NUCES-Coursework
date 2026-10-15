COMMENT!
	Write a program having nested procedures are used to calculate the total sum of 2 arrays
	(each array having 5-elements). The sum of 1-array in 1st procedure and in 2nd procedure have
	sum of 2-array. In addition, the 3rd procedure added the results of both.!

INCLUDE Irvine32.inc

.data
	arr1 DWORD 2 , 4 , 6 , 8 , 10
	arr2 DWORD 1 , 3 , 5 , 7 , 9
	msg BYTE "SUM: " , 0

.code
main PROC
	mov edx , OFFSET msg
	call WriteString

	call calcSum
	call WriteDec
	
	exit
main ENDP

; Outer procedure
calcSum PROC
    call addArr1
    push eax          ; Saving sum of arr1

    call addArr2        ; eax = sum of arr2

    pop ebx           ; restoring arr1 sum
    add eax, ebx
	ret
calcSum ENDP

;Inner proc1
addArr1 PROC
    mov ecx , LENGTHOF arr1
	mov eax , 0
	mov esi , OFFSET arr1
L1:
	add eax , [esi]
	add esi , TYPE arr1
	Loop L1

	ret
addArr1 ENDP

;Inner proc2
addArr2 PROC
    mov ecx , LENGTHOF arr2
	mov eax , 0
	mov esi , OFFSET arr2
L2:
	add eax , [esi]
	add esi , TYPE arr2
	Loop L2

	ret
addArr2 ENDP

END main