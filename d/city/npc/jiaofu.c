// jiaofu.c �η�
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("�η�", ({ "jiao fu", "jiaofu", "fu" }));
	set("long", "����һ����ǿ��׳�Ľη���ò�������������롣\n");
	set("gender", "����");
	set("age", 25);
	set("attitude", "peaceful");
	set("str", 50);
	set("int", 10);
	set("max_qi", 600);
	set("combat_exp", 10000);
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);

	setup();
	carry_object(ARMOR_D("shoes"))->wear();
	carry_object(ARMOR_D("cloth"))->wear();
}