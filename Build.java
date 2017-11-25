import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Build {
	private File keyboard_layout_file;
	public String k1[]={"","","",""};
	public String k2[]={"","","",""};
	public Build(File keyboard_layout_file)throws FileNotFoundException
	{
		try {
			this.keyboard_layout_file = keyboard_layout_file;
			FileReader fr = new FileReader(keyboard_layout_file);
			BufferedReader br = new BufferedReader(fr);
			int cnt = 0;
			String temp = " ";
			while((temp=br.readLine())!=null)
			{
				if(cnt<4)
					k1[cnt++] = temp;
				else
					k2[(cnt++)-4] = temp;
			}		
		} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	}
	public File getKeyboard_layout_file() {
		return keyboard_layout_file;
	}
	public void setKeyboard_layout_file(File keyboard_layout_file) {
		this.keyboard_layout_file = keyboard_layout_file;
	}
	public void display(){
		for(int i=0;i<4;i++)
		{
			System.out.println(k1[i]+"\n");
			System.out.println(k2[i]+"\n");
		}
	}
	public static void main(String args[])  {	
		Scanner in1=new Scanner(System.in);
		String filepath=in1.nextLine();
		Build b;
		try {
			b = new Build(new File(filepath));
			Generator gen_with_shift = new Generator(b.k1);
			Generator gen_without_shift = new Generator(b.k2);
//			b.display();
			gen_with_shift.traverse();
			gen_without_shift.traverse();
			gen_with_shift.merge();
		//	gen_without_shift.display();
			gen_with_shift.check_string();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}

