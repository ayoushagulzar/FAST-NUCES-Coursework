COMMENT!
    Use following array declarations:
    arrayB BYTE 60, 70, 80
    arrayW WORD 150, 250, 350
    arrayD DWORD 600, 1200, 1800

    For each array, add its 1st and last element using scale factors and display the result in a separate
    register. (Hint: Use ESI and TYPE Operator).!

INCLUDE Irvine32.inc

.data 
    arrayB BYTE 60, 70, 80
    arrayW WORD 150, 250, 350
    arrayD DWORD 600, 1200, 1800

.code
main PROC

    ; BYTE array
    mov esi, 0
    movzx eax, arrayB[esi * TYPE arrayB]
    mov esi, 2
    movzx ebx, arrayB[esi * TYPE arrayB]
    add eax, ebx         

    ; WORD array
    mov esi , 0
    movzx ecx , arrayW[esi * TYPE arrayW]
    mov esi , 2
    movzx edx , arrayW[esi * TYPE arrayW]
    add ecx , edx

    ; DWORD array
    mov esi , 0
    mov edi , arrayD[esi * TYPE arrayD]
    mov esi , 2
    mov ebp , arrayD[esi * TYPE arrayD]
    add edi , ebp
    call DumpRegs

	exit

main ENDP
END main
