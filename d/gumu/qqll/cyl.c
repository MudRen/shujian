// cyl.c ������
// kxkxkx 2004��3��

#include <ansi.h>

inherit NPC;

int cancel_leave();

private nomask void leave();

string ask_me()
{
	object me = this_player();
	
	if ( present("qiyan stone", me)) me->set_temp("askqysd",1);
	
	return "��˵��ʲô������С�϶��ҵ�û������\n";
}

void create()
{
   set_name("������", ({"chunyu lan", "chunyu", "lan"}));
   set("title", HIW"������"NOR);
   set("gender", "����");
   set("age", 45);
   set("long", "һ����֪���Ժη��Ľ�ʦ��\n");

   set("attitude", "friendly");
   set("no_bark",1);
   set("per", 30);
   set("str", 20);
   set("int", 20);
   set("con", 20);
   set("dex", 20);

   set("combat_exp", 100000);
   set("shen_type", 1);

   set("max_neili", 100);
   set("neili", 1000);
   set("jiali", 0);
   
   set_skill("force", 100); 
   set_skill("dodge", 100);
   set_skill("parry", 100);
   set_skill("cuff", 100);

   set("inquiry", ([
      "����ʯ" : (:ask_me:),
   ]));

   set_temp("apply/attack", 50);
   set_temp("apply/defense", 50);
   set_temp("apply/damage", 15);

   setup();
   if(clonep())
   {
   	carry_object(ARMOR_D("cloth"))->wear();   	
   	call_out("leave", 120);
   	call_out("sure_leave", 300);
   }	
}

int accept_object(object who, object ob, object me)
{
	if( !ob->can_cmds() ) return 0;	
	if( ob->query("cyl", 1) != this_object() && !(wizardp(who) && who->query("env/test"))  ) return 0;	
	if(!who->query_temp("askqysd")) return 0;	
	cancel_leave();	
	who->delete_temp("askqysd");
	call_out("move_back",1,ob,who);	
	return 1;
}

void move_back(object ob,object user)
{
	object cyl;
	
	remove_call_out("move_back");
	cyl = this_object();
	if(!ob || !user) return;	
	ob->move(user);		
	switch(ob->query("max_killers")) {
		case 3:
		ob->set("ok", 1);
		message_vision("$N�����һЦ����׳ʿ��ɱ���߱��˰���С�϶���ʵֻ�Ǹ��콭��ƭ���Եģ�\n����֪����Щ����Ķ���������\n",cyl);
		message_vision("$n��$Nһ"+ob->query("unit")+ob->query("name") + "��\n",user,cyl);
		message_vision("$Nһգ�ۣ��ֲ�֪������ȥ�ˡ�\n",cyl);
		destruct(cyl);
		break;
		case 4:
		ob->set("ok", 2);
		cyl->force_me("say �������������񣬻�����ʯ̬֮����Ҳ���������\n���Ͼ�����ʲôϡ���������Ȼ�������Դ�Ϊ�����������˲��Ⱑ��");
		message_vision("$n��$Nһ"+ob->query("unit")+ob->query("name") + "��\n",user,cyl);
		message_vision("$Nһգ�ۣ��ֲ�֪������ȥ�ˡ�\n",cyl);
		destruct(cyl);
		break;
		default:
		ob->set("ok", 3);
		message_vision("$N��ʼϸϸƷ����"+ob->name()+ "��\n",cyl);
		user->start_busy(10);
		call_out("give_hook_completion", 10,user,ob);
		break;
	}
}

void give_hook_completion(object user,object ob)
{
	ob->give_hook_completion(user);
}

private nomask void sure_leave()
{
   object self;
         
   self = this_object();
   message_vision("$N����ͻȻ����ʲô�£�����ææ���뿪�ˡ�\n", self);
   destruct(self);
}


// ��ͼȡ���뿪����Ϊ��ʱ���Ҫ�����������������
int cancel_leave()
{
   return remove_call_out("leave") != -1;
}

// 120����뿪��call_out
private nomask void leave()
{
   object self;
   
   self = this_object();
	message_vision("$N����ͻȻ����ʲô�£�����ææ���뿪�ˡ�\n", self);
	destruct(self);
}

// ���ⱻ���Σ�������npc������
void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
}

// ���ⱻ������������npc������
void die()
{
	unconcious();
}

// ������˴�ܣ�������npc������
void kill_ob(object obj)
{
	object me = this_object();

	command("!!!");
	me->remove_enemy(obj);
	obj->remove_killer(me);
	return;
}

// ������˴�ܣ�������npc������
void accept_fight(object obj)
{
	command("peace " + obj->query("id"));
	return;
}