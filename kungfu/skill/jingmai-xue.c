// jingmai-xue.c ����ѧ

#include <ansi.h>
inherit SKILL;
void create() { seteuid(getuid()); }
string type() { return "knowledge"; }

int valid_learn(object me)
{
	if((int)me->query_skill("jingmai-xue", 1) >= 200 )
		return notify_fail("�㲻����ѧϰ����ѧ�ˡ�\n");
//    return notify_fail("����ѧֻ��ͨ����ϰҽѧ�鼮����ߡ�\n");
     return 1;
}

int practice_skill(object me)
{
	return notify_fail("����ѧֻ�ܿ��ж�(study)����ߡ�\n");
}

void skill_improved(object me)
{
	switch (me->query_skill("jingmai-xue",1)) {
	case 10:
		tell_object(me,HIY"����ö���̫���ξ���ȫ�˽��ˡ�\n"NOR);break;
	case 20:
		tell_object(me,HIB"����ö��������󳦾���ȫ�˽��ˡ�\n"NOR);break;
	case 30:
		tell_object(me,HIY"����ö�������θ����ȫ�˽��ˡ�\n"NOR);break;
	case 40:
		tell_object(me,HIB"����ö���̫��Ƣ����ȫ�˽��ˡ�\n"NOR);break;
	case 50:
		tell_object(me,HIY"����ö��������ľ���ȫ�˽��ˡ�\n"NOR);break;
	case 60:
		tell_object(me,HIB"����ö���̫��С������ȫ�˽��ˡ�\n"NOR);break;
	case 70:
		tell_object(me,HIY"����ö���̫�����׾���ȫ�˽��ˡ�\n"NOR);break;
	case 80:
		tell_object(me,HIB"����ö�������������ȫ�˽��ˡ�\n"NOR);break;
	case 90:
		tell_object(me,HIB"����ö��������İ�����ȫ�˽��ˡ�\n"NOR);break;
	case 100:
		tell_object(me,HIY"����ö���������������ȫ�˽��ˡ�\n"NOR);break;
	case 110:
		tell_object(me,HIY"����ö�������������ȫ�˽��ˡ�\n"NOR);break;
	case 120:
		tell_object(me,HIB"����ö��������ξ���ȫ�˽��ˡ�\n"NOR);break;
	case 130:
		tell_object(me,HIG"����ö���������ȫ�˽��ˡ�\n"NOR);break;
	case 140:
		tell_object(me,HIW"����ö���������ȫ�˽��ˡ�\n"NOR);break;
	case 150:
		tell_object(me,HIG"����ö���ά����ȫ�˽��ˡ�\n"NOR);break;
	case 160:
		tell_object(me,HIW"����ö���ά����ȫ�˽��ˡ�\n"NOR);break;
	case 170:
		tell_object(me,HIG"����öԳ�����ȫ�˽��ˡ�\n"NOR);break;
	case 180:
		tell_object(me,HIW"����öԶ�����ȫ�˽��ˡ�\n"NOR);break;
	case 190:
		tell_object(me,HIG"����öԴ�����ȫ�˽��ˡ�\n"NOR);break;
	case 200:
		tell_object(me,HIR"����ö�������ȫ�˽��ˡ�\n");
		if(! me->query("jingmai")){
			tell_object(me,"�����ȫ��ľ�������ָ�ƣ��ڹ���֪�������Ѵ����\n"NOR);
			me->add("max_neili",50 + random(30));
			me->set("jingmai", 1);
		}
	break;
	}
}
