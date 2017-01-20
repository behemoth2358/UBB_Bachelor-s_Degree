assume CS:code, DS:data

data segment

buffer db 20 dup(?)
bufferLen dw ?
filename db "1.in",0
fileHandle dw ?
nr1 dw ?
nr2 dw ?

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
mov fileHandle,AX
;read  buffer
mov AH,3Fh
mov BX,fileHandle
mov CX,100
mov DX,offset buffer
int 21h
jc endPrg

mov SI,0
while1:
inc SI
cmp buffer[SI],' '
jne while1

mov DI,SI
dec SI
mov CX,0
mov BX,1
makeNumber1:

mov AX,BX
mov BX,2
mul BX
mov BX,AX
cmp buffer[SI],'1'
jne cont

add CX,BX

cont:
dec SI
cmp SI,0
jge makeNumber1

mov AX,CX
mov DX,0
mov CX,2
div CX
mov CX,AX

mov nr1,CX
mov SI,DI

do1:
inc SI
cmp buffer[SI],' '
jne do1

dec SI
mov CX,0
mov BX,1
makeNumber2:
mov AX,BX
mov BX,2
mul BX
mov BX,AX
cmp buffer[SI],'1'
jne cont1
add CX,BX
cont1:
dec SI
cmp buffer[SI],' '
jne makeNumber2

mov AX,CX
mov DX,0
mov CX,2
div CX
mov CX,AX

mov AX,nr1
add CX,AX
call _printNumber


endPrg:
mov AX,4C00h
int 21h
code ends
end start
