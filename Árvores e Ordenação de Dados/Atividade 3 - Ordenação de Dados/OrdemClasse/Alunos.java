package OrdemClasse;

public class Alunos {
    private String matr;
    private String nome;
    private double nota;
    private int faltas;

    public Alunos(String matr, String nome, double nota, int faltas) {
        this.matr = matr;
        this.nome = nome;
        this.nota = nota;
        this.faltas = faltas;
    }

    public double getNota() {
        return nota;
    }

    public String toString() {
        return nome + " - Nota: " + nota;
    }

    public String getMatr() {
        return matr;
    }

    public void setMatr(String matr) {
        this.matr = matr;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setNota(double nota) {
        this.nota = nota;
    }

    public int getFaltas() {
        return faltas;
    }

    public void setFaltas(int faltas) {
        this.faltas = faltas;
    }
}

