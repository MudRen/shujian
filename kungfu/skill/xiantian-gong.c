// xiantian-gong.c ���칦
//updated by action@SJ 2008/9/15

inherit FORCE;
#include <ansi.h>

int get_bouns(int damage,int t,int level,int flag);
int valid_enable(string usage) { 
 if (this_player()->query("family/family_name")=="ȫ���" || this_player()->query("cw_mp/ȫ���")  )
return usage == "force"; }

int valid_learn(object me)
{
mapping fam;
      int lvl, i;
        lvl = (int)me->query_skill("xiantian-gong", 1);
        i = (int)me->query("shen", 1);
 fam  = me->query("family");
if(!fam || fam["family_name"]!="ȫ���" && !me->query("cw_mp/ȫ���"))
             return notify_fail("�㲻��ȫ��̵��ӣ������������������\n");
        if ( me->query("gender") == "����" )
	return notify_fail("���칦�����������������������֮���������棡\n");

	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("������̫ʢ�������������������\n");
	
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");
		
		    if ((lvl > 10 && lvl < 100 && i < lvl*lvl*lvl / 20 )
            || ( lvl >=100 && i < 10000))
                return notify_fail("�����������̫���ˣ��޷�ѧϰ���칦��\n");


	return 1;
}
int practice_skill(object me)
{
	if((int)me->query_skill("xiantian-gong", 1) >= 200 ){
		if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200){
			me->improve_skill("xiantian-gong", (int)me->query_int());
			me->add("neili", -100); 
			me->add("potential", -1*(1+random(3)));
			return 1;
		}
		else return notify_fail("�����ڵ���Ϊ������������칦�ˡ�\n");
	}
	else return notify_fail("�����ڵ����칦��Ϊֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"xiantian-gong/" + func;
}

mapping exercise_msg(object me)
{
	return ([
		"status_msg" : me->name()+"��������ͨ�������ַ���ý���",
		"start_my_msg" : "����������ͨ����Ƭ��֮�䣬��������ȫ��˫�۾������䣬���ַ���ý����������٣���ƽʱ�������ˡ�\n",
		"end_my_msg" : "�㽫������ͨ��������ϣ���ȴ�������֣�˫�۾������䣬����վ��������\n",
		"end_other_msg" : ""+me->name()+"��������ͨ����ȥ��վ��������\n"
	]);
}


string* msgs =
({
	WHT"$N��������������壬����������,������ϼ,Ȼ������ͣ�����������ǵأ��β����ƣ�\n",
        HIG"$N�������"HIG"���������أ�����Ϊ��Ϊ"GRN"�����칦������ţ������񽻣��ζ���ת��\n",
	RED"$N�ѵ��泣Ӧ�Ӧ�ﲻ��֮�������о��裬������ס����ס���أ�\n",
});


int ob_hit(object ob, object me, int damage)
{
	object she;
	
	if(!environment(me)) return 0;
	if(me->query_temp("xtg/wuqi") && me->query_skill("xiantian-gong",1)>450 || me->query("quanzhen/force")=="pass" )
	{
		int t = me->query_temp("combat_time");

                if( random(10)>6 || (me->query("quanzhen/force")=="pass" && random(5)>=2 ))
		{
			message_vision(msgs[random(sizeof(msgs))]+"$nֻ���ú�����������޻����\n"NOR,me,ob);
			return -get_bouns(damage,t,me->query_skill("xiantian-gong",1),0);
		}
	}


}

int get_bouns(int damage,int t,int level,int flag)
{
	int dm;
        dm= (damage*100*(t+level/20))/(t+level/20+10);
        return dm/100;
}
