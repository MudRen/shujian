// kid.c

inherit NPC;

void create()
{
	set_name("С��",({ "xiao hai", "xiaohai", "kid" }) );
        set("gender", "����" );
        set("age", 7);
        set("long", "���Ǹ�ũ��С����\n");
        set("combat_exp", 500);
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
        setup();
	carry_object("/clone/misc/cloth")->wear();
}