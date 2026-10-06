char *line = NULL;
size_t len = 0;
ssize_t nread;
char *args[64];
while (1) {
printf("shellforge$ ");
fflush(stdout); // Force prompt to print immediately without buffer delays
fflush(stdout);
nread = getline(&line, &len, stdin);
if (nread == -1) { // Detects Ctrl-D (End of File)
printf("\nExiting cleanly...\n");
break;
}
// Strip the trailing newline character caused by pressing Enter
if (nread == -1) break;
if (nread > 0 && line[nread - 1] == '\n') {
line[nread - 1] = '\0';
}
// Exit trap condition
if (strcmp(line, "exit") == 0) {
break;
// --- WEEK 2 STRING SLICER ENGINE ---
int i = 0;
char *token = strtok(line, " \t");
while (token != NULL && i < 63) {
args[i] = token;
i++;
token = strtok(NULL, " \t");
}
if (strlen(line) > 0) {
printf("You typed: %s\n", line);
args[i] = NULL; // Strict rule: List must end with NULL
if (i == 0) continue; // Skip empty inputs
if (strcmp(args[0], "exit") == 0) break;
// Print extracted pieces
printf("Command detected: %s (Total args: %d)\n", args[0], i - 1);
for (int j = 0; j < i; j++) {
printf(" -> args[%d]: %s\n", j, args[j]);
}
}
free(line); // Prevent memory leaks
free(line);
return 0;
}
}
