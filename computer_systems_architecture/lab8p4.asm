assume cs: code, ds:data

data segment

monday db "Monday",'$'
tuesday db "Tuesday",'$'
wednesday db "Wednesday",'$'
thursday db "Thursday",'$'
friday db "Friday",'$'
saturday db "Saturday",'$'
sunday db "Sunday",'$'
yearStr db "Year:",'$'
monthStr db "Month:",'$'
dayStr db "Day:",'$'
ten db 10
dayNr db ?
month db ?
year dw ?
day db ?

data ends

code segment


;DS:DX=pointer to the string
_printString proc

mov AH,09h
int 21h

ret
endp


;CX=a number
_printNumber proc
mov SI,0

divide:
mov AX,CX
div ten
mov DL,AH
add DL,'0'
inc SI
push DX
mov AH,0
mov CX,AX
;convert back to word and compare with 0
cmp CX,0
jne divide

cout:
pop DX
mov AH,02h
int 21h
dec SI
cmp SI,0
jne cout

ret
endp

_endl proc
mov DL,10
mov AH,02h
int 21h

ret
endp

start:
mov AX, data
mov DS,AX

; Get system date
mov AH,2Ah
int 21h

mov year,CX
mov month,DH
mov dayNr,AL
mov day,DL

;print Year
mov DX,offset yearStr
call _printString
call _printNumber

call _endl

;print month
mov DX,offset monthStr
call _printString
mov CL,month
mov CH,0
call _printNumber

call _endl

;print day
mov DX,offset dayStr
call _printString
mov CL,day
mov CH,0
call _printNumber

call _endl

;print day of the week

mov AL,dayNr

cmp AL,0
je isSunday
cmp AL,1
je isMonday
cmp AL,2
je isTuesday
cmp AL,3
je isWednesday
cmp AL,4
je isThursday
cmp AL,5
je isFriday
cmp AL,6
je isSaturday

jmp endProgram

isMonday:
mov DX,offset monday
call _printString
call _endl
jmp endProgram

isTuesday:
mov DX,offset tuesday
call _printString
call _endl
jmp endProgram

isWednesday:
mov DX,offset wednesday
call _printString
call _endl
jmp endProgram

isThursday:
mov DX,offset thursday
call _printString
call _endl
jmp endProgram

isFriday:
mov DX,offset friday
call _printString
call _endl
jmp endProgram

isSaturday:
mov DX,offset saturday
call _printString
call _endl
jmp endProgram

isSunday:
mov DX,offset sunday
call _printString
call _endl
jmp endProgram

endProgram:
mov AX,4C00h
int 21h
code ends
end start
