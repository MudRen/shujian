// lgshou.c �����
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("�����", ({ "luogu shou", "shou" }));
	set("long", "����һ�����񴵴����ֵ�����֣����Ϲ�����ģ��𾢵��ô��š�\n");
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
}
