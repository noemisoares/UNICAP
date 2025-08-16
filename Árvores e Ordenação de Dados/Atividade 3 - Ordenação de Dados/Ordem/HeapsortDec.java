package Ordem;

public class HeapsortDec {

    static final int minkey = Integer.MIN_VALUE;

    void heapsort (int v[ ], int n) {
        int i, r, n1;
        int auxkey;
        i = n / 2 - 1;
        for (r = i; r >= 0; r--) {
            heap (v, n, r);
        }
        for (n1 = n-2; n1 >= 0; n1--) {
            auxkey = v [0];
            v[0] = v[n1+1];
            v[n1+1] = auxkey;
            heap (v, n1, 0);
        }
    }

    void heap(int[] v, int n, int r) {
        int i = r, h, troca = 1, auxkey;

        while (troca == 1) {
            troca = 0;

            if (keyval(v, n, 2 * i + 1) < keyval(v, n, 2 * i + 2))
                h = 2 * i + 1;
            else
                h = 2 * i + 2;

            if (i < n && h < n && v[i] > keyval(v, n, h)) {
                auxkey = v[i];
                v[i] = v[h];
                v[h] = auxkey;
                i = h;
                troca = 1;
            }
        }
    }

    int keyval(int[] v, int n, int i) {
        if (i >= n)
            return minkey;
        else
            return v[i];
    }

    public static void main(String[] args) {
        int[] vetor = {15, 10, 3, 7, 2, 30, 8, 6, 20, 19, 5};
        HeapsortDec hs = new HeapsortDec();
        hs.heapsort(vetor, vetor.length);

        for (int i : vetor) {
            System.out.print(i + " ");
        }
    }
}
