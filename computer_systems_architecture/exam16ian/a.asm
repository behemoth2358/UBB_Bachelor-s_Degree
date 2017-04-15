assume CS: code, DS: data

data segment

        arr db 1,2,0,2,5,1,8,9,0,3,11,14,0
        len dw $-arr

        public arr
        public len

data ends

code segment

extrn _printNumber:PROC
extrn _solve:PROC

start:
mov AX,data
mov DS,AX

        call _solve
        call _printNumber

        cmp CX,0
        je _endProg

        mov DL,10
        mov AH,02h
        int 21h ; new line

        dec DI
        mov SI,0
        _pushSequence:
                mov AL,arr[DI]
                push AX
                dec DI
                inc SI
        loop _pushSequence

        _printSequence:
                pop CX
                mov CH,0
                call _printNumber
                mov DL,' '
                mov AH,02h
                int 21h

                dec SI
                cmp SI,0
        jne _printSequence

        _endProg:
                
mov AX,4C00h
int 21h
code ends
end start

