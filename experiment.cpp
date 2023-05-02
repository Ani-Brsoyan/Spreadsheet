#include <iostream>

void print(int** arr, const int N){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void change(int**& arr, const int N){
	arr[N - 1][N - 1] = 5;
}

int main(){
	const int N = 3;
	int** mat = new int*[N];
	for(int i = 0; i < N; i++){
		mat[i] = new int[N]{};
	}
	print(mat, N);
	change(mat, N);
	print(mat, N);
	return 0;
}
