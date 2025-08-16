package Ordem;

public class HeapsortCresc {

    static final String maxkey = "aaaa";

    void heapsort(String v[], int n) {
        int i = n / 2 - 1;
        for (int r = i; r >= 0; r--) {
            heap(v, n, r);
        }

        for (int n1 = n - 2; n1 >= 0; n1--) {
            String auxkey = v[0];
            v[0] = v[n1 + 1];
            v[n1 + 1] = auxkey;
            heap(v, n1 + 1, 0);
        }
    }
    
    void heap(String[] v, int n, int r) {
        int i = r, h;
        boolean troca = true;

        while (troca) {
            troca = false;

            if (keyval(v, n, 2 * i + 1).compareTo(keyval(v, n, 2 * i + 2)) > 0)
                h = 2 * i + 1;
            else
                h = 2 * i + 2;

            if (i < n && h < n && v[i].compareTo(keyval(v, n, h)) < 0) {
                String auxkey = v[i];
                v[i] = v[h];
                v[h] = auxkey;
                i = h;
                troca = true;
            }
        }
    }

    String keyval(String[] v, int n, int i) {
        if (i >= n)
            return maxkey;
        else
            return v[i];
    }

    public static void main(String[] args) {
        String[] nomes = {"Kipo", "Bonnie", "Camile", "Luz", "Diana", "Rayla"};
        HeapsortCresc hs = new HeapsortCresc();
        hs.heapsort(nomes, nomes.length);
        for (String nome : nomes) {
            System.out.print(nome + " ");
        }
    }
}


