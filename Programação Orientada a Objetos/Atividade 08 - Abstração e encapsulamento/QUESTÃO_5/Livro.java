public class Livro {
    private String título, autor;
    private int anoPublicacao;
    
    public Livro(String título, String autor, int anoPublicacao) {
        this.título = título;
        this.autor = autor;
        this.anoPublicacao = anoPublicacao;
    }

    String getTítulo() {
        return título;
    }

    void setTítulo(String título) {
        this.título = título;
    }

    String getAutor() {
        return autor;
    }

    void setAutor(String autor) {
        this.autor = autor;
    }

    int getAnoPublicacao() {
        return anoPublicacao;
    }

    void setAnoPublicacao(int anoPublicacao) {
        if (anoPublicacao > 0){
            this.anoPublicacao = anoPublicacao;
        } else {
            System.out.println("Ano de publicação inválido!");
        }
    }
}