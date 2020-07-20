import java.util.List;
import java.util.ArrayList;

public class L118 {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>();
        int i = 1;
        ArrayList<Integer> tmp;
        while (numRows > 0) {
            tmp = new ArrayList<>();
            if (i == 1) {
                tmp.add(1);
            } else if (i == 2) {
                tmp.add(1);
                tmp.add(1);
            } else {
                tmp.add(1);
                List<Integer> last = res.get(res.size()-1);
                for (int j = 0; j < last.size()-1; j++) {
                    tmp.add(last.get(j)+last.get(j+1));
                }
                tmp.add(1);
            }
            res.add(tmp);
            i++;
            numRows--;
        }
        return res;
    }
}