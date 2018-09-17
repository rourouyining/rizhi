#ifndef __LOOPFILE_H__
#define __LOOPFILE_H__

#define filepath "/var/log/loopfile.log"

int module_process(void *private, Fmap *event);
int module_exit(void **private);
int module_init(void **private);

#endif __LOOPFILE_H__