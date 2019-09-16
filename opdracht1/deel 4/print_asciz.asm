tekst:
    .asciz " Hello world, the ANSWER is 42! @[]`{}~\n"
.text
.global print_asciz
.global application
.align 2

application:
    push { lr }
    ldr r0, =tekst
    bl print_asciz
    pop { pc }

print_asciz:
   push { r5, lr }
   mov  r5, r0
printloop: 
   ldrb r0, [ r5 ]
   add  r0, r0, #0
   beq  printdone
   bl   changeCase
   bl   uart_put_char
   add  r5, r5, #1
   b    printloop
printdone: 
   pop  { r5, pc }

changeCase:
   push { r5, lr }
caseloop:
   cmp r0, #90
   bgt caseCapital
   cmp r0, #65
   blt casedone
   add r0, r0, #32
   b casedone
caseCapital:
   cmp r0, #97
   blt casedone
   cmp r0, #122
   bgt casedone
   sub r0, r0, #32
   b casedone
casedone:
   pop { r5, pc }