#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHM_SIZE 1024 
key_t key = ftok("shmfile", 65); 
memory segment
one)
int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);if (shmid
== -1) {
perror("shmget");
exit(EXIT_FAILURE);
}
char *shm_ptr = (char*)shmat(shmid, NULL, 0);if
(shm_ptr == (char*)(-1)) {
perror("shmat");
exit(EXIT_FAILURE);
}
// Write data to the shared memory strcpy(shm_ptr,
"Hello, shared memory!");
// Detach the shared memory segment from the processif
(shmdt(shm_ptr) == -1) {
perror("shmdt");
exit(EXIT_FAILURE);
}
printf("Data written to shared memory: %s\n", shm_ptr);
// Optional: Remove the shared memory segmentif
(shmctl(shmid, IPC_RMID, NULL) == -1) {
perror("shmctl");
exit(EXIT_FAILURE);
}
return 0;
}

