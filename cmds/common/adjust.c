// YUJ@SJ 2001-11-02
// Modified by LOOKLOVE@SJ ������ݼ��㣬����Ż���
// 2002/4/29

// Exp�� 100K ���Ͽ����޸����ԡ�
//#define MAX_EXP 6000000
#define MIN_EXP 100000

// ʣ��EXP���ʵ���100%��ȥÿ��۳�����
// ��ǰ�޸�ÿ�����ԣ��۳�exp����Ϊ5%
#define RATE 0.9500

inherit F_CLEAN_UP;
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
string check(object ob)
{
	string msg;

	if (ob->query("registered") < 3)
		msg = "��Ǹ��ֻ����ʽ��Ҳ���������ᡣ\n";
	if ((int)ob->query("combat_exp") < MIN_EXP)
		msg = "��Ǹ�����˾��鲻�� "+MIN_EXP+" ���޷��޸����ԡ�\n";
//	if ((int)ob->query("combat_exp") > MAX_EXP)
//		msg = "��Ǹ�����˾��鳬���� "+MAX_EXP+" �������޸������ˡ�\n";
	return msg;
}

/* lklv�㷨��exp * 95%��num�η�, pow() Ϊ���ݼ��㡣
int check_exp(int exp, int num)
{
	int x;
	float i, j, y;

	i = to_float(exp);
	j = to_float(num);
	y = i * pow(RATE, j);
	x = to_int(y);

	return x;
}*/
// yuj �¹�ʽ������ѭ���㷨��
int check_exp(int exp, int num)
{
        while (num--) exp -= exp / 20;
        return exp;
}

int main(object me, string arg)
{
	object ob;
	string arg1, msg, from, to;
	int exp, num, newexp, tmpexp;

	if (wiz_level(me) < wiz_level("(arch)"))
		return 0;
	if (!arg) return help();

	if (sscanf(arg, "%s %d %s to %s", arg1, num, from, to) == 4){
		ob = LOGIN_D->find_body(arg1);
		if (!ob)
			return notify_fail(HIR"��Ǹ��û�������ң������ۻ���\n"NOR);
		if ( stringp(msg = check(ob)) )
			return notify_fail(msg);

		exp = ob->query("combat_exp");

		if (member_array(from, gift) < 0)
			return notify_fail("��Ҫ�۳�ʲô�츳��\n");
		if (member_array(to, gift) < 0)
			return notify_fail("��Ҫ����ʲô�츳��\n");
		if (from == to)
			return notify_fail("ȥ���ɣ�\n");

		if (ob->query(from) <= 10)
			return notify_fail(ob->query("name")+"��"+gift_desc[from]+"�����ټ����ˡ�\n");
		if ( ((int)ob->query(from) - num) < 10)
			return notify_fail(ob->query("name")+"��"+gift_desc[from]+"����"+num+"�㽫����10�㣬�����޸ġ�\n");
		if (ob->query(to) >= 30 )
			return notify_fail(ob->query("name")+"��"+gift_desc[to]+"�����������ˡ�\n");
		if ( ((int)ob->query(to) + num) > 30)
			return notify_fail(ob->query("name")+"��"+gift_desc[to]+"����"+num+"�㽫����30�㣬�����޸ġ�\n");

		switch (ob->query("family/family_name")) {
			case "����":
				if (from == "int" && ( ob->query("int") <= 20 || ((int)ob->query("int") - num) <=20 ) )
					return notify_fail("���̵�������Ҫ������ 20��\n");
				break;
			case "������":
				if (from == "str" && ( ob->query("str") <= 20 || ((int)ob->query("str") - num) <=20) )
					return notify_fail("�����µ�������Ҫ������ 20��\n");
				if (from == "con" && ( ob->query("con") <= 20 || ((int)ob->query("con") - num) <=20) )
					return notify_fail("�����µ��Ӹ���Ҫ������ 20��\n");
				break;
		}

		ob->add(from, -num);
		ob->add(to, num);

		// ����۳�exp
		newexp = check_exp(exp,num);
		tmpexp = exp - newexp;

		ob->add("combat_exp", -tmpexp);

		// �������ƽ����ؼ�
		if ( ob->query("str") > 20) {
			ob->delete_skill("jinshe-zhangfa");
			ob->delete_skill("jinshe-jianfa");
		}

		// �������ƶ���д��
		if (ob->query_skill("literate", 1) > ob->query("int") * 10)
			ob->set_skill("literate", ob->query("int") * 10);

		// ˫�ֻ���Ҫ������ <= 25
		if (ob->query("int") > 25){
			ob->delete("double_attack");
			ob->delete("zhou");
		}

		// �貨΢��Ҫ������ >= 22
		if ( ob->query("int") < 22 ){
			ob->delete("dali");
			ob->delete_skill("lingbo-weibu", 1);
		}

		message_vision("$N��$n��"+num+"��"+gift_desc[from]+"������"+gift_desc[to]+"�ϡ�\n", me, ob);
		ob->setup();
		ob->save();
		log_file("static/ADJUST",
			me->query("name")+"("+capitalize(geteuid(me))+")"
			+"����"+ob->query("name")+"("+capitalize(geteuid(ob))+")"+"��"+num+"��"+gift_desc[from]
			+"��"+gift_desc[to]+"�ϣ��۳� "+tmpexp+" �㾭�飬ʣ�ྭ��"+newexp+"\n",
			me,
			({ ob })
		);
		return 1;
	}

	if (sscanf(arg, "%s check %d", arg1, num) == 2){
		ob = LOGIN_D->find_body(arg1);
		if (!ob)
			return notify_fail("��Ǹ��û�������ҡ�\n");
		if ( stringp(msg = check(ob)) )
			return notify_fail(msg);

		// ����۳�exp
		exp = ob->query("combat_exp");
		newexp = check_exp(exp,num);
		tmpexp = exp - newexp;

		msg = HIG"$n��ʾ$N�����$NҪ�޸� "+num+" �����ԣ���ԼҪ�۳� "+tmpexp+" ��EXP����ʣ "+newexp+" ��EXP��\n"NOR;

		if ( newexp < 95000 )
			msg += "��Ǹ�������޸�"+num+"�����Ժ��齫���� "+MIN_EXP+" ���޷��޸����ԡ�\n";
		if (ob->query_skill("jinshe-zhangfa",1) || ob->query_skill("jinshe-jianfa",1))
			msg += HIR"ע�⣺����޸ı�������20��$N�Ľ��߽����ͽ����Ʒ�����ɾ����\n"NOR;

		if (ob->query("double_attack") && ob->query("zhou"))
			msg += HIR"ע�⣺����޸����Ը���25��$N�����һ�������ɾ����\n"NOR;

		if (ob->query("dali") && ob->query_skill("lingbo-weibu", 1))
			msg += HIR"ע�⣺����޸����Ե���22��$N���貨΢������ɾ����\n"NOR;

		message_vision(msg, ob, me);
		return 1;
	}
	return help();
}

int help()
{
	write("�޸����ԣ�adjust <id> <����> <Ҫ�۳����츳> to <Ҫ���ӵ��츳>\n");
	write("����۳���ʧ��adjust <id> check <Ҫ�޸ĵĵ���>\n");
	return 1;
}
