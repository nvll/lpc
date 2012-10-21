OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)

ENTRY(cortex_m3_start)
SECTIONS {
	. = %CM3_ROMBASE%;
	.text.vector_table : {
		KEEP (*(.text.vector_table))
	}
	.text.vector_table_platform : {
		KEEP (*(.text.vector_table_platform))
	}

	.text : {
		*(.text .text.*)
	}
	.rodata : {
		*(.rodata .rodata.*)
	}
	. = ALIGN(4);
	__data_rom = .;
	. = %CM3_MEMBASE%;
	__data_ram = .;
	.data : AT ( __data_rom ) {
			*(.data .data.*)
	}
	. = ALIGN(4);
	__data_end = .;
	.bss : {*(.bss .bss.*)}
	.debug_info : {*(.debug_line)}
}
