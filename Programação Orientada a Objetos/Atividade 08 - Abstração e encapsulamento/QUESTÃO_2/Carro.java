public class Carro {
    private String marca, modelo;
    int anoFabricacao, velocidadeAtual;

    public Carro(String marca, String modelo, int anoFabricacao, int velocidadeAtual) {
        this.marca = marca;
        this.modelo = modelo;
        this.anoFabricacao = anoFabricacao;
        this.velocidadeAtual = velocidadeAtual;
    }

    String getMarca(){
        return marca;
    }

    void setMarca(String marca){
        this.marca = marca;
    }

    String getModelo() {
        return modelo;
    }

    void setModelo(String modelo) {
        this.modelo = modelo;
    }

    int getAnoFabricacao() {
        return anoFabricacao;
    }

    void setAnoFabricacao(int anoFabricacao) {
        this.anoFabricacao = anoFabricacao;
    }

    int getVelocidadeAtual() {
        return velocidadeAtual;
    }

    void setVelocidadeAtual(int velocidadeAtual) {
        this.velocidadeAtual = velocidadeAtual;
    }

    void acelerar(int velocidade){
        this.velocidadeAtual += velocidade;
    }

    void desacelerar(int velocidade){
        if(this.velocidadeAtual - velocidade < 0){
            this.velocidadeAtual = 0;
        } else {
            this.velocidadeAtual -= velocidade; 
        }
    }    
}