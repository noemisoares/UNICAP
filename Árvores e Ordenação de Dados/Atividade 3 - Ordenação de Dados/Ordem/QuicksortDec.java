package Ordem;

public class QuicksortDec {
    
    public static void quicksort(int v[], int i, int f) {
        int k;
        if (f > i) {
            k = particao(v, i, f);
            quicksort(v, i, k - 1);
            quicksort(v, k + 1, f);
        }
    }

    /* Aplicada no livro
    public static int particao(int[] v, int p, int r) {
        int x = v[r];
        int i = p - 1;

        for (int j = p; j < r; j++) {
            if (v[j] >= x) {
                i++;
                troca(v, i, j);
            }
        }

        troca(v, i + 1, r);
        return i + 1;
    }
    
    public static void troca(int[] v, int i, int j) {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
    */

    //Aplicada em aula
    public static int particao(int[] v, int i, int f) {
        int cp = v[i];
        boolean lado = true;

        while (i < f) {
            if (lado) {
                if (v[f] > cp) {
                    v[i] = v[f];
                    i++;
                    lado = false;
                } else {
                    f--;
                }
            } else {
                if (v[i] < cp) {
                    v[f] = v[i];
                    f--;
                    lado = true;
                } else {
                    i++;
                }
            }
        }
        v[i] = cp;
        return i;
    }

    public static void main(String[] args) {
        int[] vetor = {15, 10, 3, 7, 2, 30, 8, 6, 19, 5};
        quicksort(vetor, 0, vetor.length - 1);
        for (int i : vetor) {
            System.out.print(i + " ");
        }
    }
}