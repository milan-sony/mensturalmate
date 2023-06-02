<p align="center">
    <img width="100" src="./assets/icon.png" alt="Icon">
</p>

# MensturalMate

A simple menu driven period calculator build in C language as part of my mini-project in MCA Semester 1

## Run locally

To run this project, you need to install an IDE/Code Editor (<a href = "https://code.visualstudio.com/">Visual Studio Code</a> is preferable) and also a C/C++ compiler on your system. Some popular compilers are:
1. GCC on Linux
2. GCC via Mingw-w64 on Windows
3. Microsoft C++ compiler on windows
4. Clang for XCode on MacOS

Check out this <a href = "https://www.javatpoint.com/how-to-run-a-c-program-in-visual-studio-code"> link </a> to know how to run a C program in Visual Studio Code.

## To compile the code

```bash
  gcc periods_tracker.c -o periods_tracker
```

## Run the code 

```bash
  .\periods_tracker
```

## Sample code
```bash
// stucture to hold the period details
struct period_details
{
    int day;
    int month;
    int year;
    int cycle_length;
    int period_length;
}periods;
```

```bash
    int day = periods.day;
    int month = periods.month;
    int year = periods.year;
    int days_in_month;
```

```bash
for (int i = 0; i < 3; i++){
    day += periods.cycle_length;
    if (day > days_in_month){
        day -= days_in_month;
        month++;
        if (month > 12){
            month = 1;
            year++;
         }
     }
     printf("\t=> \t%d/%d/%d\n\n", day, month, year);
}
```

## Screenshot

<img src="./assets/Screenshot.png">
