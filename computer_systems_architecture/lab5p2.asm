assume CS: code, DS: data

data segment

a dw 1111111111111111b
b dw 1111111111111111b
c dw ?

data ends

code segment
start:
mov AX,data
mov DS,AX

mov c,0
mov AX,a
and AX,1111100000000000b
shr AX,4 ; bits 0-4 of A -> bits 4-8 of C
mov BX,b
and BX,0000011110000000b
shl BX,5 ; bits 5-8 of B -> bits 0-3 of C
mov CX,a
and CX,0000001111111000b
shr CX,3 ; bits 6-12 of A -> bits 9-15 of C
or c,AX
or c,BX
or c,CX

int 21h
code ends
end start
