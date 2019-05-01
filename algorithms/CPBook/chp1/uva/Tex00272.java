import java.util.Scanner;
class Tex00272
{
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		String s,z="";
		int c=0;
		while((s=sc.nextLine())!=null && s.length()!=0)
		{
			for(int i=0;i<s.length();i++)
			{
				if(s.charAt(i)=='"' && c==0)
				{
					z=z+"``";
					c=1;
				}
				else if(s.charAt(i)=='"' && c==1)
				{
					z=z+"'"+"'";
					c=0;
				}
				else
					z=z+s.charAt(i);
			}
			System.out.println(z);
		}
		sc.close();
	}
}