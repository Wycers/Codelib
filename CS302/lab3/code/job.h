#ifndef JOB_H
#define JOB_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <signal.h>
#include <sys/types.h>

#define FIFO "/tmp/schedule.fifo"

#ifndef DEBUG
#define DEBUG
#endif

#undef DEBUG

#define BUFLEN 100
#define GLOBALFILE "screendump"
//ö����ҵ״̬�����������У����
enum jobstate
{
  READY,
  RUNNING,
  DONE
};
//ö���������ͣ����ӣ����ӣ���ǰ״̬��ѯ
enum cmdtype
{
  ENQ = -1,
  DEQ = -2,
  STAT = -3
};

/* this is data passed in fifo */
//��ҵ��������ṹ
struct jobcmd
{
  enum cmdtype type; //��ҵ��������
  int argnum;        //��������
  int owner;         //��ҵ��owner
  int defpri;        //Ĭ�����ȼ�
  char data[BUFLEN]; //��������
};

#define DATALEN sizeof(struct jobcmd)
#define error_sys printf

struct jobinfo
{
  int jid;             /* ��ҵid */
  int pid;             /* ����id */
  char **cmdarg;       /* ִ�е�������߲���the command & args to execute */
  int defpri;          /* Ĭ������Ȩ   default priority */
  int curpri;          /* ���ڵ�����Ȩ current priority */
  int ownerid;         /* ��ҵӵ����id the job owner id */
  int wait_time;       /* �ڵȴ������еȴ���ʱ��the time job in waitqueue */
  time_t create_time;  /* ������ҵ��ʱ��the time job create */
  int run_time;        /* ��ҵ���е�ʱ��the time job running */
  enum jobstate state; /* ��ҵ״̬job state */
};

struct waitqueue
{                         /* ˫������� double link list */
  struct waitqueue *next; //��һ���ȴ���ҵ
  struct jobinfo *job;    //��ǰ�ȴ���ҵ����Ϣ
};

void schedule();                                           //���Ⱥ���
void sig_handler(int sig, siginfo_t *info, void *notused); //�źŴ���
int allocjid();                                            //������ҵid
void do_enq(struct jobinfo *newjob, struct jobcmd enqcmd); //��Ӻ���
void do_deq(struct jobcmd deqcmd);                         //���Ӻ���
void do_stat();                                            //��ʾ��ҵ״̬
void updateall();                                          //����������ҵ��Ϣ
struct waitqueue *jobselect();                             //�ȴ�������ѡ����ҵ
void jobswitch();                                          //��ҵת��

#endif
