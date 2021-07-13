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
	ldr sp, =gUnknown_03007F80
	mov r0, #0x1f
	msr cpsr_fc, r0
	ldr sp, =gUnknown_03007C00
	ldr r1, =AgbMain
	mov lr, pc
	bx r1
	b Init
