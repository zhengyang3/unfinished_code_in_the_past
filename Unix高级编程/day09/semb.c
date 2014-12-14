#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<error.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
union semun {
      int              val;    /* Value for SETVAL */
      struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
      unsigned short  *array;  /* Array for GETALL, SETALL */
      struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux specific) */
        };
int main()
{
	key_t key;
	int semid;
	union semun v;
	int r;
	struct sembuf op[2];
	key=ftok(".",11);
		if(key==-1)printf("ftok error:%m\n"),exit(-1);
	semid=semget(key,1,0);
		if(semid==-1)printf("semget error:%m\n"),exit(-1);
	printf("semid:%d\n",semid);
	op[0].sem_num=0;
	op[0].sem_op=1;
	op[0].sem_flg=0;
	
	op[1].sem_num=0;
	op[1].sem_op=1;
	op[1].sem_flg=0;
	while(1)
	{
		r=semop(semid,op,2);
		sleep(2);
	}
	
	return 0;
}














