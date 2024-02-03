
/**
 * creates all possible sequences of the given rules as `choice` rule.
 * gets out of hand very quickly and is probably not a feasable solution...
 * @ do not use! there HAS to be a better way
 */
function unordered(...rules) {
	if (rules.length == 1) {
		return rules[0];
	}
	if (rules.length == 2) {
		return choice(
			seq(
				rules[0],
				rules[1],
			),
			seq(
				rules[1],
				rules[0],
			),
		);
	}
	let result = [];
	for (let i = 0; i < rules.length; i++) {
		let copy = Object.values(rules);
		copy.splice(i, 1);
		let option = unordered_recursive(result, [rules[i]], ...copy);
	}
	return choice(...result);
}

function unordered_recursive(result, preceding, ...rules) {
	if (rules.length == 2) {
		result.push(
			seq(
				...preceding,
				rules[0],
				rules[1],
			),
		);
		result.push(
			seq(
				...preceding,
				rules[1],
				rules[0],
			),
		);
		return;
	}
	for (let i = 0; i < rules.length; i++) {
		let copy = Object.values(rules);
		copy.splice(i, 1);
		unordered_recursive(
			result,
			[...preceding, rules[i]],
			...copy,
		);
	}
}
