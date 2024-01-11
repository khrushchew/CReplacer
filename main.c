#include <stdio.h> // Connecting libraries
#include <locale.h>
#include <string.h>

int mod_1();
int mod_3();

int main(){
    setlocale(LC_ALL, "Rus"); // Сonnecting the Russian language
    int click;
    char men[10] = "МЕНЮ";
    printf("\t%55s\n", men);
    printf("Нажмите 1 для запуска программы | ");
    printf("Нажмите 2 для выхода из программы | ");
    puts("Нажмите 3 для ознакомления с программой");
    scanf("%d", &click);
    if (click == 1 ){
        mod_1();
    }
    if(click == 2){
        printf("До новых встреч !");
        return 0;
    }
    if (click == 3){
        mod_3();
    }
    if (click != 1 && click != 2 && click != 3){
        printf("Ошибка, введи другое число !");
    }
}

int mod_1(){
    char usd[50][50]; // Massive of used strings

    puts("Привет, пользователь!\n"
         "Эта программа позволяет изменить некоторое количесво слов в исходном файле read.txt\n"
         "Для начала проверь наличие текста в файле, а после:\n"
         "Введи первое слово которое ты хочешь заменить и, если оно окажется в первой строке, мы его заменим");
    char search[10]; // The search word
    char first[10];
    scanf("%s", first);


    puts("Отлично! Теперь введи слово, которое хочешь видеть вместо предыдущего");
    char replace[10]; // Replacement word
    char second[10];
    scanf("%s", second);

    printf("Ну вот, теперь открой файл final.txt и посмотри результат\n"
           "Если он тебе не очень понравился, можешь попробовать изменить заменяемое слово\n");

    char string[500]; // Our first/final string

    int n = 0, m = -1; // Counters
    int str = -1;
    int j = 0, i = 0;

    snprintf(search, 10, "%s", first); // Scanning first and second words
    snprintf(replace, 10, "%s", second);

    FILE *file = fopen("/Users/nikita/Documents/CLion/Kurs/read.txt", "r"); // Opening files
    FILE *file1 = fopen("/Users/nikita/Documents/CLion/Kurs/final.txt", "w");

    while (!feof(file)) { // Scanning, writing and reading files
        if (fgets(string, 500, file) != NULL) {
            str++;
            n = 0;
            m = -1;
            for (i = 0; i < strlen(string); i++) {
                if (string[i] == ' ') {
                    m++;
                    usd[n][m] = '\0';
                    m = -1;
                    n++;
                } else {
                    m++;
                    usd[n][m] = string[i];
                }
            }
            m++;
            usd[n][m] = '\0';
            for (i = 0; i < n + 1; i++) { // Writing final text
                if (strcmp(usd[i], search) == 0 && str == 0){
                    j = 2;
                }
                if (strcmp(usd[i], search) == 0 && j == 2){
                    if (i != n){ // checking spaces
                        fprintf(file1, "%s ", replace);
                    }
                    else {
                        fprintf(file1, "%s", replace);
                    }
                }
                else{
                    if (i != n){ // checking spaces
                        fprintf(file1, "%s ", usd[i]);
                    }
                    else {
                        fprintf(file1, "%s", usd[i]);
                    }
                }
            }
        }
        else {
            perror("Ошибка ! Текст не найден");
        }
    }
    fclose(file); // Closing files
    fclose(file1);
    main();
}

int mod_3(){ // manual
    puts("Привет !");
    printf("Эта программа позволяет изменить некоторое количесво слов в исходном файле read.txt\n"
           "В этом файле содержится небольшое количество текста, который, в свою очередь, будет пересобран в final.txt\n"
           "Пользователь должен ввести слово, которое он хочет заменить во всём тексте\n"
           "Если оно содержится в первой строке этого текста, то указанное слово будет заменено на другое,"
           "введённое следом\n"
           "Если же такое слово не было найдено, будет возвращён исходный текст\n"
           "А теперь, когда ты ознакомился с программой, запусти и посмотри на неё в действии !\n");
    main();
}