inherit NPC;
#include <ansi.h>

void create()
{
	set_name("���ֶ�", ({"shabi"}));
	set("nickname", HIR "�����ܰ�����ô��...." NOR);
	set("long", HIC "\n���Ǹ�����,���ӵ���������,���Ÿ���ɫ��ȭ���̿�,���������������.\n" NOR);
	set("gender", "����");
	set("age", 51);
	set("qi", 8000);
	set("max_jing", 200);
	set("neili", 0);
	set("max_neili", 0);
	set("jiali", 0);
	set("inmortal",1);
	set("attitude", "friendly");
	set("combat_exp", 2000);
	set("str", 5);
	set("int", 5);
	set("con", 5);
	set("dex", 5);
	set("env/wimpy", 90);
	set("inquiry", ([
		"���ֶ�"   : "�ٺ�,���Ӿ���",
		"�й�"     : "�й��Ƕ���,�óԵĺ�",
                        "china"	:  "Сcase,��Ҫ������������",
                        "����˹��"    :  "С����,�������˵�,���ǹ�ɧ",
                       
	]) );
	set("chat_chance", 3);
		set("chat_chance_combat", 20);  
	set("chat_msg_combat", ({
		"�й�û������!�������˵�\n",
	(: command("chat ����˹���湻��!\n") :),
	(: command("chat �����ġ�\n") :),
	(: command("grin") :),
	(: command("hehe") :),
	(: command("chat ���������,�����ܰ�����ô��?\n") :),
	(: command("chat ����" + RANK_D->query_rude(this_player())+"�ܰ�����ô��,С������ը��ը��?\n") :),
	       
 	}) );
	setup();
	if( clonep() ) CHANNEL_D->register_relay_channel("chat");
}
