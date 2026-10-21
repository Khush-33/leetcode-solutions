
class StockSpanner {
public:
    // Each pair stores:
    // {price, span}
    //
    // span = number of consecutive days ending at this day
    // for which the stock price was <= this day's price.
    stack<pair<int, int>> st;

    StockSpanner() {
        // Stack starts empty when the object is created.
    }

    int next(int price) {
        // Today's price always contributes at least 1 day
        // (today itself).
        int span = 1;

        // Remove all previous prices that are <= today's price.
        // These days are included in today's span because
        // today's price is greater than or equal to theirs.
        while (!st.empty() && st.top().first <= price) {

            // The top pair's span tells us how many consecutive
            // days that previous price already represents.
            // Add all those days at once instead of checking
            // each individual day.
            span += st.top().second;

            // Today's price dominates this previous price,
            // so it will never be needed as a blocker again.
            st.pop();
        }

        // No remaining price on top is <= today's price.
        // Push today's price along with its complete span.
        st.push({price, span});

        // Return the number of consecutive days covered.
        return span;
    }
};
