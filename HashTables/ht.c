#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *key;
    char *value;
    struct node *next;
} node;

node *list[26]; // 26 is the size of the alphabet
                // this hash table will store 26 linked lists
                // each linked list will store the nodes with the same
                // hash value that is the sum of the first two characters of the key

int hash(char *a)
{
    int l = (a[0] + a[1]) % 10;
    return l;
}

void insert(node *item)
{
    int i = hash(item->key);
    node *pos = list[i];

    if (pos == NULL)
    {
        list[i] = item;
        return;
    }
    while (pos->next != NULL)
    {
        pos = pos->next;
    }
    pos->next = item;
}

char *search(char *key)
{
    int i = hash(key);
    node *temp = list[i];
    int count = 0;
    while (temp != NULL)
    {
        if (strcmp(key, temp->key) == 0)
        {
            printf("count to find %s from index %d : %d \n", key, i, count);
            return temp->value;
        }

        temp = temp->next;
        count++;
    }
    printf("didnt find");
    return "notfound";
}

node *create_node(char *key, char *value)
{

    node *temp = (node *)malloc(sizeof(node));
    temp->key = key;
    temp->value = value;
    temp->next = NULL;
    return temp;
}
void freeAll()
{
    for (int i = 0; i < 26; i++)
    {
        node *temp = list[i];
        if (temp == NULL)
        {
            continue;
        }
        if (temp != NULL)
        {
            list[i] = list[i]->next;
            free(temp->key);
            free(temp->value);
            temp = list[i];
        }
        while (temp != NULL)
        {
            list[i] = list[i]->next;
            free(temp->key);
            free(temp->value);
            free(temp);
            temp = list[i];
        }
    }
    printf("Fully freed");
}

int main()
{

       int choice;
    char key[100], value[100];

    printf("1. Insert \n 2. Search \n 3. Exit \n");
    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
            // before inserting create a copy of key and value and insert that copy , use strcpy function for this
            // because

        case 1: // insert
            printf("Enter the key : ");
            scanf("%s", key);
            char *key_copy = (char *)malloc(sizeof(char) * strlen(key));
            strcpy(key_copy, key);
            getchar();
            printf("Enter the value : ");
            scanf("%s", value);
            char *value_copy = (char *)malloc(sizeof(char) * strlen(value));
            strcpy(value_copy, value);
            getchar();
            insert(create_node(key_copy, value_copy));
            break;

        case 2: // search
            printf("Enter the key : ");
            scanf("%s", key);
            getchar();
            printf("Value : %s \n", search(key));
            break;

        case 3:
            //  free all the created nodes
            // free all the created copies of key and value
            // free the list
            // free the hash table
            // exit
            freeAll();
            exit(0);
            break;

        default: // invalid choice
            printf("Invalid choice \n");
            break;
        }
    }
    return 0;
}
