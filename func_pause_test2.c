#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void handler(int sig) {
    printf("シグナルを受信しました。\n");
}

int main() {
    signal(SIGINT, handler);
    for (int i = 0; i < 5; i++) {
        printf("%d秒待機します。\n", i);
        sleep(1);
        pause();
    }
    printf("プログラムが終了しました。\n");

    return 0;
}
