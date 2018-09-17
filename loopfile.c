#include<stdio.h>
#include<famp.h>
#include"loopfile.h"

#define filepath "/var/log/loopfile.log"

int module_process(void *private, Fmap *event)
{
	int fp;
	u_int32_t num;
	int flag;
	const unsigned char *str = NULL;
	void *buf;
	fp = open(filepath, O_WRONLY|O_APPEND);
	if(fp < 0)
	{
		printf("open file faild!");
		return NULL;
	}
	event = fmap_load(*private, sizeof(*private));	
	
	num = fmap_get_int(event, event->s_ip, strlen(event->s_ip), flag);
	if(flag = 1)
	{
		str = fmap_get_str(event, event->s_ip, strlen(event->s_ip));
		if(str == NULL)
			return 0;
		flag = fmap_put_str(event, event->s_ip, strlen(event->s_ip), str, strlen(str));
		if(flag == 0)
		{
			return 0;
		}
	}
	else if(flag = 0)
	{
		flag = fmap_put_int(event, event->s_ip, strlen(event->s_ip), num);
		if(flag == -1)
		{
			return 0;
		}
	}
	buf = fmap_dump(event, num);
	if(buf != NULL)
	{
		wite(fd, buf, strlen(buf));
	}
	
}

int module_exit(void **private)
{
	free(*private);
}

int module_init(void **private)
{
	*private = malloc(sizeof(Famp));
}