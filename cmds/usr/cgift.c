// YUJ@SJ 2001-11-02
// Modified by LOOKLOVE@SJ ������ݼ��㣬����Ż���
// 2002/4/29
// ��Ϊ��������޸�����

// Exp�� 100K ���Ͽ����޸����ԡ�
#define MIN_EXP 150000
// ʣ��EXP���ʵ���100%��ȥÿ��۳�����
// ��ǰ�޸�ÿ�����ԣ��۳�exp����Ϊ1%
#define RATE 1

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

string check(object me)
{
	string msg;

	if (me->query("registered") < 3)
		msg = HIY"ϵͳ��ʾ��"NOR"��Ǹ��ֻ�й������������ᡣ\n";
	if (me->is_ghost())
		msg = HIY"ϵͳ��ʾ��"NOR"��Ǹ�����״̬���ȶ��������޷��޸����ԡ�\n";
	return msg;
}

int check_exp(int exp, int num)
{
        if(exp <= 5200000) return exp;
        else while (num--) exp -= exp / 100;
        return exp;
}

int vipcheck_exp(int exp, int num)
{
        if(exp <= 25000000) return exp;
        else while (num--) exp -= exp* 9 / 1000;
        return exp;
}

int main(object me, string arg)
{
	string msg, from, to;
	int exp, num, newexp, tmpexp;

	if (!me) return 0;
	if (!arg) return help();

	if ( stringp(msg = check(me)) )
		return notify_fail(msg);

	exp = me->query("combat_exp");

	if (sscanf(arg, "%d %s to %s", num, from, to) == 3){		
		if (member_array(from, gift) < 0)
			return notify_fail("��Ҫ�۳�ʲô�츳��\n");
		if (member_array(to, gift) < 0)
			return notify_fail("��Ҫ����ʲô�츳��\n");
		if (from == to || num<0 )
			return notify_fail("���һ�£�������󣬿����ۻ���\n");
//                if(exp<1000000 && from=="int")
//                        return notify_fail("��ľ���ֵС��1M�����ܽ����Լ��١�\n");
		if (me->query(from) <= 10)
			return notify_fail("���"+gift_desc[from]+"�����ټ����ˡ�\n");
		if ( ((int)me->query(from) - num) < 10)
			return notify_fail("���"+gift_desc[from]+"����"+num+"�������10�㣬�����޸ġ�\n");
                if (me->query(to) >= 32 )
                        return notify_fail("���"+gift_desc[to]+"�Ѿ����Ｋ���ˣ������������ˡ�\n");
                if ( ((int)me->query(to) + num) > 32 )
                        return notify_fail("���"+gift_desc[to]+"����"+num+"��󽫳���32�㣬�����޸ġ�\n");

		switch (me->query("family/family_name")) {
			case "����":
				if (from == "int" && ( me->query("int") <= 20 || ((int)me->query("int") - num) <20 ) )
					return notify_fail("���̵�������Ҫ������ 20��\n");
				break;
			case "������":
				if (from == "str" && ( me->query("str") <= 20 || ((int)me->query("str") - num) <20) )
					return notify_fail("�����µ�������Ҫ������ 20��\n");
				if (from == "con" && ( me->query("con") <= 20 || ((int)me->query("con") - num) <20) )
					return notify_fail("�����µ��Ӹ���Ҫ������ 20��\n");
				break;
		}

		input_to("confirm_passwd", me, from, to, num);
		write("ȷ���޸����Գɹ���\n");
		return 1;
	}

	if (sscanf(arg, "check %d", num) == 1){

                if ( num > 200 )
			return notify_fail("�������ֵ����������������Ժϡ�\n");
	// ����۳�exp
		newexp = check_exp(exp,num);
if(me->query("buyvip")) newexp = vipcheck_exp(exp,num);
		tmpexp = exp - newexp;

		msg = HIG"��ʾ�����Ҫ�޸� "+num+" �����ԣ����ԼҪ�۳� "+tmpexp+" ��EXP����ʣ "+newexp+" ��EXP��\n"NOR;
if(me->query("can_cgift")) 
                                msg += HBRED"��ϲ����Ϊ��ʹ����ϴ�赤��������������ɵ���һ���츳����������κξ��顣\n"NOR;
		if ( newexp < 150000 )
			msg += HIR"��Ǹ���޸�"+num+"�����Ժ��齫���� "+MIN_EXP+" ��������һ�����޸ļ������ԡ�\n"NOR;
		if (me->query_skill("jinshe-zhangfa",1) || me->query_skill("jinshe-jianfa",1))
                        msg += HIR"ע�⣺����޸ı�������20������30�����߽����ͽ����Ʒ�����ɾ����\n"NOR;

		if (me->query("double_attack") && me->query("zhou"))
                        msg += HIR"ע�⣺����޸����Ը���25������31�����һ�������ɾ����\n"NOR;

		if (me->query("dali") && me->query_skill("lingbo-weibu", 1))
			msg += HIR"ע�⣺����޸����Ե���22���貨΢������ɾ����\n"NOR;

		write(msg);
		return 1;
	}
	return help();
}

private void confirm_passwd(string pass, object me, string from, string to, int num)
{
	int exp, newexp, tmpexp;

	// ����۳�exp

	exp = me->query("combat_exp", 1);
//        if( me->query("combat_exp") > 52000000 && !me->query("can_cgift") ) {
        if( me->query("combat_exp") > 5200000 && !me->query("can_cgift") ) {
	     newexp = check_exp(exp,num);
if( me->query("buyvip")) newexp = vipcheck_exp(exp,num);
	     tmpexp = exp - newexp;
	     me->add(from, -num);
	     me->add(to, num);
	     me->add("combat_exp", -tmpexp);
     }
   else
      {
            tmpexp = 0;
            me->add(from, -num);
	     me->add(to, num);
	     me->add("combat_exp", -0);
      	}
		
	me->start_busy(1);

	

	write("�㽫"+num+"��"+gift_desc[from]+"������"+gift_desc[to]+"�ϡ�\n", me);
	write("�۳� "+tmpexp+" �㾭��\n", me);
        
	me->save();
     if(me->query("can_cgift")) {
          me->delete("can_cgift"); 	
	write(HIM"��о�ϴ�赤�����������Ч�����㱾�ε��츳����û������κξ��顣\n"NOR, me);
	write(HIR"����õ�ϴ�赤��Ч���Ѿ�����ɢȥ�ˡ�\n"NOR, me);
                                   }

log_file("static/ADJUST",
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
	write("��ָ�������޸��������ԡ�\n");
       write("ʵս����5.2M�Ժ�ÿ�������޸Ľ��۳�1% exp��\n");
       write("��������ſ�Ϊ25M��ÿ�������޸�ֻ�۳�0.9% exp��\n");
       write("��Ҳ������ϴ�赤�����ɵ���һ���츳��\n");
	write("EXP����"+MIN_EXP+"�����޸����ԡ�\n");
	write("ָ���ʽ��\n");
	write("����۳���ʧ��cgift check <Ҫ�޸ĵĵ���>\n");
	write("�޸����ԣ�cgift <����> <Ҫ�۳����츳> to <Ҫ���ӵ��츳>\n");
	write("���磺��Ҫ��һ�������ӵ������ϣ�������ã�"HIG" cgift 1 str to int "NOR"\n");
	write("�����������Դ�������:����:str,����:con,��:dex,����:int\n");
	write("������ʹ�á�\n");
//        write("\n�ر�ע�⣺����ֵС��1M���ܼ������ԡ�\n");

	return 1;
}
