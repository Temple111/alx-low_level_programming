#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void display_magic(unsigned char *e_ident);
void display_class(unsigned char *e_ident);
void display_data(unsigned char *e_ident);
void display_version(unsigned char *e_ident);
void display_OSABI(unsigned char *e_ident);
void display_ABI(unsigned char *e_ident);
void display_type(unsigned int e_type, unsigned char *e_ident);
void display_entrypoint(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - checks if a file is an elf file
 * @e_ident: a pointer to a file containing elf magic numbers
 * Return: 0 for success
 */

void check_elf(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 &&
		e_ident[i] != 'E' &&
		e_ident[i] != 'L' &&
		e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * display_magic - displays the magic numbers of elf header file
 * @e_ident: pointer to file containing elf magic numbers
 * Return: 0 for success
 */

void display_magic(unsigned char *e_ident)
{
	int i;

	printf(" Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * display_class - displays the class of an elf header file
 * @e_ident: pointer to file containing elf class
 * Return: 0 for success
 */

void display_class(unsigned char *e_ident)
{
	printf(" Class:              ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * display_data - displays data of elf header
 * @e_ident: pointer to file containing elf data
 * Return: 0 for success
 */
void display_data(unsigned char *e_ident)
{
	printf(" Data:                    ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * display_version - prints the version of an elf header
 * @e_ident: pointer to file containing the elf version
 * Return: 0 for success
 */
void display_version(unsigned char *e_ident)
{
	printf(" Version:                 %d", e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * display_OSABI - displays the OS/ABI of an elf header file
 * @e_ident: pointer to file containing OS/ABI
 * Return:0 for success
 */
void display_OSABI(unsigned char *e_ident)
{
	printf(" OS/ABI:                 ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP - UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * display_ABI - displays ABI of an elf header
 * @e_ident: pointer to elf containing ABI version
 * Return: 0 successful
 */

void display_ABI(unsigned char *e_ident)
{
	printf(" ABI Version:               %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * display_type - display the type of an elf header
 * @e_type: elf type
 * @e_ident: pointer to file containing the elf class
 * Return: 0 for success
 */
void display_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * display_entrypoint - prints entry point of an elf file
 * @e_entry: address of elf entry point
 * @e_ident: pointer to a file containing elf class
 */
void display_entrypoint(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address:                   ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - closes an elf file
 * @elf: file descriptor of the elf file
 * Return: 0 for success
 */

void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int op, rd;

	op = open(argv[1], O_RDONLY);
	if (op == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(op);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	rd = read(op, header, sizeof(Elf64_Ehdr));
	if (rd == -1)
	{
		free(header);
		close_elf(op);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	display_magic(header->e_ident);
	display_class(header->e_ident);
	display_data(header->e_ident);
	display_version(header->e_ident);
	display_OSABI(header->e_ident);
	display_ABI(header->e_ident);
	display_type(header->e_type, header->e_ident);
	display_entrypoint(header->e_entry, header->e_ident);

	free(header);
	close_elf(op);
	return (0);
}
