public class Aluno {
    String nome, cpf;
    double nota1, nota2, nota3, nota4;

    public Aluno(String nome, String cpf) {
        this.nome = nome;
        this.cpf = cpf;
        this.nota1 = 0;
        this.nota2 = 0;
        this.nota3 = 0;
        this.nota4 = 0;
    }

    double calcularMedia(){
        double media = 0;
        media = (nota1 + nota2 + nota3 + nota4)/4;
        return media;
    }
}
