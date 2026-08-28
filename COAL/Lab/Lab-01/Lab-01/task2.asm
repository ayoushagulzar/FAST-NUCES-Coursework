INCLUDE Irvine32.inc

.data

studentName BYTE "Ayousha Gulzar", 0
nuID BYTE "25K-3069", 0
message BYTE "This is COAL lab 1 task" , 0

.code

main PROC

    mov edx, OFFSET studentName
    call WriteString
    call Crlf

    mov edx, OFFSET nuID
    call WriteString
    call Crlf

    mov edx, OFFSET message
    call WriteString
    call Crlf

    exit

main ENDP
END main