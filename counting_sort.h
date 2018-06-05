class Solution{
public:
	//bucket sort,可以认为只有一个桶
	void counting_sort(vector<int>& A)
	{
		int min=0;
 		int max=0;
 		int a=0;

		for(int index=0; index<A.size(); index++)
		{
			if(A[index]<min)
			{
				min=A[index];
				break;
			}
			if(A[index]>max)
				max=A[index];
		}
		vector<int> C(max-min,0);

		//
		for(int index=0; index<A.size(); index++)
		{
			C[A[index]-min]++;
		}

		for(int index=0; index<C.size(); index++)//K
		{
			for(int count=C[index]; count>0; count--)
				A[a++]=index+min;
		}

	}

	void counting_sort_origin(vector<int>& A)
	{
		int min=0;
 		int max=0;	
		for(int index=0; index<A.size(); index++)
		{
			if(A[index]<min)
			{
				min=A[index];
				break;
			}
			if(A[index]>max)
				max=A[index];
		}
		vector<int> C(max-min,0);
		vector<int> B(A.size(),0);

		for(int index=0; index<A.size(); index++)
		{
			C[A[index]-min]++;
		}

		//C[i]表示A中不大于元素值(i-min)的个数
		for(int idnex=1; index<C.size(); index++)
		{
			C[index] += C[index-1];
		}

		for(int index=A.size()-1; index>=0; index++)
		{
			B[C[A[index]-min]-1]= A[indx];
			C[A[index]-min]--;
		}

	}
};
