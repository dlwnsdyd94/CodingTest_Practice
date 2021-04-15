package Problem;
class Solution {
	public boolean detectCapitalUse(String word) {
		int wordLength = word.length();
		int upperCount = 0;
		int lowerCount = 0;

		// case 1
		upperCount = 0;
		for (int i = 0; i < wordLength; i++) {
			if (Character.isUpperCase(word.charAt(i)) == true) {
				upperCount++;
			} else {
				break;
			}
		}
		if (upperCount == wordLength) {
			return true; // case 1 success.
		}

		// case 2
		lowerCount = 0;
		for (int i = 0; i < word.length(); i++) {
			if (Character.isUpperCase(word.charAt(i)) == true) {
				break;
			} else {
				lowerCount++;
			}
		}
		if (lowerCount == wordLength) {
			return true; // case 2 success.
		}

		// case 3
		lowerCount = 0;
		if (Character.isUpperCase(word.charAt(0)) == true) {
			for (int i = 1; i < word.length(); i++) {
				if (Character.isUpperCase(word.charAt(i)) == true) {
					break;
				} else {
					lowerCount++;
				}
			}
		}
		if (lowerCount == wordLength - 1) {
			return true; // case 3 success.
		}

		return false; // all case false.
	}
}