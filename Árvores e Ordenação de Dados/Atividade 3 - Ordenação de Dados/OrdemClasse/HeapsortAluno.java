package OrdemClasse;

public class HeapsortAluno {

    static final int minkey = Integer.MIN_VALUE;

    public void heapsort(Alunos[] v, int n) {
        for (int r = n / 2 - 1; r >= 0; r--) {
            heap(v, n, r);
        }

        for (int n1 = n - 2; n1 >= 0; n1--) {
            Alunos aux = v[0];
            v[0] = v[n1 + 1];
            v[n1 + 1] = aux;
            heap(v, n1 + 1, 0);
        }
    }

    void heap(Alunos[] v, int n, int r) {
        int i = r, h;
        boolean troca = true;

        while (troca) {
            troca = false;

            if (keyval(v, n, 2 * i + 1) < keyval(v, n, 2 * i + 2))
                h = 2 * i + 1;
            else
                h = 2 * i + 2;

            if (i < n && h < n && v[i].getFaltas() > keyval(v, n, h)) {
                Alunos aux = v[i];
                v[i] = v[h];
                v[h] = aux;
                i = h;
                troca = true;
            }
        }
    }

    int keyval(Alunos[] v, int n, int i) {
        if (i >= n)
            return minkey;
        else
            return v[i].getFaltas();
    }

    public static void main(String[] args) {
        Alunos[] turma = {
            new Alunos("001", "Noemi", 7.5, 2),
            new Alunos("002", "Annabeth", 9.0, 1),
            new Alunos("003", "Luz", 6.0, 3),
            new Alunos("004", "Kipo", 8.3, 0),
            new Alunos("005", "Perseu", 5.5, 4)
        };

        HeapsortAluno hs = new HeapsortAluno();
        hs.heapsort(turma, turma.length);

        for (Alunos a : turma) {
            System.out.println(a.getNome() + " - Faltas: " + a.getFaltas());
        }
    }
}
