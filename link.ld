OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)

ENTRY(_start)
SECTIONS {
	. = 0;
	.text.vector_table : {
		KEEP (*(.text.vector_table))
	}

	.text : {
		*(.text .text.*)
	}
	.rodata : {
		*(.rodata .rodata.*)
	}
	. = ALIGN(4);
	__data_rom = .;
	. = 0x20000000;
	__data_ram = .;
	.data : AT ( __data_rom ) {
			*(.data .data.*)
	}
	. = ALIGN(4);
	__data_end = .;
	.bss : {*(.bss .bss.*)}
}
