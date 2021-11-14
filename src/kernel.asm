bits 		32
section 	.text
	align 	4
	dd 0x1badb002
	dd 0x00
	dd - (0x1badb002+0x00)

global start
extern kmain						; this is in the c code kernel
start:
	cli						; clear the interrupts
	call kmain				; continue execution from kmain in c code
	hlt						; halt the cpu
							; pause it from from executing
