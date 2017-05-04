const {IsPrime} = require('./build/Release/addon'); // native c++
const isPrime = require('./isPrime'); // js

const number = 654188429; // thirty-fifth million first prime number (see https://primes.utm.edu/lists/small/millions/)
const NATIVE = 'native';
const JS = 'js';

console.time(NATIVE);
console.log(`${NATIVE}: checking whether ${number} is prime... ${IsPrime(number)}`);
console.timeEnd(NATIVE);
console.log('');
console.time(JS);
console.log(`${JS}: checking whether ${number} is prime... ${isPrime(number)}`);
console.timeEnd(JS);
