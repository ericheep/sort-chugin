Sort s;
s => dac;

s.setInsertion();
s.setRandom();
s.freq(100.0);
s.size() => int samples;

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
