#include <stdio.h> // Connecting libraries
#include <locale.h>
#include <string.h>

// Function prototypes
int mod_1();
int mod_3();

int main() {
    setlocale(LC_ALL, "Rus"); // Setting the locale to Russian
    int click;
    char men[10] = "МЕНЮ"; // Menu title
    printf("\t%55s\n", men); // Printing the menu title with formatting
    printf("Нажмите 1 для запуска программы | ");
    printf("Нажмите 2 для выхода из программы | ");
    puts("Нажмите 3 для ознакомления с программой");
    scanf("%d", &click); // Reading user input

    // Handling user input based on the chosen option
    if (click == 1) {
        mod_1(); // Call function for option 1
    }
    if (click == 2) {
        printf("До новых встреч !");
        return 0; // Exit program for option 2
    }
    if (click == 3) {
        mod_3(); // Call function for option 3
    }
    if (click != 1 && click != 2 && click != 3) {
        printf("Ошибка, введи другое число !"); // Handling invalid input
    }
}

// Function to replace words in a file
int mod_1() {
    char usd[50][50]; // Array to store words from the file
    char search[10]; // The word to search for
    char first[10];

    // Prompt user for the words to search and replace
    puts("Привет, пользователь!\n"
         "Эта программа позволяет изменить некоторое количество слов в исходном файле read.txt\n"
         "Для начала проверь наличие текста в файле, а после:\n"
         "Введи первое слово которое ты хочешь заменить и, если оно окажется в первой строке, мы его заменим");
    scanf("%s", first);

    puts("Отлично! Теперь введи слово, которое хочешь видеть вместо предыдущего");
    char replace[10]; // The word to replace with
    char second[10];
    scanf("%s", second);

    // Informing the user to check the final result in the file final.txt
    printf("Ну вот, теперь открой файл final.txt и посмотри результат\n"
           "Если он тебе не очень понравился, можешь попробовать изменить заменяемое слово\n");

    char string[500]; // Temporary string to hold each line of the file

    int n = 0, m = -1; // Counters
    int str = -1;
    int j = 0, i = 0;

    snprintf(search, 10, "%s", first); // Copying the search and replace words
    snprintf(replace, 10, "%s", second);

    // Opening the input and output files
    FILE *file = fopen("/Users/nikita/Documents/CLion/Kurs/read.txt", "r");
    FILE *file1 = fopen("/Users/nikita/Documents/CLion/Kurs/final.txt", "w");

    // Reading lines from the input file
    while (!feof(file)) {
        if (fgets(string, 500, file) != NULL) {
            str++;
            n = 0;
            m = -1;

            // Extracting words from the line
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

            // Writing the final text to the output file
            for (i = 0; i < n + 1; i++) {
                if (strcmp(usd[i], search) == 0 && str == 0) {
                    j = 2;
                }
                if (strcmp(usd[i], search) == 0 && j == 2) {
                    if (i != n) {
                        fprintf(file1, "%s ", replace);
                    } else {
                        fprintf(file1, "%s", replace);
                    }
                } else {
                    if (i != n) {
                        fprintf(file1, "%s ", usd[i]);
                    } else {
                        fprintf(file1, "%s", usd[i]);
                    }
                }
            }
        } else {
            perror("Ошибка ! Текст не найден");
        }
    }

    // Closing files
    fclose(file);
    fclose(file1);

    // Recursive call to the main function
    main();
}

// Function to display a manual about the program
int mod_3() {
    puts("Привет !");
    printf("Эта программа позволяет изменить некоторое количество слов в исходном файле read.txt\n"
           "В этом файле содержится небольшое количество текста, который, в свою очередь, будет пересобран в final.txt\n"
           "Пользователь должен ввести слово, которое он хочет заменить во всём тексте\n"
           "Если оно содержится в первой строке этого текста, то указанное слово будет заменено на другое,"
           "введённое следом\n"
           "Если же такое слово не было найдено, будет возвращён исходный текст\n"
           "А теперь, когда ты ознакомился с программой, запусти и посмотри на неё в действии !\n");

    // Recursive call to the main function
    main();
}
