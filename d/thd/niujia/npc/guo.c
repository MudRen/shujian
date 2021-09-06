//ytx.c

inherit NPC;
#include <ansi.h>
int ask_jiuyuan();
#define QUESTDIR "quest/���Ӣ�۴�/"

void greeting(object me);

void create()
{
	set_name("��Х��", ({ "guo xiaotian", "guo", "xiaotian" }) );
	set("gender", "����" );
	set("title", HIC"����"NOR);
	set("nickname", HIC"���b����֮��"NOR);
	set("age", 28);
	set("long",
"����Ŀ��࣬Ũü���ۡ�\n"
"������ɽ���ú����������ʹ��ʢ�ĺ����\n");
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
	set_skill("cuff",200); 
	set_skill("jinyan-gong",200);
	set_skill("taizu-quan",200);
	set_skill("xiantian-gong",200);
	map_skill("force","xiantian-gong");
	map_skill("cuff","taizu-quan");
	map_skill("dodge","jinyan-gong");
  prepare_skill("cuff", "taizu-quan");
    
	set("combat_exp", 1000000);
	set("max_qi", 30000);
	set("max_jing", 30000);
	set("max_neili", 50000);
	set("eff_jingli",30000);
	set("qi",30000);
	set("jing",30000);
	set("jingli",30000);
	set("neili", 50000);

  set("inquiry", ([
    "��Ԯ": (: ask_jiuyuan :),
		"������": "��������ܡ�",
    "��Ƽ" : "�����һ�ҡ�",
    "����" : "����һ�����˸���δ�����Ķ�Ůȡ�����֡�",
    "�" : "��������������ĵĹ��⡣",
    "��ϧ��" : "�����ҵ�ϱ��",

	]));
	set("chat_chance", 10);
        set("chat_msg", ({
		"���ﲻ��ô�ĳ��ִ���������⵽���Ƿ�����ʲô���顢����\n",
		"���Ӻ͵�ϱ��Ҫ���ˣ���ڹ�������ô�ᷢ�����������ء�����\n",
        }) );
     setup();
	carry_object("/clone/armor/cloth.c")->wear();
	carry_object(ARMOR_D("shoes"))->wear();
} 

int ask_jiuyuan()
{
	object me = this_player();

	if(me->query(QUESTDIR+"start"))
		  {
	  command("beg1 "+me->query("id"));
		command("say ��λ"+RANK_D->query_respect(this_player())+"����ȥ������ܰ���Ҫ��������ס�ˣ�");
			  return 1;
  } 
	if(me->query(QUESTDIR+"over"))
				  {
	  command("beg1 "+me->query("id"));
		command("say ��л��λ"+RANK_D->query_respect(this_player())+"���־������ѽ��");		
					  return 1;
  } 
  if( me->query("combat_exp") < 2000000 )
        	{
	  command("disapp "+me->query("id"));
		command("say ���㵱ǰ�ľ�����»����ܰ�æ��Ԯ����ܣ�����ץ��ȥ����ȥ�ɡ�\n");
       			  return 1;
  }  	
  if(me->query(QUESTDIR+"time") && time()-me->query(QUESTDIR+"time")<86400)
	{
	  command("shake "+me->query("id"));
	  command("say �����Ȱﵽ����ɣ�����ɡ�");
	  return 1;
  }
   if(me->query(QUESTDIR+"combat_exp") && me->query("combat_exp")-me->query(QUESTDIR+"combat_exp")<100000)
	{
	  command("look "+me->query("id"));
	  command("say ���㵱ǰ�ľ�����»����޷���æ������ץ��ȥ����ȥ�ɡ�");
	  return 1;
  }
 if(!me->query(QUESTDIR+"over"))
    {
	me->set(QUESTDIR+"��ѩ����/start", 1);
	me->set(QUESTDIR+"time",time());
  me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));
	command("cry "+me->query("id"));
	command("say �����Һ���ܾ�Ԯһλ�����׷ɱ�ĵ�ʿ��û�뵽����ȴ���н����ץ���ǣ�\n"+
		       "��λ������Ͽ�ȥ����ܼҽ������������İɣ���׼�����������͵���");
		       return 1;
  }
}

