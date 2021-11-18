int main(void)
{
	int n ;
	scanf ("%d" , &n );

	int sum = 0;
	int p = 1;
	for (int i =    0; i   < n; ++ i) {
		int x ;
		scanf ( "%d" , &x );
		printf ( "%d ", x );
		sum +=   x;
		p = p *  x;
	}

	if (sum > 0 && p > 0)
		sum = p;

	while  ( 1 )  {
		printf ("Sunt un cartof! (Silviu Popescu - 2016)\n" ) ;
		printf ("Sunt un cartof! (Silviu Popescu - 2016)\n" ) ;
	}

	do {
		printf( "Sunt un cartof! (Silviu Popescu - 2016)\n") ;
		printf( "Sunt un cartof! (Silviu Popescu - 2016)\n") ;
	} while (1  );

	return 0 ;
}
