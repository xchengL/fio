#ifndef ARCH_RISCV_H
#define ARCH_RISCV_H

#define FIO_ARCH	(arch_riscv)

#define	nop		__asm__ __volatile__ ("nop")
#define FIO_RISCV_FENCE(p, s)	\
	__asm__ __volatile__ ("fence " #p "," #s : : : "memory")

#define read_barrier()	FIO_RISCV_FENCE(ir, ir)
#define write_barrier()	FIO_RISCV_FENCE(ow, ow)
#endif
