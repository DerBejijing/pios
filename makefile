COMPILER = gcc
LINKER = ld
ASSEMBLER = nasm
COMPILER_FLAGS = -m32 -c -ffreestanding
ASSEMBLER_FLAGS = -f elf32
LINKER_FLAGS = -m elf_i386 -T src/link.ld
EMULATOR = qemu-system-i386
EMULATOR_FLAGS = -enable-kvm -kernel


OBJS = obj/kasm.o obj/kc.o obj/string.o obj/system.o obj/screen.o obj/pios.o obj/keyboard.o obj/menu.o obj/math.o
OUTPUT = pios/boot/kernel.bin


all: $(OBJS)
	@echo "Linking..."
	@mkdir -p pios
	@mkdir -p pios/boot
	$(LINKER) -o $(OUTPUT) $(OBJS)

	@echo "Building ISO"
	@rm -rf pios/boot/grub/
	@mkdir pios/boot/grub/
	@echo "set default=0" 					>> pios/boot/grub/grub.cfg
	@echo "set timeout=0" 					>> pios/boot/grub/grub.cfg
	@echo "menuentry \"PIOS\" {"	 		>> pios/boot/grub/grub.cfg
	@echo "multiboot /boot/kernel.bin"	 	>> pios/boot/grub/grub.cfg
	@echo "}" 								>> pios/boot/grub/grub.cfg

	grub-mkrescue -o pios.iso pios/



run: $(OBJS)
	@echo "Linking..."
	@mkdir -p pios
	@mkdir -p pios/boot
	$(LINKER) $(LINKER_FLAGS) -o $(OUTPUT) $(OBJS)
	@echo "Running..."
	$(EMULATOR) $(EMULATOR_FLAGS) $(OUTPUT)



obj/kasm.o:src/kernel.asm
	$(ASSEMBLER) $(ASSEMBLER_FLAGS) -o obj/kasm.o src/kernel.asm

obj/kc.o:src/kernel.c
	$(COMPILER) $(COMPILER_FLAGS) src/kernel.c -o obj/kc.o 

obj/string.o:src/string.c
	$(COMPILER) $(COMPILER_FLAGS) src/string.c -o obj/string.o

obj/system.o:src/system.c
	$(COMPILER) $(COMPILER_FLAGS) src/system.c -o obj/system.o

obj/screen.o:src/screen.c
	$(COMPILER) $(COMPILER_FLAGS) src/screen.c -o obj/screen.o

obj/pios.o:src/pios.c
	$(COMPILER) $(COMPILER_FLAGS) src/pios.c -o obj/pios.o

obj/keyboard.o:src/keyboard.c
	$(COMPILER) $(COMPILER_FLAGS) src/keyboard.c -o obj/keyboard.o

obj/menu.o:src/menu.c
	$(COMPILER) $(COMPILER_FLAGS) src/menu.c -o obj/menu.o

obj/math.o:src/math.c
	$(COMPILER) $(COMPILER_FLAGS) src/math.c -o obj/math.o
	

clean:
	@echo "Cleaning..."
	@rm -f obj/*.o
	@rm -rf pios