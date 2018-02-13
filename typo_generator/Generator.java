import java.util.Scanner;

public class Generator {
    public static char Result_typo[][] = new char[96][14];
    public char array[][] = new char[4][15];
    public static int cntx = 0;
    public static int cnty = 0;
    public String k1[] = {};

    public Generator(String k1[]) {
        this.k1 = k1;
        array = new char[k1.length][];
        for (int i = 0; i < 4; i++) {
            String line = k1[i];
            array[i] = new char[line.length()];
            for (int j = 0; j < line.length(); j++) {
                this.array[i][j] = line.charAt(j);
            }
        }
    }

    public void traverse() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 14; j++) {
                getoutput(array[i][j], i, j);
            }
            //	System.out.println(i+"\n");
        }
    }

    public char revert(char c) {
        int a = c;
        if (a < 65 || a > 122) {
            return ' ';
        } else {
            if (a > 90 && a < 97)
                return ' ';
        }
        if (Character.isUpperCase(c))
            c = Character.toLowerCase(c);
        else
            c = Character.toUpperCase(c);
        return c;
    }

    public void getoutput(char c, int i, int j) {
        if (c == ' ')
            return;
        Result_typo[cntx][cnty++] = c;
        if (j < 13)
            if (array[i][j + 1] != ' ' && (int) array[i][j + 1] != 0)
                Result_typo[cntx][cnty++] = array[i][j + 1];
        if (j >= 1)
            if (array[i][j - 1] != ' ' && (int) array[i][j - 1] != 0)
                Result_typo[cntx][cnty++] = array[i][j - 1];
		/*if(revert(c)!=' ')
			Result_typo[cntx][cnty] = revert(c);*/
        if (i >= 1) {
            if (array[i - 1][j] != ' ' && (int) array[i - 1][j] != 0)
                Result_typo[cntx][cnty++] = array[i - 1][j];
            if (j < 13)
                if (array[i - 1][j + 1] != ' ' && (int) array[i - 1][j + 1] != 0)
                    Result_typo[cntx][cnty++] = array[i - 1][j + 1];
        }
        if (i <= 2) {
            if (array[i + 1][j] != ' ' && (int) array[i + 1][j] != 0)
                Result_typo[cntx][cnty++] = array[i + 1][j];
            if (j >= 1)
                if (array[i + 1][j - 1] != ' ' && (int) array[i + 1][j - 1] != 0)
                    Result_typo[cntx][cnty++] = array[i + 1][j - 1];
        }
        cntx++;
        cnty = 0;
        return;
    }

    public void display() {
        int c = 0;
        for (int i = 0; i <= cntx; i++) {
            System.out.println("");
            for (int j = 0; j < Result_typo[cntx].length; j++) {
                if ((int) Result_typo[i][j] != 0)
                    System.out.print(" " + Result_typo[i][j]);
            }
        }
        return;
    }

    public void merge() {
        String test = "";
        String test1 = "";
        for (int i = 0; i < 47; i++) {
            test = String.valueOf(Result_typo[(i + 47) % 94]).trim();
            test1 = String.valueOf(Result_typo[i]).trim();
            append_custom(test, i);
            append_custom(test1, (i + 47) % 94);
        }
    }

    public void append_custom(String test, int i) {
        int local = 0;
        for (int j = 0; j < 14; j++) {
            if ((Result_typo[i][j] == ' ' || (int) Result_typo[i][j] == 0) && local < test.length()) {
                Result_typo[i][j] = test.charAt(local++);
            }
        }

    }

    public void check_string(String pwd) {
        for (int i = 0; i < pwd.length(); i++) {
            String s = get_match(pwd.charAt(i));
            display_string(s, pwd, i);
        }
    }

    public void display_string(String s, String pwd, int i) {
        for (int j = 1; j < s.length(); j++) {
            String pre = pwd.substring(0, i);
            String suf = pwd.substring(i + 1, pwd.length());
            System.out.println(pre + s.charAt(j) + suf);
        }

    }

    public String get_match(char c) {
        for (int i = 0; i < 94; i++) {
            if (Result_typo[i][0] == c) {
                String str = String.valueOf(Result_typo[i]).trim();
                return str;
            }
        }
        return null;
    }
}
