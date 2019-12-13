import range.DateRange;

class Rental {
    private Movie _movie;

    private int _daysRented;

    public Rental(Movie movie, DateRange dateRange) {
        _movie = movie;
        _daysRented = (int) ((dateRange.getEnd().getTime() - dateRange.getStart().getTime()) / (1000 * 60 * 60 * 24));
    }

    public int getDaysRented() {
        return _daysRented;
    }

    public String getTitle() {
        return _movie.getTitle();
    }

    public Movie getMovie() {
        return _movie;
    }

    public int getPriceCode() {
        return _movie.getPriceCode();
    }

    double getCharge() {
        return _movie.getCharge(getDaysRented());
    }

    int getFrequentRenterPoints() {
        return _movie.getFrequentRenterPoints(getDaysRented());
    }
}
