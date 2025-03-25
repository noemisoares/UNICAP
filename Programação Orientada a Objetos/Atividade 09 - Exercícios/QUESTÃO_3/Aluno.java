import java.util.ArrayList;

public class Aluno {
    private String nome;  
    private int matricula;
    private ArrayList<Notas> nota = new ArrayList<>();
    
    public Aluno(String nome, int matricula) {
        this.nome = nome;
        this.matricula = matricula;
        this.nota = new ArrayList<>();
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getMatricula() {
        return matricula;
    }

    public void setMatricula(int matricula) {
        this.matricula = matricula;
    }

    public ArrayList<Notas> getNota() {
        return nota;
    }

    public void setNota(ArrayList<Notas> nota) {
        this.nota = nota;
    }

    double calcularMedia() {
        double soma = 0.0;
        int totalNotas = 0;

        for (Notas n : nota) {
            soma += n.getNota1() + n.getNota2() + n.getNota3() + n.getNota4();
            totalNotas += 4;
        }

        return soma / totalNotas;
    }

    public String toString(){
        return " Nº de Matricula: " + this.matricula + " | Nome: " + this.nome + " | Média: " + calcularMedia(); 
    }

}