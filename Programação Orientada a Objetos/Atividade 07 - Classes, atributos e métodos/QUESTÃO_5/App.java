public class App{
    public static void main (String[] args){
        Aluno aluno = new Aluno("Naomi", "123.456.789-10");
        aluno.nota1 = 10.0;
        aluno.nota2 = 7.5;
        aluno.nota3 = 4.5;
        aluno.nota4 = 8.0;
        
        double media = aluno.calcularMedia();
        System.out.println("Média do Aluno: " + media);

        aluno.nota2 = 5.5;
        media = aluno.calcularMedia();
        System.out.println("Nova Média do Aluno: " + media);
    }
}