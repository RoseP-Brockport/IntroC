#ifndef LOG_H
#define LOG_H

#define INITIAL_MAX (2)
#define MAX_LINE (255)

extern char **create_logs();
extern char **append_logs(char **logs, int *count, int *capacity, char *message);
extern void delete_last_log(char **logs, int *count);
extern void free_logs(char** logs, int count);

#endif 