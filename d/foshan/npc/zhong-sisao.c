// zhong.c ����ɩ 

#include <ansi.h>

inherit NPC;

int ask_me();

void create()
{
	set_name("����ɩ", ({ "zhong sisao","zhong","sisao" }));
	set("long",
		"��ͷ��ɢ�ң����ϡ����ϡ�����ȫ����Ѫ������ץ��һ���˵�����һ
��Цһ��ָ�ֻ��ţ�ԭ���Ǹ����ӡ�\n");
	set("gender", "Ů��");
	set("age", 35);

	set("str", 20);
        set("int", 15);
        set("con", 20);
        set("dex", 15);

	set("max_qi", 100);
        set("max_jing", 100);
        set("neili", 100);
        set("max_neili", 100);

        set("jingli",100);
        set("max_jingli",100);
        set("jiali", 1);   
	set("combat_exp", 2000);

        set("inquiry", ([
		"��С��"   : (: ask_me :),
                "������": "����ү���۾�ѽ������С���ӿ�û͵�˼ҵĶ�԰���\n",
]) );


	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_me()
{
	this_player()->set_temp("marks/feng",1);
	write("����ɩͻȻ�����޺�������Ŀ����ͣ���Ȼ�޷��ش�������⡣\n");
	return 1;
}