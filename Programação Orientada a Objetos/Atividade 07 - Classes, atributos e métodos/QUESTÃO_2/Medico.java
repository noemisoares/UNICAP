public class Medico {
    String codigo, nome, sexo, especialidade;
    Endereco endereco;

    public Medico(String codigo, String nome, String sexo, String especialidade, Endereco endereco){
        this.codigo = codigo;
        this.nome = nome;
        this.sexo = sexo;
        this.especialidade = especialidade;
        this.endereco = endereco;
    }
}
