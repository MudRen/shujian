// REN.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("������", ({ "Ren wuyue","ren","wuyue" }) );
        set("nickname", RED"ն���� ��˫��"NOR);        
        set("title",HIY"��ɽ����ǰ����ͽ"NOR);         
	set("gender", "����");
	set("age", 45);
	set("long",
		"����ǧ��ʯ����������һ�����ɱ����һ�������ɷ��ģ��������������η��\n");
	set("combat_exp", 120000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set("chat_chance", 5);
	set("chat_msg", ({
		"�����ºٺٵ���Ц��:���Ҵ���ǧ��ʯ��������ͱ����������ų�ȥ��!\n",
	}) );
        set_skill("tianmo-shou", 80);
	set_skill("sword", 80);
	set_skill("unarmed", 80);
	set_skill("parry", 150);
	set_skill("dodge", 80);
        map_skill("sword", "tianmo-shou");
        map_skill("parry", "tianmo-shou");
	setup();
        carry_object(BINGQI_D("changjian"))->wield();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}
