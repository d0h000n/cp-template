mt19937 rng(random_device{}());
#define my_random(l,r) uniform_int_distribution<ll>(l,r)(rng)
#define my_shuffle(...) shuffle(__VA_ARGS__,rng)
