#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
	int left = 0;
	int right = size - 1;
	while(left <= right){
		*count = *count + 1;
		int middle = (left + right)/2;
		if(mx_strcmp(arr[middle], s) > 0){
			right = middle - 1;
		}
		else if(mx_strcmp(arr[middle],s) < 0){
			left = middle + 1;
		}
		else
			return middle;
	}
	*count = 0;
	return -1;
}
