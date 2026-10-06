#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
char *line = NULL;
size_t len = 0;
ssize_t nread;
char *args[64];
while (1) {
printf("shellforge$ ");
fflush(stdout);
nread = getline(&line, &len, stdin);
if (nread == -1) break;
if (nread > 0 && line[nread - 1] == '\n') {
line[nread - 1] = '\0';
}
// --- WEEK 2 STRING SLICER ENGINE ---
int i = 0;
char *token = strtok(line, " \t");
while (token != NULL && i < 63) {
args[i] = token;
i++;
token = strtok(NULL, " \t");
}
args[i] = NULL; // Strict rule: List must end with NULL
if (i == 0) continue; // Skip empty inputs
if (strcmp(args[0], "exit") == 0) break;
// Print extracted pieces
printf("Command detected: %s (Total args: %d)\n", args[0], i - 1);
for (int j = 0; j < i; j++) {
printf(" -> args[%d]: %s\n", j, args[j]);

// Structural folder layout definition
typedef struct {
    char *args[64]; // arguments i.e no words in the line inputted by user
    int count;      // count of words
} Command;          // name of structure

// user defined function
// line the line of words inputted by user
// cmd is structure variable
void parse_command(char *line, Command *cmd) {
    cmd->count = 0;

    char *token = strtok(line, " \t");

    while (token != NULL && cmd->count < 63) {
        cmd->args[cmd->count] = token;
        cmd->count++;

        token = strtok(NULL, " \t");
    }

    cmd->args[cmd->count] = NULL;
}

int main(void) {
    char *line = NULL;
    size_t len = 0;
    Command cmd;

    while (1) {
        printf("shellforge$ ");
        fflush(stdout);

        if (getline(&line, &len, stdin) == -1)
            break;

        if (strlen(line) > 0 && line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        parse_command(line, &cmd);

        if (cmd.count == 0)
            continue;

        if (strcmp(cmd.args[0], "exit") == 0)
            break;

        printf("Structure Log -> command : %s | Arguments found: %d\n",
               cmd.args[0], cmd.count - 1);
    }

    free(line);

    return 0;
}
free(line);
return 0;
}
