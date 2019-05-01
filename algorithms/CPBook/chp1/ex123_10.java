class ex123_10
{
	public static void main(String []args)
	{
		String s ="line: a70 and a82 will be replaced , aa24 and a872 will not .",w="",z="";
		int i,l;
		for(i=0;i<s.length();i++)
		{
			if(s.charAt(i)!=' ')
				w=w+s.charAt(i);
			else
			{
				if(w.length()==3)
				{
					if(w.charAt(0)>='a' && w.charAt(0)<='z')
					{
						if(w.charAt(1)>='0' && w.charAt(1)<='9')
						{
							if(w.charAt(2)>='0' && w.charAt(2)<='9')
							{
								w="***";
								System.out.println("hey!");
							}
						}	
					}
				}
				z=z+w+" ";
				w="";
			}
		}
		System.out.println(z);
	}
}