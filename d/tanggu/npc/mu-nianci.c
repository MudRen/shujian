// mu nianci.c �����
// By tangfeng 2004

#include <ansi.h>
inherit NPC;

#define NEXT_TIME 7200
//�����׵�����ȫ��ʱ��
#define WAIT_TIME 10
//�����׵��´�����ʱ����
//�����ڼ�

#define ASKTIME 10
#define ZHAOQIN_DIR "/d/tanggu/"
//�ļ�Ŀ¼
#define BIWU_LEITAI ZHAOQIN_DIR"biwuleitai.c"
//������̨
#define BIWU_USER ZHAOQIN_DIR"npc/copy_user.c"
//��������

int start_time,over_time,ask_time;
//0 1 ��ʼ2 ������� 3 ��Ů���� 4 ������� 5 �������� 6 ����� 
//query("bwzh/host_player") [id/name/object] ��Ů
//query("bwzh/winner_player") [id/name/object] ����
//query("bwzh/challenge_player") [id/name/object] ��ս��
//query("bwzh/fail_player") [id/name/object] ʧ����(ֻ����¼������)

int ask_biwu();
int ask_lihun();

int yingzhao(string arg);
int write_qi(string arg);
int chakan (string arg);
int answer (string arg);

int check_player(object me,int i);
void init_over();
void biwu_stop(int i);

void choose_mode(string arg, object me);
void choose_age(string arg, object me);
void choose_per(string arg, object me);
void choose_exp(string arg, object me);
void choose_ok(string arg, object me);
void choose_other(object me,int x);

string query_setting();

void create()
{
	set_name("�����",({"mu nianci", "mu", "nianci"}));
	set("long", "��λ������Ȼ�������أ�������֮��������ȴ��\n");
	set("age", 25);
	set("attitude", "friendly");
	set("shen", 0);
	set("per", 30);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("no_get", 1);
	set("no_bark", 1);
	set("job_npc", 1);
	set("no_ansuan", 1);
	set("leitai",BIWU_LEITAI);

	set("max_qi", 4500);
	set("max_jing", 3200);
	set("eff_jingli", 3500);
	set("jiali", 200);
	set("combat_exp", 2500000); 
	set("unique", 1);
	set("no_clean_up",1);//����ing

	set_skill("dodge",220);
	set_skill("force", 220);
	set_skill("literate", 200);
	set_skill("strike", 220);
	set_skill("tiezhang-zhangfa", 220);
	set_skill("shuishangpiao", 220);
	set_skill("shenzhao-jing", 220);
	set_skill("parry", 220);
	set_skill("medicine", 160);

	map_skill("force", "shenzhao-jing");
	map_skill("dodge", "shuishangpiao");
	map_skill("parry", "tiezhang-zhangfa");
	map_skill("strike", "tiezhang-zhangfa");
	prepare_skill("strike", "tiezhang-zhangfa");

	set("inquiry", ([
		"��������"	:	(: ask_biwu :),
		"���"	:	(: ask_lihun :),
		"����"	:	"����������Ӧ�û������������ر߾���",
		"�":	    "...............................ԩ����",
	]));

	setup();
	carry_object(ARMOR_D("pink_cloth"))->wear();
	carry_object(ARMOR_D("shoe"))->wear();

}
void init()
{
	add_action("yingzhao","yingzhao");//over
	add_action("fabu","fabu");//over
	add_action("cancel","cancel");//over
	add_action("chakan","chakan");//over
	add_action("write_qi","write");//over
	add_action("answer","answer");//over
}

#include "ask_biwu.h";
#include "check_player.h";
#include "write_qi.h";
#include "choose_mode.h";
#include "choose.h";
#include "choose_ok.h";
#include "yingzhao.h";
#include "biwu_over.h";
#include "checking.h";
#include "zhaoqin.h";
#include "answer.h";

int fabu(string arg)
{
	object me,ob,who;
	int money = 500000;
	me = this_player();
	ob = this_object();
	if(!me->query_temp("quest/bwzh/hoster")) return 0;
	if(!arg || ( arg!="xiaoxi" && arg!="xiao xi" && arg!="message")) return 0;
	if(!query("station"))
	{
		command("? "+me->query("id"));
		command("say ���ڻ�δ�����׻���Ǻǡ�");
		return 1;	
	}

	who=find_player(query("bwzh/winner_player/id"));

	switch (MONEY_D->player_pay(me, money)) {
		case 0:
		case 2:
		return notify_fail("����һ����Ϣ��Ҫ�ķ�����"+MONEY_D->money_str(money)+"�������ϴ��Ļƽ𲻹��ˡ�\n");
	}
	command("nod");
	if(random(2)) CHANNEL_D->do_channel(this_object(),"rumor",HIY+"��˵�������ڱ������ף���ӭ��·���ܿ�ӻԾ������"NOR);
	else if(who && random(2)) CHANNEL_D->do_channel(this_object(),"rumor",HIY+"�������ڱ������ף�����Ŀǰ��"+who->query("name")+"����ӭ��·���ܿ�ӻԾ������"NOR);
	else CHANNEL_D->do_channel(this_object(),"chat",HIY+"��˵"+me->query("name")+"С�����ڱ������ף���ӭ��·���ܿ�ӻԾ������"NOR);
	command("say ���İɣ�һ��С�����ǾͶ����ˡ�");
	command("haha");
	return 1;
}

int chakan(string arg)
{
	object me;
	string str;
	me = this_player();
	if(arg ) return 0;
	if(!wizardp(me)) return 0;
	str = query_setting();
	tell_object(me,str);    
	return 1;
}
void die()
{
	reincarnate();
	message_vision("$N�������˼���������ɫ�������ö��ˡ�\n",this_object());
	return;	
}
int ask_lihun()
{
	object me=this_player();

	if(me->query("marry"))
	{
		if(!wizardp(me))
		{
			command("say ���Ǻú���ϧ��İ��°ɣ�"+me->query("marry/name")+"("+capitalize(me->query("marry/id"))+")Ҳ�����װ���");
			command("pat "+me->query("id"));
			return 1;
		}
		if(me->query("gender")=="����")
			command("chat "+HIY"Ӣ�۰���Ϊ��QUEST���㾹Ȼ�������ӣ�����ΰ�󣬸м����м���"NOR);
		else 
			command("chat "+HIY"��Ů����Ϊ��QUEST���㾹Ȼ���Ϲ����ˣ����������ң��м����м���"NOR);
		me->delete("marry");
        command("chat* thank "+me->query("id"));
		if (present("yu pei", me)) present("yu pei", me)->lost(me);
		if (present("xiang nang", me)) present("xiang nang", me)->lost(me);
	}
	else 
	{	
		command("say ������Ҹ�������");
		command("tsk "+me->query("id"));
	}
	return 1;
}
void init_over()
{
	object ob;
	ob=query("bwzh/host_player/object");
	if(ob)
	{
		ob->delete_temp("quest/bwzh");
		ob->delete_temp("quest/busy");
		ob->delete_temp("apply/short");  
	}
	ob=query("bwzh/winner_player/object");
	if(ob)
	{
		ob->delete_temp("quest/bwzh");
		ob->delete_temp("quest/busy");
		ob->delete_temp("apply/short");  
	}
	ob=query("bwzh/challenge_player/object");
	if(ob)
	{
		ob->delete_temp("quest/bwzh");
		ob->delete_temp("quest/busy");
		ob->delete_temp("apply/short");  
	}
	delete("bwzh");
	over_time=time();
	set("station",0);
	return;
}
string query_setting()
{
	object where;
	
	string str="";
	str += "\n״  ̬��"+query("station")+"";
	str += "|���飺"+query("bwzh/exp");
	str += "|��ò��"+query("bwzh/per");
	str += "|���䣺"+query("bwzh/age");
	str += "\n";
	if(query("bwzh/host_player"))
	{
		str += "\n��  �ˣ�"+query("bwzh/host_player/name");
		str += "|"+query("bwzh/host_player/id");
		where = environment(query("bwzh/host_player/object"));
		if(where)
		{
			str+="|"+where->query("short");
			str+="|"+base_name(where);
		}
		else
		{
			str+="|"+"����";
			str+="|"+"none";
		}
	}
	if(query("bwzh/winner_player"))
	{
		str += "\n��  ����"+query("bwzh/winner_player/name");
		str += "|"+query("bwzh/winner_player/id");
		where = environment(query("bwzh/winner_player/object"));
		if(where)
		{
			str+="|"+where->query("short");
			str+="|"+base_name(where);
		}
		else
		{
			str+="|"+"����";
			str+="|"+"none";
		}
	}
	if(query("bwzh/challenge_player"))
	{
		str += "\n��ս�ߣ�"+query("bwzh/challenge_player/name");
		str += "|"+query("bwzh/challenge_player/id");
		where = environment(query("bwzh/challenge_player/object"));
		if(where)
		{
			str+="|"+where->query("short");
			str+="|"+base_name(where);
		}
		else
		{
			str+="|"+"����";
			str+="|"+"none";
		}
	}
	if(query("bwzh/fail_player"))
	{
		str += "\nʧ���ߣ�"+query("bwzh/fail_player/name");
		str += "|"+query("bwzh/fail_player/id");
	}
	str += "\n";
	return str;
}
