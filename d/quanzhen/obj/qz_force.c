//  Code of ShenZhou
// /d/zhongnan/obj/qz_force.c �����ڹ��ķ�

inherit ITEM;
string *koujue = ({
					 "���������к�ƾ������Ⱥ�������",
					 "��������ӯ���оߣ������ҫ���񾩡�",
					 "������ʦ���򱾳�����ʱ�޾�ȥ���š�",
					 "�����곾����ĥ����ƫ������ҫ̫�顷"
});

int do_dazuo(string arg);
int exercising(object me);
int halt_exercise(object me);


void setup()
{}


void init()
{
	add_action("do_dazuo", "lianqi");
}


void create()
{
	set_name("�����ڹ��ķ�", ({ "neigong xinfa", "xinfa" }));
	set_weight(600);
	if( clonep() )
	set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ����װ�飬���顶�����ڹ��ķ�����ԭ����ȫ��̵�����(lianqi)�ؼ���\n");
		set("value", 5000);
		set("material", "paper");
		set("skill", ([
			"name":			"force",	// name of the skill
			"exp_required":	0,			// minimum combat experience required
			"jing_cost":	30,			// jing cost every time study this
			"difficulty":	10,			// the base int to learn this skill
			"max_skill":	150			// the maximum level you can learn
			]) );
	}
}

int do_dazuo(string arg)
{
	object me = this_player();
	int exercise_cost;
	object where;

	seteuid(getuid());
	where = environment(me);

	if (!present("neigong xinfa", me))
		return 0;

	if (where->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

	if (where->query("sleep_room"))
		return notify_fail("������˯���������ڹ������Ӱ�����ˡ�\n");

	if (where->query("no_fight"))
		return notify_fail("�㲻�ܼ��о���ֻ�����������Ҵܣ��޷�ר�������ڹ���\n");

	if (where->query("name") == "����")
		return notify_fail("����̫����, �����ڹ����߻���ħ. \n");

	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() )
		return notify_fail("ս���в������ڹ������߻���ħ��\n");

	if( me->query("rided"))
		return notify_fail("�������������ڹ������߻���ħ��\n");

	if( !stringp(me->query_skill_mapped("force")) )
		return notify_fail("��������� enable ѡ����Ҫ�õ��ڹ��ķ���\n");

	if( !arg || !sscanf(arg, "%d", exercise_cost))
		return notify_fail("��Ҫ��������������\n");
	if (exercise_cost < 10)
		return notify_fail("����ڹ���û�дﵽ�Ǹ����磡\n");

	if( (int)me->query("qi") < exercise_cost )
		return notify_fail("�����ڵ���̫���ˣ��޷�������Ϣ����ȫ������\n");

	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("�����ھ��������޷�������Ϣ��������\n");

	write("�㰴�������ڹ��ķ������������������ù���һ����Ϣ��ʼ������������\n");

	me->set_temp("pending/exercise", 1);
	me->set_temp("exercise_cost", exercise_cost);
	message_vision("$N��ϥ���£���ʼ����������\n", me);
	me->start_busy((: exercising :), (:halt_exercise:));
	return 1;
}

int exercising(object me)
{
	int cost;
	object  where = environment(me);
	int exercise_cost = (int)me->query_temp("exercise_cost");
         int neili_gain = 1 + (int)me->query_skill("force") / 2.5;
	if (exercise_cost < 1)
		return 0;
	me->add("neili", neili_gain);
	me->set_temp("exercise_cost", exercise_cost -= neili_gain);

	//me->add("qi", -neili_gain);
	cost = neili_gain*3/2;
	if( base_name(where) == "/d/quanzhen/yangxin" )
		cost = cost/3*2;

	if( me->query_skill_mapped("force") == "xiantian-gong" )
	{
		write("��Ĭ����"+koujue[random(4)]+"��ֻ����һ����Ϣ������Ѹ��������ȫ���е��泩�ޱȡ�\n");

                me->receive_damage("qi", cost);
                me->receive_damage("jing", cost/10);
                me->set_temp("die_reason", "�����߻���ħ����");
	}
	else
	{
		if( random(6)==3 )
		{
			if(me->query_skill_mapped("force") == "bitao-xuangong")
			{
				write("��Ĭ����"+koujue[random(4)]+"��ֻ����һ����Ϣ�����ڴ�����ȥ��������ò��Ծ����ѵ����߻���ħ��ǰ�ף�\n");
				cost = neili_gain + random(neili_gain*100);
			}
			else
			{
				write("��Ĭ����"+koujue[random(4)]+"��ֻ����һ����Ϣ�����ڴ�����ȥ��������ò��Ծ���\n");
				cost = neili_gain + random(neili_gain*10);
                                me->receive_damage("qi", cost);
                                me->set_temp("die_reason", "�����߻���ħ����");
			}
                        }
			else
			{
			write("������"+koujue[random(4)]+"���ƺ��е���ᣬֻ����һ����Ϣ������Ѹ��������ȫ���е��泩�ޱȡ�\n");

			me->receive_damage("qi", cost, "�����߻���ħ����");
			me->receive_damage("jing", cost/10, "�����߻���ħ����");
			}

		}
	if (exercise_cost > 0)
		return 1;

	me->set_temp("pending/exercise", 0);
	message_vision("$N�˹���ϣ��������˿�����վ��������\n", me);
	if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
		 return 0;
	else
	{
		if ((int)me->query("max_neili") > (int)me->query_skill("force") * me->query("con") * 2 / 3)
		{
			write("���������Ϊ�ƺ��Ѿ��ﵽ��ƿ����\n");
			me->set("neili", (int)me->query("max_neili"));
			return 0;
		}
		else
		{
			me->add("max_neili", 1);
			me->set("neili", (int)me->query("max_neili"));
			write("������������ˣ���\n");
			return 0;
		}
	}
}

int halt_exercise(object me)
{
	if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
		me->set("neili", (int)me->query("max_neili") * 2);
		me->set_temp("pending/exercise", 0);
		return 1;
}
