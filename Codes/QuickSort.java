import java.util.Scanner;
class Sort
{
	public static void main(String Happy[])
	{
	
		System.out.println("Input n:");
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++)
		{	System.out.print("a["+i+"]:");
			a[i]=s.nextInt();
			System.out.println();
		}
		int c=0;
		while(c!=2)
		{	System.out.println();
			System.out.println("Press 1 for quick sort:");
			System.out.println("Press 2 to exit:");
		    c=s.nextInt();5
				if(c==1)
				{
				quickSort(a, 0, a.length-1);
				for(int i=0;i<n;i++)
		{
			System.out.print("\t"+a[i]);
		}
		System.out.println();
				}
        }
    }

public static void quickSort(int a[], int beg, int end)  
    {  
          
        int loc;  
        if(beg<end)  
        {  
            loc = partition(a, beg, end);  
            quickSort(a, beg, loc-1);  
			quickSort(a, loc+1, end);  
		}

	}  

public static int partition(int a[], int beg, int end)  
    {  
          
        int left, right, temp, loc, flag;     
        loc = left = beg;  
        right = end;  
        flag = 0;  
        while(flag != 1)  
        {  
            while((a[loc] <= a[right]) && (loc!=right))  
            right--;  
            if(loc==right)  
            flag =1;  
            else if(a[loc]>a[right])  
            {  
                temp = a[loc];  
                a[loc] = a[right];  
                a[right] = temp;  
                loc = right;  
            }  
            if(flag!=1)  
            {  
                while((a[loc] >= a[left]) && (loc!=left))  
                left++;  
                if(loc==left)  
                flag =1;  
                else if(a[loc] <a[left])  
                {  
                    temp = a[loc];  
                    a[loc] = a[left];  
                    a[left] = temp;  
                    loc = left;  
                }  
            }  
        }  
        return loc;  
    }  
}