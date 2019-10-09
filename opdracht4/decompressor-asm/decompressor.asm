.bss
buffer:
    .skip 40
.text
.align 2
.global application
.global uart_put_char

application:
    push { lr }
    ldr  r0, =compressed
    ldr  r1, =buffer
    bl   loop_asciz
    pop  { pc }

loop_asciz:
    push { r5, r6, lr }
    mov  r5, r0
    mov  r6, r1
charloop:
    ldrb r0, [r6, #2]
    cmp  r0, #'@'
    beq  decompress
    ldrb r0, [ r5 ]
    add  r0, r0, #0
    beq  ascizdone
    bl   bufferstart
    add  r5, r5, #1
    b    charloop
ascizdone: 
    bl   bufferrefresh
    pop  { r5, r6, pc }

decompress:
    push { r4, r5, r6, r7 }
    ldr  r5, =buffer  //bufferadres
    ldrb r6, [r5,#1]  //offset
    sub  r6, #'0'     //offset -0 (actual offset)
    add  r6, #3       //offset met aanpassing voor 3 compress karakters
    ldrb r7, [r5]     //aantal te vervangen
    sub  r7, #'0'
    mov  r3, #0       //aantal extra verplaatste karakters
    ldrb r0, [r5, r6]
    strb r0, [r5, #2]
    sub  r7, #1
    sub  r6, #1
    ldrb r0, [r5, r6]
    strb r0, [r5, #1]
    sub  r7, #1
    sub  r6, #1
    ldrb r0, [r5, r6]
    strb r0, [r5]
    sub  r7, #1
    sub  r6, #1
    add  r7, #0
    bgt  decompressloop
    b    decompressend
decompressloop:
    add  r7, r7, #0
    beq  decompressend
    add  r4, r6, r3
    ldrb r0, [r5, r4]
    bl   bufferstart
    sub  r7, #1
    sub  r6, #1
    add  r3, #1
    b    decompressloop
decompressend:
    pop  { r4, r5, r6, r7 }
    b    charloop

bufferstart:
    push {r5, r6, lr}
    mov  r6, r0
    ldr  r5, =buffer
    mov  r1, #40
bufferloop:
    cmp  r1, #40
    beq  bufferpop 
    add  r1, r1, #0
    beq  bufferpush
    sub  r1, r1, #1
    ldrb r0, [ r5, r1 ]
    add  r1, r1, #1
    strb r0, [ r5, r1 ]   
    sub  r1, r1, #1
    b bufferloop
bufferpush:
    strb r6, [ r5, r1 ]
    b bufferend
bufferpop:
    sub  r1, #1
    ldrb r0, [ r5, r1 ]
    cmp  r0, #'!'
    beq  endlpop
    push { r1 }
    bl   uart_put_char
    pop  { r1 }
    b    bufferloop
endlpop:
    mov  r0, #'\n'
    push {r1}
    bl   uart_put_char
    pop  {r1}
    b    bufferloop
bufferend:
    pop  { r5, r6, pc }



bufferrefresh:
    push {r5, lr}
    mov  r5, #40
buffprintloop:
    add  r5, #0
    beq  buffprintdone
    mov  r0, #0
    bl   bufferstart
    sub  r5, r5, #1
    b buffprintloop
buffprintdone:
    pop  { r5, pc }