class Livro implements Comparable<Livro>{
    private String titulo, autor;  
    private boolean disponivel;

    public Livro(String titulo, String autor, boolean disponivel) {
        this.titulo = titulo;
        this.autor = autor;
        this.disponivel = disponivel;
    }

    String getTitulo() {
        return titulo;
    }
    
    void setTitulo(String titulo) {
        this.titulo = titulo;
    }
    
    String getAutor() {
        return autor;
    }
    
    void setAutor(String autor) {
        this.autor = autor;
    }
    
    boolean isDisponivel() {
        return disponivel;
    }
    
    void setDisponivel(boolean disponivel) {
        this.disponivel = disponivel;
    }

    public int compareTo(Livro Livro) {
        return this.titulo.compareToIgnoreCase(Livro.getTitulo());
    }

    public String toString(){
        return "Titulo: " + this.titulo + " | Autor: " + this.autor;
    }
}