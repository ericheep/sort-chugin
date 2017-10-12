Sort s;
s => Pan2 pan => dac;

s.setBubble();
s.setEqualize();

now => time start;

0 => int POS;
50 => int SIZE;
1000 => int ROOT;

if (me.args() > 0) Std.atoi(me.arg(0)) => POS;
if (me.args() > 1) Std.atoi(me.arg(1)) => SIZE;
if (me.args() > 2) Std.atoi(me.arg(2)) => ROOT;

POS/3.0  * 2 - 1.0=> pan.pan;
<<< pan.pan() >>>;

int freqs[SIZE];
for (0 => int i; i < SIZE; i++) {
    ROOT + i => freqs[i];
}

fun int isSorted(int arr[]) {
    arr.size() => int SIZE;

    for (int i; i < SIZE - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}


fun void shuffle(int arr[]) {
    arr.size() => int SIZE;
    int tmp;
    int j;

    for (SIZE - 1 => int i; i > 0; i--) {
        Math.random2(0, i) => j;
        arr[j] => tmp;
        arr[i] => arr[j];
        tmp => arr[i];
    }
}

fun void bubbleSort(int arr[], int stepTotal) {
    0 => int steps;
    arr.size() => int SIZE;
    for (0 => int i; i < (SIZE - 1); i++)
    {
        for (0 => int j; j < SIZE - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                if (steps > stepTotal) return;

                arr[j]     => int swap;
                arr[j + 1] => arr[j];
                swap       => arr[j + 1];
                steps++;
            }
        }
    }
}

0 => int stepTotal;
shuffle(freqs);

while (!isSorted(freqs)) {
    bubbleSort(freqs, stepTotal);
    stepTotal++;

    for (0 => int i; i < freqs.size(); i++) {
        <<< i, ":", freqs[i] >>>;
        s.freq(freqs[i]);

        while (!s.sorted()) {
            1::samp => now;
        }
        while (s.sorted()) {
            1::samp => now;
        }
    }
    <<< "-", (now - start)/second >>>;
}
