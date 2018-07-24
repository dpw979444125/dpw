long long fib(long long n)
{
	//long long n;
	//cin >> n;
	if (n < 0)
	{
		cout<< -1;
	}
	long long  fib1 = 0, fib2 = 1, fib3 = 0;
	for (long long  i = 1; i < 2 * n; ++i)
	{
		if (fib2 > n && fib1 < n)
		{
			long long ret1 = fib2 - n;
			long long ret2 = n - fib1;
			if (ret1 > ret2)
			{
				cout<<ret2;
				break;
			}
			else if (ret2 > ret1)
			{
				cout<<ret1;
				break;
			}
			else
			{
				cout << ret1;
				break;
			}			
		}
		if (n == fib2 || n == fib1)
		{
			cout<<0;
			break;
		}
		fib3 = fib1 + fib2;
		fib1 = fib2;
		fib2 = fib3;
	}
	return 0;
}

int main()
{
	long long ret = fib(15);
	cout << ret << endl;
	return 0;
}