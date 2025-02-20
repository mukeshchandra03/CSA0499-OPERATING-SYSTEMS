#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int src = open("source.txt", O_RDONLY);
    int dest = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char buffer[1024];
    int n;

    while ((n = read(src, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, n);
    }

    close(src);
    close(dest);
    printf("File copied successfully!\n");

    return 0;
}
