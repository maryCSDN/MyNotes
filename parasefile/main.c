#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>

char *mfgetline(char *s, int maxSize, FILE *stream, bool *flag);
int getClientDevInfo(char *filename);

int main()
{
    getClientDevInfo("D:\\marui\\Desktop\\clidev.txt");
    return 0;
}

int getClientDevInfo(char *filename)
{
    if (filename == NULL || filename[0] == '\0')
    {
        return -1;
    }

    FILE *fp = fopen(filename, "r");
    if (fp != NULL)
    {
        int index = 0;
        char buffer[1024] = {0};
        //int size = sizeof(buffer);
        int size = 4;
        bool flag = false;
        while (mfgetline(buffer, size, fp, &flag) != NULL)
        {
            if (!flag)
            {
                // 未读取整行数据
                printf("not read line\n");
                break;
            }

            printf("[%s]\n", buffer);
            memset(buffer, 0, size);
        }

        fclose(fp);
    }

    return -1;
}

char *mfgetline(char *s, int maxSize, FILE *stream, bool *flag)
{
    if (s == NULL || maxSize < 1 || stream == NULL || flag == NULL)
    {
        // 参数错误
        return NULL;
    }

    *flag = false;
    register int c;
    register char *cs = s;
    while (--maxSize > 0)
    {
        c = fgetc(stream);
        if (c == '\n' || c == EOF)
        {
            *flag = true;
            break;
        }

        *(cs++) = c;
    }

    *cs = '\0';
    return (c == EOF && cs == s) ? NULL : s;
}