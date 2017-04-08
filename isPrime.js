module.exports = (number) => {
  if (typeof number !== 'number') {
    throw new TypeError('argument must be a number!');
  }

  if (number < 2) {
    return false;
  }

  for (let i = 2; i < number; i++) {
    if (number % i === 0) {
      return false;
    }
  }

  return true;
};