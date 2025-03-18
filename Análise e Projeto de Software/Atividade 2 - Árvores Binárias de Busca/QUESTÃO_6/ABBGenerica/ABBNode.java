package ABBGenerica;

class ABBNode <T extends Comparable<T>> {
    private T info;
    private ABBNode <T> left;
    private ABBNode <T> right;

    ABBNode (T info) {
        this.info = info;
    }

    public T getInfo() {
        return info;
    }

    public void setInfo(T info) {
        this.info = info;
    }

    public ABBNode<T> getLeft() {
        return left;
    }

    public void setLeft(ABBNode<T> left) {
        this.left = left;
    }

    public ABBNode<T> getRight() {
        return right;
    }

    public void setRight(ABBNode<T> right) {
        this.right = right;
    }
}
