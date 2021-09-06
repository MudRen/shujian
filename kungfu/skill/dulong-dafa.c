//dulong-dafa.c

inherit FORCE;

int get_bouns(int damage,int t,int level,int flag);
int valid_enable(string usage) { 
	  if (this_player()->query("family/family_name")=="������" || this_player()->query("cw_mp/������") )return usage == "force"; }

#include "/kungfu/skill/force.h"
#include <ansi.h>
/*

*/
int force_effect(string skill)
{	
	//�Կ�Ч���Ǵ�-3 -> 3���ֱ����������ص����˺��ᣬΨһһ�����⣬��jiuyin-zhengong������
	//��Ȼ������������Ч��
	//��ͬ�ڹ����ʵ��ڹ���������˵�Ч����dulong-dafa���������ڹ���
	//���Ե��ڹ��Կ������Ч���ͺã����������ڹ����޷��Կ�����Ҫ�����˺�
	//û���г������ڹ������������ڹ����޷������ˡ�:(
        switch (skill)
        {
                case "jiuyang-shengong" : return 4;
                case "yijin-jing"       : return 3;
                case "huntian-qigong"   : return 3;
                case "qiantian-yiyang"  : return 3;
                case "yinyun-ziqi"      : return 2;
                case "zixia-gong"       : return 2;
                case "shenghuo-shengong": return 2;
                case "longxiang-boruo"  : return 2;
                case "kurong-changong"  : return 1;
                case "linji-zhuang"     : return 1;
                  case "shenzhao-jing"     : return -1;
                case "shenyuan-gong"    : return -1;
                case "guiyuan-tunafa"   : return -2;
                case "dulong-dafa"      : return -2;
                case "huagong-dafa"     : return -2;
                case "hamagong"         : return -2;
                case "yunu-xinjing"     : return -3;
                case "hanbing-zhenqi"   : return -3;
                case "bihai-chaosheng"  : return -3;
                case "jiuyin-zhengong"  : return -4;
                default: return 1;
        }
}

int valid_learn(object me)
{

		mapping fam  = me->query("family");
        int nlskill=me->query_skill("shenlong-yaoli",1);
	if ((!fam || fam["family_name"] != "������" )&& !me->query("cw_mp/������") )
			 	return notify_fail("�㲢�������̵��ӣ����ϰ���˶����󹦡�\n");

        if(nlskill<(me->query_skill("dulong-dafa",1)-100)
         && me->query_skill("dulong-dafa",1 ) < 301)
           return notify_fail("�������ҩ��ѧ�����򻹲�����\n");

        if ((int)me->query_skill("dulong-dafa", 1) > me->query_skill("force", 1) + 10
          && me->query_skill("dulong-dafa", 1) >= 200 )
               return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");
        return valid_public(me);
}

int practice_skill(object me)
{
       int lvl = me->query_skill("dulong-dafa",1);
       if(lvl >= 200 )
       {
           if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200)
           {
                   me->improve_skill("dulong-dafa", (int)me->query_int());
                   me->add("neili", -100); 
                   me->add("potential", -1*(1+random(3)));
                   return 1;
           }
           else return notify_fail("�����ڵ���Ϊ��������߶������ˡ�\n");   
       }
          return notify_fail("������ֻ����ѧ(learn)�����������������ȡ�\n");
}

string exert_function_file(string func)
{
	string * weapon;
	object me=this_player();
	int hua;
    
	hua=strsrch(func,"hua");
	weapon=explode(func,"hua");
	if(hua!=-1 && sizeof(weapon)>0)
		me->set_temp("wea_type",weapon[0]);
	else if(me->query_temp("wea_type",1))
		me->delete_temp("wea_type");
	if(hua!=-1)
		return SKILL_D("dulong-dafa/hua");
	else
		return SKILL_D("dulong-dafa/") + func;
}

mapping exercise_msg(object me)
{
	return ([
		"status_msg" : BLU + me->name()+"�����ڵ�����ϥ����������һ�ź��������š�" NOR,
		"start_my_msg" : "����ϥ���£�˫�ֺ�ʮ����ͷ����Ǳ��������һ�ź������������Χ��������˫��ð��һ˿�̹⡣\n",
		"start_other_msg" : me->name()+"��ϥ����������һ�ź��������ţ������̹����䣬���ɱ��ӡ�\n",
		"halt_msg" : "$N˫�ۻ����պϣ�Ƭ���͵������������̹⼱�������\n",
		"end_my_msg" : "��ֿ�˫�֣������������£����е��̹�Ҳ��������������\n",
		"end_other_msg" : me->name()+"�ֿ�˫�֣������������£����е��̹�Ҳ��������������\n"
	]);
}

string* msgs =
({
	RED"$N�����Ľе������������ͨ���ӣ��ڵ��������ٱ�����һ���٣��԰ٵ��򡣡�\n",
	HIR"$N�����е������������Ŀ��磬�����ķ����ҽ̵��ӻ��̶�����ͬ�����ã���\n",
	HIC"$N�����е������ҵ���ɱ�л��̣�������׼���Σ�����ʥְ����\n",	
	RED"$N�����Ľе������������ͨ����ҽ�ս�޲�ʤ�����޲��ˣ��޼᲻�ݣ��޵в��ƣ������������ң���֮زز����\n",
});

int ob_hit(object ob, object me, int damage)
{
	object she;
	
	if(!environment(me)) return 0;
/*	if(me->query_temp("sld/wudi") && me->query_skill("dulong-dafa",1)>250 || me->query_temp("sld/wudi2"))
	{
		int t = me->query_temp("combat_time");
		message("wizard",sprintf("������Ϣ�������غ�%d\n",t),environment(me));
		if( random(t)>10 || (t>20 && !random(4) ) )
		{
			message_vision(msgs[random(sizeof(msgs))]+"$nһ�����ϵ������ͻ���������\n"NOR,me,ob);
			return -get_bouns(damage,t,me->query_skill("dulong-dafa",1),0)/100;
		}
	}
*/
	if( !(int)me->query_temp("sld/huti") || !objectp(she=me->query_temp("sld/snake")) ) return 0;
	if( (me->query("qi")-damage) >= 100 ) return 0;
	
	message_vision(HIY"$N"HIY"�ۼ���Ҫ��������$N"HIY"������ȴͻȻ�ɳ�һ�����ߣ��ֵ�����������һ����\n" NOR, me);
	she->die();
	me->delete_temp("sld/huti");
	return -damage;
}

int hit_ob(object me,object victim,int damage)
{
	if(!me) return 0;
	if(!environment(me)) return 0;
	if(me->query_temp("sld/wudi") && me->query_skill("dulong-dafa",1)>250 || me->query_temp("sld/wudi2") )
	{
		int t = me->query_temp("combat_time");
		message("wizard",sprintf("������Ϣ�������غ�%d\n",t),environment(me));
		if( random(t)>10 || (t>20 && !random(4) ) )
		{
			message_vision(msgs[random(sizeof(msgs))]+"$Nֻ����ԽսԽǿ�������ٱ���\n"NOR,me);
			return get_bouns(damage,t,me->query_skill("dulong-dafa",1),1);
		}
	}
	return 0;
}

int get_bouns(int damage,int t,int level,int flag)
{
	int dm;
        dm= (damage*100*(t+level/20))/(t+level/20+10);
	if(flag && level>350) dm += dm/2;
        return dm/100;
}
