Sort s1;
Sort s2;
s1 => dac;
s2 => dac.right;

s1.setBubble();
s1.setRandom();
s1.size(1500);

s2.setBubble();
s2.setRandom();
s2.size(1500);

hour => now;

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
