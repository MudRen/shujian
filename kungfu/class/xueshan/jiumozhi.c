// jiumozhi.c �Ħ��
// by iceland
// Modified by Lklv 2001.10.23
// Modified by tangfeng 2004

inherit F_MASTER;
#include <ansi.h>
inherit NPC;

#define QUESTDIR2 "quest/�����˲�/����Ӫ��ƪ/"

string askduanyu();
//int start_condition(object ob);
int power_condition(object me,object ob,int p);
void create()
{
        set_name("�Ħ��", ({ "jiumo zhi", "jiumozhi","zhi" }));
        set("long",@LONG
������ȳƣ�������ɷ���������б������������������鱦����Ȼ���ԣ�
ֻ���������ü��ۣ����������׽�֮�⡣
LONG
        );
        set("title", HIY "����������" NOR);
        set("gender", "����");
        set("class", "huanxi");
        set("age", 55);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 35);
        set("int", 40);
        set("con", 30);
        set("dex", 30);
        set("per", 25);
        set("max_qi", 6500);
        set("eff_jingli", 3500);
        set("max_jing", 6000);
        set("neili", 14000);
        set("max_neili", 14000);
        set("jiali", 80);
        set("combat_exp", 2900000);
        set("score", 290000);
        set("unique", 1);

        set_skill("huanxi-chan", 200);
        set_skill("literate", 150);
        set_skill("force", 200);
        set_skill("longxiang-boruo", 200);
        set_skill("dodge", 290);
	set_skill("poison", 100);
        set_skill("yuxue-dunxing", 290);
        set_skill("strike", 290);
        set_skill("huoyan-dao", 300);
        set_skill("parry", 290 );
        set_skill("dashou-yin", 290 );
        set_skill("hand", 290 );
        set_skill("parry", 290 );
        set_skill("staff",290);
        set_skill("wushang-dali",290);

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hand", "dashou-yin");
        map_skill("strike", "huoyan-dao");
        map_skill("staff","wushang-dali");
        map_skill("parry", "huoyan-dao");
        prepare_skill("strike","huoyan-dao");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: exert_function, "shield jiumo zhi" :),
                (: perform_action, "strike.fen" :), }));

        create_family("������", 10, "����");
        set("class", "huanxi");
        set("chat_chance", 2);
        set("chat_msg", ({
		"�Ħ�ǵ�ͷ��˼��˵������ɽ�����£����������£��ߣ���ѩɽ�������ĵ�Ȳ��ϣ���\n",
		"�Ħ�ǽ�˫�ƾٵ���ǰ�����ƣ���Ц��һ�����������м������ҵĵ��֣���\n",
	}) );
		set("inquiry",([
		"����" : (: askduanyu :),
		"������" : "������Ǵ����¡�",
		"������" : "�������Ǵ���μ���ѧ�����֮�أ���˵�������񽣾������С�",
		"����ʮ����" : "ؤ���ѧ����ϧδ�ܵü���",
		"����" : "�����˳���Ľ�ݡ������壬�˵�һ���ú���",
		"Ӫ�ȶ���" : (: askduanyu :),
		"Ľ�ݸ�" : "�����˳���Ľ�ݡ������壬��˵Ľ�ݹ����꼶���ᣬȴ����������",
		"Ľ�ݲ�" : "���˹���Ľ�ݲ����Ľܲţ���ϧӢ�����š�",
		"������" : "��˵������������߾�ѧ����һ��Ҫ��취�����ü���",
	]));
	      set_temp("apply/armor", 60);
        set_temp("apply/damage", 50);
        set_temp("apply/attack", 60);
        set_temp("apply/dodge", 50);
        setup();
        carry_object("/d/xueshan/npc/obj/longxiang-jiasha")->wear();

        add_money("gold",1);
}
string askduanyu()
{
	object me;
	me = this_player();
  if(!me->query(QUESTDIR2+"start" ))
  {
  	  command("?");
  		return "Сɮ�����ö�������֪���ķ����֡�";
  }
	if (me->query(QUESTDIR2+"start") && !me->query_temp(QUESTDIR2+"jiumozhi")&& !me->query(QUESTDIR2+"over"))
	{
  	  command("shrug "+me->query("id"));
  		return "Сɮ�����ö�������֪���ķ����֡�";
  }
	if (me->query(QUESTDIR2+"start") && me->query_temp(QUESTDIR2+"jiumozhi")&& !me->query_temp(QUESTDIR2+"kill_dizi")&& !me->query(QUESTDIR2+"over"))
	{
  	  command("flop "+me->query("id"));
  		return "��֪����֪�����飬���Ǻ��񻹲�Ӧ���ٵ��Ұɣ�ȥ��������¿���ȥ��";
  }
	if (me->query(QUESTDIR2+"start") && me->query_temp(QUESTDIR2+"kill_dizi")&& !me->query_temp(QUESTDIR2+"caught")&& !me->query(QUESTDIR2+"over"))
	{
  	  command("flop");
  	  command("kick "+me->query("id"));
  		return "��֪����֪�����飬���Ǻ��񻹲�Ӧ���ٵ��Ұɣ���ȥ�������";
  }
	if (me->query(QUESTDIR2+"start") && me->query_temp(QUESTDIR2+"caught") && !me->query_temp(QUESTDIR2+"askzhi")&& !me->query(QUESTDIR2+"over"))
	{
  	  command("sneer "+me->query("id"));
  	  kill_ob(me); 
  	  set("quest/try_fight",1);
  	  set("quest/try_fight_id",me->query("id"));
  	  command("haha "+me->query("id"));	  
  	  power_condition(me,this_object(),200+random(100));  	  
		  return "��������ι��������������Ҫ���߻����õ㱾�³����ɡ�\n";
  }
	if (me->query(QUESTDIR2+"start") && me->query_temp(QUESTDIR2+"caught") && me->query_temp(QUESTDIR2+"askzhi")&& !me->query(QUESTDIR2+"over"))
	{
  	  command("sneer "+me->query("id"));
  	  kill_ob(me); 
  	  power_condition(me,this_object(),300+random(100));  	  
		  return "��������ι��������������Ҫ���߻����õ㱾�³����ɡ�\n";
  }
	if (me->query(QUESTDIR2+"over"))
	{
  	  command("sneer "+me->query("id"));
		  return "��������ι������������ﶺ�����죬���������粻�������ˡ�\n";
  }
	return "�������Ǵ���������֮�ӡ�";
}
void attempt_apprentice(object ob)
{
        if( (string)ob->query("gender") == "����" ) {
                command("say ʩ�������ȱ����˵�����ն�����������...\n");
                return;
        }
if( ob->query("family/master_name") == "���ַ���" || ob->query("family/master_name") == "Ѫ������" )
{
command("say "+ RANK_D->query_respect(ob) + "������ʦָ�㣬�Ҳ������㣡");
return ;
}
        if ((string)ob->query("family/family_name") != "������") {
                command("say"+ RANK_D->query_respect(ob) +
                        "���Ǳ��µ��ӣ������ﵷʲô�ң���");
                return;
        }
        if ((int)ob->query_skill("longxiang-boruo", 1) < 150) {
                command("say �Ҵ����¸����书�����ڹ��ศ��ɡ�");
                command("say"+ RANK_D->query_respect(ob) +
                        "�ٰ�����ͨ��������������б��ŵ��ڹ��ɡ�");
                return;
        }
        if (((int)ob->query_con() < 32) || ((int)ob->query_str() < 32)){
                command("hmm");
                command("say ��λ" + RANK_D->query_respect(ob) +
                	"�����ƺ����ʺ�ѧϰ�һ��浶�񹦣����Ǿ��������ĳ�·�ɡ�");
                return;
        }
	command("say ������Ǿ��棬ȷʵ������ĺò��ϣ��ðɣ����������úõ��̵�����ɡ�");
	command("recruit " + ob->query("id"));
	ob->set("title", HIY "�������������µ���" NOR);
}
int power_condition(object me,object ob,int p)
{
	int i;
	if(!me || !ob) return 0;
	if(environment(me)!=environment(ob)) return 0;
	
 	i=me->query("max_pot");
	if(p<150) p=150;
	if(i<p) i=p;
	i=i-125;	
  ob->set_skill("huanxi-chan", i+random(50));
  ob->set_skill("literate", i+random(50));
  ob->set_skill("force", i+random(50));
  ob->set_skill("longxiang-boruo",i+random(50));
  ob->set_skill("dodge", i+random(50));
	ob->set_skill("poison", 200);
  ob->set_skill("yuxue-dunxing", i+random(50));
  ob->set_skill("strike", i+random(50));
  ob->set_skill("huoyan-dao", i+random(50));
  ob->set_skill("parry", i+random(50));
  ob->set_skill("staff",i+random(50));
  ob->set_skill("wushang-dali",i+random(50));
  i=me->query("combat_exp");
  ob->set("combat_exp",i);
  i=me->query("neili");	  
  if(i<15000) i=15000;
  ob->set("neili", i);	  
  i=me->query("max_neili");	  
  if(i<8000) i=8000;
  ob->set("max_neili", i);	  
 	i=me->query("max_qi");	  
  ob->set("max_qi", i*2);	  
  ob->set("eff_qi", ob->query("max_qi"));	
  ob->set("qi", ob->query("max_qi"));	
  return 1;
}

void die()
{
	object me,ob=this_object();
	
	if(ob->query("quest/try_fight"))
	  if(ob->query("quest/try_fight_id"))
	  {
	  	me=find_player(ob->query("quest/try_fight_id"));
	  	if(!me) return 0;
	    if(environment(me)!=environment(ob)) return 0;
	    if (me->query(QUESTDIR2+"start") && me->query_temp(QUESTDIR2+"caught") && !me->query_temp(QUESTDIR2+"askzhi")&& !me->query(QUESTDIR2+"over"))
	        me->set_temp(QUESTDIR2+"askzhi",1);
	    ob->delete("quest/try_fight");
	    ob->delete("quest/try_fight_id");
     }
	::die();
}
