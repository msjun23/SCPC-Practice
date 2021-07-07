/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

/* SCPC 6회 예선 다이어트 */
#include <iostream>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T, test_case;
	int* A_restaurant;
	int* B_restaurant;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	 // freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */

		int menu, days;
		cin >> menu >> days;

		// 식당별, 메뉴별 칼로리를 각 배열에 저장
		A_restaurant = new int[menu];
		B_restaurant = new int[menu];
		for (int i = 0; i < menu; i++) {
			cin >> A_restaurant[i];
		}
		for (int i = 0; i < menu; i++) {
			cin >> B_restaurant[i];
		}

		// 메뉴별 칼로리 정렬
		sort(A_restaurant, A_restaurant + menu);
		sort(B_restaurant, B_restaurant + menu);

		// 날 마다 A식당에서는 가장 칼로리가 낮은 음식을, B식당에서는 가장 칼로리가 높은 음식을 섭취
		int* days_calroies = new int[days];
		for (int i = 0; i < days; i++) {
			days_calroies[i] = A_restaurant[i] + B_restaurant[days - 1 - i];
		}

		// 하루에 먹은 칼로리 정렬
		sort(days_calroies, days_calroies + days);

		Answer = days_calroies[days - 1];

		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;

		// 동적할당 메모리 해제
		delete[] A_restaurant;
		delete[] B_restaurant;
	}

	return 0;//Your program should return 0 on normal termination.
}