data segment

sir db "hello",'$'

data ends

code segment

extrn _printString:FAR

start:

mov AX,data
mov DS,AX

lea DX,sir

call _printString

mov AX,4C00h
int 21h

code ends
end start
