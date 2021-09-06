// Written by snowman
// Modified by look
// Modified by bbb 99/11/02
// rewrite by snowman@SJ 25/12/1999
// Modified by snowman@SJ 04/02/2000 -- Adapted to updated.c
// ����Ҫ�������ƣ�����ǿ YUJ@SJ 2001-0530
// �����������ǿ��... ��ף���˸�Ů��... augx@sj 3/8/2002

#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_SAVE;

mapping types = ([]);
string gift_temp = "";
string gift_desc = "";
int start_time;
int duration;
int sex;

nosave mapping add_types =
([
	"combat_exp":	({ "ʵս����", "add" }),
	"potential":	({ "Ǳ��", "add" }),
	"max_neili":	({ "�������", "add" }),
	"max_jingli":	({ "�����", "add" }),
	"balance":	({ "���", "add" }),
        "relife/gifts/now":        ({ "�������Ե�", "add" }),
        "relife/gifts/total":        ({ "���Ե�", "add" }),
	"jingli":	({ "����", "add" }),
	"food":		({ "ʳ��", "add" }),
	"water":	({ "��ˮ", "add" }),
  "qn_balance":	({ "Ǳ�����д��", "add" }),
	"apply/dodge":	({ "��ʱ�����Ṧ", "add_temp" }),
 	"beauty":	({ "פ����", "add" }),
        "SJ_Credit":    ({ "�齣ͨ��", "add" }),
        "party_cont":    ({ "���ɹ���", "add" }),
]);

int help(object me);

string query_save_file()
{
	return "/log/gift";
}

void create()
{
	seteuid(getuid());
	restore();
	if (time() > start_time + duration)
	{
		types = ([ ]);
		gift_temp = "";
		gift_desc = "";
		if (UPDATE_D->query_new_gift())
			UPDATE_D->have_new_gift();
	}
	else if (!UPDATE_D->query_new_gift())
		UPDATE_D->have_new_gift();
}

mapping query_types()
{
	return types;
}

int main(object me, string arg)
{
	string *str, msg;
	int j, i;

	if (wiz_level(me) < 4) return notify_fail("��������......����û�����ʾһ�°ɡ�\n");

	if (!arg ) return help(me);

	if (arg == "set"){
		types = ([ ]);
		gift_temp = "";
		gift_desc = "";
		if (UPDATE_D->query_new_gift())
			UPDATE_D->have_new_gift();
		save();
		return notify_fail("�����setting �����ϡ�\n");
	}
	if( arg == "?" )
	{
		if (sizeof(types) < 1)
			return notify_fail("�������û���趨�κ���Ʒ��\n");
		msg = "";
		for (j=0; j<sizeof(types); j++)
			msg += add_types[keys(types)[j]][0] + "(" + types[keys(types)[j]] + ") ";
		msg += "\n";
		if ((i = start_time - time()) > 0)
			tell_object(me, "���뿪ʼ����Ʒ��ʱ�仹�У�" + CHINESE_D->chinese_time(i) + "��\n");
		else if ((i += duration) > 0)
			tell_object(me, "�����������Ʒ��ʱ�仹�У�" + CHINESE_D->chinese_time(i) + "��\n");
		return notify_fail("�������¼Ϊ��"+gift_temp+"������Ϊ��"+msg);
	}
	if (sscanf(arg,"send %s", msg) == 1)
	{
		int st, dur;

		if (UPDATE_D->query_new_gift())
			return notify_fail("������������ǰһ����Ʒ���趨��\n");
		if (sscanf(msg,"%s %s %d %d %d", gift_desc, gift_temp, sex, st, dur) == 5)
		{
			if (sizeof(types) < 1)
				return notify_fail("�������������ǰ���� gift set < > to < > �趨������\n");
			if (!stringp(gift_temp) || gift_temp == "")
				return notify_fail("����������趨��Ʒ�ļ�¼��\n");
			if (!stringp(gift_desc) || gift_desc == "")
				return notify_fail("����������趨��Ʒ��������\n");
			if (dur < 0)
				return notify_fail("���������ʱ�䲻��С���㡣\n");
			if (sex<0 || sex>2)
				return notify_fail("����������Ա������0��1��2��\n");

			msg = "";
			for (j=0; j<sizeof(types); j++)
				msg += add_types[keys(types)[j]][0] + "(" + types[keys(types)[j]] + ") ";

			msg += "\n";
			if(gift_temp != "test"){
				start_time = time() + st;
				duration = dur;
				log_file("static/GIFTS",
					sprintf("%s ���� %s �����־Ϊ %s\n�����ǣ�%s",
						me->query("id"), gift_desc, gift_temp, msg
					), me
				);
			}
			save();
			if (UPDATE_D->have_new_gift())
				return notify_fail("\n���������Ϊ��"+msg);
			else return notify_fail("\n���������UPDATE_D ����ʧ�ܣ�\n");
		}
		return notify_fail("��������� gift send <����> <��¼> <��ʼ> <����> �ĸ�ʽ��\n");
	}
	if (sscanf(arg, "set %s to %d", msg, j) == 2)
	{
		if (UPDATE_D->query_new_gift())
			return notify_fail("������������ǰһ����Ʒ���趨��\n");
		str = keys(add_types);
		for (i = 0; i < sizeof(str); i++)
			if( msg == str[i]) {
				types[msg] = j;
				msg = "";
				for (j = 0;  j < sizeof(types); j++)
					msg += add_types[keys(types)[j]][0] + "(" + types[keys(types)[j]] + ") ";
				save();
				return notify_fail("�������ƷΪ "+ msg +"\n");
			}
		 return notify_fail("�������Ʒ�������Ѿ������˵�һ�֡�\n");
	}
	return notify_fail("��������� gift set < > to < > ���趨������� gift send �����͡�\n");
}

int launching(object me)
{
	int i = time(), j;
	string *str, msg;

	if (!stringp(gift_temp) || gift_temp == "")
		return 0;
	if ((j = start_time - i) > 0) {
		if (wizardp(me))
			tell_object(me, "���뿪ʼ����Ʒ��ʱ�仹�У�" + CHINESE_D->chinese_time(j) + "��\n");
		return 0;
	}
	if (i >= start_time + duration) {
		types = ([ ]);
		gift_temp = "";
		gift_desc = "";
		if (UPDATE_D->query_new_gift())
			UPDATE_D->have_new_gift();
		save();
		return 0;
	}
	if (wizardp(me)) {
		tell_object(me, HIY"�������ڷ��������־Ϊ "HIR+gift_temp+HIY"���������� gift ? �鿴��\n"NOR);
		return 0;
	}
	if (me->query("gift/time") >= start_time) return 0;

	if (gift_temp == "test") return 0;
	
	//mud_time	5404861
	//mud_age       5404885
	//
	//if (me->query("mud_age")/6 > me->query("combat_exp")) {	// ÿʮ���� >= 100 exp
	//	if (me->query("online_total") < 3600) {
	//		me->set("gift/time", start_time + duration);
	//		me->set("gift/name", gift_temp);
	//	}

	if (!me->query("gift/last_time"))
		me->set("gift/last_time", me->query("birthday"));

/*
	if (me->query("registered") < 3
	&& (me->query("mud_time") - me->query("gift/mud_time")) < (i - me->query("gift/last_time")) / 24
	&& me->query("combat_exp") <= (me->query("gift/exp") + 10000)
	)//�ϴ��콱 �Ժ�exp��������10K 
		return 0;
*/

	if ((j += duration) > 0)
		tell_object(me, "�����������Ʒ��ʱ�仹�У�" + CHINESE_D->chinese_time(j) + "��\n");
	me->set("gift/time", start_time + duration);
	me->set("gift/name", gift_temp);
	me->set("gift/last_time", i);
	me->set("gift/mud_time", me->query("mud_time"));
	me->set("gift/exp", me->query("combat_exp") + types["combat_exp"] );
	if (sizeof(types) < 1) {
		if (wizardp(me))
			tell_object(me, "����ϵͳ�����⣬���� gift.c��\n");
		return 0;
	}
	
	if(sex==1 && me->query("gender")!="����") return 0;
	if(sex==2 && me->query("gender")!="Ů��") return 0;

	tell_object(me,
		HIW "\n����һ����" BLINK HIR+gift_desc+ NOR HIW "���������ϵ���һ�θ�¶������������촽�ϣ�\n" NOR
	);
	msg = "���ڻ���п�����";
	str = keys(types);
	for (i=0; i<sizeof(str); i++){
		if (str[i] == "beauty")
			j = me->set_skill( str[i] , me->query_skill(str[i],1) + types[str[i]] );
		else
			j = call_other(me, add_types[str[i]][1], str[i], types[str[i]]);
//		if (j < 0) call_other(me, add_types[str[i]][1], str[i], -j);
		if (str[i] == "max_jingli")
		{
			j = call_other(me, add_types[str[i]][1], "eff_jingli", types[str[i]]);
			if (j < 0) call_other(me, add_types[str[i]][1], "eff_jingli", -j);
		}
		if (str[i] == "beauty")
			msg += chinese_number(types[str[i]])+"��"+add_types[str[i]][0]+"��";
		else if (str[i] == "balance")
			msg += MONEY_D->money_str(types[str[i]])+"��"+add_types[str[i]][0]+"��";
		else
			msg += chinese_number(types[str[i]])+"��"+add_types[str[i]][0]+"��";
	}

	msg += "��\n";
	msg = replace_string(msg, "����", "��");
	tell_object(me, msg);

	return 1;
}

int help(object me)
{
	int i;
	write(@HELP
���Ͳ���:
1	gift set -> �������
2	gift set <��Ʒ> to <xxx> -> set ����
3	gift send <��������> <��¼����> <�Ա�> <��ʼʱ��> <����ʱ��>-> ������
������ʼʱ���ǵ�ǰʱ������ֵ����λΪ�룻�Ա�Ϊ���֣�0Ϊ�����֣�1Ϊ���ԣ�2ΪŮ�ԡ�
���磺gift send ��ɱ�� sloganbbb 0 60 3600
��ʾ��һ���Ӻ�ʼ���������һСʱ�����󲻷�����Ů��

���ָ������ʦ�����ڽ��������������ҡ�
���У���Ʒ֧�֣�
HELP);

	i = sizeof(keys(add_types));
	while (i--)
		write(sprintf("%-12s -> %s\n", keys(add_types)[i], add_types[keys(add_types)[i]][0]));
	write("\n");

	return 1;
}
