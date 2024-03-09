#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arr_string {
	char** arr;
	int size;
} arr_string;

extern void Test(arr_string(*pattackList)(arr_string, int, int));

char* strdupX(const char* src)
{
	char* dst = (char*)malloc(strlen(src) + 1);
	if (dst == NULL) return NULL;
	strcpy(dst, src);
	return dst;
}

bool kqSoSanh(char* a, char* b, int m)
{
	int c, d;
	sscanf_s(a, "%d", &c);//string -> int
	sscanf_s(b, "%d", &d);//string -> int
	if (abs(c - d) <= (m * 100))
	{
		return true;
	}
	return false;
}

int compareStrings(const void* a, const void* b) {
	const char** str1 = (const char**)a;
	const char** str2 = (const char**)b;
	return strcmp(*str1, *str2);
}


arr_string attackList(arr_string accessList, int m, int n)
{
	arr_string expected;
	expected.arr = NULL;
	expected.size = 0;
	const char delim[] = " ";

	for (int i = 0; i < accessList.size; i++)
	{
		int carry = 0;
		char* access = strdupX(accessList.arr[i]);
		char* timeacc = strtok(access, delim);
		char* username = strtok(NULL, delim);
		//kiem tra co thuoc danh sach expec (tan cong) hay khong
		for (int j = 0; j < expected.size; j++)
		{
			
			if (strcmp(username, expected.arr[j]) == 0)
			{
				carry = 1;
				break;
			}
		}
		int cnt = 0;
		for (int u = i; u < accessList.size; u++)
		{
			char* access2 = strdupX(accessList.arr[u]);
			char* timeacc2 = strtok(access2, delim);
			char* username2 = strtok(NULL, delim);
			
			if (!(carry))
			{
				bool kq = kqSoSanh(timeacc, timeacc2,m);//xem có trong thời gian m phut không 
				if ((strcmp(username2, username) == 0) && kq)
				{
					cnt++;
					if (cnt >= n)
					{
						//dua username vao expected
						char** new_arr = (char**)realloc(expected.arr, (expected.size + 1) * sizeof(char*));
						if (new_arr == NULL) {
							printf("lỗi");
						}
						else {
							expected.arr = new_arr;
						}
						expected.arr[expected.size] = _strdup(username2);
						expected.size++;
						break;
					}
				}
			}
			free(access2);
		}
		free(access);
	}
	qsort(expected.arr, expected.size, sizeof(char*), compareStrings);
	return expected;
}

int main()
{
	Test(attackList);

	return 0;
}
