; blink_asm_hfo.asm
;
; PB0 (digital2)(0v) -> LED -> 220 ohm -> 5V
; PD2 (digital8)(5v) -> Button -> GND 

.nolist
.include <m328Pdef.inc>
.list

; Declarations
.def        temp = r16      ; designate register r16 as working register
.def        overflows = r17


.org    0x0000              ; memory (PC) location of reset handler
rjmp    Reset               ; jmp costs 2 clock cycles, rjmp only 1
                            ; so unless you need to jump more than 8k bytes
                            ; you only nead rjmp
.org    0x0020              ; memory location of Timer0 overflow handler
rjmp    overflow_handler    ; go here if a Timer0 overflow interrupt occurs 


; ===========================

Reset:
    ldi     temp, 0b00000101
    out     TCCR0B, temp    ; set the Clock Selector Bits CS00, CS01, CS02 to 101
                            ; this puts Timer Counter0, TCNT0 in to FCPU/1024 mode
                            ; so it ticks at the CPU freq/1024
    
    ldi     temp, 0b00000001
    sts     TIMSK0, temp    ; set the Timer Overflow Interrupt Enable (TOIE0) bit
                            ; of the Timer Interrupt Mask Re/prgister (TIMSK0)

    sei                     ; enable global interrupts

    clr     temp
    out     TCNT0, temp     ; initialize the Timer/Counter to 0

    sbi     DDRD, 4         ; set PD4 to OUTPUT

; ===========================
; Main progam body

blink:
    sbi     PORTD, 4        ; Turn on LED on PD4
    rcall   delay           ; delay will be 1/2 second
    cbi     PORTD, 4        ; Turn off LED on PD4
    rcall   delay
    rjmp    blink           ; loop back

delay:
    clr     overflows       ; set overflows to 0
    sec_count:
        cpi overflows, 30   ; compare number of overflows and 30
    brne sec_count          ; branch back to sec_count if not equal
    ret                     ; if 30 overflows have occured return to blink

overflow_handler:
    inc overflows           ; add 1 to the overflows variable
    cpi overflows, 61       ; compare with 61
    brne PC+2               ; Program Counter + 2 (skip next line) if not equal
    clr overflows           ; if 61 overflows occured reset the counter to zero
    reti                    ; return from interrupt
