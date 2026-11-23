import std;
using namespace std;

enum class Color {
    black,
    white,
    red,
    green,
    blue,
    invisible
};



struct Shape
{                                  // deals with color and style, and holds sequence of lines
    virtual ~Shape() {}           // destructor: see §15.5.2
    Shape(const Shape &) = delete; // prevent copying: see §12.4.1
    Shape &operator=(const Shape &) = delete;
    virtual void move(int dx, int dy); // move the shape +=dx and +=dy
    void set_color(Color col)
    {
        lcolor = col;
        redraw();
    }                                      // write
    Color color() const { return lcolor; } // read

    void set_style(Line_style sty)
    {
        ls = sty;
        redraw();
    }
    Line_style style() const { return ls; }
    void set_fill_color(Color col)
    {
        fcolor = col;
        redraw();
    }
    Color fill_color() const { return fcolor; }
    Point point(int i) const { return points[i]; }
    int number_of_points() const { return naro<int>(points.siz e()); }
    void set_window(Window * win) { parent_window = win; }
    void draw(Painter &painter) const; // deal with color and draw_specifics

protected:
    Shape(std::initializer_list<Point> lst = {}); // add() the Points to this Shape
    void add(Point p)
    {
        points.push_back(p);
        redraw();
    }
    void set_point(int i, Point p)
    {
        points[i] = p;
        redraw();
    }
    void redraw();

private:
    virtual void draw_specifics(Painter &painter) const = 0; // draw this specific shape
    Window * parent_window = nullptr;                          // The window in which the Shape appears
    vector<Point> points;                                     // not used by all shapes
    Color lcolor = Color::black;
    Line_style ls;                   // use the default line style
    Color fcolor = Color::invisible; // fill color
};