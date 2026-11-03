COMMENT!
Implement the following given code in Assembly and consider var = 0.
	while (var <= 10)
		if(var < 5)
			print "Hell0"
		else
			print "World"
		var = var + 1;
	end while 
	!

INCLUDE Irvine32.inc

.data
    var DWORD 0
    msg1 BYTE "Hello", 0
    msg2 BYTE "World", 0

.code
main PROC

LWhile:
    ; while (var <= 10)
    cmp var, 10
    ja LExit

    ; if (var < 5)
    cmp var, 5
    jae ElsePart

    mov edx, OFFSET msg1
    call WriteString
    call Crlf
    jmp LEndIf

ElsePart:
    mov edx, OFFSET msg2
    call WriteString
    call Crlf

LEndIf:
    inc var             ; var = var + 1
    jmp LWhile

LExit:
    exit

main ENDP
END main