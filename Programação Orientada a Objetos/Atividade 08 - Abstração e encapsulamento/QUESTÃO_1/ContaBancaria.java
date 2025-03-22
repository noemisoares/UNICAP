public class ContaBancaria {
    private String numero, nome;
    private double saldo;

    public ContaBancaria(String numero, String nome){
        this.nome = nome;
        this.numero = numero;
        this.saldo = 0;
    }

    void creditar(double valor) {
        saldo = saldo + valor;
    }
    
    void debitar(double valor) {
        saldo = saldo - valor;
    }

    String getNome(){
        return nome;
    }

    void setNome(String nome){
        this.nome = nome;
    }

    String getNumero(){
        return numero;
    }

    void setNumero(String numero){
        this.numero = numero;
    }

    double getSaldo(){
        return saldo;
    }

    void setSaldo(double saldo){
        this.saldo = saldo;
    }
}