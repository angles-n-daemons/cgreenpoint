var start = clock();
var shouldContinue = true;
var count = 0;

while (shouldContinue) {
    count = count + 1;
if (count > 5) {
    shouldContinue = false;
    }
  if (clock() - start > 0.5) {
    shouldContinue = false;
  }
}
