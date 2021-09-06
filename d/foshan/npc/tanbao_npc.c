//man.c for dzd job by Ciwej@SJ
//show one chat robot here ^_^

#include <ansi.h>

inherit NPC;

string ask_job();
int ask_dzd();

#define MST		"/clone/npc/hanghai_master"		// ��γ�ǣ���Ϸָ����֧��

void create()
{
	set_name("��������", ({ "zhongnian nanzi","man" }));
	set("gender", "����");
    	set("age", 37);
    	set("long", @LONG
����һ�������Ѯ���������ӡ�
���ϴ��ŵ����ĳ��ݣ��ƺ�����û�ع����ˡ�
LONG);
    	set("combat_exp", 10000000);
    	set("shen", 10000000);
    	set("shen_type", 1);
	set("attitude", "peaceful");
	set("job_npc",1);
	set("no_ansuan",1);
	set("no_get", "�������Ӷ������̫���ˡ�\n");
	
	set("unique", 1);
			
	set("inquiry",
	([
		"�Ϻ�̽��":(:ask_job:),
		"���ǵ�" : (: ask_dzd :),
		"name":"��С�����֣�̫�������벻������",
		//"�㽶":(:debug_trigger:),
		//"rumors":"��������ֳ����Ʒ������ڽ������������壬���⽭����",
		]) );
	
    	set_skill("strike", 470);
	set_skill("dodge", 470);
	set_skill("parry", 470);
	set_skill("tiyunzong", 470);
	set_skill("taizu-quan", 470);
	set_skill("cuff", 470);
	set_skill("force", 470);
	set_skill("hamagong", 470);
	set_skill("literate", 200);
	
	map_skill("force","hamagong");
	map_skill("strike","hamagong");
	map_skill("parry","hamagong");
	map_skill("dodge","tiyunzong");
	map_skill("cuff","taizu-quan");
	
	prepare_skill("strike","hamagong");
	prepare_skill("cuff","taizu-quan");
	
	set("max_qi",20000);
	set("max_jing",20000);
	set("max_jingli",20000);
	set("eff_jingli",20000);
	
	set("oyf/hamagong",3);
	
	set("chat_chance_combat", 99);
	set("chat_msg_combat", ({
 		(: exert_function, "nizhuan" :),
 		(: perform_action, "strike.hama" :),
	}));
	
	set("chat_chance", 99);
	set("chat_msg", ({
		(: exert_function, "nizhuan" :),
 		(: perform_action, "strike.hama" :),
 		//query("name")+"���˴�ü���ƺ���Ҫ˵Щʲô��\n",
	}) );
					
    	add_temp("apply/attack", 50);
    	add_temp("apply/defense", 40);
    	add_temp("apply/armor", 40);	
	if(clonep()) 
	{
		CHANNEL_D->register_relay_channel("chat");
		carry_object("/clone/misc/cloth")->wear();		
	}
	setup();
}

int ask_dzd()
{
	command("say Σ�գ�Σ�գ���˵�ϵ�����ֻ��һ���ܻ��Ż����ģ�������˵�ǵط��кܶ౦��Ү��\n");
	//this_player()->set_temp("ask_dzd",1);
	return 1;
}


string ask_job()
{
	object me = this_player(), mst_obj;

	if( me->query_temp("hanghai_gameing") )
		return "�㲻��ȥ�Ϻ�̽�����𣿣�";
	if(me->query_condition("killer")) 
		return "�ҿɲ�����ٸ�����ʲô��ϵ��\n";
	if( file_size( MST + ".c" ) < 1 )
		return "������ͣ���ţ�";

	command("say �ðɣ��Ǿ����԰ɡ�");
	write("\n========= ���Ժ�����ִ�в������� ==========\n\n");

	mst_obj = new( MST );

	mst_obj->new_game(me);
	mst_obj->move(me);
	me->move("/d/foshan/hanghai_room");

	return "";
}
void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N��������������¶��֣���Ȼ�������������о���һ�����ŵ�æ���˻�������\n", ob);
	return;
}
void die()
{
	reincarnate();
	message_vision("$N�������˼���������ɫ�������ö��ˡ�\n",this_object());
	return;	
}

void relay_channel(object me, string verb, string arg)
{	
	call_out("rerere",random(3)+1,me,verb,arg);
}


void rerere(object me, string verb, string arg)
{	
	string ret;
	int emote = 0;
		
	if(!me) return;	
	if(this_object()->query_temp("chat_busy")) return;
	/*
	switch(arg)
	{
		case "���":ret = "��Ҳ��";break;
		case "fuck":ret = "fuck u 2";break;
		case "i love u":ret = "faint";emote=1;break;
		case "byebye":ret = "wave";emote=1;break;
		//case "fuck";ret = "fuck u 2";break;
		//case "fuck";ret = "fuck u 2";break;	
	} */	
	if(strsrch(arg,"���ĵ�����ָͱ��ͱ�������ӣ����������������ľ��һ����ʲô��ӦҲû�С�")!=-1)
	{
		switch(random(11)){
			case 1:
			case 2:
			case 3:
			case 4: emote = 1;
				ret = "poke zhongnian nanzi";
				break;
			case 5:
			case 6:
			case 7: emote = 1;
				ret ="heng";
				break;
			case 10:
				if(!me->query("marry")) return;
				emote = 0;
				ret ="����NPCҮ����Ҳͱ�������������"+me->query("marry/name")+"�鷳��";
				break;
			case 0:
			case 8: emote = 1;
				ret = "hmm "+getuid(me);
				break;
			case 9:return;
		}
	}
	else if(strsrch(arg,"����˵��������������˲�ǳ�����ս�����꣬�ٵ������Ի������Ǿʹ˱������˵������һ����ƮȻ��̶��")!=-1)
	{
		switch(random(4)){
			case 0:	emote = 1;
				ret = "wave "+getuid(me);
				break;
			case 1: emote = 1;
				ret = "byebye "+getuid(me);
				break;
			case 2: emote = 1;
				ret = "wave";
				break;
			case 3: return;
		}
	}
	/*
	�����ġ�(Nipciwei)����⬱�ȭ��������ɽ���ģ���ˮ���������Ǻ�����ڣ���
	else if(strsrch(arg,"")!=-1)
	{
		emote = 1;
		ret = "wave";
	}
	*/
	if(!undefinedp(ret)){
		CHANNEL_D->do_channel(this_object(),"chat",ret,emote);
		set_temp("chat_busy",1);
		call_out("delete_temp",5+random(4),"chat_busy");
	}
}
