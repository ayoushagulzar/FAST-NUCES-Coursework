COMMENT!
	Take marks (0–100) from the user and print the grade:
	90–100 → A, 80–89 → B, 70–79 → C, 60–69 → D, below 60 → F. Print "Invalid marks" if the
	input is below 0 or above 100.!

INCLUDE Irvine32.inc

.data
    msg1 BYTE "Enter marks (0-100): ", 0
    gradeA BYTE "Grade: A", 0
    gradeB BYTE "Grade: B", 0
    gradeC BYTE "Grade: C", 0
    gradeD BYTE "Grade: D", 0
    gradeF BYTE "Grade: F", 0
    invalidMsg BYTE "Invalid marks", 0

.code
main PROC

    mov edx, OFFSET msg1
    call WriteString
    call ReadInt

    cmp eax, 0
    jl Invalid

    cmp eax, 100
    jg Invalid

    ; Check grade A (90-100)
    cmp eax, 90
    jge Grade_A

    ; Check grade B (80-89)
    cmp eax, 80
    jge Grade_B

    ; Check grade C (70-79)
    cmp eax, 70
    jge Grade_C

    ; Check grade D (60-69)
    cmp eax, 60
    jge Grade_D

    ; Below 60
    jmp Grade_F

Grade_A:
    mov edx, OFFSET gradeA
    jmp Display

Grade_B:
    mov edx, OFFSET gradeB
    jmp Display

Grade_C:
    mov edx, OFFSET gradeC
    jmp Display

Grade_D:
    mov edx, OFFSET gradeD
    jmp Display

Grade_F:
    mov edx, OFFSET gradeF
    jmp Display

Invalid:
    mov edx, OFFSET invalidMsg

Display:
    call WriteString
    call Crlf

    exit

main ENDP
END main