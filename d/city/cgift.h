// YUJ@SJ 2001-11-02
// Modified by LOOKLOVE@SJ ������ݼ��㣬����Ż���
// 2002/4/29
// ��Ϊ��������޸�����

// Exp�� 100K ���Ͽ����޸����ԡ�
#define MIN_EXP 100000
// ʣ��EXP���ʵ���100%��ȥÿ��۳�����
// ��ǰ�޸�ÿ�����ԣ��۳�exp����Ϊ5%
#define RATE 0.9500

#include <ansi.h>

int help();

nosave mapping gift_desc = ([
	"str":"����",
	"con":"����",
	"dex":"��",
	"int":"����"
]);

nosave string *gift = keys(gift_desc);

// ͳһ���� by Lklv
string check(object me)
{
	string msg;

	if (me->query("registered") < 3)
		msg = "��Ǹ��ֻ�й����Ҳ���������ᡣ\n";
	if ((int)me->query("combat_exp") < MIN_EXP)
		msg = "��Ǹ����ľ��鲻�� "+MIN_EXP+" ���޷��޸����ԡ�\n";
	if (me->is_ghost())
		msg = "��Ǹ�����״̬���ȶ��������޷��޸����ԡ�\n";
	return msg;
}

// yuj �¹�ʽ������ѭ���㷨��
int check_exp(int exp, int num)
{
        while (num--) exp -= exp / 20;
        return exp;
}

int do_change(string arg)
{
	string msg, from, to;
	int exp, num, newexp, tmpexp;
	object me = this_player();

	if (!me) return 0;
	if (!arg) return help();

	if ( stringp(msg = check(me)) )
		return notify_fail(msg);

	if (sscanf(arg, "%d %s to %s", num, from, to) == 3){
		if ( num < 1 || num > 20)
			return notify_fail("����������Ч�����������롣\n");

		exp = me->query("combat_exp");
		newexp = check_exp(exp,num);
		tmpexp = exp - newexp;

		if (member_array(from, gift) < 0)
			return notify_fail("��Ҫ�۳�ʲô�츳��\n");

		if (member_array(to, gift) < 0)
			return notify_fail("��Ҫ����ʲô�츳��\n");

		if (from == to)
			return notify_fail("���һ�£�������󣬿����ۻ���\n");

		if (me->query(from) <= 10)
			return notify_fail("���"+gift_desc[from]+"�����ټ����ˡ�\n");

		if ( ((int)me->query(from) - num) < 10)
			return notify_fail("���"+gift_desc[from]+"����"+num+"�������10�㣬�����޸ġ�\n");

		if (me->query(to) >= 30 )
			return notify_fail("���"+gift_desc[to]+"�Ѿ�����30�㣬�����������ˡ�\n");

		if ( ((int)me->query(to) + num) > 30)
			return notify_fail("���"+gift_desc[to]+"����"+num+"��󽫳���30�㣬�����޸ġ�\n");

		if ( newexp < 95000 )
			return notify_fail("��Ǹ���޸�"+num+"�����Ժ��齫���� "+MIN_EXP+" ��������һ�����޸ļ������ԡ�\n");

		switch (me->query("family/family_name")) {
			case "����":
				if (from == "int" && ( me->query("int") <= 20 || ((int)me->query("int") - num) < 20 ) )
					return notify_fail("���̵�������Ҫ������ 20��\n");
				break;
			case "������":
				if (from == "str" && ( me->query("str") <= 20 || ((int)me->query("str") - num) < 20) )
					return notify_fail("�����µ�������Ҫ������ 20��\n");
				if (from == "con" && ( me->query("con") <= 20 || ((int)me->query("con") - num) < 20) )
					return notify_fail("�����µ��Ӹ���Ҫ������ 20��\n");
				break;
		}

		if (! me->query("confirm_passwd"))
			return notify_fail("��û������ȷ������(help passwd)���޷��޸����ԡ�\n");

		write(HIR"������ȷ�����룺\n"NOR);
		input_to("confirm_passwd", me, from, to, num);
		return 1;
	}

	if (sscanf(arg, "check %d", num) == 1){
		if ( num < 1 || num > 80 )
			return notify_fail("�������ֵ����������������Ժϡ�\n");

		exp = me->query("combat_exp");
		newexp = check_exp(exp,num);
		tmpexp = exp - newexp;

		msg = HIG"��ʾ�����Ҫ�޸� "+num+" �����ԣ����ԼҪ�۳� "+tmpexp+" ��EXP����ʣ "+newexp+" ��EXP��\n"NOR;

		if ( newexp < 95000 )
			msg += HIR"��Ǹ���޸�"+num+"�����Ժ��齫���� "+MIN_EXP+" ��������һ�����޸ļ������ԡ�\n"NOR;

		if (me->query_skill("jinshe-zhangfa",1) || me->query_skill("jinshe-jianfa",1))
			msg += HIR"ע�⣺����޸ı�������20�����߽����ͽ����Ʒ�����ɾ����\n"NOR;

		if (me->query("double_attack") && me->query("zhou"))
			msg += HIR"ע�⣺����޸����Ը���25�����һ�������ɾ����\n"NOR;

		if (me->query("dali") && me->query_skill("lingbo-weibu", 1))
			msg += HIR"ע�⣺����޸����Ե���22���貨΢������ɾ����\n"NOR;

		if ( me->query("quest/qianzhu/pass") )
			msg += HIR"ע�⣺����޸ĸ��ǵ���15�����Ե���20��ǧ�����ֽ���ɾ����\n"NOR;

		if ( me->query("quest/pixie/pass") )
			msg += HIR"ע�⣺����޸�������15�����Ե���20�������񹦽���ɾ����\n"NOR;

		if ( me->query("quest/ningxue/pass") )
			msg += HIR"ע�⣺����޸�������15����ǵ���15����Ѫ��צ����ɾ����\n"NOR;

		write(msg);
		return 1;
	}
	return help();
}

private void confirm_passwd(string pass, object me, string from, string to, int num)
{
	int exp, newexp, tmpexp;
	string confirm_pass;
	confirm_pass = me->query("confirm_passwd");

	if ( confirm_pass && crypt(pass, confirm_pass) != confirm_pass) {
		write("ȷ���������\n");
		return;
	}
	// ����۳�exp
	exp = me->query("combat_exp", 1);
	newexp = check_exp(exp,num);
	tmpexp = exp - newexp;

	me->start_busy(1);

	me->add(from, -num);
	me->add(to, num);
	me->add("combat_exp", -tmpexp);

	// �������ƽ����ؼ�
	if ( me->query("str") > 20) {
		me->delete_skill("jinshe-zhangfa");
		me->delete_skill("jinshe-jianfa");
	}

	// �������ƶ���д��
	if (me->query_skill("literate", 1) > me->query("int") * 10)
		me->set_skill("literate", me->query("int") * 10);

	// ˫�ֻ���Ҫ������ <= 25
	if (me->query("int") > 25 ){
		me->delete("double_attack");
		me->delete("zhou/hubo");
	}

	// �貨΢��Ҫ������ >= 22
	if ( me->query("int") < 22 ){
		me->delete("dali/pass");
		me->delete("dali/meet_dy1");
		me->delete_skill("lingbo-weibu", 1);
	}

	// ǧ������Ҫ������ >=20 �Ҹ��� >=15
	if ( me->query("int") < 20 || me->query("con") < 15 ) {
		me->delete("quest/qianzhu/pass");
		me->delete_skill("qianzhu-wandushou", 1);
	}

	// ������Ҫ������ >=20 �Ҹ��� >=15
	if ( me->query("int") < 20 || me->query("dex") < 15 ) {
		me->delete("quest/pixie/pass");
		me->delete_skill("pixie-jian", 1);
		me->delete_skill("kuihua-shengong", 1);
	}

	// ��Ѫ��צҪ����� >=15 ���� >=15
	if ( me->query("dex") < 15 || me->query("con") < 15 ) {
		me->delete("quest/ningxue/pass");
		me->delete_skill("ningxue-shenzhua", 1);
	}

	me->setup();
	me->save();
	write(HIY"�㽫"+num+"��"+gift_desc[from]+"������"+gift_desc[to]+"�ϡ�\n"NOR, me);
	log_file("nosave/ADJUST",
		me->query("name")+"("+capitalize(geteuid(me))+")"
		+"����"+num+"��"+gift_desc[from]
		+"��"+gift_desc[to]+"�ϣ��۳� "+tmpexp+" �㾭�飬ʣ��"+newexp+"\n",
		me,
		({ me })
	);
	return;
}

int help()
{
	write(HIR"�޸��������ԣ�ÿ�������޸Ľ��۳� 5% ����ֵ��\n"NOR);
	write("EXP����"+MIN_EXP+"�����޸����ԡ�\n");
	write("\n");
	write("ָ���ʽ��\n");
	write("    ����۳���ʧ��cgift check <Ҫ�޸ĵĵ���>\n");
	write("    �޸����ԣ�cgift <����> <Ҫ�۳����츳> to <Ҫ���ӵ��츳>\n");
	write("\n");
	write("��ʹ�õ����Բ�����\n");
	write("    ����  str           ����  con\n");
	write("    ��  dex           ����  int\n");
	write("\n");
	write(HIR"������ʹ�ã�����ʧ�����Ը����Ĵ�����\n"NOR);
	return 1;
}
