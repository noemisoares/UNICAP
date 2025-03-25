import java.util.ArrayList;

public class Pedido {
    private int numero;
    private ArrayList<ItemPedido> itens = new ArrayList<>();
    private double total;

    public Pedido(int numero) {
        this.numero = numero;
        this.itens = new ArrayList<>();
        this.total = 0.0;
    }

    int getNumero() {
        return numero;
    }

    void setNumero(int numero) {
        this.numero = numero;
    }

    ArrayList<ItemPedido> getItens() {
        return itens;
    }

    void setItens(ArrayList<ItemPedido> itens) {
        this.itens = itens;
    }

    double getTotal() {
        return total;
    }

    void setTotal(double total) {
        this.total = total;
    }

    public String toString(){
        return "Pedido nº: " + this.numero + " | Total: " + this.total; 
    }
}