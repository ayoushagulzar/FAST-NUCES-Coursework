COMMENT !
	Declare an uninitialized string variable of 100 characters named msg. Then store the
	string " COMPUTER ORGANIZATION & ASSEMBLY LANGUAGE LAB" in it as a null-terminated string. !

INCLUDE Irvine32.inc

.data
msg BYTE 100 DUP(?)      

.code
main PROC
; just folowing what we have covered so far

    mov BYTE PTR msg+0,  'C'
    mov BYTE PTR msg+1,  'O'
    mov BYTE PTR msg+2,  'M'
    mov BYTE PTR msg+3,  'P'
    mov BYTE PTR msg+4,  'U'
    mov BYTE PTR msg+5,  'T'
    mov BYTE PTR msg+6,  'E'
    mov BYTE PTR msg+7,  'R'
    mov BYTE PTR msg+8,  ' '
    mov BYTE PTR msg+9,  'O'
    mov BYTE PTR msg+10, 'R'
    mov BYTE PTR msg+11, 'G'
    mov BYTE PTR msg+12, 'A'
    mov BYTE PTR msg+13, 'N'
    mov BYTE PTR msg+14, 'I'
    mov BYTE PTR msg+15, 'Z'
    mov BYTE PTR msg+16, 'A'
    mov BYTE PTR msg+17, 'T'
    mov BYTE PTR msg+18, 'I'
    mov BYTE PTR msg+19, 'O'
    mov BYTE PTR msg+20, 'N'
    mov BYTE PTR msg+21, ' '
    mov BYTE PTR msg+22, '&'
    mov BYTE PTR msg+23, ' '
    mov BYTE PTR msg+24, 'A'
    mov BYTE PTR msg+25, 'S'
    mov BYTE PTR msg+26, 'S'
    mov BYTE PTR msg+27, 'E'
    mov BYTE PTR msg+28, 'M'
    mov BYTE PTR msg+29, 'B'
    mov BYTE PTR msg+30, 'L'
    mov BYTE PTR msg+31, 'Y'
    mov BYTE PTR msg+32, ' '
    mov BYTE PTR msg+33, 'L'
    mov BYTE PTR msg+34, 'A'
    mov BYTE PTR msg+35, 'N'
    mov BYTE PTR msg+36, 'G'
    mov BYTE PTR msg+37, 'U'
    mov BYTE PTR msg+38, 'A'
    mov BYTE PTR msg+39, 'G'
    mov BYTE PTR msg+40, 'E'
    mov BYTE PTR msg+41, ' '
    mov BYTE PTR msg+42, 'L'
    mov BYTE PTR msg+43, 'A'
    mov BYTE PTR msg+44, 'B'
    mov BYTE PTR msg+45, 0

    exit

main ENDP
END main





