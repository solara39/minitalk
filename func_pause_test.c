#define _POSIX_SOURCE
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <time.h>

void handler(int sig) {
    printf("シグナルを受信しました。\n");
}

int main() {
    signal(SIGINT, handler);
    printf("Ctrl+Cを押すとシグナルを送信します。\n");
    pause();
    printf("プログラムが再開しました。\n");

    return 0;
}
