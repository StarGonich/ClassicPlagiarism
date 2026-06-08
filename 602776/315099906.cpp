long long N, otvet = 0;
cin >> N;
/*for (int i = 1; i <= N; ++i) {
	cout << i<<" ";
	if (i % 4 == 0) {
		cout << 4 << " ";
	}
	if (i % 5 == 0) {
		cout << 5 << " ";
	}
	if (i % 6 == 0) {
		cout << 6 << " ";
	}
	cout << endl;
}*/
long long vse = (N / 60);
long long first = (N / 4)-(N/12)-(N/20)+ vse;
long long second = (N / 5) - (N / 30) - (N / 20) + vse;
long long third= (N / 6) - (N / 12) - (N / 30) + vse;
cout <<first+second+third;
