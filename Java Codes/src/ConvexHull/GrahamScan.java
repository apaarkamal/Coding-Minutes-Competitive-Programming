package ConvexHull;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class GrahamScan {


    static class Point {
        int x, y;

        boolean equals (Point P) {
            return (x == P.x && y == P.y);
        }
    }


    static boolean cw(Point a, Point b, Point c) {
        return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) > 0;
    }

    static boolean  ccw(Point a, Point b, Point c) {
        return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) < 0;
    }

    static boolean  cll(Point a, Point b, Point c) {
        return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) == 0;
    }

    static List<Point> convex_hull(List<Point> points) {
        if (points.size() <= 2) return points;

        points.sort(new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point P) {
                if (o1.x == P.x) return o1.y - P.y;
                else return o1.x - P.x;
            }
        });

        List<Point> up = new ArrayList<>(), down = new ArrayList<>();
        Point first = points.get(0), last = points.get(points.size()-1);

        up.add(first); down.add(first);


        for (int i = 1; i < points.size(); i++) {
            if (i == points.size() - 1 || cw(first, points.get(i), last)) {
                // up set

                while (up.size() >= 2 && !cw(up.get(up.size() - 2), up.get(up.size() - 1), points.get(i))) {
                    up.remove(up.size()-1);
                }

                up.add(points.get(i));

            }
            if (i == points.size() - 1 || ccw(first, points.get(i), last)) {
                // down set

                while (down.size() >= 2 && !ccw(down.get(down.size() - 2), down.get(down.size() - 1), points.get(i))) {
                    down.remove(down.size()-1);
                }

                down.add(points.get(i));

            }
        }

        points.clear();
        for (int i = 0; i < up.size(); i++) {
            points.add(up.get(i));
        }
        for (int i = 0; i < up.size(); i++) {
            points.add(down.get(i));
        }


        points.sort(new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point P) {
                if (o1.x == P.x) return o1.y - P.y;
                else return o1.x - P.x;
            }
        });

        for(int i = points.size()-1; i>=1; i--){
            if(points.get(i).equals(points.get(i-1))){
                points.remove(i);
            }
        }

        return points;
    }

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();

        List<Point> points = new ArrayList<>();


        for (int i = 0; i < n; i++) {
            points.add(new Point());
            points.get(i).x = scn.nextInt();
            points.get(i).y = scn.nextInt();
        }

        List<Point> convex_hull_vector = convex_hull(points);

        for (Point x : convex_hull_vector) {
            System.out.println( x.x + " " + x.y);
        }
    }
}
