public class Post {
    String texto, link;
    int numeroCurtidas, numeroCompartilhamentos;

    public Post(String texto, String link) {
        this.texto = texto;
        this.link = link;
        this.numeroCurtidas = 0;
        this.numeroCompartilhamentos = 0;
    }

    void curtir(){
        numeroCurtidas++;
    }

    void compartilhar(){
        numeroCompartilhamentos++;
    }
}
