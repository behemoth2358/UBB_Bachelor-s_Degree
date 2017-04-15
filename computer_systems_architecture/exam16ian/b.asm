
assume CS: code

public _printNumber
public _solve
extrn arr:byte
extrn len:word

code segment

_solve proc; returns in DI the ending position and in CX the number of elements
        push BP
        mov BP,SP
        IRP reg,<AX,BX,DX,SI>
                push reg
        endm

        mov SI,0
        mov DI,0
        mov CX,0
        mov BX,0

        _for:
                mov AL,arr[SI]
                cmp AL,0
                je _isSolution
                inc BX
                _getBack:
                inc SI
                cmp SI,len
        jbe _for
        jmp _endProg
        _isSolution:
                cmp BX,CX
                ja _updateSolution
                _getBack1:
                mov BX,0
        jmp _getBack
        
        _updateSolution:
                mov CX,BX
                mov DI,SI
        jmp _getBack1

        _endProg:
        IRP reg,<SI,DX,BX,AX>
                pop reg
        endm
        mov BP,SP
        pop BP
ret
_solve endp
        
_printNumber proc; CX - number to be printed
        push BP
        mov BP,SP
        IRP reg,<AX,BX,CX,DX,SI,DI>
                push reg
        endm

        mov SI,0
        _divNr:
                mov AX,CX
                mov DX,0
                mov BX,10
                div BX
                mov CX,AX
                add DL,'0'
                push DX
                inc SI
                cmp CX,0
        jne _divNr
        mov CX,SI
        _cout:
                pop DX
                mov AH,02h
                int 21h
        loop _cout
        
        IRP reg,<DI,SI,DX,CX,BX,AX>
                pop reg
        endm
        mov BP,SP
        pop BP
ret
_printNumber endp

code ends
end
