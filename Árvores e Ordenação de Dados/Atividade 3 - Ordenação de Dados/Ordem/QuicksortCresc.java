package Ordem;

public class QuicksortCresc {

    public static void quicksort(String[] v, int i, int f) {
        int k;
        if (f > i) {
            k = particao(v, i, f);
            quicksort(v, i, k - 1);
            quicksort(v, k + 1, f);
        }
    }

    public static int particao(String[] v, int i, int f) {
        String cp = v[i];
        boolean lado = true;

        while (i < f) {
            if (lado) {
                if (v[f].compareTo(cp) < 0) {
                    v[i] = v[f];
                    i++;
                    lado = false;
                } else {
                    f--;
                }
            } else {
                if (v[i].compareTo(cp) > 0) {
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
        String[] vetor = {"Noemi", "Max", "Annabeth", "Caitlyn", "Bonnie", "Circe", "Mel", "Atena"};
        quicksort(vetor, 0, vetor.length - 1);

        for (String s : vetor) {
            System.out.print(s + " ");
        }
    }
}