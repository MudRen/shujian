//chutou.c ��ͷ���ɿ�ר��
//Modified By ChinaNet
//By 2004/1/11

//����mining����������Ĺ�ϵ��
//���ӷ���������ɿ�ɹ��Ĺ�ϵ��
//���Ӳɿ�ɹ����뼼�ܵĹ�ϵ
//Modified By ChinaNet
//by 2004/3/10
// add exp By ChinaNet
//by 2004/4/28
// By Spiderii �޸�miningΪcaikuang
// by 2007/9/17
// By Server �޸�caikuang > 230 �޷��õ�caikuang β�� ��ΪҪ��qqlly ������
#include <weapon.h>
inherit STAFF;
#include "../place.h"

void create()
{
        set_name("��ͷ", ({ "chu tou", "tou", "chu" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "��");
                set("long", "����һ�ѳ�ͷ��������ɽ���(mine)����ò������ˡ�\n");
                set("value", 1);
                set("material", "steel");
                set("wield_msg", "$N�ó�һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���ڼ��ϡ�\n");
                set("no_drop","�������ӵ�ʱ���");
                set("no_get","һ���Ƴ�ͷ��Ҳ��");
        }
        init_staff(4);
        setup();
}

void init()
{
 	add_action("do_wield","wield");
 	add_action("do_mine","mine");
}

int do_wield(string arg)
{
	object me, ob;
	me = this_player();
	ob = this_object();
	
	if( !arg ) 
		return 0;
	if (arg == "all" )
		return 1;
		
	if (arg == "chu" || arg == "tou" || arg == "chu tou") 	
	{
		if(ob->query("user")!= me->query("id") )
		{
			tell_object(me,"��λ" + RANK_D->query_respect(me) +"��Ҫ�Ҷ����˵Ķ��������ϰ�߲��á�\n");
			return 1;
		}
	}
	return 0;
}

int do_mine(string arg)
{
	object me, ob, item, mine, where;
	object killer;
	string level, str;
	int times, count, fail, success,i,j,k,exp;
	
	ob = this_object();
	me = this_player();
	where = environment(me);
	item = me->query_temp("weapon");
	level = me->query_temp("minejob/level");
	
	if (arg) 
		return notify_fail("��Ҫ��ʲô��\n");
	if (ob->query("user") != me->query("id")) 
		return notify_fail("��Ҫ��ʲô��\n");
	
	if (!item || item->query("id") != "chu tou")
		return notify_fail("��Ҫ��������\n");
		
	if (!me->query_temp("minejob/ask"))
		return notify_fail("û���ڵ���ʲô��\n");

	if (file_name(where) != me->query_temp("minejob/area"))
		return notify_fail("�˵ز���ʲô�ر�֮������Ҫ��ʲô��\n");
		
	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");
		
	if (me->query_temp("minejob/type") != "����")
		return notify_fail("�㡫�㡫���㡫�����������˰ɡ�\n");
	
	if (me->query_temp("minejob/find"))
		return notify_fail("���Ѿ��������˿�ʯ���ٻط���������\n");
	
	if (me->is_fighting())
		return notify_fail("�㡫�㡫���㡫��������æ������˵�ɡ�\n");
		
	if (me->query("jingli") < 500)
		return notify_fail("��ľ���������\n");
		
	if (me->query("neili") < 500)
		return notify_fail("�������������\n");

	str="\n$N����������������ĭ�������ͷ������ȫ�����������Բ�˸첲һ��ͷ������ȥ��\n";
	
	me->add_temp("minejob/times",1);
	
//�ɹ���ʧ�ܶԱȡ�
	i = me->query("minejob")/10;
	j = me->query("minejob_failed");
//add exp by chinanet
	if ( i > j && j < 500)
		exp = i - j;
	else 	exp = 1;
	
	if( exp > 10 ) exp = 10 ;
	if( exp < 0 ) exp = 1;

//�ɿ�ɹ����뼼�ܵĹ�ϵ
   k = me->query_skill("caikuang",1);
   if (k > 230)
   { 
   me->add_temp("minejob/success",1);
   me->add("combat_exp",exp );
   }
   else if (random(20) > 10 && me->query_temp("minejob/level") == "veryhard" && k > 200)
	{		
		me->add_temp("minejob/success",1);
		me->improve_skill("caikuang", i + random(i) );
		me->add("combat_exp",exp );
	}
	else if	(random(20) > 8 && me->query_temp("minejob/level") == "hard" && k > 150)
	{		
		me->add_temp("minejob/success",1);
		me->improve_skill("caikuang", i + random(i) );
		me->add("combat_exp",exp );
	}
	else if	(random(20) > 5 && me->query_temp("minejob/level") == "normal" && k > 200)
	{		
		me->add_temp("minejob/success",1);
		me->improve_skill("caikuang", i + random(i) );
		me->add("combat_exp",exp );
	}
	else
	{
		me->add_temp("minejob/fail",1);
            me->improve_skill("caikuang", 10);
		me->add("combat_exp",1 );
	}
//
	fail = me->query_temp("minejob/fail");
	success = me->query_temp("minejob/success");
	times = me->query_temp("minejob/times");
	count = me->query("con") + random(me->query_con());
	me->add("neili", -count);
	me->add("jingli", -count*3/2);
	
	switch (level)
	{		
		case "veryhard":
			str += "�ƺ�ûʲô�仯����$N����ʮ�㣬�������١�\n";
			if (success > 20 && success > fail && i > j && random(20) > 10)
			{
				str += "$N������ǰһ����һ�������Ŀ�ʯ¶�˳�����$N�˷ܵؽ���ͷ�ӵ��ˡ�\n";
				mine = new(__DIR__"mine.c");
				mine = settings_mine(level, mine);
				mine->move(me);
				me->set_temp("minejob/find",1);
				log_file("job/minejob",sprintf("%s %s(%s)�ڵ���%s����Ŀ�ʯ���ɹ�%i�Σ�ʧ��%i�Ρ�\n",
					ctime(time())[4..19],me->name(1),capitalize(me->query("id")),mine->query("level"),success,fail));
			}
			else if (fail > 20 || success > 30 && success>fail)
			{
				str += "�ڷɽ���ɳ������$N���񿴵���һ���ںڵĶ����������ּ���������$N�붼û��ͽ���ͷ�ӵ��ˡ�\n";
				mine = new(__DIR__"mine.c");
				mine->move(me);
				me->set_temp("minejob/find",1);
				log_file("job/minejob",sprintf("%s %s(%s)��%s����Ŀ�ʯʧ�ܡ��ɹ�%i�Σ�ʧ��%i�Ρ�\n",
					ctime(time())[4..19],me->name(1),capitalize(me->query("id")),mine->query("level"),success,fail));
			}
			break;
		case "hard":
			str += "��ʱ�������·�����˲��ɵ�������üͷ����$N��Ȼ�Ӷ�������\n";
			if (success > 16 && random(20) > 8 && i > j && success > fail)
			{
				str += "��������ɢȥ��������Լ��һ���ʵ�ʯͷ��$N���˵ؽ���ͷ�ӵ���\n";
				me->set_temp("minejob/find",1);
				mine = new(__DIR__"mine.c");
				mine = settings_mine(level,mine);
				mine->move(me);
				log_file("job/minejob",sprintf("%s %s(%s)�ڵ���%s����Ŀ�ʯ���ɹ�%i�Σ�ʧ��%i�Ρ�\n",
					ctime(time())[4..19],me->name(1),capitalize(me->query("id")),mine->query("level"),success,fail));

			}
			else if (fail > 30 || success > 30)
			{
				str += "�ڷɽ���ɳ������$N���񿴵���һ���ںڵĶ����������ּ���������$N�붼û��ͽ���ͷ�ӵ��ˡ�\n";
				mine = new(__DIR__"mine.c");
				mine->move(me);
				me->set_temp("minejob/find",1);
				log_file("job/minejob",sprintf("%s %s(%s)��%s����Ŀ�ʯʧ�ܡ��ɹ�%i�Σ�ʧ��%i�Ρ�\n",
					ctime(time())[4..19],me->name(1),capitalize(me->query("id")),mine->query("level"),success,fail));
			}
			break;
		case "normal":
			str += "����$N������С�����Ͼ�Ȼ��$N����һ���޵׶���\n";
			if (success > 8 && i > j && random(20) > 6)
			{
				str += "������ϡ���Կ���һ����������ʯͷ��$N���ֵؽ���ͷ�ӵ��ˡ�\n";
				me->set_temp("minejob/find",1);
				mine = new(__DIR__"mine.c");
				mine = settings_mine(level,mine);							
				mine->move(me);
			}
			else if (fail > 20 || success > 20)
			{
				str += "�ڷɽ���ɳ������$N���񿴵���һ���ںڵĶ����������ּ���������$N�붼û��ͽ���ͷ�ӵ��ˡ�\n";
				mine = new(__DIR__"mine.c");
				mine->move(me);
				me->set_temp("minejob/find",1);
			}
			break;
		case "easy" :
			str += "������ۇ���һ�������˵��ϣ����$N�ֱ۷��顣\n";
			if (fail > 10 || success > 10)
			{
				str += "�ڷɽ���ɳ������$N���񿴵���һ���ںڵĶ����������ּ���������$N�붼û��ͽ���ͷ�ӵ��ˡ�\n";
				mine = new(__DIR__"mine.c");
				mine->move(me);
				me->set_temp("minejob/find",1);
			}
			break;
	}
	
	message_vision(str,me);

	if (!wizardp(me)) 
		me->start_busy(1+random(3));
	if (wizardp(me)) 
		tell_object(me,"�㱾��" + me->query_temp("minejob/level") + "�������Ѿ�����" + times + "�ο�ʯ���ɹ�������"
			+ me->query_temp("minejob/success") + "��ʧ�ܴ�����" + me->query_temp("minejob/fail") + "��\n");


	if (me->query_temp("minejob/find")) 
	{
//��Ӳ������� 2004/2/1 by ChinaNet
		mine->set("long",mine->query("long")+"����������"+mine->query("material")+"���ɡ�\n");
//���������
//by ChinaNet 2004/1/29

		if (me->query_temp("minejob/killer") == 1)
		{
			killer = new(__DIR__"robber.c");
			killer->set_temp("target",me->query("id"));
			killer->set_temp("level",mine->query("level"));
			killer->move(where);		
			killer->set("long",killer->query("long")+"���߸����˵����ӣ��������Ǹո�������"+me->query("name")+"("+me->query("id")+")�Ŀ�ʯ��\n");
			mine->add("value",random(50000)+50000);
			mine->move(killer);
			str = HIR"\n$N������ϲ��ͻȻ֮�䣬һ����Ӱ����ǰ�ӹ���$N��Ȼ�Ѿ������ϵ�"+mine->query("name")+HIR"�Ѿ������ˡ�\n"NOR;
			message_vision(str,me);
		}
	destruct(ob);
	}
	return 1;
}
