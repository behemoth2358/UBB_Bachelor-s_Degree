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
and AX,0000000000001110b
shl AX,12 ; bits 12-14 of A -> bits 0-2 of C
mov BX,b
and BX,1111110000000000b
shr BX,3 ; bits 0-5 of B -> bits 3-8 of C
mov CX,a
and CX,0001111111000000b
shr CX,6 ; bits 3-9 of A -> bits 9-15 of C
or c,AX
or c,BX
or c,CX

int 21h
code ends
end start
