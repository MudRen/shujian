
inherit NPC;
#include <ansi.h>;
void create()
{
	set_name("ƽ��", ({ "ping si", "ping", "si" }));
	set("gender", "����");
	set("age", 40);
	set("str", 20);
	set("dex", 20);
	set("long", "����һλ�������ˣ�ԭ�ǲ��ݿ�ջ��һ���ջ��С��ƣ�\n"+
		"�������˷�ͺ�һ���������˺�һ�������Ӻ�쳣����������ˡ�\n");
	set("combat_exp", 50000);
	set("shen_type", 1000);
	set("attitude", "peaceful");

	set_skill("cuff", 60);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 10);

	set("neili", 900);
	set("max_neili", 900);
	set("jiali", 20);
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}
