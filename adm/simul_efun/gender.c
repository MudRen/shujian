// gender.c

string gender_self(string sex)
{
	switch(sex) {
		case "Ů��": return "��";
		default: return "��";
	}
}

string gender_pronoun(string sex)
{
	switch(sex) {
		case "������":	return "��";
		case "����":	return "��";
		case "����":    return "��";
		case "Ů��":	return "��";
		case "����":
		case "����":	return "��";
		default: return "��";
	}
}
