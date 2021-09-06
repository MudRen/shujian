// to.c

// inherit F_CLEAN_UP;
// Don't want this command be cleaned up while typing long string.

int help(object);

int main(object me, string arg)
{
	if (!arg)
		return help(me);
	if (!wiz_level(me)) {
		string cmd;

		if (sscanf(arg, "%s ", cmd)!=1)
			cmd = arg;
		switch(cmd) {
			case "reply":
			case "describe": break;
			default: return help(me);
		}
	}
	me->edit( (: call_other, this_object(), "do_to" , me, arg :) );
	return 1;
}

void do_to(object me, string arg, string str)
{
	seteuid(getuid());
	str = str[0..<2];
	if (strlen(str) > 800) {tell_object(me, "����̫����\n"); return;}
	if(arg) me->force_me(arg + " " + str);
	else me->force_me(str);
}

int help(object me)
{
write(@HELP
ָ���ʽ : to <ָ��>

����һ������������ϵ����֡�
ָ�Χ�ǣ�describe��reply��

������
to describe
�����뿪�� . ȡ�������� q
������������������������������������������������������������������������������
1: ������̽��� : ˹ŵ��
2: ���������߷��������� : Xiaoyao
3: ��������������㲿���� : ���Ź�
4: ������ߴ�첿���� : �̱̱�
5: .

�����Լ���������������ˡ�

HELP
    );
    return 1;
}
