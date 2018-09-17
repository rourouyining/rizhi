#include<stdio.h>
#include"loopfile.h"

#define filepath "/var/log/loopfile.log"
pthread_t pf;
int run = 1;

int module_process(void *private, Fmap *event)
{
	Fmap *map = (Fmap *)private;

	fmap_put_str(map, event->s_ip, strlen(event->s_ip), event->s_mac, strlen(event->s_mac));
	fmap_put_str(map, event->s_ip, strlen(event->s_ip), event->s_user, strlen(event->s_user));
}

int module_exit(void **private)
{

	Fmap *map = (Fmap *)private;


	fmap_del(map);
	*private = NULL;
}

void *sleep_func(void *private)
{
	Fmap *event = (Fmap *)private;
	char *buf;
	int msize;
	int i;


	while(run) {
		for (i = 0; i < 30; i++) {
			sleep(1);

			if(!run)
				return NULL;
		}
		msize = event.size();
		buf = fmap_dumo(event, &msize);
		
		fd = open(filename, O_WRONLY);
		if(fd < 0)
			return 0;

		write(fd, buf, msize);

		free(buf);

		close(fd);
	}
}

int module_init(void **private)
{
	int fd;
	int ret;
	void *buf;
	struct stat statbuf;
	fd = open(filename, O_RDONLY|O_CREAT);
	if(fd < 0)
	{　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　
		return 0;
	}

	ret =  stat(filename, &statbuf);
	if(ret != 0)
	{
		return 0;
	}

	if(statbuf.st_size == 0)
	{
		*private = fmap_new();
		return 0;
	}


	buf = malloc(statbuf.st_size);
	read(fd, buf, statbuf.st_size);
	*private = fmap_load(buf, statbuf.st_size)
	
	pthread_create(pf, NULL, sleep_func, *private);

}　　　　　　

int main(int argc, const char *argv[])
{
	void *private = NULL;

	module_init(&private);

	return 0;
}
