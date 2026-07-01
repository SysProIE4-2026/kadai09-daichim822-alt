/*
 *  myenv.c : env コマンドのクローン
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#ifdef __linux__
#include "myputenv.h"
#endif

int main(int argc, char *argv[]) {
    int i;
    int j;

    if (argc == 1){
        extern char **environ;
        for(i = 0; environ[i] != NULL; i++){
            printf("%s\n", environ[i]);
        }
        return 0;
    } 

    for(i = 1; i < argc; i++){
        if(strchr(argv[i], '=') != NULL){
            if(putenv(argv[i]) != 0){
                break;
            }
        } else {
            break;
        }
    }

    if(i < argc){
        execvp(argv[i], &argv[i]);
        perror("execvp");
        return 1;
    }

    


extern char **environ;
for(j = 0; environ[j] != NULL; j++){
    printf("%s\n", environ[j]);
}
}
/* 実行例

minatodaichi@MacBook-Air-MINATO kadai09-daichim822-alt % make
cc -D_GNU_SOURCE -Wall -std=c99 -o myenv myenv.c myputenv.c
minatodaichi@MacBook-Air-MINATO kadai09-daichim822-alt % ./myenv ls
Makefile        README.md       README.pdf      myenv           myenv.c         myputenv.c      myputenv.h
minatodaichi@MacBook-Air-MINATO kadai09-daichim822-alt % ./myenv LC_TIME=ja_JP.UTF-8 date
2026年 7月 1日 水曜日 09時53分23秒 JST
minatodaichi@MacBook-Air-MINATO kadai09-daichim822-alt % ./myenv LC_TIME=ja_JP.UTF-8 TZ=Cuba date
2026年 6月30日 火曜日 20時54分00秒 CDT
minatodaichi@MacBook-Air-MINATO kadai09-daichim822-alt % ./myenv LC_TIME=ja_JP.UTF-8 date +%Y-%m-%d
2026-07-01
minatodaichi@MacBook-Air-MINATO kadai09-daichim822-alt % ./myenv LC_TIME=ja_JP.UTF-8
OSLogRateLimit=64
MallocNanoZone=0
USER=minatodaichi
COMMAND_MODE=unix2003
__CFBundleIdentifier=com.microsoft.VSCode
PATH=/opt/homebrew/opt/openjdk/bin:/opt/homebrew/bin:/opt/homebrew/sbin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/opt/pmk/env/global/bin:/opt/homebrew/opt/openjdk/bin:/Users/minatodaichi/.vscode/extensions/vscjava.vscode-java-debug-0.59.0/bundled/scripts/noConfigScripts
LOGNAME=minatodaichi
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.fQQZCgpewS/Listeners
HOME=/Users/minatodaichi
SHELL=/bin/zsh
TMPDIR=/var/folders/g1/swj7kc1145s_n5jnmgq5zh2w0000gn/T/
__CF_USER_TEXT_ENCODING=0x1F5:0x1:0xE
XPC_SERVICE_NAME=0
XPC_FLAGS=0x0
SHLVL=1
PWD=/Users/minatodaichi/Desktop/SysPro/kadai09-daichim822-alt
OLDPWD=/Users/minatodaichi/Desktop/SysPro
LANG=C.UTF-8
HOMEBREW_PREFIX=/opt/homebrew
HOMEBREW_CELLAR=/opt/homebrew/Cellar
HOMEBREW_REPOSITORY=/opt/homebrew
INFOPATH=/opt/homebrew/share/info:/opt/homebrew/share/info:
TERM_PROGRAM=vscode
TERM_PROGRAM_VERSION=1.122.0
COLORTERM=truecolor
VSCODE_JDWP_ADAPTER_ENDPOINTS=/Users/minatodaichi/.vscode/extensions/vscjava.vscode-java-debug-0.59.0/.noConfigDebugAdapterEndpoints/endpoint-379f5187a3fdcacd.txt
VSCODE_JAVA_EXEC=/opt/homebrew/Cellar/openjdk/25.0.2/libexec/openjdk.jdk/Contents/Home/bin/java
GIT_ASKPASS=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass.sh
VSCODE_GIT_ASKPASS_NODE=/Applications/Visual Studio Code.app/Contents/Frameworks/Code Helper (Plugin).app/Contents/MacOS/Code Helper (Plugin)
VSCODE_GIT_ASKPASS_EXTRA_ARGS=
VSCODE_GIT_ASKPASS_MAIN=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass-main.js
VSCODE_GIT_IPC_HANDLE=/var/folders/g1/swj7kc1145s_n5jnmgq5zh2w0000gn/T/vscode-git-1a8e492b4a.sock
VSCODE_INJECTION=1
ZDOTDIR=/Users/minatodaichi
USER_ZDOTDIR=/Users/minatodaichi
TERM=xterm-256color
VSCODE_PROFILE_INITIALIZED=1
VSCODE_PYTHON_AUTOACTIVATE_GUARD=1
_=/Users/minatodaichi/Desktop/SysPro/kadai09-daichim822-alt/./myenv
LC_TIME=ja_JP.UTF-8
minatodaichi@MacBook-Air-MINATO kadai09-daichim822-alt % ./myenv AAA=BBB nonexistent_command
execvp: No such file or directory

*/
