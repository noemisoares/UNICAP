package AVL;

class AVLNode <T extends Comparable <T>> {
    private AVLNode <T> left;
    private T info;
    private AVLNode <T> right;
    private int fatBal;

    AVLNode (T info) {
        this.info = info;
    }

    AVLNode <T> getLeft() {
        return this.left;
    }

    void setLeft(AVLNode <T> left) {
        this.left = left;
    }

    T getInfo() {
        return this.info;
    }

    void setInfo(T info) {
        this.info = info;
    }

    AVLNode <T> getRight() {
        return this.right;
    }

    void setRight(AVLNode <T> right) {
        this.right = right;
    }

    int getFatBal(){
        return this.fatBal;
    }

    void setFatBal(int fatBal){
        this.fatBal = fatBal;
    }
}