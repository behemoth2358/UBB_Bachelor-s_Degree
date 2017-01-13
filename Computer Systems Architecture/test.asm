assume CS:code, DS: data

data segment

message db "number is: ",'$'
fileErrorMsg db "file error",'$'

filename db "1.in",0

fileHandle dw ?

buffer db 100 dup(?)

data ends

code segment


;CX=number to be printed
_printNumber proc

push AX
push BX
push SI

mov SI,0

divide:
mov AX,CX
mov DX,0
mov BX,10
div BX
add DL,'0'
push DX
inc SI
mov CX,AX
cmp CX,0
jne divide

cout:
pop DX
mov AH,02h
int 21h
dec SI
cmp SI,0
jne cout

pop SI
pop BX
pop AX

ret
endp


;DX=pointer to the message
_printString proc
mov AH,09h
int 21h
ret
endp

_endl proc
push AX
push DX
mov DL,10
mov AH,02h
int 21h
pop DX
pop AX
ret
endp


start:
mov AX,data
mov DS,AX
;open file
mov AH,3Dh
mov AL,0
mov DX,offset filename
int 21h

jc fileError
mov fileHandle,AX
;read buffer
mov AH,3Fh
mov BX,fileHandle
mov CX,100
mov DX,offset buffer
int 21h
jc fileError

;for debug
;mov CX,AX
;call _printNumber
;call _endl
;mov SI,AX
;mov buffer[SI],'$'
;mov DX,offset buffer
;call _printString
;call _endl

mov BX,0
mov SI,0
mov CX,AX
dec CX
makeNumber:
mov AX,1
dec CX
shl AX,CL
mov DL,buffer[SI]
inc SI
cmp DL,'0'
je cont
add BX,AX
cont:
cmp CX,0
jne makeNumber
mov DX,offset message
call _printString
mov CX,BX
call _printNumber
mov AH,3Eh
mov BX,fileHandle
int 21h
jmp finish

fileError:
mov DX,offset fileErrorMsg
call _printString

finish:
mov AX,4C00h
int 21h
code ends
end start
