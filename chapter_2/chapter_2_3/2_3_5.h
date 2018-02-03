typedef int T
void sort(vector<T> &a)
{
	int hi=s.size()-1;
	for(int i=1,int lo=0;i<=hi)
	{
		if(a[i]<a[lo])
			exch(a,i++,lo++);
	else if(a[i}>a[lo])
		exch(a,i,hi--);
	else
		i++;
	}
}