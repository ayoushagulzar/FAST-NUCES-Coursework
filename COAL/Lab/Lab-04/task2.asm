COMMENT!
	A customer has 5000 in his account. He deposits 1400 and then withdraws 3000. Use
	ADD and SUB instructions to update the balance.!

INCLUDE Irvine32.inc

.data
	balance dword 5000
	deposit dword 1400
	withdraw dword 3000
.code
main PROC
	mov eax , balance
	add eax , deposit
	sub eax , withdraw

	call DumpRegs
	exit

main ENDP
END main