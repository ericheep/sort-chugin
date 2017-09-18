Sort s;
s => dac;

s.setInsertion();
s.setEqualize();
s.freq(50.0);

10::second => now;

/*
for (0 => int i; i < samples; i++) {
    <<< s.last() >>>;
    samp => now;
}

<<< "-----------------------", "" >>>;

for (0 => int i; i < samples; i++) {
    <<< s1.last() >>>;
    samp => now;
}

<<< "-----------------------", "" >>>;

for (0 => int i; i < samples; i++) {
    <<< s1.last() >>>;
    samp => now;
}

<<< "-----------------------", "" >>>;

for (0 => int i; i < samples; i++) {
    <<< s1.last() >>>;
    samp => now;
}*/
