// You are given n triangles, specifically, their sides a, b and c. Print them in the same style but sorted by their areas from the smallest one to the largest one. It is guaranteed that all the areas are different.
// The best way to calculate a area of a triangle with sides a, b and c is Heron's formula

#include <stdio.h>
#include <math.h>   
#include <stdlib.h>

void sort_by_area(triangle* tr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double s1 = (tr[j].a + tr[j].b + tr[j].c) / 2.0;
            double area1 = sqrt(s1 * (s1 - tr[j].a) * (s1 - tr[j].b) * (s1 - tr[j].c));

            double s2 = (tr[j + 1].a + tr[j + 1].b + tr[j + 1].c) / 2.0;
            double area2 = sqrt(s2 * (s2 - tr[j + 1].a) * (s2 - tr[j + 1].b) * (s2 - tr[j + 1].c));

            if (area1 > area2) {
                triangle temp = tr[j];
                tr[j] = tr[j + 1];
                tr[j + 1] = temp;
            }
        }
    }
}
	

int main() {
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}