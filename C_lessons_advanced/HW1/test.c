#include <stdio.h>

int main() {
    double weight = 0.0; // Вес взвешиваемого объекта
    int numberOfGrains = 0; // Количество гирь
    int grainMass = 1; // Масса одной гири

    // Считываем вес взвешиваемого объекта
    scanf("%lf", &weight);

    // Определяем количество гирь
    while (weight > 0) {
        numberOfGrains += weight / grainMass;
        weight -= (weight / grainMass) * grainMass;
        grainMass *= 3;
    }

    // Выводим результат
    printf("%d\n", numberOfGrains);

    return 0;
}