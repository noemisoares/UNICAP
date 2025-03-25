public class Funcionario {
    private String nome;
    private double salarioAnual;
    private int idade;

    public Funcionario(String nome, double salarioAnual, int idade){
        this.nome = nome;
        this.salarioAnual = salarioAnual;
        this.idade = idade;
    }

    String getNome(){
        return nome;
    }

    void setNome(String nome){
        this.nome = nome;
    }

    double getSalarioAnual() {
        return salarioAnual;
    }

    void setSalarioAnual(double salarioAnual) {
        this.salarioAnual = salarioAnual;
    }

    int getIdade() {
        return idade;
    }

    void setIdade(int idade) {
        this.idade = idade;
    }

    public String toString(){
        return "Nome: " + this.nome + " | Idade: " + this.idade + " | Salário Anual: " + this.salarioAnual; 
    }
}