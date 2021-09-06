//yangtiexin.c

inherit NPC;
#include <ansi.h>
int ask_yangjiaqiang();
#define QUESTDIR "quest/���Ӣ�۴�/��ѩ����/"
#define QUESTDIR6 "quest/���Ӣ�۴�/yangjiaqiang/"

void greeting(object me);

void create()
{
	set_name("������", ({ "yang tiexin", "yang", "tiexin" }) );
	set("gender", "����" );
	set("nickname",HIY"���ǹ����"NOR);
	set("age", 27);
	set("long",
"һ���׾���Ƥ�ĺ��ӡ�\n"
"���������������������˵ĺ����\n");
	set("str", 25);
	set("dex", 25);
	set("con", 25);
	set("int", 25);
	set("per", 25);
	set("shen_type", 1);
  set("no_get", 1);
  set("no_bark", 1);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("spear", 200);
	set_skill("cuff",200); 
	set_skill("jinyan-gong",200);
	set_skill("taizu-quan",200);
	set_skill("xiantian-gong",200);
	set_skill("yangjia-qiang",200);
	map_skill("force","xiantian-gong");
	map_skill("cuff","taizu-quan");
	map_skill("dodge","jinyan-gong");
	map_skill("spear","yangjia-qiang");
	map_skill("parry","yangjia-qiang");
    prepare_skill("cuff", "taizu-quan");
	set("combat_exp", 1000000);
	set("max_qi", 30000);
	set("max_jing", 3000);
	set("max_neili", 5000);
	set("eff_jingli",3000);
	set("qi",30000);
	set("jing",3000);
	set("jingli",3000);
	set("neili", 5000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
       (: exert_function, "wuqi" :),
       (: perform_action, "spear.tiaoji" :),
       (: perform_action, "spear.shanji" :),
     }));

  set("inquiry", ([
    "���ǹ": (: ask_yangjiaqiang :),
    "��Х��" : "���������֡�",
    "��ϧ��" : "�����һ�ҡ�",
    "�" : "����һ�����˸���δ�����Ķ�Ůȡ�����֡�",
    "����" : "���������ֹ�Х��Ĺ��⡣",
    "��Ƽ" : "������ɩ��",
	]));
	setup();
	carry_object("/clone/weapon/spear.c")->wield();
	carry_object("/clone/weapon/spear.c");
	carry_object("/clone/armor/cloth.c")->wear();
} 

void init()
{
  object me;
	::init();
  if (interactive(me = this_player()) ) {
  	   me->start_busy(1);
       call_out("greeting", 2, me);
  }       
}

void greeting(object me)
{
		int i,p;
  if(!me) return;

	if(me->query_condition("killer"))
	{
	  command("fear "+me->query("id"));
    command("say С�Ĺٸ�ͨ����");
    me->move(__DIR__"njroad3");
	  return;
	}

  if(me->query(QUESTDIR+"start") && !me->query(QUESTDIR+"over"))
  {
	me->start_busy(3);
  	tell_object(me,HIG"\n��ͻȻ���ֺ�Ժդ����վ��һ���ˣ�����˵��������л��λ��������Ԯ������\n"NOR);
  	tell_object(me,HIC"������һ�£�������˵����"+me->query("name")+"��Ϊ��л������һ�ң��ҿɽ��������ǵ����ǹ�������㣬�������ʱ������̣�\n"NOR);
  	me->delete(QUESTDIR+"start");
  	me->delete_temp(QUESTDIR+"kill");
  	me->set(QUESTDIR+"over",1);
  	p=10+random(10);
    me->add("max_neili",p);
    me->add("combat_exp",me->query_skill("force")+500);
    me->set("quest/���Ӣ�۴�/time",time());
		me->set("quest/���Ӣ�۴�/combat_exp",me->query("combat_exp"));
    i=180+random(40);
   	me->add("mana",i);
  	tell_object(me,HBYEL"\n����"+NATURE_D->game_time()+"�⿪���Ӣ�۴���ѩ����ƪ�����"+p+"�����������"+((int)me->query_skill("force")+500)+"�㾭�齱����"+i+"��������\n\n"NOR); 
    log_file("quest/SheDiao", sprintf("%s(%s) ��ѩ������ɡ�������%d�����������%d�㾭�飬%d��������\n", me->name(1),me->query("id"), p,(me->query_skill("force")+500),i ) );

    return;
  }  	

}


int ask_yangjiaqiang() 
{
	object me = this_player();
	object ob = this_object();
   
if(me->query(QUESTDIR6+"pass"))
  {
	  command("disapp "+me->query("id"));
          command("say �㲻ѧ�Ѿ�ѧ�����ǹ����");
if(me->query_skill("yangjia-qiang",1) <10 ) me->set_skill("yangjia-qiang",10);
	  return 1;
  } 
    
 //�书ѧϰ֮����Ҫ���һ�죬������Ҫ���500K
	if(me->query(QUESTDIR6+"time") && time()-me->query(QUESTDIR6+"time")<86400)
	{
	  command("shake "+me->query("id"));
	  command("say �������д赽����ɣ�����ɡ�");
	  return 1;
  }
   if(me->query(QUESTDIR6+"combat_exp") && me->query("combat_exp")-me->query(QUESTDIR6+"combat_exp")<100000 &&  !me->query("cw_exp") )
	{
	  command("look "+me->query("id"));
	  command("say ���㵱ǰ�ľ�����»����������򣬻���ץ��ȥ����ȥ�ɡ�");
	  return 1;
  }
  
  if(me->query(QUESTDIR+"over") > 0)
    {
    command("pat "+me->query("id"));
    message_vision(HIC"\n$n΢Ц�Ŷ�$N˵��������Ҫ����ϸ��!��,��������ǽ�ϵ���ǹ�趯����\n"NOR,me,ob); 
    me->set(QUESTDIR6+"time",time());
    me->set(QUESTDIR6+"combat_exp",me->query("combat_exp"));
    remove_call_out("thinking");
		call_out("thinking",5, me, ob);
    tell_object(me,YEL"��ƴ���ػ����������趯����ǹ��ʽ���㿪ʼ����˼����.........\n"NOR);
    me->start_busy(2);
	  return 1;
	  }
	  else
	 {  
	  command("? "+me->query("id"));
         command("say ���������ʲô?");
    return 1;
  }
}

int thinking(object me, object ob)
{
	int p;
	if(!me) return 0;
	
  if(me->query_temp("yjq_thinking")<(3+random(3)))
	{
		me->add_temp("yjq_thinking",1);
    if(random(2)) tell_object(me,HIG"\n��Ŭ���ػ���ղ���������ǹ����ʽ,ֻ�����ۻ�����...\n"NOR);
    else tell_object(me,HIY"\nͻȻ�䣬���ƺ�ץ����ʲô����Ŭ���ػ���ղ���������ǹ����ʽ�����ƺ��о��������еı仯����...\n"NOR);
	  tell_room(environment(me),HIC""+me->query("name")+"�ƺ���˼����ʲô��һ����ü��չ�����ӡ�\n"NOR, ({}));
	  remove_call_out("thinking");
		call_out("thinking",3+random(3), me, ob);
	}
	else
	{
    me->delete_temp("yjq_thinking");

     p=random(15);

       if(p == 3 &&  random(me->query("kar"))>28  && me->query("pur")>25  && me->query("kar")<31 )
    {
       tell_object(me,HIG"\n���ʱ���½��ղŵľ�����ʽ���ˣ��������������ĵ���ʽ�Ȼ��š�\n"NOR);
       message_vision(HIC"\n$N������������Ц������˵������ԭ����ˣ�ԭ����ˡ���\n"NOR,me); 
       tell_object(me,HIR"�����������ĵ�ָ��,�������������ǹ�ľ������ڡ�\n"NOR);
       me->set(QUESTDIR6+"pass",1);
       me->set_skill("yangjia-qiang",11);
       message_vision(HIC"\n��ġ����ǹ�������ˣ���\n"NOR,me); 
	log_file("quest/SheDiao", sprintf("%s(%s) ʧ��%d�γɹ��⿪���ǹ����Դ��%d�����飺%d��", me->name(1),me->query("id"), me->query(QUESTDIR6+"fail"),me->query("kar"),me->query("combat_exp")) );
    }
    else
    {
       tell_object(me,HIG"\n���Ժ����ƺ�ץס��ʲô��������Ȼ���Ǻ����ס�\n"NOR);
       message_vision(HIC"\n$Nҡ��ҡͷ�������������Ǻ����ѵġ���˵�գ������̾�˿�����\n"NOR,me); 
       command("poor "+me->query("id"));
       me->add(QUESTDIR6+"fail",1);
	log_file("quest/SheDiao", sprintf("%s(%s) �����ǹ��%d�Ρ���Դ��%d�����飺%d��", me->name(1),me->query("id"), me->query(QUESTDIR6+"fail"),me->query("kar"),me->query("combat_exp")) );
    }
  }
  return 1;
}
