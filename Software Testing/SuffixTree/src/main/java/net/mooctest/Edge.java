package net.mooctest;

class Edge {
    private String label;
    private Node dest;

    public String getLabel() {
        return label;
    }

    public void setLabel(String label) {
        this.label = label;
    }

    public Node getDest() {
        return dest;
    }

    public void setDest(Node dest) {
        this.dest = dest;
    }

    public Edge(String label, Node dest) {
        this.label = label;
        this.dest = dest;
    }

}
