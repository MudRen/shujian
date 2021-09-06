// NPC: /d/huashan/npc/puren.c
// Date: Look 99/03/25
// Modify By Looklove@SJ 2000/1/7 for add job
// Lklv Modify at 2001.10.18
// By Spiderii@ty �����ͷ�����
#include <ansi.h>
inherit NPC;
string ask_over();
string ask_food();
string* names = ({
	FOOD_D("baozi"),
	FOOD_D("cuishan"),
	FOOD_D("douhua"),
	FOOD_D("doufu"),
	FOOD_D("guoba"),
	FOOD_D("jitui"),
	FOOD_D("liji"),
	FOOD_D("liyu"),
	FOOD_D("niurou"),
	FOOD_D("peanut"),
	FOOD_D("sansi"),
	FOOD_D("yaoliu"),
});
void create()
{
	set_name("����", ({ "pu ren", "puren",}));
	set("long","һ���շ�ɨ�ص�����\n");
	set("gender", "����");
	set("age", 26);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 23);
	set("int", 23);
	set("con", 24);
	set("dex", 28);

	set("max_qi", 300);
	set("max_jing", 180);
	set("neili", 300);
	set("max_neili", 300);
	set("eff_jingli", 180);

	set("jiali", 5);
	set("combat_exp", 5000);
	set("score", 50);

	set_skill("unarmed", 20);
	set("inquiry", ([
	      "���" : (: ask_over :),
	      "����" : (: ask_over :),
	      "caihe" : (: ask_over :),
             "ʳ��" : (:ask_food:),

	]));
	setup();
	carry_object(ARMOR_D("armor/cloth"))->wear();
}

string ask_over()
{
	int exp,pot;
	object me;
	me = this_player();

	if ((int)me->query("combat_exp") >= 100000)
		return "��Ȼ����ȱ��̣�������Щ�»������������������ɡ�\n";
	if (me->query("shen") < 1000)
		return "����¶�׹�, ����ǲ�������ʲô���£� ";
	if (!me->query_temp("hs/kc_job")||!me->query_temp("kc_job/ok"))
		return "����ʦ�ָղ���˵��Ҫ�����Ҽ�������ȥ������ȥ��ȥ��ȥ�͸�����һ����\n";

	me->delete_temp("hs/kc_job");
	me->delete_temp("kc_job");

	exp = me->query("max_pot")*1+random(500);
	
	exp = me->add_exp_combat(exp,this_object(),"��ɽ����");
	
	pot = exp/5 + random(exp/10);

	//me->add("combat_exp",exp);
	me->add("shen",exp*3/4);
	me->add("potential",pot);
	if(me->query("potential") > me->query("max_pot"))
		me->set("potential", me->query("max_pot"));
		me->improve_skill("zixia-gong",me->query("int")*2);
		
	me->add("job_time/��ɽ����",1);

	message_vision("$N����������˵��������Ҫ�Ĳ���Ҷ����ˣ����ڳ����壬��Ҫ�Ļ�������ȥȡ����\n",me);
	tell_object(me,HIM" ��õ��ˣ�\n" +
	chinese_number(exp) + "��ʵս����\n"+
	chinese_number(pot) + "��Ǳ�ܡ�\n"NOR);
	command("ok "+me->query("id"));
	return "�ȶ��Űɣ�����Ҫ�õ�ʱ���Ҿ�ȥȡ��\n";
}
string ask_food()
{
	object ob1,ob2;
	object me;
	me=this_player();
       	if ((me->query("food")*10/me->max_water_capacity())>8)
		return "����ô�Ա��˻���Ҫ��";
               ob1 = new(FOOD_D("rice"));
	        ob2 = new(names[random(sizeof(names))]);
	        if( clonep(ob2) && clonep(ob1))
	        {
	        	message_vision(HIC"\n����˵���������Ѿ�׼�����ˣ�����ȳ԰ɡ�\n" NOR, me);
	        	ob1->move(me);
	        	ob2->move(me);
		}
}

