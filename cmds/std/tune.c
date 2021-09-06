// tune.c

inherit F_CLEAN_UP;

mapping ch_name = ([
	"chat":		"����(chat)",
	"rumor":	"ҥ��(rumor)",
	"party":	"����(party)",
	"sj":		"�齣(sj)",
	"irc":		"������(irc)",
	"declare":	"��Ϣ(declare)",
]);

int main(object me, string arg)
{
	string *tuned_ch;

	if (arg == "all") {
		write("�ر�����Ƶ����\n");
		me->set("channels", ({}));
		return 1;
	}

	tuned_ch = me->query("channels");
	if (!arg) {
		if (!sizeof(tuned_ch))
			write("�����ڲ�û�������κ�Ƶ����\n");
		else
			write("������������Ƶ����" + implode(tuned_ch, "��") + "��\n");
		return 1;
	}

	if (!tuned_ch) tuned_ch = ({});
	if (member_array(arg, tuned_ch) != -1) {
		tuned_ch -= ({ arg });
		arg = ch_name[arg] ? ch_name[arg] : " " + arg + " ";
		write("�ر�" + arg + "Ƶ����\n");
	} else if (ch_name[arg]) {
		tuned_ch += ({ arg });
		write("��" + ch_name[arg] + "Ƶ����\n");
	} else write("Ҫ��ĳ��Ƶ��ֻҪ�ø�Ƶ��˵�����ɡ�\n");
	me->set("channels", tuned_ch);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��tune [<Ƶ������>]

���ָ������ѡ���Ƿ�Ҫ����ĳһƵ����ѶϢ�����û��ָ��Ƶ�����ƣ��ͻ��г�
��Ŀǰ�����е�Ƶ�������ָ����Ƶ����ԭ�������еľͻ�ص�����֮�򿪡�

������һ��û�������е�Ƶ�����������Զ������򿪡�
Ҫ��һ��Ƶ��������ֻҪ�ã�

<Ƶ������> <ѶϢ> ....

���ӣ�
  chat hello everyone!

������� help channels ��ѯĿǰ����ЩƵ������������

see also : shout
HELP
	);
	return 1;
}
