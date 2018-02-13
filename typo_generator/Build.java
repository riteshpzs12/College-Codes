import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.List;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;

public class Build {
    private File keyboard_layout_file;
    public List<String> k1 = new ArrayList<String>();
    public List<String> k2 = new ArrayList<String>();

    public Build(File keyboard_layout_file) throws FileNotFoundException {
        try {
            this.keyboard_layout_file = keyboard_layout_file;
            FileReader fr = new FileReader(keyboard_layout_file);
            BufferedReader br = new BufferedReader(fr);
            int cnt = 0;
            List<String> lines = java.nio.file.Files.readAllLines(keyboard_layout_file.toPath(), StandardCharsets.UTF_8);
            int n = lines.size();
            int i = 0;
            for (String line: lines) {
                if (i<n/2) k1.add(line);
                else k2.add(line);
                i++;
            }
            System.out.printf("len(k1) = %d, len(k2) = %d\n", k1.size(), k2.size());
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

    public void display() {
        for (int i = 0; i < 4; i++) {
            System.out.println(k1.get(i) + "\n");
            System.out.println(k2.get(i) + "\n");
        }
    }

    public static void main(String args[]) {
        Scanner in1 = new Scanner(System.in);
        if (args.length < 2) {
            System.out.println("Enter a filepath in the commandline.");
            for (int i = 0; i < args.length; i++) {
                System.out.println(args[i]);
            }
            System.exit(-1);
        }
        String filepath = args[0];
        String word = args[1];
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
            gen_with_shift.check_string(word);
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}

