// fun a(x) {
// 	fun b() {
// 		// fun c() {
// 			print x;
// 		//}
// 		//return c;
// 	}
// 	return b;
// }
// a(5)();
fun outer() {
  var x = "outside";
  fun inner() {
    print x;
  }
  inner();
}
outer();
