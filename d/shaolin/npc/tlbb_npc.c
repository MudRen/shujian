// tangfeng@SJ 2004
// /d/shaolin/npc/tlbb_npc.c
//inherit NPC;

inherit FIGHTER;
#include <ansi.h>

#define QUESTDIR3 "quest/�����˲�/��������ƪ/"
#define QUESTDIR4 "quest/�����˲�/���ɾ�Ԯƪ/"
#define QUESTDIR5 "quest/�����˲�/��������ƪ/"

//string *str_menpai = ({ "wd","hs","ss","gm","tz","dls","sld","xx","mj","thd","kl"});	
//#include "/d/city/npc/skills_pfm.h";

void create()
{
	set_name("����", ({ "di zi", "dizi"}));
	set("long", "һλĳ���ɵ��ӡ�\n");
	set("gender", "����");
	set("age", 33);
	set("attitude", "peaceful");
	set("shen", -100);
  set("str", 20);
	set("int", 20);
  set("con", 20);
	set("dex", 20);
  set("double_attack",1);
	set("max_qi", 30000);
	set("max_jing", 6000);
	set("eff_jingli",6000);
	set("neili", 40000);
	set("max_neili", 30000);
	set("jiali", 200);
	set("combat_exp", 5000000+random(8000000));
	set_skill("force", 70);
	set_skill("dodge", 80);
	set_skill("unarmed", 70);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("cuff", 80);
	setup();
	carry_object(ARMOR_D("shoes"))->wear();
	carry_object(ARMOR_D("changshan"))->wear();
}
void init()
{
    object me,ob;  
    string good_skills;
    int i;     
    ::init();
    ob = this_object();
    if(ob->query("setok")) return;
	  if(!ob->query("party"))	ob->set("party",str_menpai[random(sizeof(str_menpai))]);  	 
    ob->copy_menpai(({ob->query("party")}),1,random(2),100);  //����npc�������书                                              
	  ob->copy_state();				//�������ɸ���npc ��һЩ״̬
		if (ob->query("f_skill2")) 
				good_skills=to_chinese(ob->query("f_skill"))+"��"+to_chinese(ob->query("f_skill2"));
		else	
				good_skills=to_chinese(ob->query("f_skill"));
   	ob->set("long",HIW+ob->query("family/family_name")+"���֣�����������"+good_skills+"��"NOR);
    if(!ob->query("fight_id"))
    {
		  ob->set_skills_level(350+random(200));
    	return;
    }
    me = present(ob->query("fight_id"),environment(ob));
	  if(!me) 
	  {
		  ob->set_skills_level(350+random(200));
    	return;
    }
    ob->set("setok",1);    
	  i=me->query("max_pot");
	  if(i<350) i=350;
	  i=i-100;	
	  
    //����ɮ
	  if(ob->query("party")=="sl")
	  {
	  	set_name("������ɮ", ({"wuming laoseng","wuming","laoseng",}));
      set("long",
                "����һλ�����۵Ŀ���ɮ�ˣ���Ĳ��ߡ�\n"
                "���������Ѯ���⣬ϡϡ����ļ���������Ȼȫ�ס�\n"
      );
      set("nickname", "������ɮ");
      set("gender", "����");
      set("attitude", "friendly");
      set("class", "bonze");
      set("no_bark",1);
      set("age", 70);
      set("shen", 32000);
      set("str", 25);
      set("int", 30);
      set("con", 30);
      set("dex", 30);
    }
	  else if(ob->query("party")=="gb")
	  {
	    set_name("����", ({"xiao feng", "xiao", "feng"}));
	    set("gender", "����");
	    set("nickname",HIB"����"NOR);
	    set("title",HIY"ǰؤ�����"NOR);
	    set("age", 58);
	    set("long", 
	    	"������ؤ��ǰ�ΰ������塣\n"
	    	"������������࣬���ʮ�ֿ��࣬����һ�������ֿ���ʮ\n"
		    "�����Ի������ӣ�˫Ŀ��磬��������\n");
    	set("attitude", "peaceful");
	    set("str", 30);
    	set("int", 30);
	    set("con", 30);
	    set("dex", 30);
    }
    ob->set_skills_level(i-random(50)+random(50));
	  ob->set("max_neili",me->query("max_neili"));
  	ob->set("max_jingli",me->query("max_jingli"));
    ob->set("max_qi",me->query("max_qi"));
  	ob->set("max_jing",me->query("max_jing"));
		ob->set("neili",query("max_neili")*3/2);
		ob->set("jingli",query("max_jingli")*3/2);
		ob->set("eff_jingli",query("max_jingli")*3/2);
		ob->set("qi",query("max_qi"));
		ob->set("eff_qi",query("max_qi"));
		ob->set("jing",query("max_jing")*3/2);
		ob->set("eff_jing",query("max_jing")*3/2);
    ob->set("jiali",150+random(50));
    ob->set("combat_exp",me->query("combat_exp")*5/4);
 		ob->set_skill("literate",ob->query("int")*10); 	 											//full literate

       set_temp("double_attack",1);//�ٺ�
       set("double_attack",1);//�ٺ�
 		if(ob->query("party")=="gb") message_vision(HIC"$N��$n����Ц������$n�ϴγ�������δ��͵Ϯ����ξ��پ�һʤ������\n" NOR, ob,me);
 		if(ob->query("party")=="sl") message_vision(HIC"$N��$n����ʩ�������$n�������������سɷ������ӷ𡣡�\n" NOR, ob,me);
    ob->set_skill("wuxing-zhen",200);
    ob->remove_all_killer();
}

void die()
{
	object ob=this_object();
  if(random(2))command("why");
  else command("disapp "+ob->query("id"));
  if(random(2)) message_vision(HIG"$N���˵�ͷ��������ʧ�ڽ����\n\n" NOR, ob);
  else message_vision(HIG"$N���������˳�ȥ��\n\n" NOR, ob);
	destruct(ob);
}
void unconcious()
{
  die();
}
