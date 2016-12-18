assume cs: code, ds: data

data segment

a dw 4
b db 2
c dd 3
x dd ?
r dw ?
q dw ?

data ends

code segment
start:
mov AX, data
mov DS,AX
;(a*a+b)/(b+b)+c
mov AX,a
imul a ;AX=a*a
mov BX,AX
mov AL,b
cbw
add AX,BX;AX=a*a+b
mov BX,AX;BX=a*a+b
mov AL,b
add AL,AL
cbw;AX=b+b
mov CX,AX;CX=b+b
mov AX,BX;AX=a*a+b
idiv CX ;DX=(a*a+b)%(b+b) , AX=(a*a+b)/(b+b)
mov r,DX
mov q,AX
cwd
add AX,word ptr c
adc DX,word ptr c+2
mov word ptr x,AX
mov word ptr x+2,DX

mov ax,4C00h
int 21h
code ends
end start
