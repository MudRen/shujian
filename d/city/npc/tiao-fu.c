// seller.c

inherit NPC;

void create()
{
	set_name("����", ({ "tiao fu", "tiao", "fu", "porter" }) );
	set("gender", "����" );
	set("age", 20+random(15));
	set("long",
		"���Ǹ���ʵ�ͽ��������򣬳��ð�����Բ��һ���⡣\n");
	set("combat_exp", 700 + random(700));
        set("str", 25);
        set("dex", 22);
        set("con", 20);
        set("int", 15);
	set("attitude", "heroism");

	setup();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 3);
}

