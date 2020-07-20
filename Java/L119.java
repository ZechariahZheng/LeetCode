import java.util.List;
import java.util.ArrayList;

public class L119 {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> result = new ArrayList<>();
        int tmp = 0;
        for (int i = 0; i <= rowIndex; i++) {
            result.add(1);
            for (int j = i-1; j > 0; j--) {
                tmp = result.get(j)+result.get(j-1);
                result.set(j, tmp);
            }
        }
        return result;
    }
}