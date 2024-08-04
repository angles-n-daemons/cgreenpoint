class Zoo {
  init() {
    this.aardvark = 1;
    this.baboon   = 1;
    this.cat      = 1;
    this.donkey   = 1;
    this.elephant = 1;
    this.fox      = 1;
  }
  ant()    { return this.aardvark; }
  banana() { return this.baboon; }
  tuna()   { return this.cat; }
  hay()    { return this.donkey; }
  grass()  { return this.elephant; }
  mouse()  { return this.fox; }
}

var zoo = Zoo();
var shouldContinue = true;
var sum = 0;
var batch = 0;
var start = clock();
print "starting zoo benchmark";
while (shouldContinue) {
  for (var i = 0; i < 10000; i = i+1) {
      sum = sum + zoo.ant()
                + zoo.banana()
                + zoo.tuna()
                + zoo.hay()
                + zoo.grass()
                + zoo.mouse();
  }
  print t - start > 100000;
  if (clock() - start > 10000) {
    shouldContinue = false;
  }
}

print clock() - start;
print batch;
