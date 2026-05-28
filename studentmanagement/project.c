#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct{
    char name[30];
    char id[20];
    double prf, mae;
    double gpa;
} Manage;

void caculategpa (Manage *s){
    double average = (s->prf + s->mae) / 2;
    s->gpa = average * 0.4;
}

void addStudent(Manage student[], int  *count){
    if (*count > 100){
        printf("Danh sách đã đầy");
        return;
    }
    printf("Nhập mã số sinh viên của sinh viên %d: ", *count + 1);
    scanf("%s", student[*count].id);
    while( getchar() != '\n');
    printf("Nhập họ và tên của sinh viên này: ");
    fgets(student[*count].name, sizeof(student[*count].name), stdin);
    student[*count].name[strcspn(student[*count].name, "\n")] = 0;
    printf("Nhập điểm môn PRF192 và MAE101 của sinh viên này: ");
    scanf("%lf %lf", &student[*count].prf, &student[*count].mae);

    caculategpa(&student[*count]);
    (*count) ++;
    printf("Đã thêm thành công!");
}

void searchStudent(Manage student[], int count){   
    char key[20];
    int flag = 0;
    printf("Nhập mã số sinh viên cần tìm: ");
    scanf("%s", key);
    for (int i = 0; i < count; i++){
        if (strcasecmp(student[i].id, key) == 0){
            printf("%s - %s - GPA: %.2lf", student[i].name, student[i].id, student[i].gpa);
            flag = 1;
        }
    }
    if (!flag){
        printf("Không tìm thấy sinh viên nào!");
    }
}

void displayList(Manage student[], int count){
    if (count == 0){
        printf("Danh sách trống!");
    }
    printf("\n%-25s %-25s %-5s\n", "NAME", "MSSV", "GPA");
    for (int i = 0; i < count; i++){
        printf("%-25s %-25s %.2lf\n", student[i].name, student[i].id, student[i].gpa);
    }
}

void sortList(Manage student[], int count){
    Manage temp; 
    for (int i = 0; i < count; i++){
        for (int j = i + 1; j < count ; j++){
            if (student[i].gpa < student[j].gpa){
                temp = student[i];
                student[i] = student[j];
                student[j] = temp;
            }
        }
    }
    printf("Đã sắp xếp theo GPA thứ tự giảm dần!");
}

void loadFromFile(Manage student[], int *count){
    FILE *f = fopen("students.txt", "r");

    if (f == NULL){
        printf("Lưu ý: Chưa có dữ liệu cũ (file không tồn tại). \n");
        return;
    }
    *count = 0;

    while (fscanf(f, " %[^|]|%[^|]|%lf|%lf|%lf\n", student[*count].id, student[*count].name, &student[*count].prf, &student[*count].mae, &student[*count].gpa) != EOF){
        (*count) ++;
    }

}

void savetoFile(Manage student[], int *count){
    FILE *f = fopen("student.txt", "w" );
    if (f == NULL){
        printf("Lỗi: Không thể tạo file lưu trữ\n");
        return;
    }
    for (int i = 0; i < *count; i++){
        fprintf(f, "%s|%s|%.2lf|%.2lf|%.2lf|%.2lf\n", student[i].id, student[i].name, student[i].prf, student[i].prf, student[i].mae, student[i].gpa);
    }
    fclose(f);
    printf("Dữ liệu đã được lưu vào students.txt thành công!\n");

}
int main() {
    Manage student[100];
    int count = 0;
    int choice;
    do {
        printf("\n========= STUDENT MANAGEMENT =========\n");
        printf("1. Adding students\n");
        printf("2. Show list of all students\n");
        printf("3. Searching students by ID\n");
        printf("4. Sort students by GPA\n");
        printf("5. Exit\n");
        printf("======================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(student, &count);
                break;
            case 2:
                displayList(student, count);
                break;
            case 3:
                searchStudent(student, count);
                break;
            case 4:
                sortList(student, count);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}