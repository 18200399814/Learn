#include <stdio.h>
#include <assert.h>

typedef int data_t;

template <typename T>
static void swap(T &x,T &y);

static void display(const data_t a[],const int size);
static bool inputNumber(data_t *n);

void bubbleSort(data_t a[],const int size);
void selectSort(data_t a[],const int size);

int binarySearch(const data_t a[],const int size,const data_t n);

int main()
{
	data_t num = 0;
	int index = -1,size = 0;
	int a[]={5,4,8,1,2,7,9,0,6,3};
	
	size = sizeof(a)/sizeof(a[0]);
	display(a,size);

#if 0
	bubbleSort(a,size);
#else
	selectSort(a,size);
#endif
	display(a,size);
	
	if(!inputNumber(&num)){
		printf("����Ҫ���ҵ���ʧ��\n");
		return -1;
	}
	printf("��Ҫ���ҵ����ǣ�%d\n",num);
	
	index = binarySearch(a,size,num);
	if(index == -1){
		printf("%dû���ҵ�\n",num);
	}else{
		printf("%d�ҵ���index=%d\n",index);
	}
	
	return 0;
}

template <typename T>
static void swap(T &x,T &y)
{
	T temp;
	temp = x;
	x = y;
	y = temp;
}

static void display(const data_t a[],const int size)
{
	assert(a != NULL && size > 0);
	
	for(int i=0;i<size;++i){
		printf("%d ",*(a+i));
	}
	printf("\n");
}

static bool inputNumber(data_t *n)
{
	assert(n != NULL);
	
	printf("������0~9֮�������\n");
	scanf("%d",n);
	if(*n >= 0 && *n <= 9){
		printf("����������ǣ�%d\n",*n);
		return true;
	}else{
		while(getchar() != 'q'){
			printf("����������0~9֮�������\n");
			scanf("%d",n);
			if(*n >= 0 && *n <= 9){
				printf("����������ǣ�%d\n",*n);
				return true;
			}else{
				printf("��������ĸ�������룬��q�˳�\n");
				getchar();
			}
		}
	}
	
	return false;
}

void bubbleSort(data_t a[],const int size)
{
	assert(a != NULL && size > 0);
	
	for(int i=0;i<size-1;++i){
		for(int j=0;j<size-i-1;++j){
			if(a[j] > a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}

void selectSort(data_t a[],const int size)
{
	assert(a != NULL && size > 0);	
	
	int maxIndex;
	for(int i=0;i<size-1;++i){
		maxIndex = 0;
		for(int j=1;j<size-i;++j){
			if(a[maxIndex] < a[j]){
				maxIndex = j;
			}
		}
		swap(a[maxIndex],a[size-i-1]);
	}
}

int binarySearch(const data_t a[],const int size,const data_t n)
{
	assert(a != NULL && size > 0);
	
	int low = 0,mid = 0;
	int hig = size-1; 
	while(low <= hig){
		mid = (low+hig)/2;
		if(a[mid] == n){
			return mid;
		}else if(a[mid] < n){
			low = mid +1;
		}else{
			hig = mid -1;
		}
	}
	
	return -1;
}
