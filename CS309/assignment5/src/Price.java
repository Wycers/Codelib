public abstract class Price {
    public abstract int getPriceCode();

    abstract double getCharge(int daysRented);

    int getFrequentRenterPoints(int daysRented) {
        int res = 1;
        // add bonus for a two day new release rental
        if ((getPriceCode() == Movie.NEW_RELEASE)
                && daysRented > 1) ++res;
        return res;
    }
}
