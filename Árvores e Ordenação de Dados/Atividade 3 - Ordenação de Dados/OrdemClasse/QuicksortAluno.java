package OrdemClasse;

public class QuicksortAluno {

    public static void quicksort(Alunos[] v, int i, int f) {
        if (f > i) {
            int k = particao(v, i, f);
            quicksort(v, i, k - 1);
            quicksort(v, k + 1, f);
        }
    }

    public static int particao(Alunos[] v, int i, int f) {
        Alunos cp = v[i];
        boolean lado = true;

        while (i < f) {
            if (lado) {
                if (v[f].getNota() > cp.getNota()) {
                    v[i] = v[f];
                    i++;
                    lado = false;
                } else {
                    f--;
                }
            } else {
                if (v[i].getNota() < cp.getNota()) {
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
        Alunos[] turma = {
            new Alunos("001", "Noemi", 7.5, 2),
            new Alunos("002", "Annabeth", 9.0, 1),
            new Alunos("003", "Luz", 6.0, 3),
            new Alunos("004", "Kipo", 8.3, 0),
            new Alunos("005", "Perseu", 5.5, 4)
        };

        quicksort(turma, 0, turma.length - 1);

        for (Alunos a : turma) {
            System.out.println(a);
        }
    }
}
