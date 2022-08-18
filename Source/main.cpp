#include "source.cpp"

int main(int argc, char *argv[]){
    if (strcmp(argv[1],"-a") == 0){
        switch (argc){
        case 6:
            command_2(argc,argv);
            break;
        case 5: 
            if (!isNumber(argv[3]))
                command_1(argc,argv);
            else
                command_3(argc, argv);
            break;
        default:
            break;
        }
    } else if (strcmp(argv[1],"-c") == 0) {
        switch (argc){
        case 5:
            command_4(argc,argv);
            break;
        case 6:
            command_5(argc,argv);
            break;
        default:
            break;
        }
    }
    return 0;
}