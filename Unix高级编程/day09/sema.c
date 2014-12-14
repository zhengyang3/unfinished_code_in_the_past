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
	
	int semid=0;
	key_t key;
	int r=0;
	struct sembuf op[1];
	key=ftok(".",11);
		if(key==-1)printf("ftok error:%m\n"),exit(-1);
	//1：创建或者得到信号量  semget
	semid=semget(key,1,IPC_CREAT|IPC_EXCL|0666);
		if(semid==-1)printf("semget error:%m\n"),exit(-1);
	printf("semid:%d\n",semid);
	//2：初始化信号量中指定一标的值   semctl
	union semun v;
	v.val=5;
	r==semctl(semid,0,SETVAL,v);
		if(r==-1)printf("init fail...\n"),exit(-1);
	//3：根据信号量里面的值来决定阻塞还是解除阻塞   semop
		//先定义操作
	op[0].sem_num=0;//信号量的下标
	op[0].sem_op=-1;//信号量的操作单位与类型
	op[0].sem_flg=0;
	while(1)
	{
		semop(semid,op,1);
		sleep(2);
		printf("非阻塞状态！\n");
	}
	
	
	//4：删除信号量	semctl
	semctl(semid,0,IPC_RMID);
	return 0;
}

















