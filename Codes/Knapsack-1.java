import java.util.Scanner;
class Knapsack
{
	static int Random(int min,int max)
	{
        int range = max - min + 1; 
        int rand = (int)(Math.random() * range) + min;
        return rand;
	}
	public static void main(String Art3mis[])
	{
		System.out.println("Input number of items:");
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		float items[][]=new float[6][n];
		for(int i=0;i<n;i++)
		{
			items[0][i]=i+1;
			items[1][i]=Random(100,1000);
			items[2][i]=Random(1,100);
			items[3][i]=items[1][i]/items[2][i];
			items[4][i]=0;
		}
		String name[]={"Items","Profit","Weight","P/W","Weight used","Profit gained"};
		for(int i=0;i<5;i++)
		{	System.out.print(name[i]+"\t\t");
			for(int j=0;j<n;j++)
			{
				System.out.print(items[i][j]+"\t\t\t");
			}
			System.out.println();
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(items[3][i]>items[3][j])
				{
					float temp0=items[0][i];
					float temp1=items[1][i];
					float temp2=items[2][i];
					float temp3=items[3][i];
					items[0][i]=items[0][j];
					items[1][i]=items[1][j];
					items[2][i]=items[2][j];
					items[3][i]=items[3][j];
					items[0][j]=temp0;
					items[1][j]=temp1;
					items[2][j]=temp2;
					items[3][j]=temp3;

				}
			}
		}
		System.out.println("\n\n\n");
		for(int i=0;i<5;i++)
		{	System.out.print(name[i]+"\t\t");
			for(int j=0;j<n;j++)
			{
				System.out.print(items[i][j]+"\t\t\t");
			}
			System.out.println();
		}
		float profit=0;
		float weight_bag=50;
		float space_remaining=weight_bag;
		for(int i=0;i<n;i++)
		{
			if(space_remaining>0)
			{	if(items[2][i]<=space_remaining)
				{	items[4][i]+=items[2][i];
					space_remaining-=items[4][i];
					items[5][i]=items[4][i]*items[3][i];
				}
				else
				{
					items[4][i]=space_remaining;
					space_remaining=0;
					items[5][i]=items[4][i]*items[3][i];
				}
				profit+=items[4][i]*items[3][i];
			}
			else
				break;
		}
		System.out.println("\n\n\n");
		for(int i=0;i<6;i++)
		{	System.out.print(name[i]+"\t\t");
			for(int j=0;j<n;j++)
			{
				System.out.print(items[i][j]+"\t\t\t");
			}
			System.out.println();
		}
		System.out.println("Total profit:"+profit);

	}
}