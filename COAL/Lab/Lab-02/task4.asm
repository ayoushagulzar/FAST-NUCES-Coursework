INCLUDE Irvine32.inc

COMMENT !
Write an Assembly program to sum all error codes and store the result in a register.
01) 15d (syntax error)
02) 2Ah (semantic error)
03) 1011b (runtime warning)
04) 12o (optimization note) !

.code
main PROC

mov eax , 15d
add eax , 2Ah
add eax , 1011b
add eax , 12o

  call DumpRegs

    exit
main ENDP
END main




