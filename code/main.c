#include <header/menu.h>
#include <header/login_log.h>
#include <header/card_service.h>
#include <header/other_log.h>
#include <header/card_file.h>
#include <header/login_log_file.h>
#include <header/other_log_file.h>


int main() {
    printf("欢迎使用计费管理系统\n");
    code();

    int flag;
    //初始化链表
    initOptLog();
    initLoginLog();
    initCardList();

    do {
        outputMenu();
        switch ( opt ) {
            case '1':
                addCard();
                break;
            case '2':
                printCard();
                break;
            case '3':
                useComputer();
                break;
            case '4':
                exitComputer();
                break;
            case '5':
                charge();
                break;
            case '6':
                withdraw();
                break;
            case '7':
                searchAll();
                break;
            case '8':
                exitCard();
                break;
            case '9':
                changePwd();
                break;
            case 'r':
                reset();
                break;
            case '0':
                updateSaveAll();
                updateLog();
                updateOptLog();
                return 0;
            default:
                printf("请正确输入编码！\n");
        }
        printf("是否继续使用计费管理系统（1为继续其他为退出）：");
        scanf("%d", &flag);
    } while ( flag == 1 );

    //更新文件中的数据
    updateSaveAll();
    updateOptLog();

    return 0;
}	

