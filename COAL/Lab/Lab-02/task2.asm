INCLUDE Irvine32.inc

COMMENT !
 Debugging and Breakpoints:
 1. Use the following sample Assembly code.
 2. Set a breakpoint at the line: add eax, ebx
 3. Run the program in Debug mode.
 4. Observe how the values of registers change before and after execution.
 5. Take screenshots showing the register values. !

.code
main PROC

mov eax , 5d
mov ebx , 1001b
add eax , ebx

call dumpregs
exit

main ENDP
END main



