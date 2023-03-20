#include <stdio.h>
#include<stdlib.h>
#include <math.h>

int main()
{
	int choice;
	int arr[21][21];
	int a, b, c, i, j;
	int x, y, ytop, ybottom;
	int condition;
	float r2;

	printf("which shape would you like to draw?\n");
	printf("1. Line\n2. Parabola\n3. Circle\n4.Exit\n");
	scanf_s("%d", &choice);


	while (choice != 4)
	{

		for (i = 0; i < 21; i++)
			for (j = 0; j < 21; j++)
				arr[i][j] = 0;

		for (i = 0; i < 21; i++)
			arr[10][i] = -2;

		for (i = 0; i < 21; i++)
			arr[i][10] = -1;





		switch (choice)
		{
		case 1:

			printf("Line formula is: y = ax+b \nPlease enter coefficients a and b: ");
			scanf_s("%d %d", &a, &b);

			printf("\n");

			for (i = -10; i <= 10; i++)
			{
				x = i;
				y = a * x + b;
				y = -1 * y + 10;
				x = x + 10;
				if (y < 21 && x < 21)
					arr[y][x] = 1;
			}
			break;

		case 2:

			printf("Parabola formula is: y = ax^2 + bx + c \nPlease enter coefficients a, b and c: ");
			scanf_s("%d %d %d", &a, &b, &c);

			printf("\n");

			for (i = -10; i <= 10; i++)
			{
				x = i;
				y = (a * x * x) + (b * x) + c;
				y = -1 * y + 10;
				x = x + 10;
				if (y < 21 && x < 21)
					arr[y][x] = 1;
			}
			break;

		case 3:

			printf(" Circle formula is: (x-a)^2 + (y-b)^2 = r^2 \nPlease enter center's (a, b) and radius: ");
			scanf_s("%d %d %d", &a, &b, &c);

			while (c < 0)
			{
				printf(" Radius does not exist. Please enter radius again: ");
				scanf_s("%d", &c);
			}

			printf("\n");
			float y;
			r2 = pow(c, 2);

			for (i = -10; i <= 10; i++)
			{
				x = i;
				y = sqrt(r2 - ((x - a) * (x - a))) + b;
				ytop = sqrt(r2 - ((x - a) * (x - a))) + b;
				ybottom = -sqrt(r2 - ((x - a) * (x - a))) + b;
				y = -1 * y + 10;
				ytop = -1 * ytop + 10;
				ybottom = -1 * ybottom + 10;
				x = x + 10;
				condition = ((x - a) * (x - a)) + ((y - b) * (y - b));


				if (y < 21 && x < 21 && condition >= r2)
				{
					if (fabs(y - ytop) < 0.2)
					{
						arr[ytop][x] = 1;
						arr[ybottom][x] = 1;
					}
				}
			}
			break;

		case 4:
			break;

		default:
			printf("\nError! You can choose only numbers between 1 and 4.\n ");
			break;
		}

		printf("\n");

		if (choice == 1 || choice == 2 || choice == 3)
		{

			for (i = 0; i < 21; i++)
			{
				for (j = 0; j < 21; j++)
				{
					if (arr[i][j] == 0)
						printf(" ");
					else if (arr[i][j] == 1)
						printf("*");
					else if (arr[i][j] == -2)
						printf("-");
					else if (arr[i][j] == -1)
						printf("|");

				}
				printf("\n");
			}
		}
		printf("\nwhich shape would you like to draw?\n");
		printf("1. Line\n2. Parabola\n3. Circle\n4.Exit\n");
		scanf_s("%d", &choice);
		printf("\n");
	}

	system("pause");
}
