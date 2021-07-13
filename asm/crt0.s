.include "asm/macro.inc"
.syntax unified

	ARM_FUNC_START Start
Start: @ 0x08000000
	b Init

.include "asm/rom_header.inc"

	ARM_FUNC_START Init
Init: @ 0x080000C0
	mov r0, #0x12
	msr cpsr_fc, r0
	ldr sp, _080000E8 @ =0x03007F80
	mov r0, #0x1f
	msr cpsr_fc, r0
	ldr sp, _080000EC @ =0x03007C00
	ldr r1, _080000F0 @ =0x0807ACB1
	mov lr, pc
	bx r1
	b Init

_080000E8: .4byte 0x03007F80
_080000EC: .4byte 0x03007C00
_080000F0: .4byte 0x0807ACB1
