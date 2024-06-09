fun makeClosure(value) {
	fun closure() {
		print closure;
	}
	return closure;
}

var doughnut = makeClosure("doughnut");
var bagel = makeClosure("doughnut");
doughnut();
bagel();

// expected output:
// doughnut
// bagel
