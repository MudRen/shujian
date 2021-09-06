// supergongsun.c ����ֹ
// By  2009/2/20
#include <ansi.h>
inherit NPC;
int power_condition(object me,object ob,int p);
int start_condition(object ob);
void kill_player(object me);
void unconcious();
void die();
void kill_ob(object me);

void create()
{
	set_name("����ֹ", ({ "gongsun zhi", "gongsun", "zhi" }));
	set("long","��ĿӢ����͸�������߾�֮�ţ�ֻ����ɫ���ƣ����տ��¡�\n");
        set("title",HIW"����ȹ���"NOR);
	set("gender", "����");
	set("age", 45);
	set("attitude", "friendly");
	set("shen", -3000);
	set("str", 25);
	set("int", 24);
	set("con", 28);
	set("dex", 26);
        set("per", 20);
        set("unique", 1);

	set("max_qi", 50000);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
  set("eff_jingli", 2000);
	set("jiali", 80);
	set("combat_exp", 10000000);
 
        set_skill("force", 450);      
        set_skill("dodge", 450);
        set_skill("parry", 450);
        set_skill("guiyuan-tunafa", 450);
        set_skill("literate", 120); 
        set_skill("shuishangpiao", 450);
        set_skill("tiezhang-zhangfa", 450);
        set_skill("strike",450);
        set_skill("sword", 450);
	      set_skill("jindao-heijian", 450);

        map_skill("force", "guiyuan-tunafa");
        map_skill("dodge", "shuishangpiao");
        map_skill("strike", "tiezhang-zhangfa");
        map_skill("parry", "liangyi-jian");
	      map_skill("sword", "jindao-heijian");
	      map_skill("blade", "jindao-heijian");
        prepare_skill("strike", "tiezhang-zhangfa");

        set("inquiry", ([
            "���鵤": "��ҩ�޶࣬����Ҳ�������ƣ����򲻵��ѡ�����",
        ]) );

	setup();
	carry_object("/clone/weapon/sword")->wield();
	carry_object("/clone/weapon/blade")->wield();
	carry_object("/clone/armor/cloth")->wear();
}
 
void init()
{
	object me = this_player();
	object ob = this_object();
if(me->query_temp("quest/jindaoheijian/zhuigsz"))
  {
	  command("fear "+me->query("id"));
	  command("say �㣡�㣡��Ȼ֪����������ģ�������ֻ��������Զ��ʧ������������ˡ�");
	  me->set_temp("quest/jindaoheijian/qqchi",1);
    power_condition(me,this_object(),300+random(100));
	  me->set("kill_id",ob->query("id"));
		call_out("do_kill", 1, me, ob);
  	
  } 
}

int do_kill(object me, object ob)
{
	this_object()->kill_ob(me);
	me->kill_ob(this_object());
	this_object()->start_busy(0);
	this_object()->set("quest/try_fight",1);
  this_object()->set("quest/try_fight_id",me->query("id"));
	call_out("kill_ob", 1, me, ob);
 	return 1;
}

void kill_player(object me)
{
	object ob=this_object();
  if(!me) return;
  if(environment(me)!=environment(this_object())) return;
  if(me->query_temp("quest/jindaoheijian/zhuigsz"))
  {
     if (!present("sword",ob))
	             carry_object(BINGQI_D("sword"))->wield();
	      else command("wield sword");
    return;
  }  	
}

void kill_ob(object me)
{       
	 command("sneer " + me->query("id"));
	 	::kill_ob(me);

}

int power_condition(object me,object ob,int p)
{
	  int i;
    if(environment(me)!=environment(ob)) return 0;
    if (!present("sword",ob))
	    carry_object(BINGQI_D("sword"))->wield();
	    carry_object(BINGQI_D("blade"))->wield();
	  i=me->query("max_pot");
	  if(p<150) p=150;
	  if(i<p) i=p;
	  i=i-100;	  
	  ob->set_skill("force", i+random(50));
	  ob->set_skill("dodge", i+random(50));
	  ob->set_skill("parry", i+random(50));
	  ob->set_skill("blade", i+random(50));
	  ob->set_skill("strike",i+random(50)); 
	  ob->set_skill("sword",i+random(50));
	  ob->set_skill("jindao-heijian",i+random(50));
	  ob->set_skill("guiyuan-tunafa",i+random(50));
	  ob->set_skill("tiezhang-zhangfa",i+random(50));
	  ob->set_skill("shuishangpiao",i+random(50));
	  i=me->query("combat_exp");
	  ob->set("combat_exp",i);
	  i=me->query("neili");	  
	  if(i<12000) i=12000;
	  ob->set("neili", i);	  
	  i=me->query("max_neili");	  
	  if(i<6000) i=6000;
	  ob->set("max_neili", i);	  
  	i=me->query("max_qi");	  
	  ob->set("max_qi", i*(1+random(2)));	  
 	  ob->set("eff_qi", ob->query("max_qi"));	
 	  ob->set("qi", ob->query("max_qi"));	
    return 1;
}

int start_condition(object ob)
{
	set_skill("force", 450);
	set_skill("dodge", 450);
	set_skill("parry", 450);
	set_skill("sword", 450);
	set_skill("blade",450); 
	set_skill("strike",450); 
	set_skill("jindao-heijian",450); 
	set_skill("guiyuan-tunafa",450); 
	map_skill("force","guiyuan-tunafa");
	map_skill("blade","jindao-heijian");
	map_skill("sword","jindao-heijian");
	map_skill("dodge","shuishangpiao");
	set("combat_exp", 8000000);
	set("max_qi", 30000);
	set("max_jing", 10000);
	set("eff_jingli",10000);
	set("max_neili", 21000);
	set("qi",30000);
	set("jing",10000);
	set("jingli",10000);	
	set("neili", 42000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat",({ 
		(: perform_action, "sword.daojian" :), 

	}));
  return 1;
}



void unconcious()
{
  say( "����ֹ�����ڻ�������һ������һ��ҩ�����������Ƭ��֮����ָֻ��˾���\n");
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
}

void die()
{
	object ob=this_object();
	object me = this_player();
	if(ob->query("quest/try_fight")) {
	  command("sign");
	  if(ob->query("quest/try_fight_id")) {
      remove_call_out("kill_player");
      ob->remove_all_killer();
      start_condition(ob);
	  	me=find_player(ob->query("quest/try_fight_id"));
	    ob->delete("quest/try_fight");	 
	    ob->delete("quest/try_fight_id");
	  	if(!me) return;
      me->remove_all_killer();  
      if(environment(me)!=environment(this_object())) return;
       if(me->query_temp("quest/jindaoheijian/zhuigsz")&& me->query_temp("quest/jindaoheijian/qqchi"))
   {     	
     message_vision(HIR"\n����ֹʹ������İ������ԭ�¡�\n"NOR,me);   

     message_vision(HIC"\n����ѯ����һЩ��������������ֹ������˵���˵��귢���ڹ���ֹ����ǧ�����ϵľ�����\n"+
                       "������ǧ��ȴ���������ң����ܹ������ٷ�֮���Ǹ������ĺ���,��Ҳ��û�а취�� ��ǧ����\n"+
                       "������ˮ��Ʈ����ǧ������ã���������������߶����˾���ȣ��¼��˹���ֹ����������\n"+       
        	             "�ɷ����书������ָ�㣬һ�гɾͶ��ǰ������͡����þ��ڵĹ���ֹ����������˳�������\n"+ 
        	             "�������ϰ��ϣ�Ҫ������Զ�߸߷ɡ���ǧ��ʶ�Ƽ�ı������ȡ�ĶԸ����ǵķ�����Ϊ��������\n"+ 
        	             "���������黨���У�Ȼ��Ѿ��鵤����������˪ˮ��ֻ��һ��<ʵ����������������Ϊ�Լ���\n"+ 
        	             "�������˺���>���ù���ֹѡ����Լ����Ǿ����ˡ����������ֹɱ������������Լ�������\n"+ 
        	             "��������������ȥ���ѣ���ƭ����ǧ�߷�����ҩ��Ȼ���������������ϣ�������Ѩ֮�С���\n"+ 
        	             "������ǧ�߹������ţ�������������������ɷ����С������깫��ֹ���������ֿ�ʼͬ�鹫��\n"+ 
                       "ֹ���ҵ���ʷ���������������ˣ�Ҳ���������޳����Ҿ͸���ѧϰ�𵶺ڽ����ᣬ���������\n"+ 
                       "Ե�˾ͺͿ���ѧϰ��\n"NOR,me);
        	 message_vision(HIG"\n��л��λ������ɱ֮�����������ѧϰ�𵶺ڽ�����˫�У��Ϳ�����ʱ�������������̣�\n"NOR,me);   
        	 me->set("quest/jindaoheijian/ask",1);
        	 me->delete_temp("quest/jindaoheijian/zhuigsz");
        	 me->set_temp("quest/jindao-heijian/qqchi",0);
        	 me->move("/d/gumu/jqg/dating");
        	                         	      }
     ob->unconcious();       
                                    }
	    else  {
	    command("why");
	    ::die();
            }
  }
}
