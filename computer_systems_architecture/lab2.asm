assume CS: code, DS: data
data segment

a db "213456"
len equ $-a
b db len dup(?)

data ends

code segment
start:

mov AX,data
mov DS,AX

mov DI,0
mov SI,0

for:

cmp DI,len
jae continue
mov CL,a[DI] ;CL=a[DI]
add DI,1
mov AX,0 
mov AL,CL ;AX=a[DI]
mov BL,2 ;BL=2
div BL ;AH=a[DI] mod 2
mov BX,0
mov BL,AH
cmp BX,1
je for
mov B[SI],CL
add SI,1

jmp for

continue:

mov AX,4C00h
int 21h

code ends
end start




