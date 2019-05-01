import java.math.BigInteger;
class ex123_10
{
	public static void main(String[] args)
	{
		String s="FF";
		int X=16,Y=8;
		System.out.println(new BigInteger(s,X).toString(Y));
		
	}
}