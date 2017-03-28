org 0000h
mov 08Eh,#03h
mov DPTR,#800h
mov a,#5
movx @dptr,a
mov a,#0
movx a,@dptr
mov 090h,a
loop1: sjmp loop1
end