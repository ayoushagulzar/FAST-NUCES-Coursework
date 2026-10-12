COMMENT!
	Write a program that accepts the names and departments of three students from the user
	and then displays the collected information in a structured format.
	 Use ReadString for taking input from the user.
	 Store each student’s name and department in separate memory buffers.
	 Finally, display all student records on the console in the format:
	Student Records:
	<Name1> <Department1>
	<Name2> <Department2>
	<Name3> <Department3> !

INCLUDE Irvine32.inc

.data
    name1 BYTE 50 DUP(0)
    dept1 BYTE 50 DUP(0)

    name2 BYTE 50 DUP(0)
    dept2 BYTE 50 DUP(0)

    name3 BYTE 50 DUP(0)
    dept3 BYTE 50 DUP(0)

    promptName BYTE "Enter student name: ", 0
    promptDept BYTE "Enter student department: ", 0
    heading BYTE "Student Records:", 0

.code
main PROC
    ; Student 1
    mov edx, OFFSET promptName
    call WriteString
    mov edx, OFFSET name1
    mov ecx, SIZEOF name1
    call ReadString

    mov edx, OFFSET promptDept
    call WriteString
    mov edx, OFFSET dept1
    mov ecx, SIZEOF dept1
    call ReadString

    ; Student 2
    mov edx, OFFSET promptName
    call WriteString
    mov edx, OFFSET name2
    mov ecx, SIZEOF name2
    call ReadString

    mov edx, OFFSET promptDept
    call WriteString
    mov edx, OFFSET dept2
    mov ecx, SIZEOF dept2
    call ReadString

    ; Student 3
    mov edx, OFFSET promptName
    call WriteString
    mov edx, OFFSET name3
    mov ecx, SIZEOF name3
    call ReadString

    mov edx, OFFSET promptDept
    call WriteString
    mov edx, OFFSET dept3
    mov ecx, SIZEOF dept3
    call ReadString

    ; DISPLAY STUDENT RECORDS
    call Crlf
    mov edx, OFFSET heading
    call WriteString
    call Crlf

    mov edx, OFFSET name1
    call WriteString
    mov al, ' '
    call WriteChar
    mov edx, OFFSET dept1
    call WriteString
    call Crlf

    mov edx, OFFSET name2
    call WriteString
    mov al, ' '
    call WriteChar
    mov edx, OFFSET dept2
    call WriteString
    call Crlf

    mov edx, OFFSET name3
    call WriteString
    mov al, ' '
    call WriteChar
    mov edx, OFFSET dept3
    call WriteString
    call Crlf

    exit
main ENDP
END main