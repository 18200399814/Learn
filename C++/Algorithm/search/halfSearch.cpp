#include <stdio.h>
#include <assert.h>

typedef int data_t;

template <typename T>
static void swap(T &x,T&y);

static void display(const data_t a[],const int size);
static bool inputNumber(data_t *n);

void selectSort(data_t a[],const int size);
void bubbleSort(data_t a[],const int size);
int halfSearch(const data_t a[],const int low,const int hig,const data_t n);

int main()
{
	data_t num = 0;
	int size,index = -1;
	data_t a[] = {5,14,8,15,2,9,11,0,6,7};
	
	size = sizeof(a)/sizeof(a[0]);
	display(a,size);
	
	selectSort(a,size);
	display(a,size);
	
	if(!inputNumber(&num)){
		printf("�����������Ч\n");
		return -1;
	}
	printf("����������ǣ�%d\n",num);
	
	index = halfSearch(a,0,size-1,num);
	if(index == -1){
		printf("%dû���ҵ�\n",num);
	}else{
		printf("%d�ҵ���index=%d\n",num,index);
	}
	
	return 0;
}

template <typename T>
static void swap(T &x,T&y)
{
	T temp;
	temp = x;
	x = y;
	y = temp;
}

static void display(const data_t a[],const int size)
{
	assert(a != NULL && size >0);
	
	for(int i=0;i<size;++i){
		printf("%d ",a[i]);
	}
	printf("\n");
}

static bool inputNumber(data_t *n)
{
	assert(n != NULL);
	
	printf("������0~19������\n");
	scanf("%d",n);
	if(*n >= 0 && *n <= 19){
		printf("��������ǣ�%d\n",*n);
		return true;
	}else{
		while(getchar() == 'q'){
			printf("����������0~19������\n");
			scanf("%d",n);
			if(*n >= 0 && *n <= 19){
				printf("��������ǣ�%d\n",*n);
				return true;	
			}else{
				printf("��������ĸ�������룬��q�˳�\n");
				getchar();
			}
		}
	}
	
	return false;
}

void selectSort(data_t a[],const int size)
{
	assert(a != NULL && size >0);
	
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

void bubbleSort(data_t a[],const int size)
{
	assert(a != NULL && size >0);
	
	for(int i=0;i<size-1;++i){
		for(int j=0;j<size-i-i;++j){
			if(a[j] < a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}

int halfSearch(const data_t a[],const int low,const int hig,const data_t n)
{
	if(a == NULL || low < 0 || hig < 0){
		printf("halfSearch warn: a=NULL or low <= 0 or hig <= 0\n");
		return -1;
	}

	if(low <= hig){
		int mid = (low+hig)/2;
		if(a[mid] == n){
			return mid;
		}else if(a[mid] < n){
			return halfSearch(a,mid+1,hig,n);
		}else{
			return halfSearch(a,low,mid-1,n);
		}
	}
	
	return -1;
}
