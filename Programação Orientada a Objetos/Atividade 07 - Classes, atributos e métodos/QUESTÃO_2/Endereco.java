public class Endereco {
    String rua, complemento, bairro, cidade, uf, cep;
    int numero;

    public Endereco(String rua, int numero, String complemento, String bairro, String cidade, String uf, String cep){
        this.rua = rua;
        this.numero = numero;
        this.complemento = complemento;
        this.bairro = bairro;
        this.cidade = cidade;
        this.uf = uf;
        this.cep = cep;
    }
}
