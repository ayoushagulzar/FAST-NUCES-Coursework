COMMENT!
	A shop has 50 items. A customer buys 7, and later the shopkeeper restocks 15. Use SUB
	and ADD to update inventory.!

INCLUDE Irvine32.inc

.data
	currentItems dword 50
	sold dword 7
	restock dword 15

.code
main PROC
	mov eax , currentItems
	sub eax , sold
	add eax , restock

	call DumpRegs
	exit

main ENDP
END main

