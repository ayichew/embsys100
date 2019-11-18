/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __QUEUE_H__
#define __QUEUE_H__

void queue_init(void);
//int queue_put(char data);
//int queue_get(char* data);
int queue_put(int data);
int queue_get(int* data);

#endif
