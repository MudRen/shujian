// Npc: /kungfu/class/wudang/qlbz

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("���������", ({"qinglong dizi", "qinglong", "dizi"}));
	set("long", "����һ������ͨ�ĸ����������ӣ���ɫ�Ұס�\n");

	set("gender", "����");
	set("attitude", "peaceful");

	set("age", 30);
	set("shen", -1000);
	set("str", 35);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiaji", 50);
	set("combat_exp", 80000);
	set("score", 1);

	set_skill("force", 65);
        set_skill("unarmed", 60);
	set_skill("cuff", 60);
	set_skill("dodge", 60);
	set_skill("shuishangpiao", 20);
	set_skill("parry", 60);

	map_skill("dodge", "shuishangpiao");
	 
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
}
