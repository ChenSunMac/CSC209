struct {
    char name [NAME_LEN + 1];
    int grade;
    int age;
} student1, student2;


struct {
    char name [NAME_LEN + 1];
    int grade;
    int age;
} student1 = {"JoJo", 1, 18}, student2 = {"Jacky", 2, 10};


struct student{
    char name [NAME_LEN + 1];
    int grade;
    int age;
};

//Declare
struct student student1, student2;


typedef struct {
    char name [NAME_LEN + 1];
    int grade;
    int age;
} Student;

//Declare
Student student1, student2;

char *p = malloc(4);
...
free(p);
...
strcpy(p, "abc");  

struct node
{
    int value;
    struct node *next;
};







char *concat (char *s1, char *s2)
{
    char *result;
    result = malloc(strlen(s1) + str(s2) + 1);
    strcpy(result, s1);
    strcpy(result, s2);
    return result;
}


 p = malloc (...)
 q = malloc (...)
 p = q