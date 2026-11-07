COMMENT!
	Write a program that performs simple encryption by rotating each plaintext byte a varying number of positions
	in different directions. For example, in the following array that represents the encryption key, a negative value
	indicates a rotation to the left(ROL) and a positive value indicates a rotation to the right(ROR). The integer in each position
	indicates the magnitude of the rotation:
	Key BYTE 2, 4, 1, 0, 3, 5, 2, 4, 4, 6

	Your program should loop through a plaintext message and align the key to the first 10 bytes of the message.
	Rotate each plaintext byte by the amount indicated by its matching key array value. Then, align the key to the
	next 10 bytes of the message and repeat the process.!

INCLUDE Irvine32.inc

.data
    plaintext BYTE "hey, this is a test message", 0
    Key BYTE 2, 4, 1, 0, 3, 5, 2, 4, 4, 6

    encryptedMsg BYTE LENGTHOF plaintext DUP(?)

    msg1 BYTE "Original Message: ", 0
    msg2 BYTE "Encrypted Message: ", 0

.code
main PROC

    mov edx, OFFSET msg1
    call WriteString

    mov edx, OFFSET plaintext
    call WriteString
    call Crlf

    ; initializing indices
    mov esi, 0              ; Plaintext index
    mov edi, 0              ; Key index
    mov ebx, LENGTHOF plaintext
    dec ebx                 ; excluding the null terminator

EncryptLoop:
    cmp esi, ebx            
    jge EncryptionDone

    mov al, plaintext[esi]   ;loading plaintext character 

    mov cl, Key[edi]         ;loading key value corresponding to the plaintext char

    ;checking if key value is negative
    test cl, 80h
    jnz RotateLeft

    ; if not neg (pos/zero) -> rotate right
    ror al, cl              ;-> rotating char , keyvalue times
    jmp StoreByte

RotateLeft:
    ;first convert neg key value to pos , then rotate left
    neg cl
    rol al, cl

StoreByte:
    mov encryptedMsg[esi], al       ;storing encrypted charactersr
    inc esi
    inc edi

    cmp edi, LENGTHOF Key
    jl EncryptLoop      ;if edi < lengthof key , continue loop

    mov edi, 0          ;else reset key index
    jmp EncryptLoop     ;again jump to loop cuzthe plaintext might have more than 10 characters

EncryptionDone:
    mov edx, OFFSET msg2
    call WriteString

    mov esi, 0

CharLoop:
    cmp esi, ebx
    jge CharDone
    mov al, encryptedMsg[esi]

    ;if al < 20h(space) or greater than 7Eh (~) --> non-printable values , print dot
    cmp al, 20h                 
    jb  PrintDot
    cmp al, 7Eh                 
    ja  PrintDot

    jmp PrintChar

PrintDot:
    mov al, '.'

PrintChar:
    call WriteChar
    inc esi
    jmp CharLoop
CharDone:
    call Crlf
    exit

main ENDP
END main