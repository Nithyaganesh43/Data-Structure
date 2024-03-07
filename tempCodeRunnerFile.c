// MOM
#include <stdio.h>
#include <math.h>
#include <complex.h>


double add(double a, double b); // Addition
double subtract(double a, double b); // Subtraction
double multiply(double a, double b); // Multiplication
double divide(double a, double b); // Division
double modulo(double a, double b); // Modulo
double power(double base, double exponent); // Power
double squareRoot(double x); // Square Root
double cubeRoot(double x); // Cube Root
double sinFunction(double angle); // Sine
double cosFunction(double angle); // Cosine
double tanFunction(double angle); // Tangent
void solveQuadratic(double a, double b, double c); // Solve Quadratic Equation
void solveCubic(double a, double b, double c, double d); // Solve Cubic Equation
double logarithm(double base, double x); // Logarithm
double areaRectangle(double length, double width); // Area of Rectangle
double areaCircle(double radius); // Area of Circle
double areaTriangle(double base, double height); // Area of Triangle
double areaSquare(double side); // Area of Square
double areaRhombus(double diagonal1, double diagonal2); // Area of Rhombus
double areaParallelogram(double base, double height); // Area of Parallelogram
double areaTrapezium(double base1,double base2, double height); // Area of Trapezium
double volumeSphere(double radius); // Volume of Sphere
double volumeCube(double side); // Volume of Cube
double volumeCuboid(double length, double width, double height); // Volume of Cuboid
double volumeCylinder(double radius, double height); // Volume of Cylinder
double volumeHemisphere(double radius); // Volume of Hemisphere
double volumeCone(double radius, double height); // Volume of Cone
void differentiateAndSubstitute(double a, double b, double c, double x); // Differentiate and Substitute
void integrateAndSubstitute(double a, double b, double c, double x); // Integrate and Substitute
void matrixAddition(); // Matrix Addition
void matrixSubtraction(); // Matrix Subtraction
void matrixMultiplication(); // Matrix Multiplication
void matrixInversion(); // Matrix Inversion
void matrixTranspose(); // Matrix Transpose
void complexAddition(); // Complex Addition
void complexSubtraction(); // Complex Subtraction
void complexMultiplication(); // Complex Multiplication
void vectorAddition(); // Vector Addition
void vectorSubtraction(); // Vector Subtraction
double cubeRoot(double x);
double cotangent(double x); // Cotangent
double secant(double x);    // Secant
double cosecant(double x);  // Cosecant
double arcsin(double x);    // Arcsine
double arccos(double x);    // Arccosine
double arctan(double x);    // Arctangent
double arccot(double x);    // Arccotangent
double arcsec(double x);    // Arcsecant
double arccsc(double x);    // Arccosecant
int main() {
    int choice;
    double num1, num2, num3, result;

    do {
        printf("\n\t\t\t\t MOM Calculator \n\n\n");
        printf("Press 1 For Addition\n");
        printf("Press 2 For Subtraction\n");
        printf("Press 3 For Multiplication\n");
        printf("Press 4 For Division\n");
        printf("Press 5 For Modulo\n");
        printf("Press 6 For Power\n");
        printf("Press 7 For Square Root\n");
        printf("Press 8 For Sine\n");
        printf("Press 9 For Cosine\n");
        printf("Press 10 For Tangent\n");
        printf("Press 11 To Solve Quadratic Equation\n");
        printf("Press 12 To Solve Cubic Equation\n");
        printf("Press 13 For Logarithm\n");
        printf("Press 14 For Area of Rectangle\n");
        printf("Press 15 For Area of Circle\n");
        printf("Press 16 For Area of Triangle\n");
        printf("Press 17 For Area of Square\n");
        printf("Press 18 For Area of Rhombus\n");
        printf("Press 19 For Area of Parallelogram\n");
        printf("Press 20 For Area of Trapezium\n");
        printf("Press 21 For Volume of Sphere\n");
        printf("Press 22 For Volume of Cube\n");
        printf("Press 23 For Volume of Cuboid\n");
        printf("Press 24 For Volume of Cylinder\n");
        printf("Press 25 For Volume of Hemisphere\n");
        printf("Press 26 For Volume of Cone\n");
        printf("Press 27 To Differentiate and Substitute\n");
        printf("Press 28 To Integrate and Substitute\n");
        printf("Press 29 For Matrix Addition\n");
        printf("Press 30 For Matrix Subtraction\n");
        printf("Press 31 For Matrix Multiplication\n");
        printf("Press 32 For Matrix Inversion\n");
        printf("Press 33 For Matrix Transpose\n");
        printf("Press 34 For Complex Addition\n");
        printf("Press 35 For Complex Subtraction\n");
        printf("Press 36 For Complex Multiplication\n");
        printf("Press 37 For Vector Addition\n");
        printf("Press 38 For Vector Subtraction\n");
        printf("Press 39 For Cube Root\n");
        printf("Press 39 For Cube Root\n");
        printf("Press 40 For Cotangent\n");
        printf("Press 41 For Secant\n");
        printf("Press 42 For Cosecant\n");
        printf("Press 43 For Arcsine\n");
        printf("Press 44 For Arccosine\n");
        printf("Press 45 For Arctangent\n");
        printf("Press 46 For Arccotangent\n");
        printf("Press 47 For Arcsecant\n");
        printf("Press 48 For Arccosecant\n");
        printf("Press 0 To Exit\n\n\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n\n\n\n");

        switch (choice) {
            case 1:
                // Addition
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = add(num1, num2);
                printf("Addition: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 2:
                // Subtraction
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = subtract(num1, num2);
                printf("Subtraction: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 3:
                // Multiplication
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = multiply(num1, num2);
                printf("Multiplication: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 4:
                // Division
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                if (num2 != 0) {
                    result = divide(num1, num2);
                    printf("Division: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                } else {
                    printf("Error: Division by zero is undefined.\n");
                }
                break;

            case 5:
                // Modulo
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                if (num2 != 0) {
                    result = modulo(num1, num2);
                    printf("Modulo: fmod(%.2lf, %.2lf) = %.2lf\n", num1, num2, result);
                } else {
                    printf("Error: Modulo by zero is undefined.\n");
                }
                break;

            case 6:
                // Power
                printf("Enter base and exponent: ");
                scanf("%lf %lf", &num1, &num2);
                result = power(num1, num2);
                printf("Power: pow(%.2lf, %.2lf) = %.2lf\n", num1, num2, result);
                break;

            case 7:
                // Square Root
                printf("Enter a number: ");
                scanf("%lf", &num1);
                if (num1 >= 0) {
                    result = squareRoot(num1);
                    printf("Square Root: sqrt(%.2lf) = %.2lf\n", num1, result);
                } else {
                    printf("Error: Square root of a negative number is undefined.\n");
                }
                break;

            case 8:
                // Sine
                printf("Enter an angle in degrees: ");
                scanf("%lf", &num1);
                result = sinFunction(num1);
                printf("Sine: sin(%.2lf degrees) = %.2lf\n", num1, result);
                break;

            case 9:
                // Cosine
                printf("Enter an angle in degrees: ");
                scanf("%lf", &num1);
                result = cosFunction(num1);
                printf("Cosine: cos(%.2lf degrees) = %.2lf\n", num1, result);
                break;

            case 10:
                // Tangent
                printf("Enter an angle in degrees: ");
                scanf("%lf", &num1);
                result = tanFunction(num1);
                printf("Tangent: tan(%.2lf degrees) = %.2lf\n", num1, result);
                break;

            case 11:
                // Solve Quadratic Equation
                printf("Enter coefficients a, b, and c: ");
                scanf("%lf %lf %lf", &num1, &num2, &num3);
                solveQuadratic(num1, num2, num3);
                break;

            case 12:
                // Solve Cubic Equation
                printf("Enter coefficients a, b, c, and d: ");
                scanf("%lf %lf %lf %lf", &num1, &num2, &num3, &num3);
                solveCubic(num1, num2, num3, num3);
                break;

            case 13:
                // Logarithm
                printf("Enter base and number: ");
                scanf("%lf %lf", &num1, &num2);
                if (num1 > 0 && num1 != 1 && num2 > 0) {
                    result = logarithm(num1, num2);
                    printf("Logarithm: log_%.2lf(%.2lf) = %.2lf\n", num1, num2, result);
                } else {
                    printf("Error: Invalid input for logarithm.\n");
                }
                break;

            case 14:
                // Area of Rectangle
                printf("Enter length and width: ");
                scanf("%lf %lf", &num1, &num2);
                result = areaRectangle(num1, num2);
                printf("Area of Rectangle: %.2lf units\n", result);
                break;

            case 15:
                // Area of Circle
                printf("Enter radius: ");
                scanf("%lf", &num1);
                result = areaCircle(num1);
                printf("Area of Circle: %.2lf square units\n", result);
                break;

            case 16:
                // Area of Triangle
                printf("Enter base and height: ");
                scanf("%lf %lf", &num1, &num2);
                result = areaTriangle(num1, num2);
                printf("Area of Triangle: %.2lf square units\n", result);
                break;

            case 17:
                // Area of Square
                printf("Enter side length: ");
                scanf("%lf", &num1);
                result = areaSquare(num1);
                printf("Area of Square: %.2lf square units\n", result);
                break;

            case 18:
                // Area of Rhombus
                printf("Enter diagonals length: ");
                scanf("%lf %lf", &num1, &num2);
                result = areaRhombus(num1, num2);
                printf("Area of Rhombus: %.2lf square units\n", result);
                break;

            case 19:
                // Area of Parallelogram
                printf("Enter base and height: ");
                scanf("%lf %lf", &num1, &num2);
                result = areaParallelogram(num1, num2);
                printf("Area of Parallelogram: %.2lf square units\n", result);
                break;

            case 20:
                // Area of Trapezium
                printf("Enter lengths of bases and height: ");
                scanf("%lf %lf %lf", &num1, &num2, &num3);
                result = areaTrapezium(num1, num2, num3);
                printf("Area of Trapezium: %.2lf square units\n", result);
                break;

            case 21:
                // Volume of Sphere
                printf("Enter radius: ");
                scanf("%lf", &num1);
                result = volumeSphere(num1);
                printf("Volume of Sphere: %.2lf cubic units\n", result);
                break;

            case 22:
                // Volume of Cube
                printf("Enter side length: ");
                scanf("%lf", &num1);
                result = volumeCube(num1);
                printf("Volume of Cube: %.2lf cubic units\n", result);
                break;

            case 23:
                // Volume of Cuboid
                printf("Enter length, width, and height: ");
                scanf("%lf %lf %lf", &num1, &num2, &num3);
                result = volumeCuboid(num1, num2, num3);
                printf("Volume of Cuboid: %.2lf cubic units\n", result);
                break;

            case 24:
                // Volume of Cylinder
                printf("Enter radius and height: ");
                scanf("%lf %lf", &num1, &num2);
                result = volumeCylinder(num1, num2);
                printf("Volume of Cylinder: %.2lf cubic units\n", result);
                break;

            case 25:
                // Volume of Hemisphere
                printf("Enter radius: ");
                scanf("%lf", &num1);
                result = volumeHemisphere(num1);
                printf("Volume of Hemisphere: %.2lf cubic units\n", result);
                break;

            case 26:
                // Volume of Cone
                printf("Enter radius and height: ");
                scanf("%lf %lf", &num1, &num2);
                result = volumeCone(num1, num2);
                printf("Volume of Cone: %.2lf cubic units\n", result);
                break;

            case 27:
                // Differentiate and Substitute
                printf("Enter coefficients a, b, c, and x: ");
                scanf("%lf %lf %lf %lf", &num1, &num2, &num3, &num3);
                differentiateAndSubstitute(num1, num2, num3, num3);
                break;
    case 28:
        // Integrate and Substitute
        printf("Enter coefficients a, b, and c of the quadratic equation: ");
        scanf("%lf %lf %lf", &num1, &num2, &num3);
        printf("Enter the value of x: ");
        scanf("%lf", &result);
        integrateAndSubstitute(num1, num2, num3, result);
        break;

    case 29:
        // Matrix Addition
        matrixAddition();
        break;

    case 30:
        // Matrix Subtraction

                matrixSubtraction();
        break;

    case 31:
        // Matrix Multiplication
        matrixMultiplication();
        break;

    case 32:
        // Matrix Inversion
        matrixInversion();
        break;

    case 33:
        // Matrix Transpose
        matrixTranspose();
        break;

    case 34:
        // Complex Addition
        complexAddition();
        break;

    case 35:
        // Complex Subtraction
        complexSubtraction();
        break;

    case 36:
        // Complex Multiplication
        complexMultiplication();
        break;

    case 37:
        // Vector Addition
        vectorAddition();
        break;

    case 38:
        // Vector Subtraction
        vectorSubtraction();
        break;
    case 39:
                // Cube Root
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = cubeRoot(num1);
                printf("Cube Root: cbrt(%.2lf) = %.2lf\n", num1, result);
                break;

            case 40:
                // Cotangent
                printf("Enter an angle in degrees: ");
                scanf("%lf", &num1);
                result = cotangent(num1);
                printf("Cotangent: cot(%.2lf) = %.2lf\n", num1, result);
                break;

            case 41:
                // Secant
                printf("Enter an angle in degrees: ");
                scanf("%lf", &num1);
                result = secant(num1);
                printf("Secant: sec(%.2lf) = %.2lf\n", num1, result);
                break;

            case 42:
                // Cosecant
                printf("Enter an angle in degrees: ");
                scanf("%lf", &num1);
                result = cosecant(num1);
                printf("Cosecant: csc(%.2lf) = %.2lf\n", num1, result);
                break;
                case 43:
                // Arcsine
                printf("Enter a value between -1 and 1: ");
                scanf("%lf", &num1);
                result = arcsin(num1);
                printf("Arcsine: asin(%.2lf) = %.2lf degrees\n", num1, result);
                break;

            case 44:
                // Arccosine
                printf("Enter a value between -1 and 1: ");
                scanf("%lf", &num1);
                result = arccos(num1);
                printf("Arccosine: acos(%.2lf) = %.2lf degrees\n", num1, result);
                break;

            case 45:
                // Arctangent
                printf("Enter a value: ");
                scanf("%lf", &num1);
                result = arctan(num1);
                printf("Arctangent: atan(%.2lf) = %.2lf degrees\n", num1, result);
                break;

            case 46:
                // Arccotangent
                printf("Enter a value: ");
                scanf("%lf", &num1);
                result = arccot(num1);
                printf("Arccotangent: acot(%.2lf) = %.2lf degrees\n", num1, result);
                break;

            case 47:
                // Arcsecant
                printf("Enter a value greater than or equal to 1: ");
                scanf("%lf", &num1);
                result = arcsec(num1);
                printf("Arcsecant: asec(%.2lf) = %.2lf degrees\n", num1, result);
                break;

            case 48:
                // Arccosecant
                printf("Enter a value less than or equal to -1: ");
                scanf("%lf", &num1);
                result = arccsc(num1);
                printf("Arccosecant: acsc(%.2lf) = %.2lf degrees\n", num1, result);
                break;


    case 0:
        // Exit
        printf("Exiting calculator.\n");
        return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                continue;
        }

              printf("Result: %lf\n", result);

    } while (1);

    return 0;
}
double cotangent(double x) {
    return 1.0 / tan(x * M_PI / 180.0);
}

double secant(double x) {
    return 1.0 / cos(x * M_PI / 180.0);
}

double cosecant(double x) {
    return 1.0 / sin(x * M_PI / 180.0);
}
void solveQuadratic(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots: %lf, %lf\n", root1, root2);
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        printf("Double root: %lf\n", root);
    } else {
        printf("Complex roots.\n");
    }
}

// ...

void solveCubic(double a, double b, double c, double d) {
    double discriminant = b * b - 3 * a * c;

    int numRealRoots = 0;
    int numImaginaryRoots = 0;

    if (discriminant > 0) {
        numRealRoots = 3;
    } else if (discriminant == 0) {
        numRealRoots = 1;
    } else {
        numRealRoots = 1;
        numImaginaryRoots = 2;
    }

    // Display the number of real and imaginary roots
    printf("Number of Real Roots: %d\n", numRealRoots);
    printf("Number of Imaginary Roots: %d\n", numImaginaryRoots);
}



double areaRectangle(double length, double width) {
    return length * width;
}

double areaCircle(double radius) {
    return M_PI * radius * radius;
}

double areaTriangle(double base, double height) {
    return 0.5 * base * height;
}

double volumeSphere(double radius) {
    return (4.0 / 3.0) * M_PI * pow(radius, 3);
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero\n");
        return 0;
    }
}
double modulo(double a, double b) {
    if (b != 0) {
    return fmod(a, b);
}
    else {
    printf("Error: Modulus by zero\n");
    return 0;
}
}
double power(double base, double exponent) {
    return pow(base, exponent);
}

double squareRoot(double x) {
    if (x >= 0) {
        return sqrt(x);
    } else {
        printf("Error: Cannot calculate square root of a negative number\n");
        return 0;
    }
}

double sinFunction(double angle) {
    return sin(angle * M_PI / 180.0);
}

double cosFunction(double angle) {
    return cos(angle * M_PI / 180.0);
}

double tanFunction(double angle) {
    return tan(angle * M_PI / 180.0);
}

double logarithm(double base, double x) {
    if (base > 0 && base != 1 && x > 0) {
        return log(x) / log(base);
    } else {
        printf("Error: Invalid base or argument for logarithm\n");
        return 0;
    }

}
void differentiateAndSubstitute(double a, double b, double c, double x) {
    double derivative = 2 * a * x + b;
    double result = a * x * x + b * x + c;
    printf("Original equation: %.2lfx^2 + %.2lfx + %.2lf\n", a, b, c);
    printf("Differentiated equation: %.2lfx + %.2lf\n", 2 * a, b);
    printf("Result: %.2lf\n", result);
}

void integrateAndSubstitute(double a, double b, double c, double x) {
    double integral_a = a / 3.0;
    double integral_b = b / 2.0;
    double integral_c = c;
    double integral_result = (integral_a * pow(x, 3)) + (integral_b * pow(x, 2)) + (integral_c * x);

    printf("Original equation: %.2lfx^2 + %.2lfx + %.2lf\n", a, b, c);
    printf("Integrated equation: (%.2lf/3)x^3 + (%.2lf/2)x^2 + %.2lfx\n", a, b, c);
    printf("Result: %.2lf\n", integral_result);
}

void matrixAddition() {
    int m, n;

    printf("Enter the number of rows and columns of the matrices: ");
    scanf("%d %d", &m, &n);

    int matrix1[m][n], matrix2[m][n], result[m][n];

    printf("Enter elements of matrix 1:\n");
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &matrix1[i][j]);

    printf("Enter elements of matrix 2:\n");
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &matrix2[i][j]);

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            result[i][j] = matrix1[i][j] + matrix2[i][j];

    printf("Result of Matrix Addition:\n");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%d ", result[i][j]);
        printf("\n");
    }
}

void matrixSubtraction() {
    int m, n;

    printf("Enter the number of rows and columns of the matrices: ");
    scanf("%d %d", &m, &n);

    int matrix1[m][n], matrix2[m][n], result[m][n];

    printf("Enter elements of matrix 1:\n");
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &matrix1[i][j]);

    printf("Enter elements of matrix 2:\n");
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &matrix2[i][j]);

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            result[i][j] = matrix1[i][j] - matrix2[i][j];

    printf("Result of Matrix Addition:\n");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%d ", result[i][j]);
        printf("\n");
    }
}

void matrixMultiplication() {
    int m, n, p;

    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d %d", &m, &n);
    printf("Enter the number of columns of matrix 2: ");
    scanf("%d", &p);

    int matrix1[m][n], matrix2[n][p], result[m][p];

    printf("Enter elements of matrix 1:\n");
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &matrix1[i][j]);

    printf("Enter elements of matrix 2:\n");
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < p; ++j)
            scanf("%d", &matrix2[i][j]);

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < p; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < n; ++k)
                result[i][j] += matrix1[i][k] * matrix2[k][j];
        }

    printf("Result of Matrix Multiplication:\n");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j)
            printf("%d ", result[i][j]);
        printf("\n");
    }
}
void inverseMatrix(double matrix[][10], double result[][10], int n);

void matrixInversion() {
    int n;

    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);

    double matrix[10][10];
    double result[10][10];

    printf("Enter elements of the square matrix:\n");
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%lf", &matrix[i][j]);

    inverseMatrix(matrix, result, n);

    printf("\nInverse Matrix:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%lf ", result[i][j]);
        printf("\n");
    }
}

void inverseMatrix(double matrix[][10], double result[][10], int n) {
    // Create an augmented matrix [matrix | I]
    double augmentedMatrix[10][20];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            augmentedMatrix[i][j] = matrix[i][j];
            augmentedMatrix[i][j + n] = (i == j) ? 1.0 : 0.0;
        }
    }

    // Apply Gaussian elimination to the augmented matrix
    for (int i = 0; i < n; i++) {
        // Make the diagonal element 1
        double diagonalElement = augmentedMatrix[i][i];
        for (int j = 0; j < 2 * n; j++) {
            augmentedMatrix[i][j] /= diagonalElement;
        }

        // Make the other elements in the column 0
        for (int k = 0; k < n; k++) {
            if (i != k) {
                double scale = -augmentedMatrix[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    augmentedMatrix[k][j] += scale * augmentedMatrix[i][j];
                }
            }
        }
    }

    // Extract the inverse matrix from the augmented matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = augmentedMatrix[i][j + n];
        }
    }
}

void matrixTranspose() {
    int m, n;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &m, &n);

    double matrix[m][n];

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &matrix[i][j]);

    double transpose[n][m];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            transpose[j][i] = matrix[i][j];

    printf("Result of Matrix Transpose:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            printf("%d ", transpose[i][j]);
        printf("\n");
    }
}
double volumeCube(double side) {
    return pow(side, 3);
}

double volumeCuboid(double length, double width, double height) {
    return length * width * height;
}

double volumeCylinder(double radius, double height) {
    return M_PI * pow(radius, 2) * height;
}


double volumeHemisphere(double radius) {
    return (2.0 / 3.0) * M_PI * pow(radius, 3);
}

double volumeCone(double radius, double height) {
    return (1.0 / 3.0) * M_PI * pow(radius, 2) * height;
}
double areaSquare(double side) {
    return side * side;
}

double areaRhombus(double diagonal1, double diagonal2) {
    return (diagonal1 * diagonal2) / 2.0;
}

double areaParallelogram(double base, double height) {
    return base * height;
}

double areaTrapezium(double base1, double base2, double height) {
    return ((base1 + base2) / 2.0) * height;
}
void complexAddition() {
    int real1, imag1, real2, imag2;

    printf("Enter real part of the first complex number (x): ");
    scanf("%d", &real1);

    printf("Enter imaginary part of the first complex number (y): ");
    scanf("%d", &imag1);

    printf("Enter real part of the second complex number (x): ");
    scanf("%d", &real2);

    printf("Enter imaginary part of the second complex number (y): ");
    scanf("%d", &imag2);

    int result_real = real1 + real2;
    int result_imag = imag1 + imag2;

    printf("Result: %d+%di\n", result_real, result_imag);
}

void complexSubtraction() {
    int real1, imag1, real2, imag2;

    printf("Enter real part of the first complex number (x): ");
    scanf("%d", &real1);

    printf("Enter imaginary part of the first complex number (y): ");
    scanf("%d", &imag1);

    printf("Enter real part of the second complex number (x): ");
    scanf("%d", &real2);

    printf("Enter imaginary part of the second complex number (y): ");
    scanf("%d", &imag2);

    int result_real = real1 - real2;
    int result_imag = imag1 - imag2;

    printf("Result: %d+%di\n", result_real, result_imag);
}

void complexMultiplication() {
    int real1, imag1, real2, imag2;

    printf("Enter real part of the first complex number (x): ");
    scanf("%d", &real1);

    printf("Enter imaginary part of the first complex number (y): ");
    scanf("%d", &imag1);

    printf("Enter real part of the second complex number (x): ");
    scanf("%d", &real2);

    printf("Enter imaginary part of the second complex number (y): ");
    scanf("%d", &imag2);

    int result_real = real1 * real2 - imag1 * imag2;
    int result_imag = real1 * imag2 + imag1 * real2;

    printf("Result: %d+%di\n", result_real, result_imag);
}

void vectorAddition() {
    int n = 3;  // Fix the dimension as 3
    double vector1[n], vector2[n], result[n];

    printf("Enter elements of the first vector (i j k form):\n");
    for (int i = 0; i < n; ++i)
        scanf("%lf", &vector1[i]);

    printf("Enter elements of the second vector (i j k form):\n");
    for (int i = 0; i < n; ++i)
        scanf("%lf", &vector2[i]);

    for (int i = 0; i < n; ++i)
        result[i] = vector1[i] + vector2[i];

    printf("Result of Vector Addition: %di + %dj + %dk\n", result[0], result[1], result[2]);
}

void vectorSubtraction() {
    int n = 3;  // Fix the dimension as 3
    double vector1[n], vector2[n], result[n];

    printf("Enter elements of the first vector (i j k form):\n");
    for (int i = 0; i < n; ++i)
        scanf("%lf", &vector1[i]);

    printf("Enter elements of the second vector (i j k form):\n");
    for (int i = 0; i < n; ++i)
        scanf("%lf", &vector2[i]);

    for (int i = 0; i < n; ++i)
        result[i] = vector1[i] - vector2[i];

    printf("Result of Vector Subtraction: %di + %dj + %dk\n", result[0], result[1], result[2]);
}

double cubeRoot(double x) {
    return cbrt(x);
}
double arcsin(double x) {
    if (x >= -1 && x <= 1) {
        return asin(x) * 180.0 / M_PI;
    } else {
        printf("Error: Input value must be between -1 and 1 for arcsine function.\n");
        return 0.0;
    }
}

double arccos(double x) {
    if (x >= -1 && x <= 1) {
        return acos(x) * 180.0 / M_PI;
    } else {
        printf("Error: Input value must be between -1 and 1 for arccosine function.\n");
        return 0.0;
    }
}

double arctan(double x) {
    return atan(x) * 180.0 / M_PI;
}

double arccot(double x) {
    return atan(1.0 / x) * 180.0 / M_PI;
}

double arcsec(double x) {
    if (x >= 1) {
        return acos(1.0 / x) * 180.0 / M_PI;
    } else {
        printf("Error: Input value must be greater than or equal to 1 for arcsecant function.\n");
        return 0.0;
    }
}

double arccsc(double x) {
    if (x <= -1) {
        return asin(1.0 / x) * 180.0 / M_PI;
    } else {
        printf("Error: Input value must be less than or equal to -1 for arccosecant function.\n");
        return 0.0;
    }
}