#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <string.h>
#include "job.h"

/*
 * command syntax
 *     stat
 */
//��ʾ��Ϣ����
void usage()
{
   printf("Usage: stat\n");
}

int main(int argc, char *argv[])
{
   //��ҵ��������ṹ,
   struct jobcmd statcmd;
   int fd;

   if (argc != 1)
   {
      usage();
      return 1;
   }

   statcmd.type = STAT;
   statcmd.defpri = 0;
   statcmd.owner = getuid();
   statcmd.argnum = 0;
   strcpy(statcmd.data, "\0");

   if ((fd = open(FIFO, O_WRONLY)) < 0)
      error_sys("stat open fifo failed");

   if (write(fd, &statcmd, DATALEN) < 0)
      error_sys("stat write failed");

   close(fd);
   return 0;
}
