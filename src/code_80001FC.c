#include "global.h"

struct unkStruct_020100B0 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    s8 unk6;
    s8 unk7;
    u8 unk8[4];
    s32 unkc;
    u8 unk10[0x36];
    s16 unk46;
    s16 unk48;
};

extern struct unkStruct_020100B0 *gUnknown_020100B0;

extern void gUnknown_0827D400;
extern void gUnknown_0827D4B0;
extern void gUnknown_0827D82C;

extern void sub_800028C(void);
extern void sub_80002E0(void);
extern void sub_80002F4(void);
extern void sub_8000340(void);
extern void sub_80004BC(void);
extern void sub_80033CC(void);
extern void sub_8003444(void);
extern void sub_80049E0(void);
extern u32 sub_8004BE8(void);
extern void sub_8005D18(void);
extern void sub_80183D4(void *ptr1);
extern void sub_801B85C(u32 arg1, u32 arg2, void *ptr1, u32 arg4);

void sub_80001FC(u16 arg1) {
	gUnknown_020100B0->unk4 = arg1;
	gUnknown_020100B0->unk6 = 1;
}

void sub_800020C(void) {
	switch (gUnknown_020100B0->unk4) {
		case 0:
			sub_800028C();
			break;
		case 1:
			sub_80004BC();
			break;
		case 2:
			sub_8005D18();
			break;
		case 3:
			sub_80049E0();
			break;
		case 5:
			sub_8000340();
			break;
		case 6:
			sub_80002E0();
			break;
		case 7:
			sub_80002F4();
		case 4:
		case 8:
		case 9:
			break;
	}
}

void sub_8000280(void) {
	sub_80001FC(1);
}

void sub_800028C(void) {
	if (gUnknown_020100B0->unk6 != 0) {
		gUnknown_020100B0->unk6 = 0;
		gUnknown_020100B0->unk2 = 0;
		gUnknown_020100B0->unkc = 30;
	}
	if (gUnknown_020100B0->unk2 == 0) {
		if (--gUnknown_020100B0->unkc == 0) {
			gUnknown_020100B0->unk2 = 1;
			sub_80183D4(!sub_8004BE8() ? &gUnknown_0827D400 : &gUnknown_0827D4B0);
		}
	}
}

void sub_80002E0(void) {
}

void sub_80002E4(void) {
	gUnknown_020100B0->unk2 = 1;
}

void sub_80002F4(void) {
	if (gUnknown_020100B0->unk6 != 0) {
		gUnknown_020100B0->unk6 = 0;
		gUnknown_020100B0->unk2 = 0;
		sub_8003444();
	}
	if (gUnknown_020100B0->unk2 == 0) {
		sub_801B85C(gUnknown_020100B0->unk46, gUnknown_020100B0->unk48, &gUnknown_0827D82C, 0xD000);
		sub_80033CC();
	}
}
