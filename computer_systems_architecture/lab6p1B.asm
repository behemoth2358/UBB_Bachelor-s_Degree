assume DS:data, CS:code

data segment
a db "123"
la equ $-a
b db "45"
lb equ $-b
c db la+lb dup(?)
data ends

code segment
start:

mov AX,data
mov DS,AX

lea SI,a


lea DI,c
cld
mov CX,la

mov AX,data
mov ES,AX

rep1:
lodsb
stosb
loop rep1

lea SI,b
cld
mov CX,lb

rep2:
lodsb
stosb
loop rep2

mov AX,4C00h
int 21h

code ends
end start
